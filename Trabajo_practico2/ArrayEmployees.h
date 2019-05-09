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

int spaceFinderInTheArray(Employee* eEmployee,int len,int* index);

int addEmployee(Employee* eEmployee, int len,int posLibre);

int modifyEmployee(Employee* eEmployee, int len);

int findEmployeeById(Employee* eEmployee, int len,int* idE);

int removeEmployee(Employee* eEmployee, int len);

int sortEmployeesUpward(Employee* eEmployee, int len);

int sortEmployeesFalling(Employee* eEmployee, int len);

int printEmployees(Employee* eEmployee, int len);

#endif // ARRAYEMPLOYEES_H_INCLUDED
