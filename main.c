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


int main()
{
    int opcMenu;
    int opcSelect;


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


int getOption(int* pResult, char* errorMsj, int min, int max)
{
    int error = -1;
    int opcion;
    int validate;
    if(pResult != NULL && errorMsj != NULL && min <= max)
    {
        do
        {
            printf("\nIngrese opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
            validate = isdigit(opcion);
            if((opcion >= min && opcion <= max) && !validate)
            {
                *pResult = opcion;
                error = 0;
            }
            else
            {
                printf("%s\n", errorMsj);
                system("pause");
            }
        }
        while(error != 0);
    }
    return error;
}

void menu()
{
    system("cls");
    printf("********************************************************************************************************\n");
    printf("                                               PARCIAL 1          \n");
    printf("********************************************************************************************************\n");
    printf("                                          SISTEMA BICICLETERIA                    \n");
    printf("********************************************************************************************************\n");
    printf("1. ALTA BICICLETA\n");
    printf("2. MODIFICAR BICICLETA\n");
    printf("3. BAJA BICICLETA\n");
    printf("4. LISTAR BICICLETAS\n");
    printf("5. LISTAR COLORES\n");
    printf("6. LISTAR TIPOS\n");
    printf("7. LISTAR SERVICIOS\n");
    printf("8. ALTA TRABAJO\n");
    printf("9. LISTAR TRABAJOS\n");
    printf("10. SALIR\n");
}
