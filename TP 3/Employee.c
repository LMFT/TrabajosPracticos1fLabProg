#include "Employee.h"

static int lastId = 0;

int employee_setLastId(int id)
{
    lastId = id;
    return lastId;
}

int employee_getLastId()
{
    return lastId;
}

int employee_increaseLastId()
{
    lastId++;
    return lastId;
}

int employee_decreaseLastId()
{
    lastId--;
    return lastId;
}

Employee* employee_new()
{
    Employee* new = (Employee*)calloc(1, sizeof(Employee));
    return new;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salarioStr) // Consultar por salario
{
    int id;
    int hoursWorked;
    int salary;
    Employee* new;

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && salarioStr != NULL)
    {
        new = employee_new();
        if(new != NULL)
        {
            id = atoi(idStr);
            hoursWorked = atoi(horasTrabajadasStr);
            salary = atoi(salarioStr);
            employee_setHorasTrabajadas(new, hoursWorked);
            employee_setId(new, id);
            employee_setNombre(new, nombreStr);
            employee_setSueldo(new, salary);
        }
    }
    return new;
}

Employee* employee_newSetted() // Consultar por salario
{
    Employee* new;
    int id;
    int hoursWorked;
    int salary;
    char name[128];

    new = employee_new();
    if(new != NULL)
    {
        fflush(stdin);
        Input_String_Name(name, 128,"Ingrese el nombre del empleado: ", "Este campo no acepta numeros");
        Input_IntOverValue(&hoursWorked, "Ingrese las horas trabajadas: ", 0, "Las horas trabajadas deben ser mayores a 0");
        Input_IntOverValue(&salary, "Ingrese el salario: ", 0, "El salario debe ser mayor a 0");
        id = employee_increaseLastId();
        employee_setHorasTrabajadas(new, hoursWorked);
        employee_setId(new, id);
        employee_setNombre(new, name);
        employee_setSueldo(new, salary);
    }
    return new;
}

void employee_delete()
{

}

int employee_setId(Employee* this,int id)
{
    int set = -1;

    if(this != NULL)
    {
        this->id = id;
        set = 0;
    }
    return set;
}

int employee_getId(Employee* this,int* id)
{
    int get = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        get = 0;
    }
    return get;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int set = -1;

    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        set = 0;
    }
    return set;
}

int employee_getNombre(Employee* this,char* nombre)
{
    {
    int get = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        get = 0;
    }
    return get;
}

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int set = -1;

    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        set = 0;
    }
    return set;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)

{
    int get = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        get = 0;
    }
    return get;
}


int employee_setSueldo(Employee* this,int sueldo)
{
    int set = -1;

    if(this != NULL)
    {
        this->sueldo = sueldo;
        set = 0;
    }
    return set;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int get = -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        get = 0;
    }
    return get;
}

int employee_printOne(Employee* myEmployee)
{
    int printedEmployee = -1;
    int id;
    char name[128];
    int hoursWorked;
    int salary;

    if(myEmployee != NULL)
    {
        if(!employee_getHorasTrabajadas(myEmployee, &hoursWorked))
        {
            if(!employee_getId(myEmployee, &id))
            {
                if(!employee_getNombre(myEmployee, name))
                {
                    if(!employee_getSueldo(myEmployee, &salary))
                    {
                        printf("\n%d %s %d %d", id, name, hoursWorked, salary);
                        printedEmployee = 0;
                    }
                }
            }
        }
    }
    return printedEmployee;
}

int employee_compareById(void* firstEmployee, void* secondEmployee)
{
    Employee* e1;
    Employee* e2;
    int comparison = -2;
    int id1;
    int id2;

    if(firstEmployee != NULL && secondEmployee != NULL)
    {
        e1 = (Employee*)firstEmployee;
        e2 = (Employee*)secondEmployee;

        if(!employee_getId(e1, &id1))
        {
            if(!employee_getId(e2, &id2))
            {
                if(id1 < id2)
                {
                    comparison = -1;
                }
                else
                {
                    comparison = 0;
                    if(id1 > id2)
                    {
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int employee_compareByName(void* firstEmployee, void* secondEmployee)
{
    Employee* e1;
    Employee* e2;
    int comparison = -2;
    char name1[128];
    char name2[128];

    if(firstEmployee != NULL && secondEmployee != NULL)
    {
        e1 = (Employee*)firstEmployee;
        e2 = (Employee*)secondEmployee;

        if(!employee_getNombre(e1, name1))
        {
            if(!employee_getNombre(e2, name2))
            {
                comparison = strcmp(name1, name2);
                if(comparison < -1)
                {
                    comparison = -1;
                }
                else
                {
                    if(comparison>1)
                    {
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int employee_compareByHoursWorked(void* firstEmployee, void* secondEmployee)
{
    Employee* e1;
    Employee* e2;
    int comparison = -2;
    int hours1;
    int hours2;

    if(firstEmployee != NULL && secondEmployee != NULL)
    {
        e1 = (Employee*)firstEmployee;
        e2 = (Employee*)secondEmployee;

        if(!employee_getHorasTrabajadas(e1, &hours1))
        {
            if(!employee_getHorasTrabajadas(e2, &hours2))
            {
                if(hours1 < hours2)
                {
                    comparison = -1;
                }
                else
                {
                    comparison = 0;
                    if(hours1 > hours2)
                    {
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int employee_compareBySalary(void* firstEmployee, void* secondEmployee)
{
    Employee* e1;
    Employee* e2;
    int comparison = 2;
    int salary1;
    int salary2;

    if(firstEmployee != NULL && secondEmployee != NULL)
    {
        e1 = (Employee*)firstEmployee;
        e2 = (Employee*)secondEmployee;

        if(!employee_getSueldo(e1, &salary1))
        {
            if(!employee_getSueldo(e2, &salary2))
            {
                if(salary1 < salary2)
                {
                    comparison = -1;
                }
                else
                {
                    comparison = 0;
                    if(salary1 > salary2)
                    {
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}
