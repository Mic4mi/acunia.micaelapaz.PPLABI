#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "eColor.h"


int imprimirColores(eColor* colores, int tam)
{
    int error = -1;
    if(colores != NULL && tam > 0)
    {
        printf("++++++++++++++++++++++++++++++++++++++++++\n");
        printf("                COLORES\n"                   );
        printf("------------------------------------------\n");
        printf("   ID                  NOMBRE COLOR        \n");
        printf("++++++++++++++++++++++++++++++++++++++++++\n");
        for(int i = 0; i < tam; i++)
        {
            mostrarColor(colores[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

void mostrarColor(eColor color)
{
    printf("  %d    %20s\n", color.id, color.nombreColor);
}

int encontrarColorPorID(eColor* lista, int tam, int id)
{
    int indiceId = -1;
    if(lista != NULL && tam > 0 && tam <= 100)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == id)
            {
                indiceId = lista[i].id;
                break;
            }
        }
    }
    return indiceId;
}

int cargarNombre(eColor* lista, int tam, int ID, char* nombre)
{
    int error = -1;

    if(lista != NULL && nombre != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == ID)
            {
                strcpy(nombre, lista[i].nombreColor);
                error = 0;
                break;
            }
        }
    }

    return error;
}
