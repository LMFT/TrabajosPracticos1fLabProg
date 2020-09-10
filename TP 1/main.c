/*******************************************************************
*Programa: Trabajo Practico 1: Calculadora
*
*Objetivo: Ingresar 2 numeros, realizar operacion de suma, resta, producto, division y factorial
 entre ambos numeros y mostrar los resultados al usuario. Realizar estas tareas hasta que el usuario decida salir


*
*Version:1.0 (09/09/2020)
*Autor:Lucas Ferrini
*
********************************************************************/
//Bibliotecas Oficiales
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Bibliotecas personalizadas
#include "Aritmeticas.h"
#include "Entrada y verificacion.h"
#include "Salida.h"
#include "Funcionalidades.h"

#define T 6 // Cantidad de resultados a guardar(suma, resta, producto, division y 2 factoriales)


int main()
{

    //Inputs
    float numero1;
    float numero2;
    int opcion;


    //Outputs
    long double resultados[T];

    //Flags
    int flag;

    //Inicializo las variables para mostrarlas en el menu y futuro uso en el programa
    numero1 = 0;
    numero2 = 0;
    flag = 0;

    do
    {
    opcion = menu(numero1, numero2);
    flag = verificarPrimerIngreso(flag, opcion);

    if(flag == 0)
    {
        continue;
    }

    switch(opcion)
    {
        case 1:
            printf("Ingrese el primer numero: ");
            numero1 = pedirNumeroFlotante();
            break;
        case 2:
            printf("Ingrese el segundo numero: ");
            numero2 = pedirNumeroFlotante();
            break;
        case 3:
            hacerOperaciones(resultados, T, numero1, numero2);
            break;
        case 4:
            mostrarResultados(resultados, T, numero2);
            break;
        case 5:
            break;
        default:
            printf("\nLa opcion ingresada no es valida.\n");

    }
    }while(opcion != 5);
    return 0;
}
