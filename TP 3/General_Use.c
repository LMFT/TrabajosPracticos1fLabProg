#include <stdio.h>
#include "EntradaVerificacion.h"
void gu_InitializeString(char string[], int stringSize)
{
    int i;

    for(i=0;i<stringSize;i++)
    {
        string[i] = '\0';
    }
}

int gu_Confirmation()
{
    int confirmation;

    do
    {
        printf("\nDesea confirmar esta operacion?\n 1- Si\n 2- No");
        ev_InputInt("\nIngrese una opcion: ", &confirmation);
        if(confirmation<1 || confirmation>2)
        {
            printf("\nOpcion inv%clida", 160);
        }
    }while(confirmation<1 || confirmation>2);
    if(confirmation == 2)
    {
        confirmation=0;
    }
    return confirmation;
}

int gu_CompareTwoInt (int number1, int number2)
{
    int comparison;

    if(number1 == number2)
    {
        comparison = 0;
    }
    else
    {
        if(number1<number2)
        {
            comparison = -1;
        }
        else
        {
            comparison = 1;
        }
    }
    return comparison;
}

int gu_CompareTwoFloat (float number1, float number2)
{
    int comparison;

    if(number1 == number2)
    {
        comparison = 1;
    }
    else
    {
        if(number1<number2)
        {
            comparison = -1;
        }
        else
        {
            comparison = 1;
        }
    }
    return comparison;
}


