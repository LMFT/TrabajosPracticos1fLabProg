#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructuras.h"
#include "EntradaVerificacion.h"
#include "Funcionalidades.h"
#define O 4 // Cantidad de datos que se pueden  modificar de un empleado, funcion ModifyEmployeeOperations linea 504
#define TAM 5

Employee InputStruct() // Ingresar datos a una estructura
{
    Employee nuevoEmpleado;

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", nuevoEmpleado.nombre);
    printf("Ingrese apellido: ");
    fflush(stdin);
    scanf("%[^\n]", nuevoEmpleado.apellido);
    printf("Ingrese sector: ");
    nuevoEmpleado.sector = pedirNumeroEntero();
    printf("Ingrese sueldo: ");
    nuevoEmpleado.sueldo = pedirNumeroFlotante();
    nuevoEmpleado.estado = 1;

    return nuevoEmpleado;
}

int MemoryFull_Menu() // Menu de Memoria llena
{

    float opcion;
    int comparacion;

    printf("\nLa memoria del porgrama se encuentra llena. Elija una opcion:");
    printf("\n1- Vaciar memoria");
    printf("\n2- Abortar");
    printf("\nElija una opcion: ");
    opcion = pedirNumeroFlotante();
    comparacion = opcion;
    if(comparacion != opcion)
    {
        return -1;
    }

    return opcion;
}


Employee* InitializeStructArray(Employee empleados[], int cant) // Inicializar un array de estructuras
{
    int i;
    int j;

    for(i = 0; i<cant; i++)
    {
        empleados[i].sector = 0;
        empleados[i].sueldo = 0;

        for(j=0; j<51; j++)
        {
            empleados[i].nombre[j] = ' ';
            empleados[i].apellido[j] = ' ';
        }

        empleados[i].estado = 0; //Vacio o lleno
    }
    return empleados;
}

void MemoryFull (Employee estructura[], int cant) // Funcionalidad de memoria llena
{
    int opcion = MemoryFull_Menu(); // Menu principal
    do
    {
        if(opcion == 1 && Confirmation()) // Opcion de vaciar memorua
        {

                InitializeStructArray(estructura, cant);
        }
        else
        {
            if(opcion==2)
            {
                break;
            }
            printf("\nLa opcion ingresada no es valida");
        }
    }while(opcion != 2 || opcion != 1);
}

void ArrangeStructByTwoFactors(Employee employeeList[], int listSize)
{
    int i;
    int j;
    Employee aux;


    for(i=0; i<listSize-1; i++)//NARANJA
    {
        for(j=i+1; j<listSize; j++)//AZUL
        {
            if((strcmp(employeeList[i].apellido, employeeList[j].apellido) > 0 && employeeList[j].estado != 0))//criterio de ordenamiento
            {
                aux.id = employeeList[i].sector;
                employeeList[i].sector = employeeList[j].sector;
                employeeList[j].sector = aux.sector;

                aux.sueldo = employeeList[i].sueldo;
                employeeList[i].sueldo = employeeList[j].sueldo;
                employeeList[j].sueldo = aux.sueldo;

                strcpy(aux.nombre, employeeList[i].nombre);
                strcpy(employeeList[i].nombre, employeeList[j].nombre);
                strcpy(employeeList[j].nombre, aux.nombre);

                strcpy(aux.apellido, employeeList[i].apellido);
                strcpy(employeeList[i].apellido, employeeList[j].apellido);
                strcpy(employeeList[j].apellido, aux.apellido);
            }
            else
            {
                if(strcmp(employeeList[i].apellido, employeeList[j].apellido) == 0 && employeeList[i].sector > employeeList[j].sector)
                {
                    aux.id = employeeList[i].sector;
                    employeeList[i].sector = employeeList[j].sector;
                    employeeList[j].sector = aux.sector;

                    aux.sueldo = employeeList[i].sueldo;
                    employeeList[i].sueldo = employeeList[j].sueldo;
                    employeeList[j].sueldo = aux.sueldo;

                    strcpy(aux.nombre, employeeList[i].nombre);
                    strcpy(employeeList[i].nombre, employeeList[j].nombre);
                    strcpy(employeeList[j].nombre, aux.nombre);

                    strcpy(aux.apellido, employeeList[i].apellido);
                    strcpy(employeeList[i].apellido, employeeList[j].apellido);
                    strcpy(employeeList[j].apellido, aux.apellido);
                }
            }
        }
    }
}

void ShowEmployees(Employee employeeList[], int listSize)
{
    int option;
    int inputs;

    inputs = SearchEmptyPosition(employeeList, listSize); // Retorna 0 si no hay valores almacenados en el array

    if(inputs == 0) // Si no hay ingresos no permite mostrar el listado
    {
        printf("\nDebe ingresar empleados antes de poder mostrar el listado");
    }
    else
    {
    option = ShowEmployeesMenu();
    ShowEmployeesOperations(employeeList, listSize, option);
    }
}

