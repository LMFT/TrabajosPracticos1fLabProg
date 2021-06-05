#include "Input.h"


#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


int employee_setLastId(int id);
int employee_getLastId();
int employee_increaseLastId();
int employee_decreaseLastId();


Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salarioStr);
Employee* employee_newSetted();

void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_printOne(Employee* myEmployee);

int employee_compareById(void* firstEmployee, void* secondEmployee);
int employee_compareByName(void* firstEmployee, void* secondEmployee);
int employee_compareByHoursWorked(void* firstEmployee, void* secondEmployee);
int employee_compareBySalary(void* firstEmployee, void* secondEmployee);
#endif // employee_H_INCLUDED
