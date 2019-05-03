#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "utn_strings.h"

static int generarId(void);

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

int addEmployee(Employee* eEmployee,
                int len,
                int id,
                char name[],
                char lastName[],
                float salary,
                int sector,
                int pIndex,
                char* msgE,
                int tries)
{
    char bufferName[50];
    char bufferLastName[50];
    char bufferSalario[20];
    char bufferSector[20];
    float auxSalario;
    int auxSector;
    int retorno=-1;
    if((eEmployee!=NULL)&&(len>0))
    {
        if(((getStringLetras(bufferName,"\nIngrese nombre: ",msgE,tries)==0)&&
            (getStringLetras(bufferLastName,"\nIngrese apellido: ",msgE,tries)==0)))
        {
            if((getStringNumerosFloat(bufferSalario,"\nIngrese salario: ",msgE,tries)==0)
                &&(getStringNumeros(bufferSector,"\nIngrese sector: ",msgE,tries)==0))
            {
                auxSalario=atof(bufferSalario);
                auxSector=atoi(bufferSector);
                strncpy(eEmployee[pIndex].name,bufferName,sizeof(bufferName));
                strncpy(eEmployee[pIndex].lastName,bufferLastName,sizeof(bufferLastName));
                eEmployee[pIndex].salary=auxSalario;
                eEmployee[pIndex].sector=auxSector;
                eEmployee[pIndex].id=generarId();
                eEmployee[pIndex].isEmpty=0;
                retorno=0;
            }
        }
    }
    return retorno;
}

int findEmployeeById(Employee* eEmployee, int len,int idE)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(eEmployee[i].id==idE)
        {
            ret=i;
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

static int generarId(void)
{
    static int idEmployee=0;
    return idEmployee++;
}
