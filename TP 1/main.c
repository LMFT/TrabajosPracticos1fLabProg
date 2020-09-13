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
    int flagNumero1;
    int flagNumero2;
    int flagOperaciones;
    int verificacion;

    //Inicializo variables
    inicializarResultados(resultados, R);
    flagNumero1 = 0;
    flagNumero2 = 0;
    flagOperaciones = 0;

    do
    {
        system("cls");
        // Cargo el menu de opciones y recibo la respuesta del usuario por retorno
        opcion = menu(numero1, numero2, flagNumero1, flagNumero2);

        //Verifico si el usuario ya ingresó datos previamente
        verificacion = verificarPrimerIngreso(opcion,flagNumero1,flagNumero2);
        //Si la verificacion retorna 0, muestra un mensaje de error y vuelve al menu
        if(!(verificacion == 1))
        {
            system("pause");
            continue;
        }
        if(flagOperaciones == 0 && opcion == 4)
        {
            printf("\nDebe realizar los calculos antes de mostrar los resultados\n");
            system("pause");
            continue;
        }

        // Se ejecuta la opcion ingresada por el usuario
        switch(opcion)
        {
            case 1:
                printf("\nIngrese un numero: ");
                flagNumero1 = 1;
                numero1 = pedirNumeroFlotante();
                break;
            case 2:
                flagNumero2 = 1;
                printf("\nIngrese un numero: ");
                numero2 = pedirNumeroFlotante();
                break;
            case 3:
                flagOperaciones = hacerOperaciones(resultados, R, numero1, numero2);
                break;
            case 4:
                mostrarResultados(resultados, R, numero2);
                system("pause");
                break;
            case 5:
                break;
            default:
                printf("\nLa opcion ingresada no es valida.\n");
        }
    }while(opcion != 5);
    return 0;
}
