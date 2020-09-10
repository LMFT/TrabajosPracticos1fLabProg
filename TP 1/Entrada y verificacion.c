
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

int menu(float numero1, float numero2)
{
    int opcion;

    printf("*** Calculadora de dos numeros *** \n\n");
    printf("\n***Ingrese una opcion ***\n\n");
    printf("1- Ingresar primer numero (A = %.2f)\n", numero1);
    printf("2- Ingresar segundo numero (B = %.2f)\n", numero2);
    printf("3- Realizar Operaciones \n");
    printf("4- Mostrar Resultados\n");
    printf("5- Salir\n\n");
    opcion = pedirNumeroEntero();



    return opcion;
}

