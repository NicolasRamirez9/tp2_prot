#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_strings.h"
#include "biblioteca.h"
#define REINTENTOS 3
#define LEN_LISTA 5

int main()
{
    int flag=0;
    int posLibre;
    int opcion=0;
    Pantalla visores[LEN_LISTA];
    Publicidad Marketing[LEN_LISTA];


    pan_initPantalla(visores,LEN_LISTA);
    pub_initPublicidad(Marketing,LEN_LISTA);

    //******************* SACAR *****************
  //  strcpy(visores[0].direccion,"Mitre 750");
   // visores[0].isEmpty=0;
    //strcpy(visores[0].nombre,"pantalla 1");
    //visores[0].precio= 1000.20;
    //visores[0].tipo=0;
    //visores[0].idPantalla=0;

    //strcpy(visores[1].direccion,"Belgrano 750");
    //visores[1].isEmpty=0;
    //strcpy(visores[1].nombre,"pantalla 2");
    //visores[1].precio= 2000.20;
    //visores[1].tipo=0;
    //visores[1].idPantalla=1;

    flag=1;

    strcpy(Marketing[0].archivo,"archivo1.mp4");
    strcpy(Marketing[0].cuit,"20-20056658-5");
    Marketing[0].dias = 10;
    Marketing[0].isEmpty = 0;
    Market ing[0].idPublicidad = 0;
    Marketing[0].idPantalla = 0;

    strcpy(Marketing[1].archivo,"archivo2.mp4");
    strcpy(Marketing[1].cuit,"20-20056658-5");
    Marketing[1].dias = 1;
    Marketing[1].isEmpty = 0;
    Marketing[1].idPublicidad = 1;
    Marketing[1].idPantalla = 0;

    strcpy(Marketing[2].archivo,"archivo3.mp4");
    strcpy(Marketing[2].cuit,"20-20056659-5");
    Marketing[2].dias = 6;
    Marketing[2].isEmpty = 0;
    Marketing[2].idPublicidad = 2;
    Marketing[2].idPantalla = 1;
    //******************* SACAR *****************


    while(opcion!=7)
    {
        getIntInRange(&opcion,"\n1)Alta de pantalla\n2)Modificar datos de pantalla\n3)Baja de pantalla\n"
                      "4)Contratar Publicidad\n5)Mostrar Pantallas\n6)Informes\n\n    INGRESE OPCION: ","ERROR\n",1,6,3);
        switch(opcion)
        {
            case 1:
            {
                posLibre=pan_findFree(visores,LEN_LISTA);
                if(posLibre>=0)
                {
                    printf("\n----Se encontro lugar----\n");
                    if(!pan_addPan(visores,LEN_LISTA,posLibre,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        flag=1;
                        printf("\n----Se dio de ALTA exitosamente!----\n");
                    }
                    else
                    {
                        printf("\n----No se realizo el ALTA!----\n");
                    }
                }
                else
                {
                    printf("\n----No se encontro lugar libre!----\n");
                }
                break;
            }
            case 2:
            {
                if(flag)
                {
                    if(pan_alter(visores,LEN_LISTA,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----Se modifico exitosamente----\n");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS en la NOMINA!----\n");
                }
                break;
            }
            case 3:
            {
                if(flag)
                {
                    if(pan_removePantalla(visores,LEN_LISTA,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----La BAJA se realizo con exito!----\n");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS en la NOMINA!----\n");
                }
                break;
            }
            case 4:
            {
                if(flag)
                {
                    pan_printPantalla(visores,LEN_LISTA);
                    if(!pub_addPub(Marketing,visores,LEN_LISTA,"\nDATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----La CONTRATACION se realizo con exito!----\n");
                    }
                    else
                    {
                        printf("\n----No pudo CONTRATARSE la pantalla!----\n");
                    }
                }
                else
                {
                    printf("\n----No hay PANTALLAS en la NOMINA!----\n");
                }
                break;
            }
            case 5:
            {
                if(flag)
                {
                    pan_printPantalla(visores,LEN_LISTA);
                }
                break;
            }

            case 6:
              //  acomodamientoPrecio(visores,LEN_LISTA);
              //  acomodamientoNombre(visores,LEN_LISTA);
                  cantidadDeDiasMenor(visores,Marketing,LEN_LISTA);
                break;

        }
    }
    return 0;
}
