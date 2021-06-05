#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED



#endif // TEXT_H_INCLUDED

#include "Comparison.h"


int Text_NormalizeName(char name[]);

int Text_ConcatenateName(char firstName[], char lastName[], char fullName[]);

int Text_Initialize(char myString[]);

int Text_ContainsNumbers(char myString[]);

int Text_PrintString_Internal(char myString[], va_list arguments);

int Text_PrintString(char myString[], ...);

int Text_ReadFormatMask(char* myString);
