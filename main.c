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
    eTipo listaTipos[TAM_TIPOS] =
    {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };
    eColor listaColores[TAM_COLORES] =
    {
        {5000, "Gris"},
        {5001, "Negro"},
        {5002, "Blanco"},
        {5003, "Azul"},
        {5004, "Rojo"}
    };
    eServicio listaServicios[TAM_SERVICIOS] =
    {
        {20000, "Limpieza", 250},
        {20001, "Parche", 300},
        {20002, "Centrado", 400},
        {20003, "Cadena", 350},
    };

    int bicicletas_IDActual = INICIAR_ID_BICI;
    int trabajos_IDActual = INICIAR_ID_TRABAJO;

    int opcMenu;
    int opcSelect;

    int bicicletas_resultadoHardcodeo;
    int trabajos_resultadoHardcodeo;

    int modificarBicicleta;
    int eliminarBicicleta;

    bicicletas_inicializar(listaBicicletas, TAM_BICI);
    trabajos_inicializar(listaTrabajos, TAM_TRABAJOS);

    bicicletas_resultadoHardcodeo = bicicletas_hardcodear(listaBicicletas, TAM_BICI, 5);
    trabajos_resultadoHardcodeo = trabajos_hardcodear(listaTrabajos, TAM_TRABAJOS, 5);

    trabajos_IDActual += trabajos_resultadoHardcodeo + 1;
    bicicletas_IDActual += bicicletas_resultadoHardcodeo + 1;

    do
    {
        bicicletas_menuPrincipal();
        opcMenu = obtenerOpcion(&opcSelect, "\nOpcion invalida, intente nuevamente\n", 1, 10);
        if(!opcMenu)
        {
            switch(opcSelect)
            {
            case 1:
                if(bicicletas_agregar(
                            listaBicicletas,
                            TAM_BICI,
                            bicicletas_IDActual,
                            listaTipos,
                            TAM_TIPOS,
                            listaColores,
                            TAM_COLORES) < 0)
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                else
                {
                    printf("\nOperacion exitosa\n");
                    bicicletas_IDActual++;
                }
                break;
            case 2:
                modificarBicicleta = bicicletas_modificar(
                                         listaBicicletas,
                                         TAM_BICI,
                                         listaTipos,
                                         TAM_TIPOS,
                                         listaColores,
                                         TAM_COLORES
                                     );
                if(!modificarBicicleta)
                {
                    printf("\nModificacion exitosa.\n");
                }
                else if(modificarBicicleta == 1)
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
                eliminarBicicleta = bicicletas_eliminar(
                                        listaBicicletas,
                                        TAM_BICI,
                                        listaTipos,
                                        TAM_TIPOS,
                                        listaColores,
                                        TAM_COLORES
                                    );
                if(!eliminarBicicleta)
                {
                    printf("\nBaja exitosa.\n");
                }
                else if(eliminarBicicleta == 1)
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
                bicicletas_ordenarPorTipoYRodado(
                    listaBicicletas,
                    TAM_BICI,
                    listaTipos,
                    TAM_TIPOS);
                bicicletas_imprimirLista(
                    listaBicicletas,
                    TAM_BICI,
                    listaTipos,
                    TAM_TIPOS,
                    listaColores,
                    TAM_COLORES
                );
                break;
            case 5:
                //listar colores
                system("cls");
                colores_imprimirLista(listaColores, TAM_COLORES);
                break;
            case 6:
                //listar tipos
                system("cls");
                imprimirTipos(listaTipos, TAM_TIPOS);
                break;
            case 7:
                //LISTAR SERVICIOS
                system("cls");
                servicios_imprimirLista(listaServicios, TAM_SERVICIOS);
                break;
            case 8:
                if(trabajos_agregar(
                            listaTrabajos,
                            TAM_TRABAJOS,
                            trabajos_IDActual,
                            listaBicicletas,
                            TAM_BICI,
                            listaServicios,
                            TAM_SERVICIOS,
                            listaTipos,
                            TAM_TIPOS,
                            listaColores,
                            TAM_COLORES) < 0)
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                else
                {
                    printf("\nOperacion exitosa\n");
                    trabajos_IDActual++;
                }
                break;
            case 9:
                system("cls");
                trabajos_imprimirLista(
                    listaTrabajos,
                    TAM_TRABAJOS,
                    listaBicicletas,
                    TAM_BICI,
                    listaServicios,
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


