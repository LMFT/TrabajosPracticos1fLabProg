#include <stdio.h>
#include <stdlib.h>
#include "Aritmeticas.h"
#include "Entrada y verificacion.h"

int main()
{
    int operacion;

    float numero1;
    float numero2;

    float suma;
    float resta;
    float producto;
    float division;
    long int factorial1;
    long int factorial2;

    char repetir;

    printf("Calculadora de dos numeros: \n");
    do
    {

    numero1 = pedirNumero();
    numero2 = pedirNumero();

    printf("Ingrese una opcion: \n");
    printf("1- Sumar \n");
    printf("2- Restar \n");
    printf("3- Multiplicar \n");
    printf("4- Dividir\n");
    printf("5- Factorial\n");
    printf("6- Salir\n");
    scanf("%d", &operacion);

    if(operacion == 6)
    {
        break;
    }
    switch(operacion)
    {
        case 1:
            suma = sumarDosNumeros(numero1, numero2);
            printf("\nEl resultado de la suma es: %.2f\n", suma);
            break;
        case 2:
            resta = restarDosNumeros(numero1, numero2);
            printf("\nEl resultado de la resta es: %.2f\n", resta);
            break;
        case 3:
            producto = multiplicarDosNumeros(numero1, numero2);
            printf("\nEl resultado de la multiplicacion es: %.2f\n", producto);
            break;
        case 4:
            division = dividirDosNumeros(numero1, numero2);
            printf("\nEl resultado de la division es: %.2f\n", division);
            break;
        case 5:
            factorial1 = factorialNumero(numero1);
            factorial2 = factorialNumero(numero2);
            printf("\nEl factorial de %f es: %ld\n", numero1, factorial1);
            printf("\nEl factorial de %f es: %ld\n", numero2, factorial2);
            break;
        default:
            printf("\nLa opcion ingresada no es válida.\n");

    }
    printf("Desea realizar otra operacion? s/n: ");
    fflush(stdin);
    scanf("%c", &repetir);
    }while(repetir == 's');
    return 0;
}
