#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dataStore.h"
#include "eTipo.h"
#include "eColor.h"
#include "eBicicleta.h"




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

//Inicializar bicis
int initBicis(eBicicleta* list, int len)
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

//Buscar bici por id
int findBiciById(eBicicleta* list, int len,int id)
{
    int indiceId = -1;
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id && list[i].estaVacio == 0)
            {
                indiceId = i;
                break;
            }
        }
    }
    return indiceId;
}


// harcodeo
int hardcodeBicis(eBicicleta* list, int len, int numberOfBicis)
{
    int returns = -1;
    if(list != NULL && len > 0 && numberOfBicis > 0 && numberOfBicis < len)
    {
        for(int i = 0; i < numberOfBicis; i++)
        {
            if(list[i].estaVacio == 1)
            {
                list[i].estaVacio = 0;
                list[i].id = idBicis[i];
                strcpy(list[i].marca, marcas[i]);
                list[i].idTipo = idTipos[i];
                list[i].idColor = idColores[i];
                list[i].rodado = rodados[i];
                returns++;
            }
        }
    }

    return returns; //retorna -1 si hubo un error, sino un entero indicando la cantidad de mascotas que cargó
}


//imprimir
int printBicis(eBicicleta* list, int len, eTipo* tipos, int lenTipos, eColor* colores, int lenColores)
{
    if(list != NULL && len > 0 && len <= 100 && tipos != NULL && lenTipos > 0 && colores != NULL && lenColores > 0)
    {
        //system("cls");
        printf("*********************************************************************************************************\n");
        printf("                                                BICLETAS      \n");
        printf("*********************************************************************************************************\n");
        printf("  ID            MARCA                      TIPO                     COLOR                    RODADO      \n");
        printf("*********************************************************************************************************\n");
        for(int i = 0; i < len; i++)
        {
            if(list[i].estaVacio != 1)
            {
                showBici(list[i], tipos, lenTipos, colores, lenColores);
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

void showBici(eBicicleta bici, eTipo* tipos, int lenTipos, eColor* colores, int lenColores)
{
    char descTipo[30];
    char descColor[30];

    cargarDescTipo(tipos, lenTipos, bici.idTipo, descTipo);

    cargarNombre(colores, lenColores, bici.idColor, descColor);

    printf("%5d %15s           %15s           %15s                    %4.2f\n",
           bici.id,
           bici.marca,
           descTipo,
           descColor,
           bici.rodado
          );
}


//ALTA
int addBici(eBicicleta* list, int len, int ID, eTipo* listaTipos, int lenTipos, eColor* listaColores, int lenColores)
{
    eBicicleta newBici;
    int tipoIDValido;
    int colorIDValido;
    if(list != NULL && len > 0 && len <= 100 && listaTipos != NULL && lenTipos > 0 && listaColores != NULL && lenColores > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].estaVacio == 1)
            {
                newBici.estaVacio = 0;
                newBici.id = ID;
                //marca
                printf("\nIngrese marca: ");
                fflush(stdin);
                gets(newBici.marca);
                formatName(newBici.marca);
                while(strlen(newBici.marca) > 30)
                {
                    printf("\nDato invalido. Ingrese marca: ");
                    fflush(stdin);
                    gets(newBici.marca);
                    formatName(newBici.marca);
                }
                //tipo
                showTipos(listaTipos, lenTipos);
                printf("\nIngrese ID tipo: ");
                fflush(stdin);
                scanf("%d", &newBici.idTipo);
                tipoIDValido = findTipoById(listaTipos, lenTipos, newBici.idTipo);
                while( tipoIDValido < 0)
                {
                    printf("\nDato invalido. Ingrese ID tipo: ");
                    fflush(stdin);
                    scanf("%d", &newBici.idTipo);
                    tipoIDValido = findTipoById(listaTipos, lenTipos, newBici.idTipo);
                }
                //color
                showColores(listaColores, lenColores);
                printf("\nIngrese ID color: ");
                fflush(stdin);
                scanf("%d", &newBici.idColor);
                colorIDValido = findColorById(listaColores, lenColores, newBici.idColor);
                while( colorIDValido < 0)
                {
                    printf("\nDato invalido. Ingrese ID color: ");
                    fflush(stdin);
                    scanf("%d", &newBici.idColor);
                    colorIDValido = findColorById(listaColores, lenColores, newBici.idColor);
                }
                //rodado
                printf("\nIngrese rodado: ");
                fflush(stdin);
                scanf("%f", &newBici.rodado);

                list[i] = newBici;
                return 0;
            }
        }
        printf("\nNo hay lugar para otra bicicleta...\n");
    }

    return -1;
}

//modificacion
int modifieBici(eBicicleta* list, int len, eTipo* listaTipo, int lenTipo, eColor* listaColor, int lenColor)
{
    eBicicleta newBici;
    int error = -1;
    int id;
    int index;
    int rst;
    int mOption;
    int tipoIDValido;
    char confirmation;
    if(list != NULL && len > 0 && len <= 100 && listaTipo != NULL && listaColor != NULL && lenTipo > 0 && lenColor > 0)
    {
        system("cls");
        printf("*********************************************************************************************************\n");
        printf("                                  BIENVENIDO AL MENU DE MODIFICACIONES                                  \n");
        printBicis(list, len, listaTipo, lenTipo, listaColor, lenColor);
        printf("\nIngrese ID de la bicicleta a modificar: ");
        fflush(stdin);
        scanf("%d", &id);
        index = findBiciById(list, len, id);
        if(index == -1)
        {
            system("cls");
            printf("*********************************************************************************************************\n");
            printf("                                  BIENVENIDO AL MENU DE MODIFICACIONES                                  \n");
            printf("*********************************************************************************************************\n");
            printf("\nLo sentimos. No hay bicicletas con ese ID...\n");
        }
        else
        {
            system("cls");
            printf("*********************************************************************************************************\n");
            printf("                                                BICLETAS      \n");
            printf("*********************************************************************************************************\n");
            printf("  ID            MARCA                      TIPO                     COLOR                    RODADO      \n");
            printf("*********************************************************************************************************\n");
            showBici(list[index], listaTipo, lenTipo, listaColor, lenColor);
            printf("\nMODIFICAR:\n");
            printf("1. Tipo\n");
            printf("2. Rodado\n");
            rst = getOption(&mOption, "\nOpcion invalida\n", 1, 2);
            if(!rst)
            {
                switch(mOption)
                {
                case 1:
                    //Pedir tipo
                    showTipos(listaTipo, lenTipo);
                    printf("\nIngrese ID tipo: ");
                    fflush(stdin);
                    scanf("%d", &newBici.idTipo);
                    tipoIDValido = findTipoById(listaTipo, lenTipo, newBici.idTipo);
                    while( tipoIDValido < 0)
                    {
                        printf("\nDato invalido. Ingrese ID tipo: ");
                        fflush(stdin);
                        scanf("%d", &newBici.idTipo);
                        tipoIDValido = findTipoById(listaTipo, lenTipo, newBici.idTipo);
                    }
                    //pedir confirmacion
                    printf("\nConfirma modificacion? s-si n-no\n");
                    fflush(stdin);
                    scanf("%c", &confirmation);
                    confirmation = tolower(confirmation);
                    while(confirmation != 's' && confirmation != 'n')
                    {
                        printf("\nOpcion invalida. \nConfirma modificacion? s-si n-no\n");
                        fflush(stdin);
                        scanf("%c", &confirmation);
                        confirmation = tolower(confirmation);
                    }
                    if(confirmation == 's')
                    {
                        list[index].idTipo = newBici.idTipo;
                        error = 0;
                    }
                    else
                    {
                        error = 1;
                    }
                    break;
                case 2:
                    //pedir rodado
                    printf("\nIngrese nuevo rodado: ");
                    scanf("%f", &newBici.rodado);
                    printf("\nRodado anterior: %.2f", list[index].rodado);
                    printf("\nRodado nuev0: %.2f", newBici.rodado);
                    //confirmar edad
                    printf("\nConfirma modificacion? s-si n-no\n");
                    fflush(stdin);
                    scanf("%c", &confirmation);
                    confirmation = tolower(confirmation);
                    while(confirmation != 's' && confirmation != 'n')
                    {
                        printf("\nOpcion invalida. \nConfirma modificacion? s-si n-no\n");
                        fflush(stdin);
                        scanf("%c", &confirmation);
                        confirmation = tolower(confirmation);
                    }
                    if(confirmation == 's')
                    {
                        list[index].rodado = newBici.rodado;
                        error = 0;
                    }
                    else
                    {
                        error = 1;
                    }
                    break;
                }
            }
        }
    }

    return error;
}

//BAJA
int removeBici(eBicicleta* list, int len, eTipo* listaTipo, int lenTipo, eColor* listaColor, int lenColor)
{
    int error = -1;
    int id;
    int index;
    char confirmation;
    //La función podría devolver 3 enteros (0 - ok, -1 error, 1 ok pero no borró a nadie
    if(list != NULL && len > 0 && len <= 100 && listaColor != NULL && lenColor > 0 && listaTipo != NULL && lenTipo > 0)
    {
        printBicis(list, len, listaTipo, lenTipo, listaColor,lenColor);
        printf("\nIngrese ID de la bicicleta a eliminar: ");
        fflush(stdin);
        scanf("%d", &id);
        index = findBiciById(list, len, id);
        if(index == -1)
        {
            printf("No hay bicicletas con ese ID\n");
        }
        else
        {
            printf("*********************************************************************************************************\n");
            printf("                                                BICLETAS      \n");
            printf("*********************************************************************************************************\n");
            printf("  ID            MARCA                      TIPO                     COLOR                    RODADO      \n");
            printf("*********************************************************************************************************\n");
            showBici(list[index], listaTipo, lenTipo, listaColor, lenColor);
            printf("Confirmar baja? s - si; n - no\n");
            fflush(stdin);
            scanf("%c", &confirmation);
            confirmation = tolower(confirmation);
            while(confirmation != 's' && confirmation != 'n')
            {
                printf("Opción invalida. s - si; n - no\n");
                fflush(stdin);
                scanf("%c", &confirmation);
                confirmation = tolower(confirmation);
            }

            if(confirmation == 's')
            {
                list[index].estaVacio = 1;
                error = 0;
            }
            else if(confirmation == 'n')
            {
                error = 1;
            }
        }

    }

    return error;
}




//validacion, mover a otra biblioteca
void formatName(char* name)
{

    int len;
    strlwr(name);
    name[0] = toupper(name[0]);
    len = strlen(name);
    for(int i = 0; i < len; i++)
    {
        if(name[i] == ' ')
        {
            i++;
            if(name[i] >= 'a' && name[i] <= 'z')
            {
                name[i] = toupper(name[i]);
            }
        }
    }
}

//cargar marcas ??
int cargarDescMarca(eBicicleta* lista, int len, int ID, char* descripcion)
{
    int error = -1;

    if(lista != NULL && descripcion != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(lista[i].id == ID)
            {
                strcpy(descripcion, lista[i].marca);
                error = 0;
                break;
            }
        }
    }

    return error;
}

