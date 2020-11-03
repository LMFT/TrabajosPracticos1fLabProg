#include "Controller.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;

    int retorno;
    retorno = 0;

    pFile = fopen(path, "r");
    if(pFile != NULL && path != NULL && pArrayListEmployee != NULL)
    {
        parser_EmployeeFromText(pFile, pArrayListEmployee);
        retorno = 1;
    }
    fclose(pFile);
    ll_remove(pArrayListEmployee, 0);

    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno;
    retorno = 0;

    pFile = fopen(path, "rb");
    if(pFile != NULL)
    {

        while(!feof(pFile))
        {
            if(pFile != NULL && path != NULL && pArrayListEmployee != NULL)
            {
                parser_EmployeeFromBinary(pFile, pArrayListEmployee);
                retorno= 1;
            }
        }
    }

    fclose(pFile);
    ll_remove(pArrayListEmployee, 0);

    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee, int* lastId)
{
    Employee* newEmployee;
    int addedEmployee;
    char id[10];
    char name[128];
    char hoursWorked[10];
    char salary[10];
    int hoursWorkedInt;
    float salaryFloat;

    addedEmployee = 0;

    if(pArrayListEmployee != NULL && lastId != NULL)
    {
        *lastId = controller_GetLastId(pArrayListEmployee, *lastId);
        ev_InputString_Name(name, sizeof(name), "\nIngrese el nombre del empleado: ",
                             "\nEl nombre no puede contener numeros. Reingrese el nombre: ");
        ev_InputIntOverParameter("\nIngrese las horas trabajadas: ",
                                 "\nLas horas trabajadas deben ser mayores a 0. Reingrese las horas: ",
                                 &hoursWorkedInt, 0);
        ev_InputFloatOverParameter("\nIngrese el sueldo: ",
                                 "\nEl sueldo debe ser mayor a 0. Reingrese el sueldo: ",&salaryFloat, 0);
        snprintf(id, 10, "%d", *lastId);
        snprintf(hoursWorked, 10, "%d", hoursWorkedInt);
        snprintf(salary, 10, "%f", salaryFloat);

        if(gu_Confirmation() == 1)
        {
            newEmployee = employee_newParametros(id, name, hoursWorked, salary);
            addedEmployee = ll_add(pArrayListEmployee, newEmployee);
        }
    }
    else
    {
        addedEmployee = -1;
    }

    return addedEmployee;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int index;
    int retorno; // return variable
    int option;
    Employee* anEmployee;

    retorno = 0;

    if(pArrayListEmployee != NULL)
    {
        ev_InputIntOverParameter("\nIngrese el ID del empleado: ", "\nEl ID debe ser mayor a 0. Reingrese el ID: ",&id, 0);
        anEmployee = controller_SearchByID(pArrayListEmployee, id);
        if(anEmployee != NULL)
        {
            index = ll_indexOf(pArrayListEmployee, anEmployee);
            if(anEmployee != NULL)
            {
                option = controller_editEmployee_Menu();
                controller_editEmployee_Operations(pArrayListEmployee, anEmployee, option, index);
                retorno = 1;
            }
            else
            {
                printf("\nEmpleado Nulo\n");
            }
        }
        else
        {
            printf("\nNo se encuentra el ID ingresado\n");
        }
    }
    else
    {
        printf("\nlistado nulo\n");
    }
    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int retorno;
    int index;
    Employee* anEmployee;

    retorno = 0;
    if(pArrayListEmployee != NULL)
    {
        ev_InputIntOverParameter("\nIngrese el ID del empleado: ", "\nEl ID debe ser mayor a 0. Reingrese el ID: ",&id, 0);
        anEmployee = controller_SearchByID(pArrayListEmployee, id);
        if(anEmployee != NULL)
        {
            index = ll_indexOf(pArrayListEmployee, anEmployee);

            if(gu_Confirmation())
            {
                ll_remove(pArrayListEmployee, index);
                retorno = 1;
            }
        }
        else
        {
            printf("\nNo se encuentra el ID ingresado\n");
        }
    }
    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int len;
    Employee* aux;
    int id;
    char name[128];
    int hoursWorked;
    float salary;

    printf("\n%4s %13s %19s %19s", "ID", "Nombre", "Horas Trabajadas", "Sueldo");
    len=ll_len(pArrayListEmployee);

    for(i=0;i<len;i++)
    {
        aux = ll_get(pArrayListEmployee, i);
        employee_getId(aux, &id);
        employee_getNombre(aux, name);
        employee_getHorasTrabajadas(aux, &hoursWorked);
        employee_getSueldo(aux, &salary);
        printf("\n%4d %12s %14d %19c%.2f", id, name, hoursWorked, 36,salary);
    }
    printf("\n");
    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int option;
    int retorno; // return variable

    option = controller_sortEmployee_Menu();
    retorno = controller_sortEmployee_Operations(option, pArrayListEmployee);

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* anEmployee;
    int i;
    char id[10];
    char name[128];
    char hoursWorked[10];
    char salary[20];
    int retorno; // return variable

    retorno = 0;
    pFile = fopen(path,"w");

    if(pArrayListEmployee != NULL && pFile != NULL && path != NULL)
    {
        fprintf(pFile,"%s, %s, %s, %s\n", "ID", "Nombre", "Horas Trabajadas", "Sueldo");
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            anEmployee = ll_get(pArrayListEmployee, i);
            controller_ConvertEmployeeDataToString(anEmployee, id, name, hoursWorked, salary);
            printf("%s, %s, %s, %s\n", id, name, hoursWorked, salary);
            fprintf(pFile, "%s, %s, %s, %s\n", id, name, hoursWorked, salary);
        }
        fclose(pFile);
        retorno = 1;
    }
    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* anEmployee;
    int i;
    int cant;
    int retorno; // return variable

    retorno = 0;
    pFile = fopen(path,"wb");

    if(pArrayListEmployee != NULL && pFile != NULL && path != NULL)
    {
        cant = ll_len(pArrayListEmployee);

        fprintf(pFile,"%s, %s, %s, %s", "ID", "Nombre", "Horas Trabajadas", "Sueldo");
        for(i=0;i<cant;i++)
        {
            anEmployee = ll_get(pArrayListEmployee, i);
            fwrite(anEmployee, sizeof(Employee), 1, pFile);
        }

        fclose(pFile);
        retorno = 1;
    }
    return retorno;
}

