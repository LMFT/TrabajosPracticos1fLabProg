#include "Controller.h"

#define EXIT 5
#define HEADER "id,nombre,horasTrabajadas,sueldo"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int gotData = ll_isEmpty(pArrayListEmployee);
    FILE* pFile;

    if(gotData != -1 && path != NULL)
    {
        if(!gotData)
        {
            printf("\nYa existen elementos cargados en la lista. Si continua, se perder%cn los datos no guardados", 160);
            if(Input_Confirmation("\nDesea continuar? s/n: ", "Esta opcion no es valida", 's', 'n'))
            {
                ll_clear(pArrayListEmployee);
                gotData = 1;
            }
        }
        if(gotData == 1)
        {

            pFile = fopen(path,"r");
            if(pFile != NULL)
            {
                gotData = parser_EmployeeFromText(pFile, pArrayListEmployee);
                printf("\nDatos cargados exitosamente");
                fclose(pFile);
            }
        }

    }
    return gotData;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int gotData = -1;
    FILE* pFile;
    int tempInt = ll_isEmpty(pArrayListEmployee);

    if(path != NULL && tempInt != -1)
    {
        if(!tempInt)
        {
            printf("\nYa existen elementos cargados en la lista. Si continua, se perder%cn los datos no guardados", 160);
            if(Input_Confirmation("\nDesea continuar? s/n: ", "Esta opcion no es valida", 's', 'n'))
            {
                ll_clear(pArrayListEmployee);
                tempInt = 1;
            }
        }
        if(tempInt == 1)
        {
            pFile = fopen(path, "rb");
            if(pFile != NULL)
            {
                gotData = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
                printf("\nDatos cargados exitosamente");
            }
        }
        fclose(pFile);
    }
    return gotData;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int addedEmployee = -3;
    int employeeId;
    Employee* new;

    if(ll_isEmpty(pArrayListEmployee) >=0)
    {
        new = employee_newSet();
        if(new != NULL)
        {
            employeeId = employee_increaseLastId();
            employee_setId(new, employeeId);
            employee_printOne(new);
            if(Input_Confirmation("\nDesea confirmar este ingreso? s/n: ", "\nOpcion invalida", 's', 'n', 162, 160))
            {
                ll_add(pArrayListEmployee, new);
                addedEmployee = 0;
                printf("\nNuevo empleado cargado exitosamente");
            }
            else
            {
                printf("\nSe ha cancelado el ingreso de este empleado");
                free(new);
                employee_decreaseLastId();
                addedEmployee = -1;
            }
        }
        else
        {
            printf("\nSe produjo un error al añadir un empleado");
            addedEmployee = -2;
        }

    }
    return addedEmployee;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int index = -4;
    int targetId;
    Employee* target;
    Employee* modifiedEmployee;

    if(!ll_isEmpty(pArrayListEmployee))
    {
        controller_ListEmployee(pArrayListEmployee);
        Input_Int(&targetId, "\nIngrese el ID del empleado que desea editar: ");
        index = controller_searchEmployeeById(pArrayListEmployee, targetId);
        if(index>=0)
        {
            modifiedEmployee = employee_newSet();
            if(modifiedEmployee != NULL)
            {
                employee_setId(modifiedEmployee, targetId);
                printf("\nEmpleado original: ");
                target = ll_get(pArrayListEmployee, index);
                employee_printOne(target);
                printf("\nEmpleado modificado: ");
                employee_printOne(modifiedEmployee);
                if(Input_Confirmation("\nDesea confirmar este ingreso? s/n: ", "\nOpcion invalida", 's', 'n', 162, 160))
                {

                    ll_set(pArrayListEmployee, index, modifiedEmployee);
                    employee_delete(target);
                    printf("\nEmpleado modificado exitosamente");
                }
                else
                {
                    printf("\nSe ha cancelado la modificacion de este empleado");
                    free(modifiedEmployee);
                    index = -2;
                }
            }
            else
            {
                printf("\nHa ocurrido un error durante la modificacion");
                index = -3;
            }
        }
    }
    else
    {
        printf("\nError: El listado est%c vac%co o no existe.", 160, 161);
        printf("Cargue datos desde un archivo o d%c de alta un empleado para acceder a esta opci%cn", 130, 162);
    }
    return index;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int removedEmployee;
    int index;
    int targetId;
    Employee* target;
    if(!ll_isEmpty(pArrayListEmployee))
    {
        removedEmployee = -2;
        controller_ListEmployee(pArrayListEmployee);
        Input_Int(&targetId, "\nIngrese el ID del empleado que desea eliminar: ");
        index = controller_searchEmployeeById(pArrayListEmployee, targetId);
        if(index>=0)
        {
            target = ll_get(pArrayListEmployee, index);
            employee_printOne(target);
            if(Input_Confirmation("\nDesea eliminar este empleado? s/n: ", "Opcion invalida", 's', 'n'))
            {
                employee_delete(target);
                ll_remove(pArrayListEmployee, index);
                removedEmployee = 0;
                printf("\nEmpleado dado de baja exitosamente");
            }
            else
            {
                printf("\nSe ha cancelado la baja de este empleado");
                removedEmployee = -1;
            }
        }
    }
    else
    {
        printf("\nError: El listado est%c vac%co o no existe.", 160, 161);
        printf("Cargue datos desde un archivo o d%c de alta un empleado para acceder a esta opci%cn", 130, 162);
        removedEmployee = -3;
    }

    return removedEmployee;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i = -1;
    Employee* current;

    if(!ll_isEmpty(pArrayListEmployee))
    {
        if(!ll_isEmpty(pArrayListEmployee))
        {
            printf("\n%3s %10s %20s %7s\n", "ID", "Nombre", "Horas Trabajadas", "Salario");
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                current = ll_get(pArrayListEmployee, i);
                employee_printOne(current);
            }
        }
        else
        {
            printf("\nError: El listado est%c vac%co o no existe.", 160, 161);
            printf("Cargue datos desde un archivo o d%c de alta un empleado para acceder a esta opci%cn", 130, 162);
            i = 0;
        }
    }
    return i;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int option;
    int order;

    if(!ll_isEmpty(pArrayListEmployee))
    {
            option = Ui_CreateMenu("Elija un criterio de ordenamiento: ", "\nIngrese una opcion: ", 5,    "Por ID",
                                                                                                        "Por Nombre",
                                                                                                        "Por horas trabajadas",
                                                                                                        "Por salario",
                                                                                                        "Salir");

            order = Ui_CreateMenu("Desea ordenar de forma ascendente o descendente", "\nIngrese una opcion: ", 2,
                                                                                                    "Descendente",
                                                                                                    "Ascendente");
            order--;
            printf("\nOrenando el listado. Esto puede demorar unos instantes...");
            switch(option)
            {
                case 1:
                    ll_sort(pArrayListEmployee, employee_compareById, order);
                    break;
                case 2:
                    ll_sort(pArrayListEmployee, employee_compareByName, order);
                    break;
                case 3:
                    ll_sort(pArrayListEmployee, employee_compareByHoursWorked, order);
                    break;
                case 4:
                    ll_sort(pArrayListEmployee, employee_compareBySalary, order);
                    break;
                case EXIT:
                    break;
            }
            if(option != 5)
            {
                printf("\nListado ordenado exitosamente");
            }
    }
    else
    {
        printf("\nError: El listado est%c vac%co o no existe.", 160, 161);
        printf("Cargue datos desde un archivo o d%c de alta un empleado para acceder a esta opci%cn", 130, 162);
        option = -1;
    }
    return option;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int savedData = ll_isEmpty(pArrayListEmployee);
    Employee* current;
    int id;
    int hoursWorked;
    int salary;
    char name[128];
    FILE* pFile;

    if(path != NULL && savedData != -1)
    {
        savedData = 0;
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            fprintf(pFile, "%s\n", HEADER);
            for(int i=0;i<ll_len(pArrayListEmployee);i++)
            {
                current = ll_get(pArrayListEmployee, i);
                if(!employee_getHorasTrabajadas(current, &hoursWorked))
                {
                    if(!employee_getId(current, &id))
                    {
                        if(!employee_getNombre(current, name))
                        {
                            if(!employee_getSueldo(current, &salary))
                            {
                                fprintf(pFile, "%d,%s,%d,%d\n", id, name, hoursWorked, salary);
                                savedData++;
                            }
                        }
                    }
                }
            }
            printf("\nListado guardado exitosamente. %d elementos registrados", savedData);
        }
    }
    return savedData;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int savedData = ll_isEmpty(pArrayListEmployee);
    Employee* current;
    FILE* pFile;

    if(path != NULL && savedData != -1)
    {
        savedData = 0;
        pFile = fopen(path, "wb");
        if(pFile != NULL)
        {
            //fprintf(pFile, "%s\n", HEADER);
            for(int i=0;i<ll_len(pArrayListEmployee);i++)
            {
                current = ll_get(pArrayListEmployee, i);
                fwrite(current, sizeof(Employee), 1, pFile);
                savedData++;
            }
            printf("\nListado guardado exitosamente. %d elementos registrados", savedData);
        }
    }
    return savedData;
}

int controller_searchEmployeeById(LinkedList* pArrayListEmployee, int targetId)
{
    int index = -2;
    int currentId;
    Employee* target;
    if(!ll_isEmpty(pArrayListEmployee))
    {
        for(index=0;index<ll_len(pArrayListEmployee);index++)
        {
            target = ll_get(pArrayListEmployee, index);
            if(!employee_getId(target, &currentId))
            {
                if(currentId == targetId)
                {
                    break;
                }
            }
        }
        if(index == ll_len(pArrayListEmployee))
        {
            index = -1;
        }
    }
    return index;
}

int controller_saveLastId(char* path)
{
    int id = -1;
    FILE* pFile;

    if(path != NULL)
    {
        pFile = fopen(path, "wb");
        if(pFile != NULL)
        {
            id = employee_getLastId();
            fwrite(&id, sizeof(int), 1, pFile);
            fclose(pFile);
        }
    }
    return id;
}

int controller_loadLastId(char* path)
{
    int id = -1;
    FILE* pFile;

    if(path != NULL)
    {
        pFile = fopen(path, "rb");
        if(pFile != NULL)
        {
            fread(&id, sizeof(int), 1, pFile);
            employee_setLastId(id);
            fclose(pFile);
        }
    }
    return id;
}
