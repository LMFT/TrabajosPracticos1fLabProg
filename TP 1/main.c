<<<<<<< HEAD
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
=======
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
>>>>>>> 315ed78b7b96f3de95966b4aef8b5764167d733a