int ShowEmployeesMenu()
{
    int opcion;
    printf("Que informacion desea ver?");
    printf("\n1- Lista de empleados por Apellido y Sector\n");
    printf("2- Promedio de sueldos y empleados por encima del mismo\n");
    printf("3- Cancelar\n");
    printf("\nIngrese una opcion: ");

    opcion = pedirNumeroEntero();
    fflush(stdin);
    return opcion;
}

void ShowOneStruct(Employee employee)
{
    if(employee.estado != 0)
    {
        printf("\n %5d %12s  %12s  %6.2f  %2d",employee.id, employee.nombre, employee.apellido, employee.sueldo, employee.sector );
    }
}

void ShowEmployeesOperations(Employee employeeList[], int listSize, int option)
{
    int average;

    printf("%6s %12s %10s %10s %8s", "ID", "Nombre", "Apellido", "Sueldo", "Sector");
    switch(option)
    {
        case 1: //Apellido y sector
            ArrangeStructByTwoFactors(employeeList, listSize);
            ShowStructArray(employeeList, listSize);
            break;
        case 2: // Promedio de sueldos y mostrar empleados por encima del promedio
            average = GetAverage(employeeList, listSize);
            ShowOverParameter(employeeList, listSize, average);

    }
}

Employee EnterEmployee (int counter)
{
    Employee aux; // Para guardar el resultado de la carga hasta que el usuario confirme

    aux = InputStruct();
    counter++;
    aux.id = counter;
    if(!Confirmation()) //Retorna 1 si el usuario confirma el ingreso
    {
        aux = InitializeStruct(aux);
    }
    return aux;
}

Employee InitializeStruct(Employee employeeParameter)
{
    strcpy(employeeParameter.nombre, "");
    strcpy(employeeParameter.apellido, "");
    employeeParameter.sector = 0;
    employeeParameter.sueldo = 0;
    employeeParameter.estado = 0;
    return employeeParameter;
}


int SearchEmptyPosition(Employee employeeList[], int listSize)
{
    int i;
    int position;

    position = -1; // Si no se encuentra una posicion libre en el array devuelve -1

    for(i=0;i<listSize;i++)
    {
        if(employeeList[i].estado == 0)
        {
            position = i;
            break;
        }
    }
    return position;
}

int NewEmployee (Employee employeeList[], int listSize, int counter)
{
    int position;

    position = SearchEmptyPosition(employeeList, listSize); // Almaceno el valor de la posicion vacia para verificar condiciones
                                                            // Devuelve -1 si no hay posiciones vacias
    if(position >= 0)
    {
        employeeList[position] = EnterEmployee(counter); // Cargo y confirmo ingreso de empleado
        if(employeeList[position].estado == 1) // Si el usuario confirmo el ingreso modifico el contador
        {
            counter++;
        }
    }
    else
    {
        MemoryFull(employeeList, listSize);
    }
    return counter;

}

void ModifyEmployee(Employee employeeList[], int listSize)
{
    int id;
    int opcion;
    int i;
    int flag;
    Employee aux;

    i=0;
    flag = SearchEmptyPosition(employeeList, listSize); // Si retorna 0 no hay empleados cargados en lista

    if(flag != 0)
    {
        //Tomar ID
        printf("\nIngrese el ID de empleado: ");
        id=pedirNumeroEntero();
        //Buscar Empleado
        aux=SearchById(employeeList,listSize, id);
        if(aux.estado)
        {
            printf("\n\n%6s %12s %10s %10s %8s", "ID", "Nombre", "Apellido", "Sueldo", "Sector");
            ShowOneStruct(aux);
            //Preguntar que modificar
            opcion = ModifyEmployeeMenu();
            //Ejecutar
            aux = ModifyEmployeeOperations(aux, opcion);
            //Confirmar
            if(Confirmation())
            {
                for(i=0;i<listSize;i++)
                {
                    if(employeeList[i].id == id)
                    {
                        employeeList[i] = aux;
                    }
                }
            }
        }
        else
        {
            printf("\nError: El ID ingresado no existe");
        }


    }
    else
    {
        printf("\nDebe ingresar empleados antes de poder modificar el listado");
    }
}

Employee SearchById(Employee employeeList[],int listSize, int id)
{
    int i;
    Employee aux;

    aux = InitializeStruct(aux);

    for(i=0; i<listSize; i++)
    {
        if(id == employeeList[i].id)
        {
            aux = employeeList[i];
        }
    }

    return aux;
}

