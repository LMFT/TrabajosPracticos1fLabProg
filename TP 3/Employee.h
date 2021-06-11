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
 * \return int [-1] if either pointer is NULL
                [0] if ok
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief Gets the name of the employee passed as argument and outputs it through the int pointer
 *
 * \param this Employee* Pointer to the employee whos id i wish to get
 * \param nombre char* Output argument. Stores the name of the employee
 * \return int [-1] if the pointer to employee is NULL or the name pointer is NULL
                [0] if ok
 *
 */
int employee_getNombre(Employee* this,char* nombre);
/** \brief Sets the employee's hours worked to the value passed as a parameter
 *
 * \param this Employee* Pointer to the employee i wish to set his hours
 * \param hoursWorked int Value i wish to set as the employee's hours
 * \return int [-1] if pointer is NULL
                [0] if ok
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Gets the hours worked by the employee passed as argument and outputs it through the int pointer
 *
 * \param this Employee* Pointer to the employee whos id i wish to get
 * \param horasTrabajadas int* Output argument. Stores the hours worked by the employee
 * \return int [-1] if the pointer to employee is NULL or the hours pointer is NULL
                [0] if ok
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief Sets the employee's salary to the value passed as a parameter
 *
 * \param this Employee* Pointer to the employee i wish to set his name
 * \param sueldo int Value i wish to set as the employee's salary
 * \return int [-1] if pointer is NULL
                [0] if ok
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief Gets the salary of the employee passed as argument and outputs it through the int pointer
 *
 * \param this Employee* Pointer to the employee whos id i wish to get
 * \param sueldo int* Output argument. Stores the salary of the employee
 * \return int [-1] if the pointer to employee is NULL or the salary pointer is NULL
                [0] if ok
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Deletes an employee
 *
 * \param this Employee* Employee to delete
 * \return int [-1] if pointer is NULL
                [0] if ok
 *
 */
int employee_delete(Employee* this);

/** \brief Prints the data of the employee passed as a parameter
 *
 * \param myEmployee Employee* Pointer to employee to print
 * \return int [-1] if pointer is NULL
                [0] if ok
 *
 */
int employee_printOne(Employee* myEmployee);

/** \brief Compares the ID of the employees passed as parameters
 *
 * \param firstEmployee void* pointer to first employee
 * \param secondEmployee void* pointer to second employee
 * \return int [-1] if first employee's id is smaller than second employee's one
                [0] if ID's are the same
                [1] if first employee's id is bigger than second employee's one
 *
 */
int employee_compareById(void* firstEmployee, void* secondEmployee);
/** \brief Compares the names of the employees passed as parameters
 *
 * \param firstEmployee void* pointer to first employee
 * \param secondEmployee void* pointer to second employee
 * \return int [-1] if first employee's name is smaller than second employee's one
                [0] if names's are the same
                [1] if first employee's name is bigger than second employee's one
 *
 */
int employee_compareByName(void* firstEmployee, void* secondEmployee);
/** \brief Compares the hours worked of the employees passed as parameters
 *
 * \param firstEmployee void* pointer to first employee
 * \param secondEmployee void* pointer to second employee
 * \return int [-1] if first employee's hours worked is smaller than second employee's one
                [0] if hours worked's are the same
                [1] if first employee's hours worked is bigger than second employee's one
 *
 */
int employee_compareByHoursWorked(void* firstEmployee, void* secondEmployee);
/** \brief Compares the salaries of the employees passed as parameters
 *
 * \param firstEmployee void* pointer to first employee
 * \param secondEmployee void* pointer to second employee
 * \return int [-1] if first employee's salary is smaller than second employee's one
                [0] if salaries's are the same
                [1] if first employee's salary is bigger than second employee's one
 *
 */
int employee_compareBySalary(void* firstEmployee, void* secondEmployee);
#endif // employee_H_INCLUDED
