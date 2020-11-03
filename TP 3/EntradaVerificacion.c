#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "EntradaVerificacion.h"
#include "General_Use.h"

int ev_InputInt(char inputMessage[], int* number)
{
    int retorno; // return variable

    retorno = 0;

    if(number != NULL)
        {

        printf("\n%s", inputMessage);
        while(!(scanf("%d", number) == 1)) //Permite validar que el usuario solamente ingrese numeros
        {
            fflush(stdin);
            printf("\nEl valor ingresado no es un n%cmero. Reingrese un valor: ", 163);
        }
        retorno = 1;
    }
    return retorno;
}

float ev_InputFloat(char inputMessage[], float* number)
{
    int retorno; // return variable

    retorno = 0;

    if(number != NULL)
    {
        printf("\n%s", inputMessage);
        //Permite validar que el usuario solamente ingrese numeros
        while(!(scanf("%f", number) == 1))
        {
            fflush(stdin);
            printf("\nEl valor ingresado no es un n%cmero. Reingrese un valor", 163);
        }
        retorno = 1;
    }
    return retorno;
}

char ev_InputChar(char inputMessage[], char errorMessage[], char* character)
{
    int retorno; // return variable
    retorno = 1;
    printf("\n%s", inputMessage);
    //Permite validar que el usuario solamente ingrese numeros
    while(!(scanf("%c", character) == 1))
    {
        fflush(stdin);
        printf("\n%s", errorMessage);
    }
    retorno = 1;
    return retorno;
}


void ev_InputString_Name(char string[], int stringSize, char inputMessage[], char errorMessage[])
{
    int i;
    do
    {
        gu_InitializeString(string, stringSize);
        fflush(stdin);
        printf("\n%s", inputMessage);
        fgets(string, stringSize, stdin);

        for(i=0;i<stringSize;i++)
        {
            ev_NormalizeText_Name (string,i);
            ev_Fix_fgets(string,i);
        }

        if(ev_ValidateStringOnlyText(string, stringSize))
        {
            printf("\n%s", errorMessage);
        }

    }while(ev_ValidateStringOnlyText(string, stringSize));
}

void ev_InputString_OnlyText(char string[], int stringSize, char inputMessage[], char errorMessage[])
{
    int i;
    do
    {
        gu_InitializeString(string, stringSize);
        fflush(stdin);
        printf("\n%s", inputMessage);
        fgets(string, stringSize, stdin);

        for(i=0;i<stringSize;i++)
        {
            ev_NormalizeText(string,i);
            ev_Fix_fgets(string,i);

        }

        if(ev_ValidateStringOnlyText(string, stringSize))
        {
            printf("\n%s", errorMessage);
        }
    }while(ev_ValidateStringOnlyText(string, stringSize));
}

void ev_NormalizeText_Name (char string[], int position)
{
    if(position == 0)
    {
        string[position] = toupper(string[position]);
    }
    else
    {
        if(string[position] == '\n' && (string[position+1] != '\0' && string[position] != '\n'))
        {
            string[position] = toupper(string[position]);
        }
        else
        {
            string[position] = tolower(string[position]);
        }
    }
}

void ev_NormalizeText (char string[], int position)
{
    if(position == 0)
    {
        string[position] = toupper(string[position]);
    }
    else
    {
        string[position] = tolower(string[position]);
    }
}

int ev_ValidateStringOnlyText (char string[], int stringSize)
{
    int i;
    int digitFound;

    digitFound = 0;

    for(i=0;i<stringSize; i++)
    {
        if(isdigit(string[i])!= 0)
        {
            digitFound = 1;
            printf("\nEste campo no acepta caracteres num%cricos", 130);
            break;
        }

        if(string[i] == '\0')
        {
            break;
        }
    }
    return digitFound;
}

void ev_Fix_fgets(char string[], int position)
{
    if(string[position] == '\n' && string[position+1] == '\0')
    {
        string[position] = '\0';
    }
}

int ev_InputIntOverParameter(char inputMessage[], char errorMessage[], int* number, int parameter)
{
    int assignedValue;
    assignedValue = 0;
    if(number != NULL)
    {
        do
        {
            ev_InputInt(inputMessage, number);
        }while(!ev_ValidateIntOverParameter(*number, parameter,errorMessage));
        assignedValue = 1;
    }
    return assignedValue;
}

int ev_InputFloatOverParameter(char inputMessage[], char errorMessage[], float* number, float parameter)
{
    int assignedValue;
    assignedValue = 0;
    if(number != NULL)
    {
        do
        {
            ev_InputFloat(inputMessage, number);
        }while(!ev_ValidateFloatOverParameter(*number, parameter, errorMessage));
        assignedValue = 1;
    }
    return assignedValue;
}

int ev_ValidateIntOverParameter(int number, int parameter, char errorMessage[])
{
    int comparison;
    comparison = 0;
    if(number>parameter)
    {
        comparison = 1;
    }
    else
    {
        printf("\n%s", errorMessage);
    }
    return comparison;
}

int ev_ValidateFloatOverParameter(float number, float parameter, char errorMessage[])
{
    int comparison;
    comparison = 0;
    if(number>parameter)
    {
        comparison = 1;
    }
    else
    {
        printf("\n%s", errorMessage);
    }
    return comparison;
}

void ev_InputString_OnlyNumbers(char string[], int stringSize, char inputMessage[], char errorMessage[])
{
    int i;
    do
    {
        printf("\n%s", inputMessage);
        fflush(stdin);
        fgets(string, stringSize, stdin);

        for(i=0;i<stringSize; i++)
        {
            ev_Fix_fgets(string, i);

        }

        if(ev_ValidateString_OnlyNumbers(string, stringSize) == 1)
        {
            printf("\n%s", errorMessage);
        }
    }while(ev_ValidateString_OnlyNumbers(string, stringSize) == 1);
}

int ev_ValidateString_OnlyNumbers(char string[], int stringSize)
{
    int i;
    int charFound;

    charFound = 0;

    for(i=0;i<stringSize; i++)
    {
        if(isalpha(string[i])!= 0)
        {
            charFound = 1;
            printf("\nEste campo no acepta caracteres alfab%cticos", 130);
            break;
        }

        if(string[i] == '\0')
        {
            break;
        }
    }
    return charFound;
}

void ev_InputInt_BetweenTwoNumbers(char inputMessage[], char errorMessage[], int* number, int min, int max)
{
    do
    {

    ev_InputInt(inputMessage, number);

    if(*number<min || *number>max)
    {
        printf("\n%s", errorMessage);
    }

    }while(*number<min || *number>max);
}