int ModifyEmployeeMenu()
{
    int opcion;
    printf("\n\nQue desea modificar del empleado?\n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Sueldo\n");
    printf("4- Sector\n\n");
    printf("5- Multiples opciones\n");
    printf("6- Cancelar\n");
    printf("Ingrese una opcion: ");

    opcion = pedirNumeroEntero();
    fflush(stdin);
    return opcion;
}

Employee ModifyEmployeeOperations(Employee employeeParameter, int option)
{
    int aux[O]; // Para almacenar multiples operaciones
    int operationCounter;
    int i;

    i=0;
    operationCounter = 0;
    InitializeArrayInt(aux, O);

    do
    {


        switch(option)
        {
            case 1:
                printf("\nIngrese nombre: ");
                fflush(stdin);
                InputString(employeeParameter.nombre, LEN);
                break;
            case 2:
                printf("\nIngrese apellido: ");
                fflush(stdin);
                InputString(employeeParameter.apellido, LEN);
                break;
            case 3:
                printf("\nIngrese sueldo: ");
                employeeParameter.sueldo = pedirNumeroFlotante();
                break;
            case 4:
                printf("\nIngrese sector: ");
                employeeParameter.sector = pedirNumeroEntero();
                break;
            case 5:
                    printf("\nIngrese las operaciones que desea resolver:");
                do
                {
                    option = pedirNumeroEntero();
                    fflush(stdin);
                    if(AlreadyInputed(aux, O, option))
                    {
                        printf("\n Esa opcion ya ha sido ingresada");
                        continue;
                    }
                    else
                    {
                        aux[i] = option;
                        i++;
                    }
                }while((AnotherInput() == 's' || AnotherInput() == 'S') && operationCounter == 0 );
                break;
            case 6:
                break;
            default:
                printf("\nLa opcion ingresada no es valida");
        }
        option = aux[operationCounter];
        operationCounter++;
    }while(aux[operationCounter -1 != 0]);


    return employeeParameter;
}


int AlreadyInputed(int arrayParameter[], int arraySize, int number)
{
    int i;
    int foundValue;

    foundValue = 0;

    for(i=0;i<arraySize; i++)
    {
        if(number == arrayParameter[i])
        {
            foundValue = 1;
        }
    }
    return foundValue;
}

void RemoveEmployee(Employee employeeList[], int listSize)
{
    int id;
    int i;
    int inputs;

    inputs = SearchEmptyPosition(employeeList, listSize); // Retorna 0 si no hay datos cargados en el array

    i=0;
    if(inputs != 0)
    {
        printf("\nIngrese el ID de empleado: ");
        id=pedirNumeroEntero();

        for(i=0;i<listSize;i++)
        {
            if(employeeList[i].id == id)
            {
                employeeList[i]=InitializeStruct(employeeList[i]);
            }
        }
    }
    else
    {
        printf("\nError: No se ingresaron empleados, no puede eliminarse ningun registro");
    }
}

float GetAverage(Employee employeeList[], int listSize)
{
    int i;
    float sum;
    float average;

    sum = 0;

    for(i=0;i<listSize;i++)
    {
        if(employeeList[i].estado)
        {
        sum += employeeList[i].sueldo;
        }
    }

    average = sum / i;

    return average;
}


void ShowOverParameter(Employee employeeList[], int listSize, float parameter)
{
    int i;

    for(i=0;i<listSize;i++)
    {
        if(employeeList[i].sueldo > parameter)
        {
            ShowOneStruct(employeeList[i]);
        }
    }
}

void ShowStructArray(Employee employeeList[], int listSize)
{
    int i;

    for(i=0;i<listSize;i++)
    {
        ShowOneStruct(employeeList[i]);
    }
}

void MainMenu()
{
    //Estructuras
    Employee listaEmpleados[TAM];

    //Variables
    int opcion;
    int contadorCargas;


                            //Permite almacenar la estructura del menu y del switch en funciones
    contadorCargas = 0;

    InitializeStructArray(listaEmpleados, TAM); // Inicializo la estructura de empleados

    do
    {
        opcion = menu(); // Menu Principal


        switch(opcion)
        {
            case 1: //Cargar Datos
                contadorCargas=NewEmployee(listaEmpleados, TAM, contadorCargas);
                break;
            case 2: // Modificar
                ModifyEmployee(listaEmpleados, TAM);
                break;
            case 3: // Bajas
                // Funcion Borrar empleado
                RemoveEmployee(listaEmpleados, TAM);
                break;
             case 4: // Mostrar Datos
                ShowEmployees(listaEmpleados, TAM);
                break;
             case 5: // Salir
                break;
             default: // Opcion erronea
                printf("\nLa opcion ingresada no es valida");
                break;
        }
    }while(opcion!=5); // Opcion de salida del programa
}
