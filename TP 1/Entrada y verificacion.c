
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
    float opcion;  //Permite cargar numeros flotantes al menu
    int comparacion; // Compara el valor de la variable opcion contra su contraparte entera para eliminar casos de error

    printf("\n*********************************");
    printf("\n******     CALCULADORA     ******");
    printf("\n*********************************\n\n");
    printf("\n*** MENU PRINCIPAL ***\n\n");
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

    //Estructura condicional para alternar entre letras y numeros al mostrar las operaciones en el menu
    printf("3- Realizar Operaciones \n\n");
    if(flag1 && flag2)
    {
       printf("    a. Suma (%.2f+%.2f)\n", numero1, numero2);
    }
    else if (flag1)
    {
       printf("    a. Suma (%.2f+B)\n", numero1);
    }
    else if (flag2)
    {
        printf("    a. Suma (A+%.2f)\n", numero2);
    }
    else
    {
       printf("    a. Suma (A+B)\n");
    }

    if(flag1 && flag2)
    {
       printf("    b. Resta (%.2f-%.2f)\n", numero1, numero2);
    }
    else if (flag1)
    {
       printf("    b. Resta (%.2f-B)\n", numero1);
    }
    else if (flag2)
    {
        printf("    b. Resta (A-%.2f)\n", numero2);
    }
    else
    {
       printf("    b. Resta (A-B)\n");
    }

    if(flag1 && flag2)
    {
       printf("    c. Producto (%.2f*%.2f)\n", numero1, numero2);
    }
    else if (flag1)
    {
       printf("    c. Producto (%.2f*B)\n", numero1);
    }
    else if (flag2)
    {
        printf("    c. Producto (A*%.2f)\n", numero2);
    }
    else
    {
       printf("    c. Producto (A*B)\n");
    }

    if(flag1 && flag2)
    {
       printf("    d. Division (%.2f/%.2f)\n", numero1, numero2);
    }
    else if (flag1)
    {
       printf("    d. Division (%.2f/B)\n", numero1);
    }
    else if (flag2)
    {
        printf("    d. Division (A/%.2f)\n", numero2);
    }
    else
    {
       printf("    d. Division (A/B)\n");
    }

    if(flag1)
    {
       printf("    e. Factorial de A (%.2f!)\n", numero1);
    }
    else
    {
       printf("    e. Factorial de A (A!)\n");
    }

    if(flag2)
    {
       printf("    f. Factorial de B (%.2f!)\n", numero2);
    }
    else
    {
       printf("    f. Factorial de B (B!)\n\n");
    }
    printf("4- Mostrar Resultados\n");
    printf("5- Salir\n\n");
    printf("Ingrese una opcion: ");
    opcion = pedirNumeroFlotante();
    comparacion = opcion;
    if(comparacion != opcion)
    {
        return -1;
    }

    return opcion;
}

//Recibe el valor de los flags de main() junto con la opcion ingresada por el usuario para verificar que el usuario ingrese datos antes
// de realizar cualquier tipo de calculo
int verificarPrimerIngreso(int opcion, int flag1, int flag2)
{
    if((flag1 == 0 || flag2 == 0) && (opcion != 1 && opcion != 2 && opcion != 5))
    {
        printf("\nDebe ingresar valores en A y B para poder realizar operaciones\n");
        return 0;
    }
    else
    {
        return 1;
    }
}


