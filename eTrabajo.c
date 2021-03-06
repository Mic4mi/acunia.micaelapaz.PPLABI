#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dataStore.h"
#include "eTrabajo.h"
#include "validaciones.h"

int trabajos_agregar(
    eTrabajo* lista,
    int tam, int ID,
    eBicicleta* listaBicis,
    int tamBicis,
    eServicio* listaServicios,
    int tamServicios,
    eTipo* tiposDeBici,
    int tamTiposBicis,
    eColor* coloresDeBicis,
    int tamColores,
    eCliente* listaClientes,
    int tamClientes
)
{
    eTrabajo nuevoTrabajo;
    int biciIDValido;
    int servIDValido;
    if(lista != NULL &&
            tam > 0 &&
            tam <= 100 &&
            listaBicis != NULL &&
            tamBicis > 0 &&
            listaServicios != NULL &&
            tamServicios > 0)
    {
        system("cls");
        printf("_________________________________________________________________________________________________________\n");
        printf("                                            AGREGAR TRABAJO                                              \n");
        printf("_________________________________________________________________________________________________________\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].estaVacio == 1)
            {
                nuevoTrabajo.estaVacio = 0;
                nuevoTrabajo.id = ID;
                system("cls");
                printf("_________________________________________________________________________________________________________\n");
                printf("                                            AGREGAR TRABAJO                                              \n");
                printf("_________________________________________________________________________________________________________\n");
                printf("\n Ingrese ID de la Bicicleta del nuevo trabajo\n");
                bicicletas_imprimirLista(
                    listaBicis,
                    tamBicis,
                    tiposDeBici,
                    tamTiposBicis,
                    coloresDeBicis,
                    tamColores,
                    listaClientes,
                    tamClientes);
                printf("\n Ingrese ID de la Bicicleta: ");
                fflush(stdin);
                scanf("%d", &nuevoTrabajo.idBicicleta);
                biciIDValido = bicicletas_buscarPorID(
                                   listaBicis,
                                   tamBicis,
                                   nuevoTrabajo.idBicicleta
                               );
                while(  biciIDValido < 0)
                {
                    printf("\n Dato invalido. Ingrese ID tipo: ");
                    fflush(stdin);
                    scanf("%d", &nuevoTrabajo.idBicicleta);
                    biciIDValido = bicicletas_buscarPorID(
                                       listaBicis,
                                       tamBicis,
                                       nuevoTrabajo.idBicicleta
                                   );
                }
                system("cls");
                printf("_________________________________________________________________________________________________________\n");
                printf("                                            AGREGAR TRABAJO                                              \n");
                printf("_________________________________________________________________________________________________________\n");
                printf("\n Ingrese ID del servicio realizado en el nuevo trabajo\n");
                servicios_imprimirLista(listaServicios, tamServicios);
                printf("\n Ingrese ID del servicio: ");
                fflush(stdin);
                scanf("%d", &nuevoTrabajo.idServicio);
                servIDValido = servicios_buscarPorID(
                                   listaServicios,
                                   tamServicios,
                                   nuevoTrabajo.idServicio
                               );
                while(  servIDValido < 0)
                {
                    printf("\n Dato invalido. Ingrese ID tipo: ");
                    fflush(stdin);
                    scanf("%d", &nuevoTrabajo.idServicio);
                    servIDValido = servicios_buscarPorID(
                                       listaServicios,
                                       tamServicios,
                                       nuevoTrabajo.idServicio
                                   );
                }
                //Pedir fecha
                system("cls");
                printf("_________________________________________________________________________________________________________\n");
                printf("                                            AGREGAR TRABAJO                                              \n");
                printf("_________________________________________________________________________________________________________\n");
                printf("\n Ingrese fecha dd/mm/aaaa: ");
                fflush(stdin);
                scanf("%d/%d/%d",
                      &nuevoTrabajo.fecha.dia,
                      &nuevoTrabajo.fecha.mes,
                      &nuevoTrabajo.fecha.anio
                     );
                while(
                    nuevoTrabajo.fecha.dia > 31 ||
                    nuevoTrabajo.fecha.dia < 0 ||
                    nuevoTrabajo.fecha.mes > 12 ||
                    nuevoTrabajo.fecha.mes < 0 ||
                    nuevoTrabajo.fecha.anio < 1900 ||
                    nuevoTrabajo.fecha.anio > 2100
                )
                {
                    printf("\n Dato invalido\n Ingrese fecha dd/mm/aaaa: ");
                    fflush(stdin);
                    scanf("%d/%d/%d",
                          &nuevoTrabajo.fecha.dia,
                          &nuevoTrabajo.fecha.mes,
                          &nuevoTrabajo.fecha.anio);
                }

                lista[i] = nuevoTrabajo;
                return 0;
            }
        }
        printf("\n No hay lugar para otro trabajo...\n");
    }

    return -1;
}


int trabajos_inicializar(eTrabajo* lista, int tam)
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

//imprimir
int trabajos_imprimirLista(
    eTrabajo* lista,
    int tam,
    eBicicleta* bicicletas,
    int tamBicis,
    eServicio* servicios,
    int tamServicios)
{
    if(lista != NULL &&
            tam > 0 &&
            tam <= 100 &&
            bicicletas != NULL &&
            tamBicis > 0 &&
            servicios != NULL &&
            tamServicios > 0)
    {
        //system("cls");
        printf("_________________________________________________________________________________________________________\n");
        printf("                                                TRABAJOS      \n");
        printf("_________________________________________________________________________________________________________\n");
        printf("  ID            SERVICIO                      BICICLETA                     FECHA      \n");
        printf("_________________________________________________________________________________________________________\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].estaVacio != 1)
            {
                trabajos_imprimirItem(
                    lista[i],
                    bicicletas,
                    tamBicis,
                    servicios,
                    tamServicios
                );
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

void trabajos_imprimirItem(
    eTrabajo trabajo,
    eBicicleta* bicicletas,
    int tamBicis,
    eServicio* servicios,
    int tamServicios)
{
    char descServ[30];
    char descMarcaBici[30];

    servicios_cargarDesc(servicios, tamServicios, trabajo.idServicio, descServ);
    bicicletas_cargarDescMarca(bicicletas, tamBicis, trabajo.idBicicleta, descMarcaBici);

    printf("  %5d %15s               %15s                    %0d/%0d/%d\n",
           trabajo.id,
           descServ,
           descMarcaBici,
           trabajo.fecha.dia,
           trabajo.fecha.mes,
           trabajo.fecha.anio);
}

int trabajos_hardcodear(eTrabajo* lista, int tam, int numeroDeTrabajos)
{
    int returns = -1;
    if(lista != NULL && tam > 0 && numeroDeTrabajos > 0 && numeroDeTrabajos < tam)
    {
        for(int i = 0; i < numeroDeTrabajos; i++)
        {
            if(lista[i].estaVacio == 1)
            {
                lista[i].estaVacio = 0;
                lista[i].id = idTrabajos[i];
                lista[i].idBicicleta = idBicis[i];
                lista[i].idServicio = idTrabajosServicios[i];
                lista[i].fecha.dia = trabajosDias[i];
                lista[i].fecha.mes = trabajosMes;
                lista[i].fecha.anio = trabajosAnio;
                returns++;
            }
        }
    }

    return returns;
}

