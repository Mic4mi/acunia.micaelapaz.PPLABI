#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "eColor.h"


int colores_imprimirLista(eColor* colores, int tam)
{
    int error = -1;
    if(colores != NULL && tam > 0)
    {
        printf("___________________________________________\n");
        printf("                 COLORES\n"                   );
        printf("___________________________________________\n");
        printf("   ID                  NOMBRE COLOR        \n");
        printf("___________________________________________\n");
        for(int i = 0; i < tam; i++)
        {
            colores_imprimirItem(colores[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

void colores_imprimirItem(eColor color)
{
    printf("  %d    %20s\n", color.id, color.nombreColor);
}

int colores_buscarPorID(eColor* lista, int tam, int id)
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

int colores_cargarNombre(
    eColor* lista,
    int tam,
    int ID,
    char* nombre
)
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
