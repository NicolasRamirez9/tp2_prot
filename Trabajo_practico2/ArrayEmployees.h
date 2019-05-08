#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#define NOMBRE_APELLIDO 51

struct
{
 int id;
 char name[NOMBRE_APELLIDO];
 char lastName[NOMBRE_APELLIDO];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

int initEmployees(Employee* eEmployee, int len);

int addEmployee(Employee* eEmployee, int len,int posLibre);

int findEmployeeById(Employee* eEmployee, int len,int idE);

int removeEmployee(Employee* eEmployee, int len, char* msgE,int tries);

int sortEmployees(Employee* eEmployee, int len);

int printEmployees(Employee* eEmployee, int len);

#endif // ARRAYEMPLOYEES_H_INCLUDED
