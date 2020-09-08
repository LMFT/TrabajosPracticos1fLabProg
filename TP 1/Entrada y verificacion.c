<<<<<<< HEAD
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

=======
#include <stdio.h>

/** \brief Recibe un dato ingresado por el usuario, valida que sea un numero flotante y retorna su valor
 *
 * \return float El numero ingresado ya validado
 *
 */
float pedirNumero()
{
    float numero;
    while(!(scanf("%f", &numero) == 1))
    {
        fflush(stdin);
        printf("\nEl valor ingresado no es un numero. Ingrese un numero: ");
    }



    return numero;
}

char pedirCaracter()
{
    char caracter;
    while(!(scanf("%c", &caracter) == 1))
    {
        fflush(stdin);
        printf("\nEl valor ingresado no es un caracter. Ingrese un caracter: ");
    }



    return caracter;
}
>>>>>>> 315ed78b7b96f3de95966b4aef8b5764167d733a
