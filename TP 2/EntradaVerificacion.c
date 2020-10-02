#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "EntradaVerificacion.h"

int pedirNumeroEntero()
{
    int numero;


    //Permite validar que el usuario solamente ingrese numeros
    while(!(scanf("%d", &numero) == 1))
    {
        fflush(stdin);
        printf("\nEl valor ingresado no es un numero. Ingrese un numero: ");
    }
    return numero;
}

float pedirNumeroFlotante()
{
    float numero;
    //Permite validar que el usuario solamente ingrese numeros
    while(!(scanf("%f", &numero) == 1))
    {
        fflush(stdin);
        printf("\nEl valor ingresado no es un numero. Ingrese un numero: ");
    }
    return numero;
}

char InputChar()
{
    char caracter;
    //Permite validar que el usuario solamente ingrese numeros

        fflush(stdin);
    while(!(scanf("%c", &caracter) == 1))
    {
        printf("\nError: Eso no es un caracter");
    }
    return caracter;
}


int ValidateInput(int flag)
{
    if(flag == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}




void InputArrayInt(int i, int string[])
{

        printf("Ingrese numero de legajo: ");
        string[i] = pedirNumeroFlotante();

}

void InputArrayFloat(int i, float string[i])
{
    printf("Ingrese el sueldo: ");
    string[i] = pedirNumeroFlotante();

}

void InputString(char string[], int stringSize)
{
    int i;
    int numbers;
    do
    {
        fflush(stdin);
        fgets(string, stringSize, stdin);

        for(i=0;i<stringSize;i++)
        {
            if(string[i] == '\n' && string[i+1] == '\0')
            {
                string[i] = '\0';
            }

            if(i == 0 || (string[i-1] == ' ' && string[i] != ' '))
            {
               string[i] = toupper(string[i]);
            }
            else
            {
                string[i] = tolower(string[i]);
            }
        }


        numbers = ValidateStringOnlyText(string, stringSize);

        if(numbers == 1)
        {
            printf("Este campo no acepta caracteres numericos\n");
        }

    }while(numbers == 1);
}

int ValidateStringOnlyText (char string[], int stringSize)
{
    int i;
    int digitFound;

    digitFound = 0;

    for(i=0;i<stringSize; i++)
    {
        if(isdigit(string[i])!= 0)
        {
            digitFound = 1;
            break;
        }

        if(string[i] == '\0')
        {
            break;
        }
    }
    return digitFound;
}
