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
#define INIT_ID_BICI 9000


int main()
{
    int opcMenu;
    int opcSelect;
    eBicicleta listaBicicletas[LEN_BICI];
    //Tipos, colores y servicios
    eTipo tipos[] =
    {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };
    eColor colores[] =
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

    do
    {
        menu();
        opcMenu = getOption(&opcSelect, "\nOpcion invalida, intente nuevamente\n", 1, 10);
        if(!opcMenu)
        {
            switch(opcSelect)
            {
            case 1:
                printf("Opcion en mantemiento.\n");
                break;
            case 2:
                printf("Opcion en mantemiento.\n");
                break;
            case 3:
                printf("Opcion en mantemiento.\n");
                break;
            case 4:
                printf("Opcion en mantemiento.\n");
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


