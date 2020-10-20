#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"


int validaciones_obtenerOpcion(int* pResultado, char* errorMsj, int min, int max)
{
    int error = -1;
    int opcion;
    int validate;
    if(pResultado != NULL && errorMsj != NULL && min <= max)
    {
        do
        {
            printf("\nIngrese opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
            validate = isdigit(opcion);
            if((opcion >= min && opcion <= max) && !validate)
            {
                *pResultado = opcion;
                error = 0;
            }
            else
            {
                printf("%s\n", errorMsj);
                system("pause");
            }
        }
        while(error != 0);
    }
    return error;
}


void validaciones_formatearCadena(char* cadena)
{
    int tam;
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]);
    tam = strlen(cadena);
    for(int i = 0; i < tam; i++)
    {
        if(cadena[i] == ' ')
        {
            i++;
            if(cadena[i] >= 'a' && cadena[i] <= 'z')
            {
                cadena[i] = toupper(cadena[i]);
            }
        }
    }
}
