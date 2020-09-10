
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

    printf("\n***Ingrese una opcion ***\n\n");
    printf("1- Ingresar primer numero (A = %.2f)\n", numero1);
    printf("2- Ingresar segundo numero (B = %.2f)\n", numero2);
    printf("3- Realizar Operaciones \n");
    printf("4- Mostrar Resultados\n");
    printf("5- Salir\n\n");
    opcion = pedirNumeroEntero();



    return opcion;
}

int verificarPrimerIngreso(int flag, int opcion)
{
    if(!(opcion == 1 || opcion == 2 || opcion == 5) && flag == 0)
    {
        printf("\nDebe ingresar valores antes de realizar o mostrar calculos\n\n");
        return 0;
    }
    else
    {
        return 1;
    }

}

