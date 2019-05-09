#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_strings.h"
#define EMPLEADO 3
#define VACIO -1
#define LLENO 1

int abm(void)
{
    int opciones;
    int posLibre;
    int flagValidar = 0;
    char seguir = 's';
    int report;
    Employee eEmployee[EMPLEADO];

    initEmployees(eEmployee, EMPLEADO);

    do
        {
            system ("color 4f");

            printf("\n *------------------Trabajo practico N°2-------------------* \n");

            printf("\n *                                                         * \n");

            printf("\n *   1. Alta.                                              * \n");

            printf("\n *                                                         * \n");

            printf("\n *   2. Modificar.                                         * \n");

            printf("\n *                                                         * \n");

            printf("\n *   3. Baja.                                              * \n");

            printf("\n *                                                         * \n");

            printf("\n *   4. Informar.                                          * \n");

            printf("\n *                                                         *\n");

            printf("\n *   0. Salir.                                             *\n");

            printf("\n *---------------------------------------------------------* \n");

            printf ("\n Ingrese una opcion: ");
            scanf("%d" , &opciones);

            switch (opciones)
            {
            case 0:
                system("cls");
                printf("\n Saliendo... \n");
                printf("\n");
                break;

            case 1:
                system ("cls");
                if(!spaceFinderInTheArray(eEmployee, EMPLEADO, &posLibre))
                {
                    flagValidar = 1;
                    switch(addEmployee(eEmployee, EMPLEADO, posLibre))
                    {
                    case 0:

                        printf("\n El dato ingresado es correcto. \n");
                        break;

                    case 1:

                        printf("\n El dato ingresado es incorrecto. \n");
                        break;
                    }
                }
                else
                {
                    printf("LLENO.");
                }
                break;

            case 2:
                if(flagValidar == 0)
                {
                    system ("cls");
                    printf("\n No hay datos para modificar, se debe cargar el empleado primero. \n");
                }
                else
                {
                    modifyEmployee(eEmployee, EMPLEADO);
                }
                break;

            case 3:
                if(flagValidar == 0)
                {
                    printf("\n No hay datos para dar de baja, se debe cargar al empleado primero. \n");
                }
                else
                {
                    removeEmployee(eEmployee, EMPLEADO);
                }
                break;

            case 4:
                if(flagValidar == 0)
                {
                    printf("\n No hay datos que informar, se debe cargar al empleado primero. \n");
                }
                else
                {
                    printf("\n *---------------------------------------------------* \n");

                    printf("\n *                                                   * \n");

                    printf("\n *   1. Apellido y sector del empleado ordenados     * \n");

                    printf("\n *      alfabeticamente de manera ascendente.        * \n");

                    printf("\n *                                                   * \n");

                    printf("\n *   1. Apellido y sector del empleado ordenados     * \n");

                    printf("\n *      alfabeticamente de manera descendente.       * \n");

                    printf("\n *                                                   * \n");

                    printf("\n *   3. Total y promedio de los salarios.            * \n");

                    printf("\n *                                                   * \n");

                    printf("\n *---------------------------------------------------* \n");

                    printf("\n Elija una opcion: \n");
                    scanf("%d", &report);

                    switch(report)
                    {
                    case 1:
                        alphabeticallyOrderedByUpward(eEmployee, EMPLEADO);
                        break;
                    case 2:
                        alphabeticalOrderByFalling(eEmployee, EMPLEADO);
                        break;
                    case 3:
                        totalAndAverageSalary(eEmployee, EMPLEADO);
                        break;
                    }
                }
                break;

            default:
                printf("\n");
                printf("\n Ingrese una opcion valida! \n");
                printf("\n");
            }

            system("pause");
            system("cls");

        }while(seguir != 's');

        return 0;
}

static int generarId(void)
{
    static int idEmployee = 0;
    return idEmployee++;
}

int initEmployees(Employee* eEmployee, int len)
{
    int i;
    int ret;
    for(i=0; i<len;i++)
    {
        eEmployee[i].isEmpty = VACIO;
        ret = 0;
    }
    return ret;
}

int spaceFinderInTheArray(Employee* eEmployee,int len,int* index)
{
    int i;
    int ret;

    for(i=0; i<len; i++)
    {
        if(eEmployee[i].isEmpty == VACIO)
        {
            *index = i;
            ret=0;
            break;
        }
        ret=-1;
    }

    return ret;
}

