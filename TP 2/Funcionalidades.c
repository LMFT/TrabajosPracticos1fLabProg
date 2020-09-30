#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EntradaVerificacion.h"
#include "Funcionalidades.h"

void InitializeArrayFloat(float string[], int cant)
{

    int i;

    for(i = 0; i<cant; i++)
    {
        string[i] = 0;
    }
}

void InitializeArrayInt(int string[], int cant)
{

    int i;

    for(i = 0; i<cant; i++)
    {
        string[i] = 0;
    }
}

void InitializeArrayString(char string[][20], int cant)
{

    int i;

    for(i = 0; i<cant; i++)
    {
        strcpy(string[i], " ");
    }
}

void ArrangeArraysMax(int legajos[], float sueldos[],char nombres[][20], int cant, int option)
{
    int i;
    int j;
    int auxInt;
    float auxFloat;
    char auxString [100];

    if(option == 1) //Legajos
    {
        for(i=0; i<cant-1; i++)//NARANJA
        {
            for(j=i+1; j<cant; j++)//AZUL
            {
                if(legajos[i]<legajos[j])//criterio de ordenamiento
                {
                    auxInt = legajos[i];
                    legajos[i] = legajos[j];
                    legajos[j] = auxInt;

                    auxFloat = sueldos[i];
                    sueldos[i] = sueldos[j];
                    sueldos[j] = auxFloat;

                    strcpy(auxString,nombres[i]);
                    strcpy(nombres[i], nombres[j]);
                    strcpy(nombres[j],auxString);
                }
            }
        }
    }
    else //Sueldos
    {
        for(i=0; i<cant-1; i++)//NARANJA
        {
            for(j=i+1; j<cant; j++)//AZUL
            {
                if(sueldos[i]<sueldos[j])//criterio de ordenamiento
                {
                    auxInt = legajos[i];
                    legajos[i] = legajos[j];
                    legajos[j] = auxInt;

                    auxFloat = sueldos[i];
                    sueldos[i] = sueldos[j];
                    sueldos[j] = auxFloat;

                    strcpy(auxString,nombres[i]);
                    strcpy(nombres[i], nombres[j]);
                    strcpy(nombres[j],auxString);
                }
            }
        }
    }
}


void ArrangeArraysMin(int legajos[], float sueldos[],char nombres[][20], int cant, int option)
{
    int i;
    int j;
    int auxInt;
    float auxFloat;
    char auxString [100];

    if(option == 1) //Legajos
    {
        for(i=0; i<cant-1; i++)//NARANJA
        {
            for(j=i+1; j<cant; j++)//AZUL
            {
                if(legajos[i]>legajos[j])//criterio de ordenamiento
                {
                    auxInt = legajos[i];
                    legajos[i] = legajos[j];
                    legajos[j] = auxInt;

                    auxFloat = sueldos[i];
                    sueldos[i] = sueldos[j];
                    sueldos[j] = auxFloat;

                    strcpy(auxString,nombres[i]);
                    strcpy(nombres[i], nombres[j]);
                    strcpy(nombres[j],auxString);
                }
            }
        }
    }
    else //Sueldos
    {
        for(i=0; i<cant-1; i++)//NARANJA
        {
            for(j=i+1; j<cant; j++)//AZUL
            {
                if(sueldos[i]>sueldos[j])//criterio de ordenamiento
                {
                    auxInt = legajos[i];
                    legajos[i] = legajos[j];
                    legajos[j] = auxInt;

                    auxFloat = sueldos[i];
                    sueldos[i] = sueldos[j];
                    sueldos[j] = auxFloat;

                    strcpy(auxString,nombres[i]);
                    strcpy(nombres[i], nombres[j]);
                    strcpy(nombres[j],auxString);
                }
            }
        }
    }
}


void ArrangeArraysAlphabetical(int legajos[], float sueldos[],char nombres[][20], int cant, int option)
{
    int i;
    int j;
    int auxInt;
    float auxFloat;
    char auxString [100];

    if(option == 1) //Alfabetico Ascendente
    for(i=0; i<cant-1; i++)//NARANJA
    {
        for(j=i+1; j<cant; j++)//AZUL
        {
            if((strcmp(nombres[i], nombres[j]) > 0))//criterio de ordenamiento
            {
                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxFloat = sueldos[i];
                sueldos[i] = sueldos[j];
                sueldos[j] = auxFloat;

                strcpy(auxString,nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j],auxString);


            }
        }
    }
    else //Alfabetico Descendente
    {
        for(i=0; i<cant-1; i++)//NARANJA
        {
            for(j=i+1; j<cant; j++)//AZUL
            {
                if((strcmp(nombres[i], nombres[j]) < 0))//criterio de ordenamiento
                {
                    auxInt = legajos[i];
                    legajos[i] = legajos[j];
                    legajos[j] = auxInt;

                    auxFloat = sueldos[i];
                    sueldos[i] = sueldos[j];
                    sueldos[j] = auxFloat;

                    strcpy(auxString,nombres[i]);
                    strcpy(nombres[i], nombres[j]);
                    strcpy(nombres[j],auxString);


                }
            }

        }
    }
}

char AnotherInput()
{
    char respuesta;

    printf("\nDesea realizar otro ingreso? s/n : ");
    respuesta = InputChar();

    return respuesta;
}

int menu()
{
    int opcion; // Compara el valor de la variable opcion contra su contraparte entera para eliminar casos de error

    printf("\n __________________________________________");
    printf("\n|        Base de datos de empleados        |");
    printf("\n|__________________________________________|\n\n");
    printf("\n*** MENU PRINCIPAL ***\n\n");
    printf("1- Alta de empleados\n");
    printf("2- Modificar datos de empleados\n");
    printf("3- Baja de empleados\n");
    printf("4- Mostrar empleados\n");
    printf("5- Salir\n\n");
    printf("Ingrese una opcion: ");

    opcion = pedirNumeroEntero();
    fflush(stdin);
    return opcion;
}

int Confirmation()
{
    int respuestaI;
    char respuestaC;

    respuestaI = 0;

    printf("\nDesea confrimar la operacion? s/n: ");
    respuestaC = InputChar();

    if(respuestaC == 's' || respuestaC == 'S')
    {
        respuestaI = 1;
    }
    return respuestaI;
}



