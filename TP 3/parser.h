#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED

#include "LinkedList.h"
#include "Employee.h"

/** \brief Parses the data stored in a text file and loads it into the employee list.
 *
 * \param pFile FILE* Pointer to file where the data is stored
 * \param pArrayListEmployee LinkedList* Pointer to employee list
 * \return int [-1] if either pointers is NULL
                amount of elements parsed otherwise
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parses the data stored in a binary file and loads it into the employee list.
 *
 * \param pFile FILE* Pointer to file where the data is stored
 * \param pArrayListEmployee LinkedList* Pointer to employee list
 * \return int [-1] if either pointers is NULL
                amount of elements parsed otherwise
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
