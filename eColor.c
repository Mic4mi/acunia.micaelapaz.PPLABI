#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "eColor.h"


int showColores(eColor* colores, int len)
{
    int error = -1;
    if(colores != NULL && len > 0)
    {
        printf("++++++++++++++++++++++++++++++++++++++++++\n");
        printf("                COLORES\n"                   );
        printf("------------------------------------------\n");
        printf("   ID                  NOMBRE COLOR        \n");
        printf("++++++++++++++++++++++++++++++++++++++++++\n");
        for(int i = 0; i < len; i++)
        {
            //showBreed(breeds[i]);
            showColor(colores[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

void showColor(eColor color)
{
    printf("  %d    %20s\n", color.id, color.nombreColor);
}

int findColorById(eColor* list, int len, int id)
{
    int indiceId = -1;
    if(list != NULL && len > 0 && len <= 100)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id)
            {
                indiceId = list[i].id;
                break;
            }
        }
    }
    return indiceId;
}

int cargarNombre(eColor* lista, int len, int ID, char* nombre)
{
    int error = -1;

    if(lista != NULL && nombre != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
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
