#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete(Employee*);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,float sueldo); // Cambio la firma de int sueldo a float sueldo, tiene mas sentido que se puedan incluir decimales
int employee_getSueldo(Employee* this,float* sueldo); // Cambio la firma de int* sueldo a float* sueldo, tiene mas sentido que se puedan incluir decimales

int employee_CompareByName(void* e1, void* e2);
int employee_CompareById(void* e1, void* e2);
int employee_CompareByHours(void* e1, void* e2);
int employee_CompareBySalary(void* e1, void* e2);

int employee_AssignSueldo(Employee* pEmployee);
int employee_AssignHorasTrabajadas(Employee* pEmployee);
int employee_AssignNombre(Employee* pEmployee);

#endif // employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EntradaVerificacion.h"
#include "General_Use.h"
