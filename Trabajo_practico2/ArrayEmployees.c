#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "biblioteca.h"
#include "utn_strings.h"

static int generarId(void)
{
    static int idEmployee=0;
    return idEmployee++;
}

int initEmployees(Employee* eEmployee, int len)
{
    int i;
    if(eEmployee!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            eEmployee[i].id=-1;
            eEmployee[i].isEmpty=1;
        }
    }
    return 0;
}

int addEmployee(Employee* eEmployee, int len,int posLibre)
{
     int ret=1;

 //   printf("ID es:%d",generarId(void));

    if (!getName(eEmployee[posLibre].name,"ingrese un nombre: ","error, vuelva a ingresar\n\n",2,20,1))
    {
        if (!getName(eEmployee[posLibre].lastName,"ingrese un apellido: ","error, vuelva a ingresar\n\n",2,20,1))
        {
            if (!getFloat("ingrese salario: ","error,vuelva a intentar",0,10,1,&eEmployee[posLibre].salary))
            {
                if(!getInt("ingrese un sector:\n1=LCD\n2=LED\n:","\nerror,vuelva a intentar",1,2,1,&eEmployee[posLibre].sector))
                {
                    eEmployee[posLibre].isEmpty=0;
                    ret=0;
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

    for(i=0;i<cant;i++)
    {
        if(eEmployee[i].isEmpty != -1)
        {
            printf("ID disponibles: %d\n",eEmployee[i].id);
        }
    }
    if(!searchId(eEmployee, len, &posId))
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
                getName(eEmployee[posPrueba].name,"\n Modifique el nombre: \n","\nerror, vuelva a ingresar\n\n",2,20,1);
                break;
            case 6:
                getName(eEmployee[posPrueba].lastName,"\n Modifique el apellido: \n","\nerror, vuelva a ingresar\n\n",2,20,1);
                break;
            case 7:
                getFloat("\n Modifique el salario: \n","\n error,vuelva a intentar\n",0,10,1,salary);
                auxSal=atof(salary);
                eEmployee[posPrueba].salary=auxSal;
                break;
            case 8:
                getInt("\n Modifique el sector: \n","\n error,vuelva a intentar",1,2,1,sector);
                auxSec=atoi(sector);
                eEmployee[posPrueba].sector=auxSec;
                break;
            }
            printf("\n Quiere modificar otro campo?\n   s/para continuar n/para salir\n");
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

int removeEmployee(Employee* eEmployee, int len, char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;
    if(eEmployee!=NULL && len>0)
    {
        auxID = emp_getID(eEmployee, len, msgE, tries);
         if(auxID>=0)
        {
            posOfID=findEmployeeById(eEmployee, len, auxID);
            if(posOfID!=-1)
            {
               eEmployee[posOfID].isEmpty=1;
               retorno=0;
            }
        }
     }
    return retorno;
}

int emp_getID (Employee* eEmployee, int len, char* msgE, int                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     tries)
{
    int retorno=-1;
    char bufferID[20];
    int auxID;
    if(eEmployee!=NULL && len>0)
    {
        if(!getStringNumeros(bufferID,"\nIngrese ID: ",msgE,tries))
        {
            auxID=atoi(bufferID);
            retorno=auxID;
        }
    }
    return retorno;
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

int printEmployees (Employee* eEmployee,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(eEmployee[i].isEmpty==0)
        {
            printf("\nID: %d\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d\n-------",
                   eEmployee[i].id,
                   eEmployee[i].name,
                   eEmployee[i].lastName,
                   eEmployee[i].salary,
                   eEmployee[i].sector);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}

int spaceFinderInTheArray(Empleado* eEmpleado,int len,int* index)
{
    int ret;
    int i;

    for(i=0; i<len; i++)
    {
        if(eEmpleado[i].isEmpty == VACIO)
        {
            *index = i;
            ret=0;
            break;
        }
        ret=-1;
    }

    return ret;
}
