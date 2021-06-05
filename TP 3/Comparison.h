#ifndef COMPARISON_H_INCLUDED
#define COMPARISON_H_INCLUDED

typedef enum bool
{
    false,
    true,
}bool;

#endif // COMPARISON_H_INCLUDED

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int Compare_Elements(void* firstObject, void* secondObject, size_t size);

int Comparison_Swap(void* firstObject, void* secondObject, size_t size);

int Comparison_IntInRange(int number, int min, int max);

int Comparison_CheckParityInt(int parameter);
