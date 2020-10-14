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
#define LEN_COLORES 5
#define LEN_TIPOS 4
#define INIT_ID_BICI 9000


int main()
{
    int opcMenu;
    int opcSelect;
    int hardcodeResult;
    int actualIDBicis = INIT_ID_BICI;
    eBicicleta listaBicicletas[LEN_BICI];
    int addNuevaBici;
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
                printf("Opcion en mantemiento.\n");
                break;
            case 3:
                printf("Opcion en mantemiento.\n");
                break;
            case 4:
                system("cls");
                printBicis(listaBicicletas, LEN_BICI, tiposDeBicis, LEN_TIPOS, coloresDeBicis, LEN_COLORES);
                break;
            case 5:
                printf("Opcion en mantemiento.\n");
                break;
            case 6:
                printf("Opcion en mantemiento.\n");
                break;
            case 7:
                printf("Opcion en mantemiento.\n");
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


