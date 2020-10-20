#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dataStore.h"
#include "eTipo.h"
#include "eColor.h"
#include "eBicicleta.h"
#include "validaciones.h"

void bicicletas_menuPrincipal()
{
    system("cls");
    printf("_________________________________________________________________________________________________________\n");
    printf("                                               PARCIAL 1          \n");
    printf("_________________________________________________________________________________________________________\n");
    printf("                                          SISTEMA BICICLETERIA                    \n");
    printf("_________________________________________________________________________________________________________\n");
    printf("1. ALTA BICICLETA\n");
    printf("2. MODIFICAR BICICLETA\n");
    printf("3. BAJA BICICLETA\n");
    printf("4. LISTAR BICICLETAS POR TIPO Y RODADO\n");
    printf("5. LISTAR COLORES\n");
    printf("6. LISTAR TIPOS\n");
    printf("7. LISTAR SERVICIOS\n");
    printf("8. ALTA TRABAJO\n");
    printf("9. LISTAR TRABAJOS\n");
    printf("10. SALIR\n");
}

int bicicletas_inicializar(eBicicleta* lista, int tam)
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

int bicicletas_buscarPorID(eBicicleta* lista, int tam, int id)
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


int bicicletas_hardcodear(eBicicleta* lista, int tam, int numeroDeBicis)
{
    int returns = -1;
    if(
        lista != NULL &&
        tam > 0 &&
        numeroDeBicis > 0 &&
        numeroDeBicis < tam)
    {
        for(int i = 0; i < numeroDeBicis; i++)
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

    return returns;
}

int bicicletas_imprimirLista(
    eBicicleta* lista,
    int tam,
    eTipo* tipos,
    int tamTipos,
    eColor* colores,
    int tamColores)
{
    if(
        lista != NULL &&
        tam > 0 &&
        tam <= 100 &&
        tipos != NULL &&
        tamTipos> 0 &&
        colores != NULL &&
        tamColores > 0)
    {
        printf("_________________________________________________________________________________________________________\n");
        printf("                                                BICICLETAS      \n");
        printf("_________________________________________________________________________________________________________\n");
        printf("  ID            MARCA                      TIPO                     COLOR                    RODADO      \n");
        printf("_________________________________________________________________________________________________________\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].estaVacio != 1)
            {
                bicicletas_imprimirItem(
                    lista[i],
                    tipos,
                    tamTipos,
                    colores,
                    tamColores);
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

void bicicletas_imprimirItem(
    eBicicleta bici,
    eTipo* tipos,
    int tamTipos,
    eColor* colores,
    int tamColores)
{
    char descTipo[30];
    char descColor[30];

    tipos_cargarDesc(tipos, tamTipos, bici.idTipo, descTipo);

    colores_cargarNombre(colores, tamColores, bici.idColor, descColor);

    printf("%5d %15s           %15s           %15s                    %4.2f\n",
           bici.id,
           bici.marca,
           descTipo,
           descColor,
           bici.rodado
          );
}

int bicicletas_agregar(
    eBicicleta* lista,
    int tam,
    int ID,
    eTipo* listaTipos,
    int tamTipos,
    eColor* listaColores,
    int tamColores)
{
    eBicicleta nuevaBici;
    int tipoIDValido;
    int colorIDValido;
    if(
        lista != NULL &&
        tam > 0 &&
        tam <= 100 &&
        listaTipos != NULL &&
        tamTipos > 0 &&
        listaColores != NULL &&
        tamColores > 0)
    {
        system("cls");
        printf("_________________________________________________________________________________________________________\n");
        printf("                                            AGREGAR BICICLETA     \n");
        printf("_________________________________________________________________________________________________________\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].estaVacio == 1)
            {
                nuevaBici.estaVacio = 0;
                nuevaBici.id = ID;
                //marca
                printf("\n Ingrese marca: ");
                fflush(stdin);
                gets(nuevaBici.marca);
                validaciones_formatearCadena(nuevaBici.marca);
                while(strlen(nuevaBici.marca) > 30)
                {
                    printf("\n Dato invalido. Ingrese marca: ");
                    fflush(stdin);
                    gets(nuevaBici.marca);
                    validaciones_formatearCadena(nuevaBici.marca);
                }
                //tipo
                system("cls");
                printf("\n Ingrese ID tipo para la nueva bicicleta\n");
                tipos_imprimirLista(listaTipos, tamTipos);
                printf("\nIngrese ID: ");
                fflush(stdin);
                scanf("%d", &nuevaBici.idTipo);
                tipoIDValido = tipos_encontrarPorID(
                                   listaTipos,
                                   tamTipos,
                                   nuevaBici.idTipo
                               );
                while( tipoIDValido < 0)
                {
                    printf("\n Dato invalido. Ingrese ID tipo: ");
                    fflush(stdin);
                    scanf("%d", &nuevaBici.idTipo);
                    tipoIDValido = tipos_encontrarPorID(
                                       listaTipos,
                                       tamTipos,
                                       nuevaBici.idTipo
                                   );
                }
                //color
                system("cls");
                printf("\n Ingrese ID color para la nueva bicicleta\n");
                colores_imprimirLista(listaColores, tamColores);
                printf("\nIngrese ID: ");
                fflush(stdin);
                scanf("%d", &nuevaBici.idColor);
                colorIDValido = colores_buscarPorID(
                                    listaColores,
                                    tamColores,
                                    nuevaBici.idColor
                                );
                while( colorIDValido < 0)
                {
                    printf("\n Dato invalido. Ingrese ID color: ");
                    fflush(stdin);
                    scanf("%d", &nuevaBici.idColor);
                    colorIDValido = colores_buscarPorID(
                                        listaColores,
                                        tamColores,
                                        nuevaBici.idColor
                                    );
                }
                //rodado
                system("cls");
                printf("RODADOS:\n- 20\n- 26\n- 27.5\n- 29\n");
                printf("\nIngrese rodado para la nueva bicicleta: ");
                fflush(stdin);
                scanf("%f", &nuevaBici.rodado);
                while(
                    nuevaBici.rodado != 20 &&
                    nuevaBici.rodado != 26 &&
                    nuevaBici.rodado != 27.5 &&
                    nuevaBici.rodado != 29)
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

int bicicletas_modificar(
    eBicicleta* lista,
    int tam,
    eTipo* listaTipo,
    int tamTipo,
    eColor* listaColor,
    int tamColor)
{
    eBicicleta nuevaBici;
    int error = -1;
    int id;
    int index;
    int rst;
    int mOpcion;
    int tipoIDValido;
    char confirmacion;
    if(
        lista != NULL &&
        tam > 0 &&
        tam <= 100 &&
        listaTipo != NULL &&
        listaColor != NULL &&
        tamTipo > 0 &&
        tamColor > 0)
    {
        system("cls");
        printf("_________________________________________________________________________________________________________\n");
        printf("                                  BIENVENIDO AL MENU DE MODIFICACIONES                                  \n");
        bicicletas_imprimirLista(
            lista,
            tam,
            listaTipo,
            tamTipo,
            listaColor,
            tamColor);
        printf("\nIngrese ID de la bicicleta a modificar: ");
        fflush(stdin);
        scanf("%d", &id);
        index = bicicletas_buscarPorID(lista, tam, id);
        if(index == -1)
        {
            system("cls");
            printf("_________________________________________________________________________________________________________\n");
            printf("                                     BIENVENIDO AL MENU DE MODIFICACIONES                                  \n");
            printf("_________________________________________________________________________________________________________\n");
            printf("\nLo sentimos. No hay bicicletas con ese ID...\n");
        }
        else
        {
            system("cls");
            printf("_________________________________________________________________________________________________________\n");
            printf("                                                BICICLETAS      \n");
            printf("_________________________________________________________________________________________________________\n");
            printf("  ID            MARCA                      TIPO                     COLOR                    RODADO      \n");
            printf("_________________________________________________________________________________________________________\n");
            bicicletas_imprimirItem(
                lista[index],
                listaTipo,
                tamTipo,
                listaColor,
                tamColor);
            printf("\nMODIFICAR:\n");
            printf("1. Tipo\n");
            printf("2. Rodado\n");
            rst = validaciones_obtenerOpcion(&mOpcion, "\nOpcion invalida\n", 1, 2);
            if(!rst)
            {
                switch(mOpcion)
                {
                case 1:
                    //Pedir tipo
                    system("cls");
                    printf("\n Ingrese un ID tipo nuevo\n");
                    tipos_imprimirLista(listaTipo, tamTipo);
                    printf("\nIngrese ID: ");
                    fflush(stdin);
                    scanf("%d", &nuevaBici.idTipo);
                    tipoIDValido = tipos_encontrarPorID(
                                       listaTipo,
                                       tamTipo,
                                       nuevaBici.idTipo);
                    while( tipoIDValido < 0)
                    {
                        printf("\n Dato invalido. Ingrese ID tipo: ");
                        fflush(stdin);
                        scanf("%d", &nuevaBici.idTipo);
                        tipoIDValido = tipos_encontrarPorID(
                                           listaTipo,
                                           tamTipo,
                                           nuevaBici.idTipo);
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
                    system("cls");
                    printf("RODADOS:\n- 20\n- 26\n- 27.5\n- 29\n");
                    printf("\nIngrese rodado nuevo: ");
                    fflush(stdin);
                    scanf("%f", &nuevaBici.rodado);
                    while(
                        nuevaBici.rodado != 20 &&
                        nuevaBici.rodado != 26 &&
                        nuevaBici.rodado != 27.5 &&
                        nuevaBici.rodado != 29)
                    {
                        printf("\n Dato Invalido. Ingrese nuevo rodado: ");
                        fflush(stdin);
                        scanf("%f", &nuevaBici.rodado);
                    }

                    printf("\n Rodado anterior: %.2f", lista[index].rodado);
                    printf("\n Rodado nuev0: %.2f", nuevaBici.rodado);
                    //confirmar modificacion
                    printf("\n Confirma modificacion? s-si n-no\n");
                    fflush(stdin);
                    scanf("%c", &confirmacion);
                    confirmacion = tolower(confirmacion);
                    while(confirmacion != 's' && confirmacion != 'n')
                    {
                        printf("\n Opcion invalida. \nConfirma modificacion? s-si n-no\n");
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

int bicicletas_eliminar(
    eBicicleta* lista,
    int tam,
    eTipo* listaTipo,
    int tamTipo,
    eColor* listaColor,
    int tamColor)
{
    int error = -1;
    int id;
    int index;
    char confirmacion;
    if(
        lista != NULL &&
        tam > 0 &&
        tam <= 100 &&
        listaColor != NULL &&
        tamColor > 0 &&
        listaTipo != NULL &&
        tamTipo > 0)
    {
        bicicletas_imprimirLista(
            lista,
            tam,
            listaTipo,
            tamTipo,
            listaColor,
            tamColor);
        printf("\nIngrese ID de la bicicleta a eliminar: ");
        fflush(stdin);
        scanf("%d", &id);
        index = bicicletas_buscarPorID(lista, tam, id);
        if(index == -1)
        {
            system("cls");
            printf("No hay bicicletas con ese ID\n");
        }
        else
        {
            system("cls");
            printf("_________________________________________________________________________________________________________\n");
            printf("                                                BICICLETAS      \n");
            printf("_________________________________________________________________________________________________________\n");
            printf("  ID            MARCA                      TIPO                     COLOR                    RODADO      \n");
            printf("_________________________________________________________________________________________________________\n");
            bicicletas_imprimirItem(
                lista[index],
                listaTipo,
                tamTipo,
                listaColor,
                tamColor);
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

int bicicletas_cargarDescMarca(
    eBicicleta* lista,
    int len,
    int ID,
    char* descripcion)
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

int bicicletas_ordenarPorTipoYRodado(
    eBicicleta* lista,
    int tam,
    eTipo* tipos,
    int tamTipos)
{
    int error = -1;
    eBicicleta auxBici;
    char descripcionTipoI[30];
    char descripcionTipoJ[30];

    if(lista != NULL && tam > 0 && tipos != NULL && tamTipos > 0)
    {
        for(int i = 0; i < tam-1; i++)
        {
            tipos_cargarDesc(tipos, tamTipos, lista[i].idTipo, descripcionTipoI);

            for(int j = i + 1; j < tam; j++)
            {
                tipos_cargarDesc(tipos, tamTipos, lista[j].idTipo, descripcionTipoJ);

                if(strcmp(descripcionTipoI, descripcionTipoJ) > 0)
                {
                    auxBici = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxBici;
                }
                else if(
                    strcmp(descripcionTipoI, descripcionTipoJ) == 0 &&
                    lista[i].rodado > lista[j].rodado)
                {
                    auxBici = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxBici;
                }
            }
        }
        error = 0;
    }

    return error;
}

