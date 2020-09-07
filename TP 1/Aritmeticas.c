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

    while(numero2 == 0)
    {
        printf("\nNo se puede dividir por cero. Ingrese otro numero\n");
        scanf("%f", &numero2);
    }
    division = numero1 / numero2;
    return division;
}

//Calcula el factorial de un número

long int factorialNumero(float numero)
{
    long int resultado;
    int comparacion;

    //Resultado inicializada con la respuesta por defecto y para uso en futuros productos
    resultado = 1;
    //Para verificar que el numero ingresado sea entero
    comparacion = numero;


    while(numero < 0 || numero != comparacion)
    {
        printf("El factorial solo admite enteros positivos. Reingrese el numero\n");
        scanf("%f", &numero);
        comparacion = numero;
    }

    //El valor por defecto del resultado es 1, si el numero ingresado es mayor se reemplaza el valor del resultado

    while(numero >1)
    {
    resultado*=numero;
    numero--;
    }
    return resultado;
}
