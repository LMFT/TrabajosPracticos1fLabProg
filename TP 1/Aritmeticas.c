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

    //Si el segundo numero es 0 se devuelve 0 como valor, se compara este retorno junto al valor de numero2
    //para determinar si la division es válida
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

    //Inicializo resultado en 1 como valor predeterminado (factorial de 0 o 1)
    resultado = 1;
    //Al asignar un numero flotante a un valor entero, elimino la parte decimal sin modificar el valor original. De esta forma
    // puedo analizar si el numero ingresado es decimal o entero
    comparacion = numero;

    //Si el numero del usuario es decimal o entero la funcion retorna 0 y devuelve un mensaje de error
    if(numero <0 || comparacion != numero)
    {
        return 0;
    }

    while(numero > 1)
    {
    resultado*=numero;
    numero--;
    }
    return resultado;
}
