#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int elementsAdded = -1;
    char parsedId[9];
    char parsedHours[5];
    char parsedSalary[9];
    char parsedName[128];
    Employee* new;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        elementsAdded = 0;
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", parsedId, parsedName, parsedHours, parsedSalary);
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", parsedId, parsedName, parsedHours, parsedSalary);
            new = employee_newParametros(parsedId, parsedName, parsedHours, parsedSalary);
            ll_add(pArrayListEmployee, new);
            elementsAdded++;
        }
    }
    return elementsAdded;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int elementsAdded = -1;
    int id;
    Employee* new;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        elementsAdded = 0;
        while(!feof(pFile))
        {
            new = employee_new();
            if(new != NULL)
            {
                fread(new, sizeof(Employee), 1, pFile);
                employee_getId(new, &id);
                if(id == 0)
                {
                    continue;
                }
                ll_add(pArrayListEmployee, new);
                elementsAdded++;
            }
        }
    }
    return elementsAdded;
}
