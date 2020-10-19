#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dataStore.h"
#include "eTrabajo.h"



//mover a la biblioteca trabajo
int altaTrabajo(eTrabajo* list, int len, int ID, eBicicleta* listaBicis, int lenBicis, eServicio* listaServicios, int lenServicios, eTipo* tiposDeBici, int lenTiposBicis, eColor* coloresDeBicis, int lenColores)
{
    eTrabajo newTrabajo;
    int biciIDValido;
    int servIDValido;
    if(list != NULL && len > 0 && len <= 100 && listaBicis != NULL && lenBicis > 0 && listaServicios != NULL && lenServicios > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].estaVacio == 1)
            {
                newTrabajo.estaVacio = 0;
                newTrabajo.id = ID;
                //pedir Bici
                printBicis(listaBicis, lenBicis, tiposDeBici, lenTiposBicis, coloresDeBicis, lenColores);
                printf("\nIngrese ID de la Bicicleta: ");
                fflush(stdin);
                scanf("%d", &newTrabajo.idBicicleta);
                biciIDValido = findBiciById(listaBicis, lenBicis, newTrabajo.idBicicleta);
                while(  biciIDValido < 0)
                {
                    printf("\nDato invalido. Ingrese ID tipo: ");
                    fflush(stdin);
                    scanf("%d", &newTrabajo.idBicicleta);
                    biciIDValido = findBiciById(listaBicis, lenBicis, newTrabajo.idBicicleta);
                }
                //Pedir Servicio
                showServicios(listaServicios, lenServicios);
                printf("\nIngrese ID del servicio: ");
                fflush(stdin);
                scanf("%d", &newTrabajo.idServicio);
                servIDValido = findServicioById(listaServicios, lenServicios, newTrabajo.idServicio);
                while(  servIDValido < 0)
                {
                    printf("\nDato invalido. Ingrese ID tipo: ");
                    fflush(stdin);
                    scanf("%d", &newTrabajo.idServicio);
                    servIDValido = findServicioById(listaServicios, lenServicios, newTrabajo.idServicio);
                }
                //Pedir fecha
                printf("\nIngrese fecha dd/mm/aaaa: ");
                fflush(stdin);
                scanf("%d/%d/%d", &newTrabajo.fecha.dia, &newTrabajo.fecha.mes, &newTrabajo.fecha.anio);
                while(newTrabajo.fecha.dia > 31 || newTrabajo.fecha.dia < 0 || newTrabajo.fecha.mes > 12 || newTrabajo.fecha.mes < 0 || newTrabajo.fecha.anio < 1900 || newTrabajo.fecha.anio > 2100)
                {
                    printf("\nDato invalido\nIngrese fecha dd/mm/aaaa: ");
                    fflush(stdin);
                    scanf("%d/%d/%d", &newTrabajo.fecha.dia, &newTrabajo.fecha.mes, &newTrabajo.fecha.anio);
                }

                list[i] = newTrabajo;
                return 0;
            }
        }
        printf("\nNo hay lugar para otra bicicleta...\n");
    }

    return -1;
}


int initTrabajos(eTrabajo* list, int len)
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

//imprimir
int printTrabajos(eTrabajo* list, int len, eBicicleta* bicicletas, int lenBicis, eServicio* servicios, int lenServicios)
{
    if(list != NULL && len > 0 && len <= 100 && bicicletas != NULL && lenBicis > 0 && servicios != NULL && lenServicios > 0)
    {
        //system("cls");
        printf("*********************************************************************************************************\n");
        printf("                                                 TRABAJOS      \n");
        printf("*********************************************************************************************************\n");
        printf("  ID            SERVICIO                      BICICLETA                     FECHA      \n");
        printf("*********************************************************************************************************\n");
        for(int i = 0; i < len; i++)
        {
            if(list[i].estaVacio != 1)
            {
                showTrabajo(list[i], bicicletas, lenBicis, servicios, lenServicios);
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

void showTrabajo(eTrabajo trabajo, eBicicleta* bicicletas, int lenBicis, eServicio* servicios, int lenServicios)
{
    char descServ[30];
    char descMarcaBici[30];

    cargarDescServ(servicios, lenServicios, trabajo.idServicio, descServ);
    cargarDescMarca(bicicletas, lenBicis, trabajo.idBicicleta, descMarcaBici);

    printf("  %5d %15s               %15s                    %0d/%0d/%d\n",
           trabajo.id,
           descServ,
           descMarcaBici,
           trabajo.fecha.dia,
           trabajo.fecha.mes,
           trabajo.fecha.anio);
}

int hardcodeTrabajos(eTrabajo* list, int len, int numberOfTrabajos)
{
    int returns = -1;
    if(list != NULL && len > 0 && numberOfTrabajos > 0 && numberOfTrabajos < len)
    {
        for(int i = 0; i < numberOfTrabajos; i++)
        {
            if(list[i].estaVacio == 1)
            {
                list[i].estaVacio = 0;
                list[i].id = idTrabajos[i];
                list[i].idBicicleta = idBicis[i];
                list[i].idServicio = idTrabajosServicios[i];
                list[i].fecha.dia = trabajosDias[i];
                list[i].fecha.mes = trabajosMes;
                list[i].fecha.anio = trabajosAnio;
                returns++;
            }
        }
    }

    return returns; //retorna -1 si hubo un error, sino un entero indicando la cantidad de mascotas que cargó
}
