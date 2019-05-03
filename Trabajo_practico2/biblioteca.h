#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
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

int addEmployee(Employee* eEmployee,
                int len,
                int id,
                char name[],
                char lastName[],
                float salary,
                int sector,
                int pIndex,
                char* msgE,
                int tries);

int findEmployeeById(Employee* eEmployee, int len,int idE);

int removeEmployee(Employee* eEmployee, int len, char* msgE,int tries);

int sortEmployees(Employee* eEmployee, int len);

int printEmployees(Employee* eEmployee, int len);





#endif // BIBLIOTECA_H_INCLUDED
