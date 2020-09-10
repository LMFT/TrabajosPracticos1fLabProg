#include <stdio.h>

//Suma dos numeros
long double sumarDosNumeros (float numero1, float numero2)
{
   long double suma;

   suma = numero1 + numero2;


   return suma;

}
//Resta 2 numeros
long double restarDosNumeros (float numero1, float numero2)
{
    long double resta;
    resta = numero1 - numero2;


    return resta;
}
// Multiplica 2 numeros
long double multiplicarDosNumeros (float numero1, float numero2)
{
    long double producto;
    producto = numero1 * numero2;


    return producto;
}
//Divide dos numeros
long double dividirDosNumeros (float numero1, float numero2)
{
    long double division;

    if(numero2 == 0)
    {
        division = 0;
    }
    else
    {
    division = numero1 / numero2;
    }
    return division;
}

//Calcula el factorial de un número

long double  factorialNumero(float numero)
{
    long double  resultado;
    int comparacion;

    resultado = 1;
    comparacion = numero;

    if(numero <0 || comparacion != numero)
    {
        return 0;
    }
   /* if(numero > 12)
    {
        return -1;
    }*/
    while(numero > 1)
    {
    resultado*=numero;
    numero--;
    }
    return resultado;
}
