
#include <stdio.h>
#include "Entrada y verificacion.h"

int pedirNumeroEntero()
{
    int numero;
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
    while(!(scanf("%f", &numero) == 1))
    {
        fflush(stdin);
        printf("\nEl valor ingresado no es un numero. Ingrese un numero: ");
    }



    return numero;
}

void cargarNumerosArray(int numeros[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        printf("Ingrese un numero: ");
        while(!(scanf("%d", &numeros[i]) == 1))
    {
        fflush(stdin);
        printf("\nEl valor ingresado no es un numero. Ingrese un numero: ");
    }

    }
}
