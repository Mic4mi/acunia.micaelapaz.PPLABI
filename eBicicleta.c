#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dataStore.h"
#include "eTipo.h"
#include "eColor.h"
#include "eBicicleta.h"
#include "validaciones.h"


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
int iniciarBicicletas(eBicicleta* lista, int tam)
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

int encontrarBicicletaPorID(eBicicleta* lista, int tam, int id)
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


// harcodeo
int hardcodearBicicletas(eBicicleta* lista, int tam, int numberoDeBicis)
{
    int returns = -1;
    if(lista != NULL && tam > 0 && numberoDeBicis > 0 && numberoDeBicis < tam)
    {
        for(int i = 0; i < numberoDeBicis; i++)
        {
            if(lista[i].estaVacio == 1)
            {
                lista[i].estaVacio = 0;
                lista[i].id = idBicis[i];
                strcpy(lista[i].marca, marcas[i]);
                lista[i].idTipo = idTipos[i];
                lista[i].idColor = idColores[i];
                lista[i].rodado = rodados[i];
                returns++;
            }
        }
    }

    return returns; //retorna -1 si hubo un error, sino un entero indicando la cantidad de bicicletas que cargó
}


//imprimir
int imprimirBicicletas(eBicicleta* lista, int tam, eTipo* tipos, int tamTipos, eColor* colores, int tamColores)
{
    if(lista != NULL && tam > 0 && tam <= 100 && tipos != NULL && tamTipos> 0 && colores != NULL && tamColores > 0)
    {
        //system("cls");
        printf("*********************************************************************************************************\n");
        printf("                                                BICLETAS      \n");
        printf("*********************************************************************************************************\n");
        printf("  ID            MARCA                      TIPO                     COLOR                    RODADO      \n");
        printf("*********************************************************************************************************\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].estaVacio != 1)
            {
                mostrarBicicleta(lista[i], tipos, tamTipos, colores, tamColores);
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

void mostrarBicicleta(eBicicleta bici, eTipo* tipos, int tamTipos, eColor* colores, int tamColores)
{
    char descTipo[30];
    char descColor[30];

    cargarDescTipo(tipos, tamTipos, bici.idTipo, descTipo);

    cargarNombre(colores, tamColores, bici.idColor, descColor);

    printf("%5d %15s           %15s           %15s                    %4.2f\n",
           bici.id,
           bici.marca,
           descTipo,
           descColor,
           bici.rodado
          );
}


//ALTA
int agregarBicicleta(eBicicleta* lista, int tam, int ID, eTipo* listaTipos, int tamTipos, eColor* listaColores, int tamColores)
{
    eBicicleta nuevaBici;
    int tipoIDValido;
    int colorIDValido;
    if(lista != NULL && tam > 0 && tam <= 100 && listaTipos != NULL && tamTipos > 0 && listaColores != NULL && tamColores > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].estaVacio == 1)
            {
                nuevaBici.estaVacio = 0;
                nuevaBici.id = ID;
                //marca
                printf("\nIngrese marca: ");
                fflush(stdin);
                gets(nuevaBici.marca);
                formatearCadena(nuevaBici.marca);
                while(strlen(nuevaBici.marca) > 30)
                {
                    printf("\nDato invalido. Ingrese marca: ");
                    fflush(stdin);
                    gets(nuevaBici.marca);
                    formatearCadena(nuevaBici.marca);
                }
                //tipo
                imprimirTipos(listaTipos, tamTipos);
                printf("\nIngrese ID tipo: ");
                fflush(stdin);
                scanf("%d", &nuevaBici.idTipo);
                tipoIDValido = encontrarTipoPorID(listaTipos, tamTipos, nuevaBici.idTipo);
                while( tipoIDValido < 0)
                {
                    printf("\nDato invalido. Ingrese ID tipo: ");
                    fflush(stdin);
                    scanf("%d", &nuevaBici.idTipo);
                    tipoIDValido = encontrarTipoPorID(listaTipos, tamTipos, nuevaBici.idTipo);
                }
                //color
                imprimirColores(listaColores, tamColores);
                printf("\nIngrese ID color: ");
                fflush(stdin);
                scanf("%d", &nuevaBici.idColor);
                colorIDValido = encontrarColorPorID(listaColores, tamColores, nuevaBici.idColor);
                while( colorIDValido < 0)
                {
                    printf("\nDato invalido. Ingrese ID color: ");
                    fflush(stdin);
                    scanf("%d", &nuevaBici.idColor);
                    colorIDValido = encontrarColorPorID(listaColores, tamColores, nuevaBici.idColor);
                }
                //rodado
                printf("\nIngrese rodado: ");
                fflush(stdin);
                scanf("%f", &nuevaBici.rodado);
                while(nuevaBici.rodado != 20 && nuevaBici.rodado != 26 && nuevaBici.rodado != 27.5 && nuevaBici.rodado != 29)
                {
                    printf("\nDato Invalido. Ingrese rodado: ");
                    fflush(stdin);
                    scanf("%f", &nuevaBici.rodado);
                }

                lista[i] = nuevaBici;
                return 0;
            }
        }
        printf("\nNo hay lugar para otra bicicleta...\n");
    }

    return -1;
}

//modificacion
int modificarBicicleta(eBicicleta* lista, int tam, eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor)
{
    eBicicleta nuevaBici;
    int error = -1;
    int id;
    int index;
    int rst;
    int mOpcion;
    int tipoIDValido;
    char confirmacion;
    if(lista != NULL && tam > 0 && tam <= 100 && listaTipo != NULL && listaColor != NULL && tamTipo > 0 && tamColor > 0)
    {
        system("cls");
        printf("*********************************************************************************************************\n");
        printf("                                  BIENVENIDO AL MENU DE MODIFICACIONES                                  \n");
        imprimirBicicletas(lista, tam, listaTipo, tamTipo, listaColor, tamColor);
        printf("\nIngrese ID de la bicicleta a modificar: ");
        fflush(stdin);
        scanf("%d", &id);
        index = encontrarBicicletaPorID(lista, tam, id);
        if(index == -1)
        {
            system("cls");
            printf("*********************************************************************************************************\n");
            printf("                                  BIENVENIDO AL MENU DE MODIFICACIONES                                  \n");
            printf("*********************************************************************************************************\n");
            printf("\nLo sentimos. No hay bicicletas con ese ID...\n");
        }
        else
        {
            system("cls");
            printf("*********************************************************************************************************\n");
            printf("                                                BICLETAS      \n");
            printf("*********************************************************************************************************\n");
            printf("  ID            MARCA                      TIPO                     COLOR                    RODADO      \n");
            printf("*********************************************************************************************************\n");
            mostrarBicicleta(lista[index], listaTipo, tamTipo, listaColor, tamColor);
            printf("\nMODIFICAR:\n");
            printf("1. Tipo\n");
            printf("2. Rodado\n");
            rst = obtenerOpcion(&mOpcion, "\nOpcion invalida\n", 1, 2);
            if(!rst)
            {
                switch(mOpcion)
                {
                case 1:
                    //Pedir tipo
                    imprimirTipos(listaTipo, tamTipo);
                    printf("\nIngrese ID tipo: ");
                    fflush(stdin);
                    scanf("%d", &nuevaBici.idTipo);
                    tipoIDValido = encontrarTipoPorID(listaTipo, tamTipo, nuevaBici.idTipo);
                    while( tipoIDValido < 0)
                    {
                        printf("\nDato invalido. Ingrese ID tipo: ");
                        fflush(stdin);
                        scanf("%d", &nuevaBici.idTipo);
                        tipoIDValido = encontrarTipoPorID(listaTipo, tamTipo, nuevaBici.idTipo);
                    }
                    //pedir confirmacion
                    printf("\nConfirma modificacion? s-si n-no\n");
                    fflush(stdin);
                    scanf("%c", &confirmacion);
                    confirmacion = tolower(confirmacion);
                    while(confirmacion != 's' && confirmacion != 'n')
                    {
                        printf("\nOpcion invalida. \nConfirma modificacion? s-si n-no\n");
                        fflush(stdin);
                        scanf("%c", &confirmacion);
                        confirmacion = tolower(confirmacion);
                    }
                    if(confirmacion == 's')
                    {
                        lista[index].idTipo = nuevaBici.idTipo;
                        error = 0;
                    }
                    else
                    {
                        error = 1;
                    }
                    break;
                case 2:
                    //pedir rodado
                    printf("\nIngrese nuevo rodado: ");
                    fflush(stdin);
                    scanf("%f", &nuevaBici.rodado);
                    while(nuevaBici.rodado != 20 && nuevaBici.rodado != 26 && nuevaBici.rodado != 27.5 && nuevaBici.rodado != 29)
                    {
                        printf("\nDato Invalido. Ingrese nuevo rodado: ");
                        fflush(stdin);
                        scanf("%f", &nuevaBici.rodado);
                    }

                    printf("\nRodado anterior: %.2f", lista[index].rodado);
                    printf("\nRodado nuev0: %.2f", nuevaBici.rodado);
                    //confirmar modificacion
                    printf("\nConfirma modificacion? s-si n-no\n");
                    fflush(stdin);
                    scanf("%c", &confirmacion);
                    confirmacion = tolower(confirmacion);
                    while(confirmacion != 's' && confirmacion != 'n')
                    {
                        printf("\nOpcion invalida. \nConfirma modificacion? s-si n-no\n");
                        fflush(stdin);
                        scanf("%c", &confirmacion);
                        confirmacion = tolower(confirmacion);
                    }
                    if(confirmacion == 's')
                    {
                        lista[index].rodado = nuevaBici.rodado;
                        error = 0;
                    }
                    else
                    {
                        error = 1;
                    }
                    break;
                }
            }
        }
    }

    return error;
}

int eliminarBicicleta(eBicicleta* lista, int tam, eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor)
{
    int error = -1;
    int id;
    int index;
    char confirmacion;
    if(lista != NULL && tam > 0 && tam <= 100 && listaColor != NULL && tamColor > 0 && listaTipo != NULL && tamTipo > 0)
    {
        imprimirBicicletas(lista, tam, listaTipo, tamTipo, listaColor,tamColor);
        printf("\nIngrese ID de la bicicleta a eliminar: ");
        fflush(stdin);
        scanf("%d", &id);
        index = encontrarBicicletaPorID(lista, tam, id);
        if(index == -1)
        {
            system("cls");
            printf("No hay bicicletas con ese ID\n");
        }
        else
        {
            system("cls");
            printf("*********************************************************************************************************\n");
            printf("                                                BICLETAS      \n");
            printf("*********************************************************************************************************\n");
            printf("  ID            MARCA                      TIPO                     COLOR                    RODADO      \n");
            printf("*********************************************************************************************************\n");
            mostrarBicicleta(lista[index], listaTipo, tamTipo, listaColor, tamColor);
            printf("Confirmar baja? s - si; n - no\n");
            fflush(stdin);
            scanf("%c", &confirmacion);
            confirmacion = tolower(confirmacion);
            while(confirmacion != 's' && confirmacion != 'n')
            {
                printf("Opción invalida. s - si; n - no\n");
                fflush(stdin);
                scanf("%c", &confirmacion);
                confirmacion = tolower(confirmacion);
            }

            if(confirmacion == 's')
            {
                lista[index].estaVacio = 1;
                error = 0;
            }
            else if(confirmacion == 'n')
            {
                error = 1;
            }
        }

    }

    return error;
}

//cargar marcas
int cargarDescMarca(eBicicleta* lista, int len, int ID, char* descripcion)
{
    int error = -1;

    if(lista != NULL && descripcion != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(lista[i].id == ID)
            {
                strcpy(descripcion, lista[i].marca);
                error = 0;
                break;
            }
        }
    }

    return error;
}

