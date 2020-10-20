#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "eFecha.h"
#include "eTipo.h"
#include "eColor.h"
#include "eBicicleta.h"
#include "eServicio.h"
#include "eTrabajo.h"
#include "validaciones.h"
#define TAM_BICI 10
#define TAM_TRABAJOS 10
#define TAM_COLORES 5
#define TAM_TIPOS 4
#define TAM_SERVICIOS 4
#define INICIAR_ID_BICI 9000
#define INICIAR_ID_TRABAJO 10000


int main()
{
    int opcMenu;
    int opcSelect;
    int hardcodeResult;
    int hardcodeResultTrab;
    int actualIDBicis = INICIAR_ID_BICI;
    int actualIDTrabajos = INICIAR_ID_TRABAJO;
    eBicicleta listaBicicletas[TAM_BICI];
    int agregarNuevaBici;
    //case 2
    int modifBici;
    //case 3
    int elimBici;
    int altaTrabajos;
    //Trabajos
    eTrabajo listaTrabajos[TAM_TRABAJOS];
    //Tipos, colores y servicios
    eTipo tiposDeBicis[TAM_TIPOS] =
    {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };
    eColor coloresDeBicis[TAM_COLORES] =
    {
        {5000, "Gris"},
        {5001, "Negro"},
        {5002, "Blanco"},
        {5003, "Azul"},
        {5004, "Rojo"}
    };
    eServicio servicios[] =
    {
        {20000, "Limpieza", 250},
        {20001, "Parche", 300},
        {20002, "Centrado", 400},
        {20003, "Cadena", 350},
    };

    iniciarBicicletas(listaBicicletas, TAM_BICI);
    iniciarTrabajos(listaTrabajos, TAM_TRABAJOS);
    hardcodeResult = hardcodearBicicletas(listaBicicletas, TAM_BICI, 5);
    hardcodeResultTrab = hardcodearTrabajos(listaTrabajos, TAM_TRABAJOS, 5);
    actualIDTrabajos += hardcodeResultTrab + 1;
    actualIDBicis += hardcodeResult + 1;
    do
    {
        menu();
        opcMenu = obtenerOpcion(&opcSelect, "\nOpcion invalida, intente nuevamente\n", 1, 10);
        if(!opcMenu)
        {
            switch(opcSelect)
            {
            case 1:
                //Cargar bici
                system("cls");
                printf("*********************************************************************************************************\n");
                printf("                                            ANIADIR BICICLETA     \n");
                printf("*********************************************************************************************************\n");
                agregarNuevaBici = agregarBicicleta(listaBicicletas, TAM_BICI, actualIDBicis, tiposDeBicis, TAM_TIPOS, coloresDeBicis, TAM_COLORES);
                if(agregarNuevaBici < 0)
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                else
                {
                    printf("\nOperacion exitosa\n");
                    actualIDBicis++;
                }
                break;
            case 2:
                //modificar bici
                modifBici = modificarBicicleta(listaBicicletas, TAM_BICI, tiposDeBicis, TAM_TIPOS, coloresDeBicis, TAM_COLORES);
                if(!modifBici)
                {
                    printf("\nModificacion exitosa.\n");
                }
                else if(modifBici == 1)
                {
                    printf("\nModificacion cancelada por usuario.\n");
                }
                else
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                break;
            case 3:
                //eliminar
                system("cls");
                elimBici = eliminarBicicleta(listaBicicletas, TAM_BICI, tiposDeBicis, TAM_TIPOS, coloresDeBicis, TAM_COLORES);
                if(!elimBici)
                {
                    printf("\nBaja exitosa.\n");
                }
                else if(elimBici == 1)
                {
                    printf("\nBaja cancelada por usuario.\n");
                }
                else
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                break;
            case 4:
                system("cls");
                imprimirBicicletas(listaBicicletas, TAM_BICI, tiposDeBicis, TAM_TIPOS, coloresDeBicis, TAM_COLORES);
                break;
            case 5:
                //listar colores
                system("cls");
                imprimirColores(coloresDeBicis, TAM_COLORES);
                break;
            case 6:
                //listar tipos
                system("cls");
                imprimirTipos(tiposDeBicis, TAM_TIPOS);
                break;
            case 7:
                //LISTAR SERVICIOS
                system("cls");
                imprimirServicios(servicios, TAM_SERVICIOS);
                break;
            case 8:
                //alta trabajo
                system("cls");
                printf("*********************************************************************************************************\n");
                printf("                                            ANIADIR TRABAJO     \n");
                altaTrabajos = altaTrabajo(listaTrabajos, TAM_TRABAJOS, actualIDTrabajos, listaBicicletas, TAM_BICI, servicios, TAM_SERVICIOS, tiposDeBicis, TAM_TIPOS, coloresDeBicis, TAM_COLORES);
                if(altaTrabajos < 0)
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                else
                {
                    printf("\nOperacion exitosa\n");
                    actualIDTrabajos++;
                }
                break;
            case 9:
                system("cls");
                imprimirTrabajos(listaTrabajos, TAM_TRABAJOS, listaBicicletas, TAM_BICI, servicios, TAM_SERVICIOS);
                break;
            case 10:
                printf("Saliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while(opcSelect != 10);

    return 0;
}