int addEmployee(Employee* eEmployee, int len,int posLibre)
{
    int ret=1;
    char salary[50];
    float auxSal;
    char sector[50];
    int auxSec;

    if (!getName( eEmployee[posLibre].name,
                  "\n Ingrese nombre del empleado: \n",
                  "\n Error, vuelva a ingresar el nombre del empleado: \n",
                  2,
                  20,
                  1))
    {
        if (!getName( eEmployee[posLibre].lastName,
                      "\n Ingrese apellido del empleado: \n",
                      "\n Error, vuelva a ingresar el apellido del empleado: \n",
                      2,
                      20,
                      1))
        {
            if (!getFloat("\n Ingrese salario del empleado: \n",
                          "\n Error,vuelva a ingresar el salario del empleado: \n",
                          0,
                          10,
                          1,
                          salary))
            {
                auxSal=atof(salary);
                eEmployee[posLibre].salary = auxSal;
                if(!getInt( "\n Ingrese el sector del empleado: \n",
                            "\n Error, vuelva a ingresar el sector del empleado: \n",
                            1,
                            10,
                            1,
                            sector))
                {
                    auxSec=atoi(sector);
                    eEmployee[posLibre].sector = auxSec;
                    eEmployee[posLibre].id = generarId();
                    eEmployee[posLibre].isEmpty = 0;
                    ret=0;
                }
            }
        }
    }
    else
    {
        ret=1;
    }
    return ret;
}

int modifyEmployee(Employee* eEmployee, int len)
{
    int opcionesSegundoMenu;
    char mod;
    int ret=-1;
    int posId;
    char salary[50];
    float auxSal;
    char sector[50];
    int auxSec;
    int i;
    int posPrueba=0;

    for(i=0; i<len; i++)
    {
        if(eEmployee[i].isEmpty != -1)
        {
            printf("ID disponibles: %d\n",eEmployee[i].id);
        }
    }
    if(!findEmployeeById(eEmployee, len, &posId))
    {
        do
        {
            system("cls");
            printf("\n *---------------------------------------------* \n");

            printf("\n *                                             *\n");

            printf("\n *   5. Nombre.                                *\n");

            printf("\n *                                             *\n");

            printf("\n *   6. Apellido.                              *\n");

            printf("\n *                                             *\n");

            printf("\n *   7. Salario.                               *\n");

            printf("\n *                                             *\n");

            printf("\n *   8. Sector.                                *\n");

            printf("\n *                                             *\n");

            printf("\n *---------------------------------------------* \n");

            printf("\n Ingrese opcion que quiera modificar: \n");
            scanf("%d",&opcionesSegundoMenu);
            system("cls");
            switch(opcionesSegundoMenu)
            {
            case 5:
                getName( eEmployee[posPrueba].name,
                         "\n Modifique el nombre del empleado: \n",
                         "\n Error, vuelva a ingresar el nombre del empleado: \n",
                         2,
                         20,
                         1);
                break;
            case 6:
                getName( eEmployee[posPrueba].lastName,
                         "\n Modifique el apellido del empleado: \n",
                         "\n Error, vuelva a ingresar el apellido del empleado: \n",
                         2,
                         20,
                         1);
                break;
            case 7:
                getFloat( "\n Modifique el salario del empleado: \n",
                          "\n Error,vuelva a ingresar el salario del empleado: \n",
                          0,
                          10,
                          1,
                          salary);
                auxSal=atof(salary);
                eEmployee[posPrueba].salary=auxSal;
                break;
            case 8:
                getInt( "\n Modifique el sector del empleado: \n",
                        "\n error,vuelva a intentar",
                        1,
                        2,
                        1,
                        sector);
                auxSec=atoi(sector);
                eEmployee[posPrueba].sector=auxSec;
                break;
            }
            printf("\n ¿Quiere modificar otro campo? \n   Presione 's' para continuar o 'n' para salir: \n");
            scanf("%s",&mod);
            system("cls");
        }
        while(mod=='s');
        ret=0;
    }
    else
    {
        printf("No se encontro ID");
    }
    return ret;
}

int findEmployeeById(Employee* eEmployee, int len,int* idE)
{
    int i;
    int ret=-1;
    Employee auxEmployee;
    printf("\n Buscar ID: \n");
    scanf("%d", &auxEmployee.id);

    for(i=0;i<len;i++)
    {
        if(eEmployee[i].id == auxEmployee.id)
        {
            ret = 0;
            *idE = i;
            break;
        }
    }
    return ret;
}

int removeEmployee(Employee* eEmployee, int len)
{
    int posId;
    char resp;
    int posBaja=0;
    int i;

    for(i=0; i<len; i++)
    {
        if(eEmployee[i].isEmpty != VACIO)
        {
            printf("ID disponibles: %d\n", eEmployee[i].id);
        }
    }
    if(!findEmployeeById(eEmployee, len, &posId))
    {
        printf("\n ¿Está seguro que quiere dar de baja este ID? \n Presione 's' para aceptar o 'n' para cancelar: \n");
        scanf("%s",&resp);
        if(resp=='s')
        {
            printf("\n Este ID ha sido dado de baja. \n");
            eEmployee[posBaja].isEmpty = VACIO;
        }
        else
        {
            printf("\n Vuelva al menu. \n");
        }
    }
    return 0;
}

