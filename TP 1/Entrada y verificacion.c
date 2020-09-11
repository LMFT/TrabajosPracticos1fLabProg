
#include <stdio.h>
#include "Entrada y verificacion.h"

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

//Menu de opciones de la calculadora, permitiendo ingresar los datos
int menu(float numero1, float numero2, int flag1, int flag2)
{
    int opcion;

    printf("\n***x MENU PRINCIPAL ***\n\n");
    //El if es para no mostrar valores basura previo a la carga de datos
    if(flag1 == 0)
    {
        printf("1- Ingresar primer numero (A = X)\n");
    }
    else
    {
        printf("1- Ingresar primer numero (A = %.2f)\n", numero1);
    }
    //El if es para no mostrar valores basura previo a la carga de datos
    if(flag2 == 0)
    {
        printf("2- Ingresar segundo numero (B = Y)\n");
    }
    else
    {
        printf("2- Ingresar segundo numero (B = %.2f)\n", numero2);
    }

    printf("3- Realizar Operaciones \n");
    printf("4- Mostrar Resultados\n");
    printf("5- Salir\n\n");
    printf("Ingrese una opcion: ");
    opcion = pedirNumeroEntero();



    return opcion;
}

//Recibe el valor de los flags de main() junto con la opcion ingresada por el usuario para verificar que el usuario ingrese datos antes
// de realizar cualquier tipo de calculo
int verificarPrimerIngreso(int opcion, int flag1, int flag2)
{
    if((flag1 == 0 || flag2 == 0) && (opcion != 1 && opcion != 2 && opcion != 5))
    {
        printf("\nDebe ingresar valores en A y B para poder realizar operaciones");
        return 0;
    }
    else
    {
        return 1;
    }
}


