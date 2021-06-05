
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
    LinkedList* employeeList = ll_newLinkedList();
    int option;
    bool loadedData = false;
    bool savedModifications = true;

    do
    {
        option = Ui_CreateMenu("Menu principal", "\nIngrese una opcion: ", 10, "Cargar datos de empleados desde archivo de texto",
                                                                                "Cargar datos de empleados desde archivo binario",
                                                                                 "Alta de empleado",
                                                                                 "Editar empleado",
                                                                                 "Baja de empleado",
                                                                                 "Listar empleados",
                                                                                 "Ordenar empleados",
                                                                                 "Guardar empleados en archivo de texto",
                                                                                 "Guardar empleados en archivo binario",
                                                                                 "Salir");

        switch(option)
        {
            case 1: // cargar texto
                if((loadedData == true&&
                   Input_Confirmation("\nYa hay elementos cargados en la lista. Si procede, cualquier modificacion no guardada se perder%c. Desea continuar? s/n: ",
                                      "Esta respuesta no es valida", 's', 'n', 160)) || loadedData == false)
                {
                    ll_clear(employeeList);
                    controller_loadFromText("data_prueba.csv", employeeList);
                    controller_loadLastId("last_id2.bin");
                    printf("\n%d", employee_getLastId());
                    loadedData = true;
                }
                break;
            case 2: // cargar binario
                if((loadedData == true&&
                   Input_Confirmation("\nYa hay elementos cargados en la lista. Si procede, cualquier modificacion no guardada se perder%c. Desea continuar? s/n: ",
                                      "Esta respuesta no es valida", 's', 'n', 160)) || loadedData == false)
                {
                    ll_clear(employeeList);
                    controller_loadFromBinary("data_prueba.bin", employeeList);
                    controller_loadLastId("last_id2.bin");
                    printf("\n%d", employee_getLastId());
                    loadedData = true;
                }
                break;
            case 3: // a
                controller_addEmployee(employeeList);
                savedModifications = false;
                break;
            case 4: // m
                controller_editEmployee(employeeList);
                savedModifications = false;
                break;
            case 5: // b
                controller_removeEmployee(employeeList);
                savedModifications = false;
                break;
            case 6: // mostrar
                controller_ListEmployee(employeeList);
                break;
            case 7: // ordenar
                controller_sortEmployee(employeeList);
                savedModifications = false;
                break;
            case 8: // guardar texto
                controller_saveAsText("data_prueba.csv", employeeList);
                controller_saveLastId("last_id.bin");
                savedModifications = true;
                break;
            case 9: // guardar binario
                controller_saveAsBinary("data_prueba.bin", employeeList);
                controller_saveLastId("last_id2.bin");
                savedModifications = true;
                break;
            case 10: // salir
                if(savedModifications == true)
                {
                    ll_deleteLinkedList(employeeList);
                }
                else
                {
                    if(Input_Confirmation("\nTiene elementos sin guardar. Esta seguro que desea salir? s/n: ",
                                      "Esta respuesta no es valida", 's', 'n', 160))
                    {
                             ll_deleteLinkedList(employeeList);
                    }
                    else
                    {
                        option = 0;
                    }
                }
            break;
            default:
                printf("\nOpci%cn inv%clida", 162, 160);
        }
        printf("\n");
        system("pause");
        system("cls");
    }while(option != 10);

    return 0;
}

