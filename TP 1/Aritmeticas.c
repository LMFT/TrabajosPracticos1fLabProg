#include <stdio.h>

//Suma dos numeros
float sumarDosNumeros (float numero1, float numero2)
{
   float suma;

   suma = numero1 + numero2;


   return suma;

}
//Resta 2 numeros
float restarDosNumeros (float numero1, float numero2)
{
    float resta;
    resta = numero1 - numero2;


    return resta;
}
// Multiplica 2 numeros
float multiplicarDosNumeros (float numero1, float numero2)
{
    float producto;
    producto = numero1 * numero2;


    return producto;
}
//Divide dos numeros
float dividirDosNumeros (float numero1, float numero2)
{
    float division;

    division = numero1 / numero2;
    return division;
}

//Calcula el factorial de un número

long int  factorialNumero(float numero)
{
    long int  resultado;

    resultado = 1;

    while(numero >1)
    {
    resultado*=numero;
    numero--;
    }
    return resultado;
}
