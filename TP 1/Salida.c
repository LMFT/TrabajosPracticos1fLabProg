#include <stdio.h>


void mostrarResultados(long double resultados[], int cant, float numero2)
{
    int i;

    for(i=0; i<cant; i++)
    {
        switch(i)
        {
        case 0:
            printf("El resultado de la suma es: %.2f\n",(double)resultados[i]);

            break;
        case 1:
            printf("El resultado de la resta es: %.2f\n",(double)resultados[i]);
            break;
        case 2:
            printf("El resultado del producto es: %.2f\n",(double)resultados[i]);
            break;
        case 3:
            if(resultados[i] == 0 && numero2 == 0)
            {
                printf("Error: No se puede calcular la division por 0, modifique el valor de B");
            }
            else
            {
            printf("El resultado de la division es: %.2f\n",(double)resultados[i]);
            }
            break;
        case 4:
            if(resultados[i] == 0)
            {
                printf("\nError: No se puede calcular el factorial de numeros negativos ni numeros decimales");
            }
            else if(resultados[i] == -1)
            {
                printf("\nEl numero ingresado es muy grande para realizar este calculo. Este programa soporta hasta el numero inclusive");
            }
            else
            {
               printf("\nEl resultado del factorial de A es: %.2f\n",(double)resultados[i]);
            }
            break;
        case 5:
            if(resultados[i] == 0)
            {
                printf("Error: No se puede calcular el factorial de numeros negativos ni numeros decimales");
            }
            else if(resultados[i] == -1)
            {
                printf("El numero ingresado es muy grande para realizar este calculo. Este programa soporta hasta el numero inclusive");
            }
            else
            {
                printf("El resultado del factorial de B es: %.2f\n",(double)resultados[i]);
            }
            break;
        }
    }
}
