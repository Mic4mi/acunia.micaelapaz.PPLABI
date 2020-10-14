#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dataStore.h"
#include "eBicicleta.h"


int getOption(int* pResult, char* errorMsj, int min, int max)
{
    int error = -1;
    int opcion;
    int validate;
    if(pResult != NULL && errorMsj != NULL && min <= max)
    {
        do
        {
            printf("\nIngrese opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
            validate = isdigit(opcion);
            if((opcion >= min && opcion <= max) && !validate)
            {
                *pResult = opcion;
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

void menu()
{
    system("cls");
    printf("********************************************************************************************************\n");
    printf("                                               PARCIAL 1          \n");
    printf("********************************************************************************************************\n");
    printf("                                          SISTEMA BICICLETERIA                    \n");
    printf("********************************************************************************************************\n");
    printf("1. ALTA BICICLETA\n");
    printf("2. MODIFICAR BICICLETA\n");
    printf("3. BAJA BICICLETA\n");
    printf("4. LISTAR BICICLETAS\n");
    printf("5. LISTAR COLORES\n");
    printf("6. LISTAR TIPOS\n");
    printf("7. LISTAR SERVICIOS\n");
    printf("8. ALTA TRABAJO\n");
    printf("9. LISTAR TRABAJOS\n");
    printf("10. SALIR\n");
}

//Inicializar bicis
int initBicis(eBicicleta* list, int len)
{
    if(list != NULL && len > 0 && len <= 100)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].estaVacio = 1;
        }
        return 0;
    }

    return -1;
}

//Buscar bici por id
int findBiciById(eBicicleta* list, int len,int id)
{
    int indiceId = -1;
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id && list[i].estaVacio == 0)
            {
                indiceId = i;
                break;
            }
        }
    }
    return indiceId;
}


// harcodeo
int hardcodeBicis(eBicicleta* list, int len, int numberOfBicis)
{
    int returns = -1;
    if(list != NULL && len > 0 && numberOfBicis > 0 && numberOfBicis < len)
    {
        for(int i = 0; i < numberOfBicis; i++)
        {
            if(list[i].estaVacio == 1)
            {
                list[i].estaVacio = 0;
                list[i].id = idBicis[i];
                strcpy(list[i].marca, marcas[i]);
                list[i].idTipo = idTipos[i];
                list[i].idColor = idColores[i];
                list[i].rodado = rodados[i];
                returns++;
            }
        }
    }

    return returns; //retorna -1 si hubo un error, sino un entero indicando la cantidad de mascotas que cargó
}


//imprimir
