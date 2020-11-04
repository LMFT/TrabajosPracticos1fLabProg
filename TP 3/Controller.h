#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include <ctype.h>
#include "Employee.h"
#include "parser.h"
#include "EntradaVerificacion.h"
#include "General_Use.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee, int* lastId); // Added last ID parameter to keep track of the last id registered
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


void BinaryToText(char*, char*);

int controller_GetMax(LinkedList* , int* );
int controller_GetLastId(LinkedList* this, int id);

Employee* controller_SearchByID (LinkedList* this, int id);

int controller_editEmployee_Menu();
int controller_editEmployee_Operations(LinkedList* employeeList, Employee* pEmployee, int option, int index);

int controller_sortEmployee_Menu();
int controller_sortEmployee_Operations(int option, LinkedList* employeeList);
int controller_sortEmployee_ById(LinkedList* employeeList);
int controller_sortEmployee_ByName(LinkedList* employeeList);
int controller_sortEmployee_ByHours(LinkedList* employeeList);
int controller_sortEmployee_BySalary(LinkedList* employeeList);

int controller_MainMenu();
int controller_MainMenu_Operations(int option, LinkedList* employeeList, int dataLoaded, int* lastId);

int controller_loadFromText_VerifyDataLoaded(int dataLoaded, LinkedList* employeeList, int* lastId);
int controller_loadFromBinary_VerifyDataLoaded(int dataLoaded, LinkedList* employeeList, int* lastId);

int controller_LoadWithoutSaving(int changesMade);

int controller_ConvertEmployeeDataToString(Employee* anEmployee, char id[], char name[], char hours[], char salary[]);

int controller_loadLastId_Text(char* path, int* lastId);
int controller_loadLastId_Binary(char* path, int* lastId);
int controller_SaveLastId_Text(int* lastId, char* path);
int controller_SaveLastId_Binary(int* lastId, char* path);
