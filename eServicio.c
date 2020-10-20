#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "eServicio.h"

int imprimirServicios(eServicio* servicios, int tam)
{
    int error = -1;
    if(servicios != NULL && tam > 0)
    {
        printf("_________________________________________________\n");
        printf("                   SERVICIOS \n"                   );
        printf("_________________________________________________\n");
        printf("   ID            DESCRIPCION           PRECIO\n");
        printf("_________________________________________________\n");
        for(int i = 0; i < tam; i++)
        {
            mostrarServicio(servicios[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

void mostrarServicio(eServicio servicio)
{
    printf("  %d    %15s            $%4.2f\n", servicio.id, servicio.descripcion, servicio.precio);
}

int econtrarServicioPorID(eServicio* lista, int tam, int id)
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

int cargarDescServ(eServicio* lista, int tam, int ID, char* descripcion)
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
