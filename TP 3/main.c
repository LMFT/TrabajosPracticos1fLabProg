#include "Controller.h"

int main()
{
    LinkedList* pArrayListEmployee = ll_newLinkedList();
    int option;
    int returnAux;
    bool dataLoaded = false;

    do
    {
        printf("\n\nLast ID: %d\n\n", employee_getLastId());
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
                returnAux = controller_loadFromText("data_prueba.csv", pArrayListEmployee);
                if(returnAux >= 0)
                {
                    controller_loadLastId("last_id2.bin");
                    dataLoaded = true;
                }
                break;
            case 2: // cargar binario
                controller_loadFromBinary("data_prueba.bin", pArrayListEmployee);
                if(returnAux >= 0)
                {
                    controller_loadLastId("last_id2.bin");
                    dataLoaded = true;
                }
                break;
            case 3: // a
                if(dataLoaded)
                {
                    controller_addEmployee(pArrayListEmployee);
                }
                break;
            case 4: // m
                if(dataLoaded)
                {
                    controller_editEmployee(pArrayListEmployee);
                }
                break;
            case 5: // b
                if(dataLoaded)
                {
                    controller_removeEmployee(pArrayListEmployee);
                }
                break;
            case 6: // mostrar
                if(dataLoaded)
                {
                    controller_ListEmployee(pArrayListEmployee);
                }
                break;
            case 7: // ordenar
                if(dataLoaded)
                {
                    controller_sortEmployee(pArrayListEmployee);
                }
                break;
            case 8: // guardar texto
                if(dataLoaded)
                {
                    controller_saveAsText("data_prueba.csv", pArrayListEmployee);
                    controller_saveLastId("last_id2.bin");
                }
                break;
            case 9: // guardar binario
                controller_saveAsBinary("data_prueba.bin", pArrayListEmployee);
                controller_saveLastId("last_id2.bin");
                break;
            case 10: // salir
                option--;
                if(Input_Confirmation("Desea salir del programa? Se perder%cn todos los cambios no guardados. s/n: ",
                                      "Opcion invalida", 's', 'n', 160))
                {
                    ll_deleteLinkedList(pArrayListEmployee);
                    option++;

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

