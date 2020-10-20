#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "eTipo.h"

int tipos_imprimirLista(eTipo* tipos, int tam)
{
    int error = -1;
    if(tipos != NULL && tam > 0)
    {
        printf("___________________________________________\n");
        printf("                 TIPOS \n"                      );
        printf("___________________________________________\n");
        printf("   ID                  DESCRIPCION        \n");
        printf("___________________________________________\n");
        for(int i = 0; i < tam; i++)
        {
            tipos_imprimirItem(tipos[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

void tipos_imprimirItem(eTipo tipo)
{
    printf("  %d    %20s\n", tipo.id, tipo.descripcion);
}

//Buscar
int tipos_encontrarPorID(eTipo* lista, int tam, int id)
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

int tipos_cargarDesc(eTipo* lista, int tam, int ID, char* descripcion)
{
    int error = -1;

    if(lista != NULL && descripcion != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == ID)
            {
                strcpy(descripcion, lista[i].descripcion);
                error = 0;
                break;
            }
        }
    }

    return error;
}

