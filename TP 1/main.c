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

#define R 6 // Cantidad de resultados a guardar(suma, resta, producto, division y 2 factoriales)



int main()
{

    //Inputs
    float numero1;
    float numero2;
    int opcion;


    //Outputs
    long double resultados[R];

    //Variables de uso interno
    int flag1;
    int flag2;
    int verificacion;

    //Inicializo flags y string de resultados
    inicializarResultados(resultados, R);
    flag1 = 0;
    flag2 = 0;

    do
    {
        // Cargo el menu de opciones y recibo la respuesta del usuario
        opcion = menu(numero1, numero2, flag1, flag2);

        //Verifico si el usuario ya ingresó datos previamente
        verificacion = verificarPrimerIngreso(opcion,flag1,flag2);
        //Si la verificacion retorna 0, muestra un mensaje de error y vuelve al menu
        if(verificacion == 0)
        {
            continue;
        }

        // Se ejecuta la opcion ingresada por el usuario
        switch(opcion)
        {
            case 1:
                flag1 = 1;
                printf("Ingrese el primer numero: ");
                numero1 = pedirNumeroFlotante();
                break;
            case 2:
                flag2 = 1;
                printf("Ingrese el segundo numero: ");
                numero2 = pedirNumeroFlotante();
                break;
            case 3:
                hacerOperaciones(resultados, R, numero1, numero2);
                break;
            case 4:
                mostrarResultados(resultados, R, numero2);
                break;
            case 5:
                break;
            default:
                printf("\nLa opcion ingresada no es valida.\n");

        }
    }while(opcion != 5);
    return 0;
}
