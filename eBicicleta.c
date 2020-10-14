#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dataStore.h"
#include "eTipo.h"
#include "eColor.h"
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
int printBicis(eBicicleta* list, int len, eTipo* tipos, int lenTipos, eColor* colores, int lenColores)
{
    if(list != NULL && len > 0 && len <= 100 && tipos != NULL && lenTipos > 0 && colores != NULL && lenColores > 0)
    {
        //system("cls");
        printf("*********************************************************************************************************\n");
        printf("                                                BICLETAS      \n");
        printf("*********************************************************************************************************\n");
        printf("  ID            MARCA                      TIPO                     COLOR                    RODADO      \n");
        printf("*********************************************************************************************************\n");
        for(int i = 0; i < len; i++)
        {
            if(list[i].estaVacio != 1)
            {
                showBici(list[i], tipos, lenTipos, colores, lenColores);
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

void showBici(eBicicleta bici, eTipo* tipos, int lenTipos, eColor* colores, int lenColores)
{
    char descTipo[30];
    char descColor[30];

    cargarDescTipo(tipos, lenTipos, bici.idTipo, descTipo);

    for(int i = 0; i < lenColores; i++)
    {
        if(colores[i].id == bici.idColor)
        {
            strcpy(descColor, colores[i].nombreColor);
        }
    }

    printf("%5d %15s           %15s           %15s                    %4.2f\n",
           bici.id,
           bici.marca,
           descTipo,
           descColor,
           bici.rodado
          );
}


//ALTA
int addBici(eBicicleta* list, int len, int ID, eTipo* listaTipos, int lenTipos, eColor* listaColores, int lenColores)
{
    eBicicleta newBici;
    int tipoID;
    int tipoIDValido;
    int colorID;
    int colorIDValido;
    if(list != NULL && len > 0 && len <= 100 && listaTipos != NULL && lenTipos > 0 && listaColores != NULL && lenColores > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].estaVacio == 1)
            {
                newBici.estaVacio = 0;
                newBici.id = ID;
                //marca
                printf("\nIngrese marca: ");
                fflush(stdin);
                gets(newBici.marca);
                formatName(newBici.marca);
                while(strlen(newBici.marca) > 30)
                {
                    printf("\nDato invalido. Ingrese marca: ");
                    fflush(stdin);
                    gets(newBici.marca);
                    formatName(newBici.marca);
                }
                //tipo
                showTipos(listaTipos, lenTipos);
                printf("\nIngrese ID tipo: ");
                fflush(stdin);
                scanf("%d", &tipoID);
                tipoIDValido = findTipoById(listaTipos, lenTipos, tipoID);
                while( tipoIDValido < 0)
                {
                    printf("\nDato invalido. Ingrese ID tipo: ");
                    fflush(stdin);
                    scanf("%d", &tipoID);
                    tipoIDValido = findTipoById(listaTipos, lenTipos, tipoID);
                }
                //color
                showColores(listaColores, lenColores);
                printf("\nIngrese ID color: ");
                fflush(stdin);
                scanf("%d", &colorID);
                colorIDValido = findColorById(listaColores, lenColores, colorID);
                while( colorIDValido < 0)
                {
                    printf("\nDato invalido. Ingrese ID color: ");
                    fflush(stdin);
                    scanf("%d", &colorID);
                    colorIDValido = findColorById(listaColores, lenColores, colorID);
                }
                //rodado
                printf("\nIngrese rodado: ");
                fflush(stdin);
                scanf("%f", &newBici.rodado);

                list[i] = newBici;
                return 0;
            }
        }
        printf("\nNo hay lugar para otra bicicleta...\n");
    }

    return -1;
}


//validacion, mover a otra biblioteca
void formatName(char* name)
{

    int len;
    strlwr(name);
    name[0] = toupper(name[0]);
    len = strlen(name);
    for(int i = 0; i < len; i++)
    {
        if(name[i] == ' ')
        {
            i++;
            if(name[i] >= 'a' && name[i] <= 'z')
            {
                name[i] = toupper(name[i]);
            }
        }
    }
}
