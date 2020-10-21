#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "eCliente.h"
#include "validaciones.h"
#include "dataStore.h"

int clientes_inicializar(eCliente* lista, int tam)
{
    if(lista != NULL && tam > 0 && tam <= 100)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].estaVacio = 1;
        }
        return 0;
    }

    return -1;
}

int clientes_buscarPorID(eCliente* lista, int tam, int id)
{
    int indiceId = -1;
    if(lista != NULL && tam > 0 && tam <= 1000)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == id && lista[i].estaVacio == 0)
            {
                indiceId = i;
                break;
            }
        }
    }
    return indiceId;
}

int clientes_hardcodear(eCliente* lista, int tam, int numeroDeClientes)
{
    int returns = -1;
    if(
        lista != NULL &&
        tam > 0 &&
        numeroDeClientes > 0 &&
        numeroDeClientes < tam)
    {
        for(int i = 0; i < numeroDeClientes; i++)
        {
            if(lista[i].estaVacio == 1)
            {
                lista[i].estaVacio = 0;
                lista[i].id = idClientes[i];
                strcpy(lista[i].nombre, clientesNombre[i]);
                lista[i].sexo = clientesGenero[i];
                returns++;
            }
        }
    }

    return returns;
}

int clientes_imprimirLista(eCliente* lista, int tam)
{
    if(lista != NULL && tam > 0 && tam <= 100)
    {
        printf("_________________________________________________\n");
        printf("                  CLIENTES      \n");
        printf("_________________________________________________\n");
        printf("  ID            NOMBRE                  SEXO  \n");
        printf("_________________________________________________\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].estaVacio != 1)
            {
                clientes_imprimirItem(lista[i]);
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

void clientes_imprimirItem(eCliente cliente)
{

    printf("%5d %20s               %c\n",
           cliente.id,
           cliente.nombre,
           cliente.sexo
          );
}

int clientes_cargarNombre(eCliente* lista, int tam, int ID, char* nombre)
{
    int error = -1;

    if(lista != NULL && nombre != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == ID)
            {
                strcpy(nombre, lista[i].nombre);
                error = 0;
                break;
            }
        }
    }

    return error;
}
