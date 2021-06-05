#include "Ui.h"

int Ui_CreateMenu(char header[],char inputMsg[], int amountOfOptions, ...)
{
    int selectedOption = 0;
    int i;
    va_list options;

    if(header != NULL && inputMsg != NULL && amountOfOptions >0)
    {
        va_start(options, amountOfOptions);
        printf("\n%s", header);
        for(i=1;i<=amountOfOptions;i++)
        {
            printf("\n%d- %s", i, va_arg(options, char*));
        }
        Input_IntInRange(&selectedOption, inputMsg, 1, i-1, "Opcion invalida");
    }

    return selectedOption;
}
