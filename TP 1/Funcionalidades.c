#include "Aritmeticas.h"

int hacerOperaciones(long double resultados[], int cant, float numero1, float numero2)
{

    int i;

    for(i=0; i < cant; i++)
    {
        switch(i)
        {
        case 0:
            resultados[i] = sumarDosNumeros(numero1, numero2);
            break;
        case 1:
            resultados[i] = restarDosNumeros(numero1, numero2);
            break;
        case 2:
            resultados[i] = multiplicarDosNumeros(numero1, numero2);
            break;
        case 3:
            resultados[i] = dividirDosNumeros(numero1, numero2);
            break;
        case 4:
            resultados[i] = factorialNumero(numero1);
            break;
        case 5:
            resultados[i] = factorialNumero(numero2);
            break;

        }
    }
    return 1;
}

void inicializarResultados(float string[], int cant)
{

    int i;

    for(i = 0; i<cant; i++)
    {
        string[i] = 0;
    }
}

