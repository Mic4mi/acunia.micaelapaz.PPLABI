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
    eBicicleta listaBicicletas[TAM_BICI];
    eTrabajo listaTrabajos[TAM_TRABAJOS];
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

    int actualIDBicis = INICIAR_ID_BICI;
    int actualIDTrabajos = INICIAR_ID_TRABAJO;

    int opcMenu;
    int opcSelect;

    int hardcodeResult;
    int hardcodeResultTrab;

    int modifBici;
    int elimBici;

    bicicletas_inicializar(listaBicicletas, TAM_BICI);
    trabajos_inicializar(listaTrabajos, TAM_TRABAJOS);

    hardcodeResult = bicicletas_hardcodear(listaBicicletas, TAM_BICI, 5);
    hardcodeResultTrab = trabajos_hardcodear(listaTrabajos, TAM_TRABAJOS, 5);

    actualIDTrabajos += hardcodeResultTrab + 1;
    actualIDBicis += hardcodeResult + 1;

    do
    {
        bicicletas_menuPrincipal();
        opcMenu = obtenerOpcion(&opcSelect, "\nOpcion invalida, intente nuevamente\n", 1, 10);
        if(!opcMenu)
        {
            switch(opcSelect)
            {
            case 1:
                if(bicicletas_agregar(listaBicicletas, TAM_BICI, actualIDBicis, tiposDeBicis, TAM_TIPOS, coloresDeBicis, TAM_COLORES) < 0)
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
                modifBici = bicicletas_modificar(listaBicicletas, TAM_BICI, tiposDeBicis, TAM_TIPOS, coloresDeBicis, TAM_COLORES);
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
                system("cls");
                elimBici = bicicletas_eliminar(listaBicicletas, TAM_BICI, tiposDeBicis, TAM_TIPOS, coloresDeBicis, TAM_COLORES);
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
                bicicletas_ordenarPorTipoYRodado(listaBicicletas, TAM_BICI, tiposDeBicis, TAM_TIPOS);
                bicicletas_imprimirLista(listaBicicletas, TAM_BICI, tiposDeBicis, TAM_TIPOS, coloresDeBicis, TAM_COLORES);
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
                if(trabajos_agregar(
                            listaTrabajos,
                            TAM_TRABAJOS,
                            actualIDTrabajos,
                            listaBicicletas,
                            TAM_BICI,
                            servicios,
                            TAM_SERVICIOS,
                            tiposDeBicis,
                            TAM_TIPOS,
                            coloresDeBicis,
                            TAM_COLORES) < 0)
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
                trabajos_imprimirLista(
                    listaTrabajos,
                    TAM_TRABAJOS,
                    listaBicicletas,
                    TAM_BICI,
                    servicios,
                    TAM_SERVICIOS);
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


