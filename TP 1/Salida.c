#include <stdio.h>


void mostrarResultados(long double resultados[], int cant, float numero2)
{
    int i;

    for(i=0; i<cant; i++)
    {
        switch(i)
        {
        case 0:
            printf(" El resultado de la suma es: %.2f\n",(double)resultados[i]);

            break;
        case 1:
            printf("El resultado de la resta es: %.2f\n",(double)resultados[i]);
            break;
        case 2:
            printf("El resultado del producto es: %.2f\n",(double)resultados[i]);
            break;
        case 3:
            //En caso de que el retorno haya sido 0, se verifica si numero2 es igual a 0 para determinar si se trata
            // de una division válida o una division por 0 (el calculo de la division retorna 0 al dividir por 0)
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
                printf("\nError: No se puede calcular el factorial de A: no es posible calcular el factorial");
                printf(" numeros negativos ni decimales\n");
            }
            else
            {
               printf("\nEl resultado del factorial de A es: %.2f\n",(double)resultados[i]);
            }
            break;
        case 5:
            if(resultados[i] == 0)
            {
                printf("\nError: No se puede calcular el factorial de B: no es posible calcular el factorial");
                printf(" numeros negativos ni decimales\n");
            }
            else
            {
                printf("El resultado del factorial de B es: %.2f\n",(double)resultados[i]);
            }
            break;
        }
    }
}
