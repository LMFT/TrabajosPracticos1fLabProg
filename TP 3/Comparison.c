#include "Comparison.h"

int Compare_Elements(void* firstObject, void* secondObject, size_t size)
{
    int comparison = -2;

    if(firstObject != NULL && secondObject != NULL)
    {
        comparison = memcmp(firstObject, secondObject, size);
        if(comparison > 0)
        {
            comparison = 1;
        }
        else
        {
            if(comparison < 0)
            {
                comparison = -1;
            }
        }
    }
    return comparison;
}

int Comparison_Swap(void* firstObject, void* secondObject, size_t size)
{
    int swap = 0;
    void* temp;

    if(firstObject != NULL && secondObject != NULL)
    {
        temp = malloc(size);
        memmove(temp, firstObject, size);
        memmove(firstObject, secondObject, size);
        memmove(secondObject, temp, size);
        free(temp);
    }
    return swap;
}

int Comparison_CheckParityInt(int parameter)
{
    int parity;
    if(parameter%2 == 0)
    {
        parity = 1;
    }
    else
    {
        parity=0;
    }
    return parity;
}
