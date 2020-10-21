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
#include "eCliente.h"
#include "informes.h"
#include "validaciones.h"

#define TAM_BICI 10
#define TAM_TRABAJOS 10
#define TAM_CLIENTES 10
#define TAM_COLORES 5
#define TAM_TIPOS 4
#define TAM_SERVICIOS 4
#define INICIAR_ID_BICI 9000
#define INICIAR_ID_CLIENTE 100
#define INICIAR_ID_TRABAJO 10000


int main()
{
    eBicicleta listaBicicletas[TAM_BICI];
    eCliente listaClientes[TAM_CLIENTES];
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

    int bicicletasExisten = 0;
    int trabajosExisten = 0;

    int bicicletas_IDActual = INICIAR_ID_BICI;
    int clientes_IDActual = INICIAR_ID_CLIENTE;
    int trabajos_IDActual = INICIAR_ID_TRABAJO;

    int menuPrincipal;
    int menuPrincipal_opcionSeleccionada;

    int bicicletas_resultadoHardcodeo;
    int clientes_resultadoHardcodeo;
    int trabajos_resultadoHardcodeo;

    int modificarBicicleta;
    int eliminarBicicleta;

    bicicletas_inicializar(listaBicicletas, TAM_BICI);
    clientes_inicializar(listaClientes, TAM_CLIENTES);
    trabajos_inicializar(listaTrabajos, TAM_TRABAJOS);

    bicicletas_resultadoHardcodeo = bicicletas_hardcodear(listaBicicletas, TAM_BICI, 5);
    clientes_resultadoHardcodeo = clientes_hardcodear(listaClientes, TAM_CLIENTES, 5);
    trabajos_resultadoHardcodeo = trabajos_hardcodear(listaTrabajos, TAM_TRABAJOS, 5);

    bicicletas_IDActual += bicicletas_resultadoHardcodeo + 1;
    clientes_IDActual += clientes_resultadoHardcodeo + 1;
    trabajos_IDActual += trabajos_resultadoHardcodeo + 1;

    do
    {
        bicicletas_menuPrincipal();
        menuPrincipal = validaciones_obtenerOpcion
                        (
                            &menuPrincipal_opcionSeleccionada,
                            "\nOpcion invalida, intente nuevamente\n",
                            1,
                            12
                        );
        if(!menuPrincipal)
        {
            switch(menuPrincipal_opcionSeleccionada)
            {
            case 1:
                if(bicicletas_agregar(
                            listaBicicletas,
                            TAM_BICI,
                            bicicletas_IDActual,
                            listaTipos,
                            TAM_TIPOS,
                            listaColores,
                            TAM_COLORES,
                            listaClientes,
                            TAM_CLIENTES) < 0)
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                else
                {
                    printf("\nOperacion exitosa\n");
                    bicicletas_IDActual++;
                    bicicletasExisten = 1;
                }
                break;
            case 2:
                if(!bicicletasExisten)
                {
                    printf("\nPrimero debe realizar un alta de una bicicleta.\n");
                    break;
                }

                modificarBicicleta = bicicletas_modificar(
                                         listaBicicletas,
                                         TAM_BICI,
                                         listaTipos,
                                         TAM_TIPOS,
                                         listaColores,
                                         TAM_COLORES,
                                         listaClientes,
                                         TAM_CLIENTES
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
                if(!bicicletasExisten)
                {
                    printf("\nPrimero debe realizar un alta de una bicicleta.\n");
                    break;
                }
                system("cls");
                eliminarBicicleta = bicicletas_eliminar(
                                        listaBicicletas,
                                        TAM_BICI,
                                        listaTipos,
                                        TAM_TIPOS,
                                        listaColores,
                                        TAM_COLORES,
                                        listaClientes,
                                        TAM_CLIENTES
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
                            TAM_COLORES,
                            listaClientes,
                            TAM_CLIENTES) < 0)
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                else
                {
                    printf("\nOperacion exitosa\n");
                    trabajos_IDActual++;
                    trabajosExisten = 1;
                }
                break;
            case 5:
                if(!bicicletasExisten)
                {
                    printf("\nPrimero debe realizar un alta de una bicicleta.\n");
                    break;
                }
                //listar bicicletas
                system("cls");
                bicicletas_imprimirLista(
                    listaBicicletas,
                    TAM_BICI,
                    listaTipos,
                    TAM_TIPOS,
                    listaColores,
                    TAM_COLORES,
                    listaClientes,
                    TAM_CLIENTES
                );
                break;
            case 6:
                if(!trabajosExisten)
                {
                    printf("\nPrimero debe realizar un alta de un trabajo.\n");
                    break;
                }
                //listar trabajos
                system("cls");
                trabajos_imprimirLista(
                    listaTrabajos,
                    TAM_TRABAJOS,
                    listaBicicletas,
                    TAM_BICI,
                    listaServicios,
                    TAM_SERVICIOS
                );
                break;
            case 7:
                //listar colores
                system("cls");
                colores_imprimirLista(listaColores, TAM_COLORES);
                break;
            case 8:
                //Listar tipos
                system("cls");
                tipos_imprimirLista(listaTipos, TAM_TIPOS);
                break;
            case 9:
                //Listar clientes
                system("cls");
                clientes_imprimirLista(listaClientes,TAM_CLIENTES);
                break;
            case 10:
                //listar servicios
                system("cls");
                servicios_imprimirLista(listaServicios, TAM_SERVICIOS);
                break;
            case 11:
                if(!bicicletasExisten || !trabajosExisten)
                {
                    printf("\nPrimero debe realizar un alta de una bicicleta y/o un trabajo.\n");
                    break;
                }

                system("cls");
                informes_Menu(
                    listaBicicletas,
                    TAM_BICI,
                    listaColores,
                    TAM_COLORES,
                    listaTipos,
                    TAM_TIPOS,
                    listaClientes,
                    TAM_CLIENTES,
                    listaTrabajos,
                    TAM_TRABAJOS,
                    listaServicios,
                    TAM_SERVICIOS
                );
                break;
            case 12:
                printf("Saliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while(menuPrincipal_opcionSeleccionada != 12);

    return 0;
}


