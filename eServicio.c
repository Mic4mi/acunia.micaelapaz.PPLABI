#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "eServicio.h"

int showServicios(eServicio* servicios, int len)
{
    int error = -1;
    if(servicios != NULL && len > 0)
    {
        printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("                   SERVICIOS \n"                   );
        printf("------------------------------------------------\n");
        printf("   ID            DESCRIPCION           PRECIO\n");
        printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");
        for(int i = 0; i < len; i++)
        {
            showServicio(servicios[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

void showServicio(eServicio servicio)
{
    printf("  %d    %15s            $%4.2f\n", servicio.id, servicio.descripcion, servicio.precio);
}

int findServicioById(eServicio* list, int len, int id)
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

int cargarDescServ(eServicio* lista, int len, int ID, char* descripcion)
{
    int error = -1;

    if(lista != NULL && descripcion != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
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
