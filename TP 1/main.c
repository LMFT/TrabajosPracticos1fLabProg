#include <stdio.h>
#include <stdlib.h>
#include "Aritmeticas.h"
#include "Entrada y verificacion.h"

int main()
{

    //Inputs
    float numero1;
    float numero2;
    int opcion;

    //Variables internas
    int comparacion1; //Para asegurar que el numero sea entero para el calculo del factorial
    int comparacion2; //Para asegurar que el numero sea entero para el calculo del factorial

    //Outputs
    float division;
    float producto;
    float resta;
    float suma;
    long int factorial1;
    long int factorial2;

    //Inicializo las variables para mostrarlas en el menu
    numero1 = 0;
    numero2 = 0;

    do
    {
    printf("*** Calculadora de dos numeros *** \n\n");
    printf("\n***Ingrese una opcion ***\n\n");
    printf("1- Ingresar primer numero (A = %.2f)\n", numero1);
    printf("2- Ingresar segundo numero (B = %.2f)\n", numero2);
    printf("3- Realizar Operaciones \n");
    printf("4- Mostrar Resultados\n");
    printf("5- Salir\n\n");
    opcion= pedirNumeroEntero();

    switch(opcion)
    {
        case 1:
            printf("Ingrese el primer numero: ");
            numero1 = pedirNumeroFlotante();
            comparacion1 = numero1;
            break;
        case 2:
            printf("Ingrese el segundo numero: ");
            numero2 = pedirNumeroFlotante();
            comparacion2 = numero2;
            break;
        case 3:
            suma = sumarDosNumeros(numero1, numero2);
            resta = restarDosNumeros(numero1, numero2);
            producto = multiplicarDosNumeros(numero1, numero2);
            if(numero2 != 0)
            {
                division = dividirDosNumeros(numero1, numero2);
            }
            if(numero1 > 0 && numero1 == comparacion1 && numero1 < 12)
            {
            factorial1 = factorialNumero(numero1);
            }
            if(numero2 > 0 && numero2 == comparacion2 && numero2 <= 12)
            {
            factorial2 = factorialNumero(numero2);
            }

            break;
        case 4:
            printf("\nEl resultado de la suma es: %.2f\n", suma);
            printf("\nEl resultado de la resta es: %.2f\n", resta);
            printf("\nEl resultado de la multiplicacion es: %.2f\n", producto);
            if(numero2 != 0)
            {
                printf("\nEl resultado de la division es: %.2f\n", division);
            }
            else
            {
                printf("\n No pudo realizarse la division: No es posible dividir por 0\n");
            }
            if(numero1 < 0 || numero1 != comparacion1)
            {
                printf("\nNo pudo calcularse el factorial de %.2f: El factorial solo admite enteros positivos\n", numero1);
            }
            else if (numero1 >12)
            {
                printf("\nError: El numero ingresado es demasiado grande para este calculo\n");
            }
            {
            printf("\nEl factorial de %.2f es: %ld\n", numero1, factorial1);
            }
            if(numero2 < 0 || numero2 != comparacion2)
            {
                printf("\nNo pudo calcularse el factorial de %.2f: El factorial solo admite enteros positivos\n", numero2);
            }
            else if (numero1 >12)
            {
                printf("\nError: El numero ingresado es demasiado grande para este calculo\n");
            }
            else
            {
            printf("\nEl factorial de %.2f es: %ld\n", numero2, factorial2);
            }
            break;
        case 5:
            break;
        default:
            printf("\nLa opcion ingresada no es válida.\n");

    }
    }while(opcion != 5);
    return 0;
}
