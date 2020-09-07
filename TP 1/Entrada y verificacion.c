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
