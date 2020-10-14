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
#define LEN_BICI 10
#define LEN_TRABAJOS 10
#define LEN_COLORES 5
#define LEN_TIPOS 4
#define LEN_SERVICIOS 4
#define INIT_ID_BICI 9000
#define INIT_ID_TRABAJO 10000


int main()
{
    int opcMenu;
    int opcSelect;
    int hardcodeResult;
    int actualIDBicis = INIT_ID_BICI;
    int actualIDTrabajos = INIT_ID_TRABAJO;
    eBicicleta listaBicicletas[LEN_BICI];
    int addNuevaBici;
    //case 2
    int modifBici;
    //case 3
    int remBici;
    //Trabajos
    eTrabajo listaTrabajos[LEN_TRABAJOS];
    //Tipos, colores y servicios
    eTipo tiposDeBicis[LEN_TIPOS] =
    {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };
    eColor coloresDeBicis[LEN_COLORES] =
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

    initBicis(listaBicicletas, LEN_BICI);
    initTrabajos(listaTrabajos, LEN_TRABAJOS)
    hardcodeResult = hardcodeBicis(listaBicicletas, LEN_BICI, 5);
    actualIDBicis += hardcodeResult + 1;
    do
    {
        menu();
        opcMenu = getOption(&opcSelect, "\nOpcion invalida, intente nuevamente\n", 1, 10);
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
                addNuevaBici = addBici(listaBicicletas, LEN_BICI, actualIDBicis, tiposDeBicis, LEN_TIPOS, coloresDeBicis, LEN_COLORES);
                if(addNuevaBici < 0)
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
                modifBici = modifieBici(listaBicicletas, LEN_BICI, tiposDeBicis, LEN_TIPOS, coloresDeBicis, LEN_COLORES);
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
                remBici = removeBici(listaBicicletas, LEN_BICI, tiposDeBicis, LEN_TIPOS, coloresDeBicis, LEN_COLORES);
                if(!remBici)
                {
                    printf("\nBaja exitosa.\n");
                }
                else if(remBici == 1)
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
                printBicis(listaBicicletas, LEN_BICI, tiposDeBicis, LEN_TIPOS, coloresDeBicis, LEN_COLORES);
                break;
            case 5:
                //listar tipos
                system("cls");
                showTipos(tiposDeBicis, LEN_TIPOS);
                break;
            case 6:
                //listar colores
                system("cls");
                showColores(coloresDeBicis, LEN_COLORES);
                break;
            case 7:
                //LISTAR SERVICIOS
                system("cls");
                showServicios(servicios, LEN_SERVICIOS);
                break;
            case 8:
                printf("Opcion en mantemiento.\n");
                break;
            case 9:
                printf("Opcion en mantemiento.\n");
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


