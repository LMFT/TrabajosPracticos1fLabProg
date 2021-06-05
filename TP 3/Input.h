#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED



#endif // INPUT_H_INCLUDED




#include "Text.h"

int Input_GetChar(char* c, char inputMsg[], ...);

int Input_GetChar_WithArguments(char* c, char inputMsg[], va_list arguments);

int Input_Int(int* number, char* inputMsg, ...);

int Input_IntOverValue(int* number, char inputMsg[], int minValue, char invalidInput[],...);

int Input_IntExcludingRange(int* number, char inputMsg[], int min, int max, ...);

int Input_IntInRange(int* number, char inputMsg[], int min, int max, char invalidInput[],...);

int Input_Float(float* number, char inputMsg[], ...);

int Input_FloatOverValue(float* number, char inputMsg[], int minValue, ...);

int Input_Confirmation(char inputMsg[], char invalidInput[], char confirmChar, char cancelChar, ...);

int Input_String(char myString[],int sizeOfString, char inputMsg[]);

int Input_String_Initialize(char myString[]);

int Input_String_Name(char name[],int sizeOfString, char inputMsg[], char numberFound[]);
