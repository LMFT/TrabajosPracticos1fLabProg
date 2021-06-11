#include "Input.h"


#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


/** \brief Sets the value of the last Id variable to the number passed as argument. Returns the value of last Id
 *
 * \param id int New value for the last Id variable
 * \return int value of lastId
 *
 */
int employee_setLastId(int id);


/** \brief Gets the value of the last Id variable
 *
 * \return int last id
 *
 */
int employee_getLastId();

/** \brief Increases the value of the last id by 1 and returns the new value
 *
 * \return int new value of the last id variable
 *
 */
int employee_increaseLastId();

/** \brief Decreases the value of the last id by 1 and returns the new value
 *
 * \return int new value of the last id variable
 *
 */
int employee_decreaseLastId();


/** \brief Allocates memory to store a new employee
 *
 * \return Employee* [NULL] if no memory was allocated, otherwise it returns a pointer to the new address
 *
 */
Employee* employee_new();

/** \brief Allocates memory to store a new employee, parses the data received as strings and sets its values
 *
 * \param idStr char* Id of the new employee
 * \param nombreStr char* Name
 * \param horasTrabajadasStr char* Hours worked by the new employee
 * \param salarioStr char* Salary of the new employee
 * \return Employee* [NULL] if no memory was allocated, a pointer to said address otherwise
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salarioStr);

/** \brief Allocates memory to store a new employee, asks the user to input the new data and sets those values to the new employee
 *
 * \return Employee* [NULL] if no memory was allocated, a pointer to said address otherwise
 *
 */
Employee* employee_newSet();

/** \brief Sets the id of the employee passed by reference to the value given in arguments
 *
 * \param this Employee* Pointer to the employee whom i wish to set the id
 * \param id int new value for the ID of the employee
 * \return int  [-1] if the pointer to employee is NULL or the ID is less than 0
                [0] if ok
 *
 */
int employee_setId(Employee* this,int id);
/** \brief Gets the ID of the employee passed as argument and outputs it through the int pointer
 *
 * \param this Employee* Pointer to the employee whos id i wish to get
 * \param id int* Output argument. Stores the id of the employee
 * \return int [-1] if the pointer to employee is NULL or the ID pointer is NULL
                [0] if ok
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Sets the employee's name to the value passed as a parameter
 *
 * \param this Employee* Pointer to the employee i wish to set his name
 * \param nombre char* String i wish to set as the employee's name
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_delete(Employee* this);

int employee_printOne(Employee* myEmployee);

int employee_compareById(void* firstEmployee, void* secondEmployee);
int employee_compareByName(void* firstEmployee, void* secondEmployee);
int employee_compareByHoursWorked(void* firstEmployee, void* secondEmployee);
int employee_compareBySalary(void* firstEmployee, void* secondEmployee);
#endif // employee_H_INCLUDED
