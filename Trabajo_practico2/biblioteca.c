#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_strings.h"
#include "biblioteca.h"
#define EMPLEADO 3
#define VACIO -1
#define LLENO 1

int abm(void)
{
    int opciones;
    int posLibre;
    int flagValidar = 0;
    char seguir = 's';
    Employee eEmployee[EMPLEADO];

    initEmployees(eEmployee, EMPLEADO);

    do
        {
            system ("color 4f");

            printf("\n *------------------Trabajo practico N°2-------------------* \n");

            printf("\n *                                                *\n");

            printf ("\n *   1. Alta.                                     *\n");

            printf("\n *                                                *\n");

            printf ("\n *   2. Modificar.                                *\n");

            printf("\n *                                                *\n");

            printf ("\n *   3. Baja.                                     *\n");

            printf("\n *                                                *\n");

            printf ("\n *   4. Informar.                                 *\n");

            printf("\n *                                                *\n");

            printf ("\n *   0. Salir.                                    *\n");

            printf("\n *------------------------------------------------* \n");

            printf ("\n Ingrese una opcion: ");
            scanf("%d" , &opciones);

            switch (opciones)
            {
            case 0:
                system("cls");
                opciones = ;
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

                        printf("\n El dato ingresado es correcto. \n");
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

                }
                break;

            case 3:
                system ("cls");
                break;

            case 4:
                system ("cls");
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

