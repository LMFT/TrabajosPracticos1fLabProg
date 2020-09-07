#include <stdio.h>
#include <stdlib.h>
#include "Aritmeticas.h"
#include "Entrada y verificacion.h"

int main()
{
    //Para asegurar de que el usuario ingresa una opcion válida en el switch
    float opcionF;
    int opcionI;

    //Inputs
    float numero1;
    float numero2;

    //Outputs
    float suma;
    float resta;
    float producto;
    float division;
    long int factorial1;
    long int factorial2;

    //Repite el programa
    char repetir;

    repetir = 'n';

    printf("*** Calculadora de dos numeros *** \n\n");
    do
    {
    printf("Ingrese el primer numero: ");
    numero1 = pedirNumero();
    printf("Ingrese el segundo numero: ");
    numero2 = pedirNumero();

    printf("\n***Ingrese una opcion ***\n\n");
    printf("1- Sumar (%.2f + %.2f) \n", numero1, numero2);
    printf("2- Restar (%.2f - %.2f) \n", numero1, numero2);
    printf("3- Multiplicar (%.2f * %.2f) \n", numero1, numero2);
    printf("4- Dividir(%.2f / %.2f) \n", numero1, numero2);
    printf("5- Factorial (%.2f!, %.2f!) \n", numero1, numero2);
    printf("6- Reingresar Datos\n");
    printf("7- Salir\n\n");
    opcionF = pedirNumero();
    opcionI = opcionF;

    if(opcionI == 6)
    {
        repetir = 's';
        printf("\n\n");
        continue;
    }
    else if( opcionI == 7)
    {
        break;
    }
    switch(opcionI)
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
            printf("\nEl factorial del primer numero es: %ld\n", factorial1);
            printf("\nEl factorial del segundo es: %ld\n", factorial2);
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
