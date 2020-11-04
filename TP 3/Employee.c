#include "Employee.h"


Employee* employee_new()
{
    Employee* employeeParameter;

    employeeParameter = (Employee*)malloc(sizeof (Employee));

    return employeeParameter;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* newEmployee;
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        newEmployee = employee_new();

        if(employee_setId(newEmployee,atoi(idStr)))
        {
            if(employee_setNombre(newEmployee,nombreStr))
            {
                if(employee_setHorasTrabajadas(newEmployee,atoi(horasTrabajadasStr)))
                {
                    if(employee_setSueldo(newEmployee,atof(sueldoStr)))
                    {

                    }
                }
            }
        }
    }
    else
    {
        newEmployee = NULL;
    }

    return newEmployee;
}

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int employee_setId(Employee* this,int id)
{
    int set;

    set = 0;

    if(this!=NULL && id>0)
    {
        set = 1;
        this->id =id;
    }
    return set;
}

int employee_getId(Employee* this,int* id)
{
    int get;

    get = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        get = 1;
    }
    return get;
}



int employee_setNombre(Employee* this,char* nombre)
{
    int set;

    set = 0;

    if(this!=NULL && nombre != NULL)
    {
        set = 1;
        strcpy(this->nombre, nombre);
    }
    return set;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int get;

    get = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        get = 1;
    }
    return get;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int set;

    set = 0;

    if(this!=NULL && horasTrabajadas>0)
    {
        set = 1;
        this->horasTrabajadas =horasTrabajadas;
    }
    return set;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int get;

    get = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        get = 1;
    }
    return get;
}

int employee_setSueldo(Employee* this,float sueldo)
{
    int set;

    set = 0;

    if(this!=NULL && sueldo>0)
    {
        set = 1;
        this->sueldo =sueldo;
    }
    return set;
}

int employee_getSueldo(Employee* this,float* sueldo)
{
    int get;

    get = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        get = 1;
    }
    return get;
}

int employee_CompareByName(void* e1, void* e2)
{
    int comparison;
    char name1[128];
    char name2[128];
    comparison = -2;

    if(e1 != NULL && e2 != NULL)
    {
        employee_getNombre(e1, name1);

        employee_getNombre(e2, name2);
        comparison = strcmp(name1, name2);
    }
    return comparison;
}

int employee_CompareById(void* e1, void* e2)
{
    int comparison;
    int id1;
    int id2;

    comparison = -2;
    if(e1 != NULL && e2 != NULL)
    {
        employee_getId(e1, &id1);
        employee_getId(e2, &id2);
        comparison = gu_CompareTwoInt(id1, id2);
    }

    return comparison;
}

int employee_AssignNombre(Employee* pEmployee)
{
    char name[128];
    int retorno;
    retorno = 0;
    if(pEmployee != NULL && name != NULL)
    {
        ev_InputString_Name(name, sizeof(name), "\nIngrese el nombre del empleado: ",
                                 "\nEl nombre no puede contener numeros. Reingrese el nombre: ");
        employee_setNombre(pEmployee, name);
        retorno = 1;
    }
    return retorno;
}

int employee_AssignHorasTrabajadas(Employee* pEmployee)
{
    int hoursWorked;
    int retorno;

    retorno = 0;
    if(pEmployee != NULL)
    {
        ev_InputIntOverParameter("\nIngrese las horas trabajadas: ",
                                     "\nLas horas trabajadas deben ser mayores a 0. Reingrese las horas: ",
                                     &hoursWorked, 0);
        employee_setHorasTrabajadas(pEmployee, hoursWorked);
        retorno = 1;
    }
    return retorno;
}

int employee_AssignSueldo(Employee* pEmployee)
{
    float salary;
    int retorno; // return variable

    retorno = 0;
    if(pEmployee != NULL)
    {
        ev_InputFloatOverParameter("\nIngrese el sueldo: ",
                                 "\nEl sueldo debe ser mayor a 0. Reingrese el sueldo: ",&salary, 0);
        employee_setSueldo(pEmployee, salary);
        retorno = 1;
    }
    return retorno;
}

int employee_CompareByHours(void* e1, void* e2)
{
    int comparison;
    int hours1;
    int hours2;
    comparison = -2;
    if(e1 != NULL && e2 != NULL)
    {
        employee_getHorasTrabajadas(e1, &hours1);
        employee_getHorasTrabajadas(e2, &hours2);
        comparison = gu_CompareTwoInt(hours1, hours2);
    }
    return comparison;
}

int employee_CompareBySalary(void* e1, void* e2)
{
    int comparison;
    float salary1;
    float salary2;

    comparison = -2;
    if(e1 != NULL && e2 != NULL)
    {
        employee_getSueldo(e1, &salary1);
        employee_getSueldo(e2, &salary2);
        comparison = gu_CompareTwoFloat(salary1, salary2);
    }
    return comparison;
}
