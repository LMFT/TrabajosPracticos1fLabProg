#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EntradaVerificacion.h"
#include "Funcionalidades.h"

#define LEN 51
//Estructura de empleados
typedef struct
{
    int id;
    char nombre[LEN];
    char apellido[LEN];
    int sector;
    float sueldo;
    int estado; //Vacio = 0 / Lleno = 1
}Employee;





/** \brief Funcion principal del programa
 *
 *
 */
void EmployeeDatabase();

/////////////////////////////////
///////Ingreso de datos/////////
///////////////////////////////
/** \brief Permite cargar una variable del tipo Empleado
 *
 * \return Employee Datos del nuevo empleado
 *
 */
Employee InputStruct();

/////////////////////////////////
////////////Menus///////////////
///////////////////////////////


/** \brief Menu de la funcion MemoryFull. Permite elegir entre vaciar datos en memoria o abortar la operacion
 *
 * \return int Opcion ingresada por el usuario
 *
 */
int MemoryFull_Menu();

/** \brief Menu de la funcion ShowEmployees. Permite mostrar los empleados segun el criterio que desea el usuario
 *
 * \return int Opcion ingresada por el usuario
 *
 */
int ShowEmployeesMenu();

/** \brief Menu de la funcion ModifyEmployee. Permite ingresar que campos se desean modificar
 *
 * \return int Opcion ingresada por el usuario
 *
 */
int ModifyEmployeeMenu();

/////////////////////////////////
///////Funcionalidades//////////
///////////////////////////////

/** \brief Ordena un array segun el criterio que desea el usuario
 *
 * \param Employee[]  Array de empleados a ordenar
 * \param  int        Tamaño del array de empleados
 *
 */
void SortBy (Employee[], int );

/** \brief Inicializa una variable del tipo Employee
 *
 * \param Employee Variable a inicializar
 * \return Employee Variable inicializado
 *
 */
Employee InitializeStruct(Employee);

/** \brief Inicializa un array del tipo Employee
 *
 * \param Employee[] Array a inicializar
 * \param int Tamaño del array
 * \return Employee* Array inicializado
 *
 */
Employee* InitializeStructArray(Employee[], int );

/** \brief Funcionalidad que se ejecuta al llenarse el espacio de memoria del vector. Permite elegir entre vaciar los datos almacenados
 *          y abortar el ingreso de un dato, conservando los datos originales
 * \param Employee[] Array de datos de la estructura
 * \param  int Cantidad de posiciones del array de empleados
 * \return Employee* Retorna el mismo array ingresado o el array inicializado segun desee el usuario
 *
 */
void MemoryFull (Employee[], int );

/** \brief Funcionalidad secundaria de ingreso de empleados. Permnite ingresar un empleado y confirmar su ingreso
 *
 * \return Employee Si el usuario confirma el ingreso del empleado retorna sus datos, sino retorna un valor inicializado
 *
 */
Employee EnterEmployee ();

/** \brief Funcionalidad principal de ingreso de empleados. Busca la primer posicion de memoria libre y carga los datos en la misma
 *         Si no hubiese una posicion de memoria llama a la funcion MemoryFull
 *
 * \param [] Employee Listado de empleados donde ingresar los nuevos datos
 * \param  int Tamaño del array de empleados
 * \param  int Contador de empleados totales para cargar una nueva ID
 * \return int Retorna el valor del contador (original si no se modificaron datos, original+1 en caso contrario)
 *
 */
int NewEmployee (Employee [], int , int );

/** \brief Busca la primer posicion de memoria libre en un array
 *
 * \param [] Employee Array de empleados donde buscar
 * \param int Tamaño del array
 * \return int Valor de la posicion de memoria libre. -1 si no se encontraron espacios
 *
 */
int SearchEmptyPosition(Employee [], int );

/** \brief Funcion principal de modificacion de empleados. Permite modificar cualquier campo menos ID y estado
 *
 * \param [] Employee Listado de empleados
 * \param int Tamaño del array de empleados
 *
 */
void ModifyEmployee(Employee [], int);

/** \brief Operaciones de la funcion ModifyEmployee. Permite seleccionar qué campos modificar
 * \param  Employee Empleado a modificar
 * \param  int Opcion ingresada por el usuario
 * \return Employee Empleado modificado
 *
 */
Employee ModifyEmployeeOperations(Employee , int );

/** \brief Busca un empleado por ID
 *
 * \param [] Employee Listado de empleados
 * \param int Tamaño del listado
 * \param int ID buscada
 * \return Employee Empleado cuyo ID coincide con el ID requerido
 *
 */
Employee SearchById(Employee [],int , int );

/** \brief Analiza si una opcion ya ha sido ingresada previamente(en caso de seleccionarse multiples valores)
 *
 * \param [] int Array con los valores ingresados por el usuario
 * \param int Tamaño del array de valores
 * \param int Numero ingresado por el usuario
 * \return int Retorna 0 si no encuentra el valor ingresado en el array, 1 si lo encuentra
 *
 */
int AlreadyInputed(int [], int , int );

/** \brief Funcionalidad principal de remover empleados a traves de su ID
 *
 * \param [] Employee Listado de empleados
 * \param int tamaño del listado
 * \return void
 *
 */
void RemoveEmployee(Employee [], int);
/** \brief Calcula el promedio de sueldo de los empleados
 *
 * \param [] Employee Listado de empleados
 * \param int Cantidad de empleados
 * \return float Promedio de sueldo
 *
 */
float GetAverage(Employee [], int);

/////////////////////////////////
////////Ordenamiento////////////
///////////////////////////////

/** \brief Ordena un array segun dos factores dados
 *
 * \param [] Employee Listado de empleados a ordenar
 * \param  int Tamaño del array a ordenar
 *
 */
void ArrangeStructByTwoFactors(Employee [], int );

/////////////////////////////////
///////Salida de datos//////////
///////////////////////////////
/** \brief Funcion principal para mostrar datos de empleados
 *
 * \param eEmpleados[] Array de empleados
 * \param int tamaño del array
 *
 */
void ShowEmployees( Employee[], int);

/** \brief Muestra los valores cargados en una variable de una estructura
 *
 * \param Employee Empleado a mostrar
 *
 */
void ShowOneStruct(Employee );

/** \brief Muestra a los empleados que estan por encima del promedio de sueldo
 *
 * \param Employee[] Listado de empleados
 * \param int Cantidad de empleados
 * \param float Parametro de muestra de datos
 *
 */
void ShowOverParameter(Employee[], int, float);

/** \brief Operaciones de la funcion mostrar empleados. Ordena, muestra y calcula segun opcion ingresada
 *
 * \param employeeList[] Employee Lista de empleados
 * \param listSize int Cantidad de empleados
 * \param option int Opcion ingresada por el usuario
 *
 */
void ShowEmployeesOperations(Employee employeeList[], int listSize, int option);

/** \brief Muestra un array de variables de una estructura
 *
 * \param employeeList[] Employee Lista de empleados
 * \param listSize int Cantidad de empleados
 *
 */
void ShowStructArray(Employee employeeList[], int listSize);