int controller_GetMax(LinkedList* list, int* max)
{
    Employee* aux;
    int lastId;
    int i;
    int retorno;

    retorno = 0;

    if(list != NULL && max != NULL)
    {
        for(i=0;i<ll_len(list);i++)
        {
            aux = ll_get(list, i);
            employee_getId(aux, &lastId);
        }
        *max = lastId+1;
        retorno = 1;
    }

    return retorno;
}

int controller_GetLastId(LinkedList* this, int id)
{
    int currentMaxId;
    if(this != NULL)
    {
        if(ll_len(this) == 0)
        {
            id = 1;
        }
        else
        {
            controller_GetMax(this, &currentMaxId);

            if(currentMaxId>= id)
            {
                id = currentMaxId;
            }
        }
    }

    return id;
}

Employee* controller_SearchByID (LinkedList* this, int id)
{
    int i;
    int cant;
    int currentId;
    Employee* anEmployee;

    anEmployee = NULL;

    if(this!=NULL)
    {
        cant = ll_len(this);

        for(i=0;i<cant;i++)
        {
            anEmployee = ll_get(this, i);
            employee_getId(anEmployee, &currentId);
            if(currentId == id)
            {
                break;
            }
        }
        if(i == cant && currentId != id)
        {
            anEmployee = NULL;
        }
    }
    return anEmployee;
}

int controller_editEmployee_Menu()
{
    int option;
    printf("\nIngrese el campo que desea modificar");
    printf("\n1-Nombre");
    printf("\n2-Horas trabajadas");
    printf("\n3-Salario");
    printf("\n4-Cancelar");
    ev_InputInt("\nIngrese una opcion: ", &option);
    return option;
}

void controller_editEmployee_Operations(LinkedList* employeeList, Employee* pEmployee, int option, int index)
{
    if(employeeList != NULL && pEmployee != NULL)
    {
        switch(option)
        {
            case 1:
                 employee_AssignNombre(pEmployee);
                break;
            case 2:
                employee_AssignHorasTrabajadas(pEmployee);
                break;
            case 3:
                employee_AssignSueldo(pEmployee);
                break;
            case 4:
                break;
            default:
                printf("\nLa opcion ingresada no es v%clida", 160);
        }
        if(gu_Confirmation())
        {
            ll_set(employeeList, index, pEmployee);
        }
    }
}

int controller_sortEmployee_Menu()
{
    int option;
    printf("\nSeleccione el criterio de ordenamiento: ");
    printf("\n1-Por ID");
    printf("\n2-Por nombre");
    printf("\n3-Por horas trabajadas");
    printf("\n4-Por salario");
    printf("\n5-Cancelar");
    ev_InputInt("\nIngrese una opcion: ", &option);
    fflush(stdin);
    return option;
}

int controller_sortEmployee_Operations(int option, LinkedList* employeeList)
{
    int sortedList;
    sortedList = -1;
    if(employeeList != NULL)
    {
        sortedList = 1;
        switch(option)
        {
            case 1: // ID
                controller_sortEmployee_ById(employeeList);
            case 2:// NOMBRE
                controller_sortEmployee_ByName(employeeList);
            case 3: // Horas
                controller_sortEmployee_ByHours(employeeList);
            case 4:// Sueldo
                controller_sortEmployee_BySalary(employeeList);
            case 5:// Salir
                break;
            default:
                printf("\nLa opci%cn ingresada no es v%clida", 163, 160);
                sortedList = 0;

        }

    }
    return sortedList;
}

