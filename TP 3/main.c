#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* employeeList;
    int lastId;
    int option;
    int dataLoaded;


    dataLoaded = 0;
    lastId = 0;
    employeeList = ll_newLinkedList();

    do
    {
        printf("\nLast ID: %d", lastId);
        option = controller_MainMenu();

        if((option == 1 || option == 2) && dataLoaded == 0)
        {
            employeeList = ll_newLinkedList();
        }
        dataLoaded =  controller_MainMenu_Operations(option, employeeList, dataLoaded, &lastId);
        if((option == 8 || option == 9) && dataLoaded == 1)
        {
            ll_deleteLinkedList(employeeList);
        }

        if(option != 10)
        {
            system("pause");
            system("cls");
        }

    }while(option != 10);

    return 0;
}

/*Errores detectados:

1- El archivos .txt se guarda mal
2- Archivo .bin lee basura
3- Sorts en bucle infinito

*/