int sortEmployees(Employee* eEmployee, int len)
{
    int i;
    int j;
    Employee buffer;
    for(i=0;i<len-1;i++)
    {
        if(eEmployee[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<len;j++)
        {
            if(eEmployee[j].isEmpty==1)
            {
                continue;
            }
            if(eEmployee[i].id > eEmployee[j].id)
            {
                buffer=eEmployee[i];
                eEmployee[i]=eEmployee[j];
                eEmployee[j]=buffer;
            }
        }
    }
    return 0;
}

int sortEmployeesUpward(Employee* eEmployee, int len)
{
    int i;
    int j;
    int a;
    int b;
    int c;
    int d;
    Employee auxUno;
    Employee auxDos;

    printf("\n Apellido ordenado alfabeticamente de manera ascendente: \n");

    for(i = 1; i < len; i++)
    {
        auxUno = eEmployee[i];
        j = i;

        while(j > 0 && strcmp( auxUno.apellido, eEmployee[j - 1].apellido) < 0)
        {
            eEmployee[j] = eEmployee[j - 1];
            j--;
        }
        eEmployee[j] = auxUno;
    }

    for (d=0; d < len; d++)
    {
        if(eEmployee[d].isEmpty != VACIO)
        {
            printf("\n Nombre: %s  Apellido: %s  Salario: %.2f  Sector: %d \n",
                   eEmployee[d].name,
                   eEmployee[d].lastName,
                   eEmployee[d].salary,
                   eEmployee[d].sector);
        }
    }
    printf("\n Sector ordenado alfabeticamente de manera ascendente: \n");
    for(b = 1; b < len; b++)
    {
        auxDos = eEmployee[b];
        c = b;
        while(c > 0 &&  auxDos.sector < eEmployee[j - 1].sector)
        {
            eEmployee[c] = eEmployee[c - 1];
            c--;
        }
        arrayEmpleado[c] = auxDos;
    }
    for (a=0; a < len; a++)
    {
        if(eEmployee[a].isEmpty != VACIO)
        {
            printf("\n  Nombre: %s  Apellido: %s Salario: %.2f  Sector: %d \n",
                   eEmployee[a].name,
                   arrayEmpleado[a].lastName,
                   arrayEmpleado[a].salary,
                   arrayEmpleado[a].sector);
        }
    }
    return 0;
}

int sortEmployeesFalling(Employee* eEmployee, int len)
{
    int i;
    int j;
    int a;
    int b;
    int c;
    int d;
    Employee auxUno;
    Employee auxDos;

    printf("\n Apellido ordenado alfabeticamente de manera descendente: \n");
    for(i = 1; i < len; i++)
    {
        aux = arrayEmpleado[i];
        j = i;
        while(j > 0 && strcmp( aux.apellido, arrayEmpleado[j - 1].apellido)>0)
        {
            arrayEmpleado[j] = arrayEmpleado[j - 1];
            j--;
        }
        arrayEmpleado[j] = aux;
    }
    for (d=0; d<cant; d++)
    {
        if(arrayEmpleado[d].isEmpty!=VACIO)
        {
            printf("  nombre:%s  apellido:%s  salario:%.2f  sector:%d\n",arrayEmpleado[d].nombre,arrayEmpleado[d].apellido,arrayEmpleado[d].salario,arrayEmpleado[d].sector);
        }
    }
    printf("\n  ordenado alfabeticamente descendente por sector:\n");
    for(b = 1; b < cant; b++)
    {
        aux1 = arrayEmpleado[b];
        c = b;
        while(c > 0 &&  aux1.sector > arrayEmpleado[j - 1].sector)
        {
            arrayEmpleado[c] = arrayEmpleado[c - 1];
            c--;
        }
        arrayEmpleado[c] = aux1;
    }
    for (a=0; a<cant; a++)
    {
        if(arrayEmpleado[a].isEmpty!=VACIO)
        {
            printf("  nombre:%s  apellido:%s  salario:%.2f  sector:%d\n",arrayEmpleado[a].nombre,arrayEmpleado[a].apellido,arrayEmpleado[a].salario,arrayEmpleado[a].sector);
        }
    }
    return 0;
}
void totalAndAverageSalary(Empleado *arrayEmpleado,int cant)
{
    int i;
    float acum=0;
    float prom;
    float cont=0;
    int contDeProm=0;
    for(i=0; i<cant; i++)
    {
        acum=acum+arrayEmpleado[i].salario;
        if(arrayEmpleado[i].isEmpty!=VACIO)
        {
            cont++;
        }
    }
    prom=acum/cont;
    if(arrayEmpleado[i].isEmpty>prom)
    {
        contDeProm++;
    }
    printf("\n  el salario total es:%.2f y el promedio es:%.2f\n",acum,prom);
    printf("\n  los empleados que superaron el salario son:%d\n",contDeProm);
}