int controller_sortEmployee_ById(LinkedList* employeeList)
{
    int retorno; // return variable

    retorno = 0;
    if(employeeList != NULL)
    {
        ll_sort(employeeList, employee_CompareById, 0);
        retorno = 1;
    }
    return retorno;
}

int controller_sortEmployee_ByName(LinkedList* employeeList)
{
    int retorno; // return variable

    retorno = 0;
    if(employeeList != NULL)
    {
        ll_sort(employeeList, employee_CompareByName, 0);
        printf("\nSort terminado");
        retorno = 1;
    }
    return retorno;
}

int controller_sortEmployee_ByHours(LinkedList* employeeList)
{
    int retorno; // return variable

    retorno = 0;
    if(employeeList != NULL)
    {
        ll_sort(employeeList, employee_CompareByHours, 0);
        retorno = 1;
    }
    return retorno;
}

int controller_sortEmployee_BySalary(LinkedList* employeeList)
{
    int retorno; // return variable

    retorno = 0;
    if(employeeList != NULL)
    {
        ll_sort(employeeList, employee_CompareBySalary, 0);
        retorno = 1;
    }
    return retorno;
}

int controller_MainMenu()
{
    int option;

    printf("\n\n *** Menu ***");
    printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    printf("\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
    printf("\n3. Alta de empleado");
    printf("\n4. Modificar datos de empleado");
    printf("\n5. Baja de empleado");
    printf("\n6. Listar empleados");
    printf("\n7. Ordenar empleados");
    printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
    printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).");
    printf("\n10. Salir");
    ev_InputInt("\n\nIngrese una opcion: ", &option);
    fflush(stdin);
    return option;
}

int controller_MainMenu_Operations(int option, LinkedList* employeeList, int dataLoaded, int* lastId)
{
    if(employeeList != NULL)
    {
        if(dataLoaded == 0 && (option<10 && option>2))
        {
            printf("\nDebe cargar datos en la lista antes de realizar esta operaci%cn", 162);
        }
        else
        {
            switch(option)
            {
                case 1:
                    controller_loadFromText_VerifyDataLoaded(dataLoaded, employeeList);
                    dataLoaded = 1;
                    break;
                case 2:
                    controller_loadFromBinary_VerifyDataLoaded(dataLoaded, employeeList);
                    dataLoaded = 1;
                    break;
                case 3:
                     controller_addEmployee(employeeList, lastId);
                    break;
                case 4:
                    controller_ListEmployee(employeeList);
                    controller_editEmployee(employeeList);
                    break;
                case 5:
                    controller_ListEmployee(employeeList);
                    controller_removeEmployee(employeeList);
                    break;
                case 6:
                    controller_ListEmployee(employeeList);
                    break;
                case 7:
                     controller_sortEmployee(employeeList);
                    break;
                case 8:
                    controller_saveAsText("data1.csv", employeeList);
                    dataLoaded = 0;
                    break;
                case 9:
                    controller_saveAsBinary("data1.dat", employeeList);
                    dataLoaded = 0;
                    break;
                case 10:
                    break;
                default:
                    printf("\nLa opcion ingresada no es v%clida", 160);

            }
            *lastId = controller_GetLastId(employeeList, *lastId);
        }
    }
    return dataLoaded;
}

int controller_loadFromText_VerifyDataLoaded(int dataLoaded, LinkedList* employeeList)
{
    int retorno;
    retorno = -1;
    if(employeeList != NULL)
    {
        if(dataLoaded == 0)
        {
            controller_loadFromText("data1.csv", employeeList);
            retorno = 1;
        }
        else
        {
            printf("\nDebe guardar la lista antes de poder volver a cargarla");
        }
    }
    return retorno;
}

int controller_loadFromBinary_VerifyDataLoaded(int dataLoaded, LinkedList* employeeList)
{
    int retorno;
    retorno = -1;
    if(employeeList != NULL)
    {
        if(dataLoaded == 0)
        {
            controller_loadFromBinary("data1.dat", employeeList);
            retorno = 1;
        }
        else
        {
            printf("\nDebe guardar la lista antes de poder volver a cargarla");
        }

    }
    return retorno;
}

int controller_ConvertEmployeeDataToString(Employee* anEmployee, char id[], char name[], char hours[], char salary[])
{
    int idInt;
    int hoursInt;
    float salaryFloat;
    int conversion;
    conversion = 0;
    if(anEmployee != NULL && id != NULL && name != NULL && hours != NULL && salary != NULL)
    {
        employee_getId(anEmployee, &idInt);
        itoa(idInt, id, 10);
        employee_getNombre(anEmployee, name);
        employee_getHorasTrabajadas(anEmployee, &hoursInt);
        itoa(hoursInt, hours, 10);
        employee_getSueldo(anEmployee, &salaryFloat);
        gcvt(salaryFloat, 20, salary);
        conversion = 1;
    }
    return conversion;
}
