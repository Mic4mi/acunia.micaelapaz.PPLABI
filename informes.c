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
#include "informes.h"

void informes_subMenu()
{
    system("cls");
    printf("_________________________________________________________________________________________________________\n");
    printf("                                            MENU DE INFORMES          \n");
    printf("_________________________________________________________________________________________________________\n");
    printf("                                          SISTEMA BICICLETERIA                    \n");
    printf("_________________________________________________________________________________________________________\n");
    printf("1. MOSTRAR BICICLETAS DEL MISMO COLOR \n");
    printf("2. MOSTRAR BICICLETAS DE UN MISMO TIPO \n");
    printf("3. INFORMAR LA O LAS BICIS DE MENOR RODADO\n");
    printf("4. MOSTRAR UN LISTADO DE LAS BICICLETAS SEPARADAS POR TIPO\n");
    printf("5. CUANTAS BICICLETAS HAY DE UN COLOR Y UN TIPO\n");
    printf("6. MOSTRAR EL O LOS COLORES MAS ELEGIDOS POR LOS CLIENTES\n");
    printf("7. PEDIR UNA BICICLETA Y MOSTRAR TODOS LOS TRABAJOS QUE SE LE HICIERON A LA MISMA\n");
    printf("8. PEDIR UNA BICICLETA E INFORMAR LA SUMA DE LOS IMPORTES QUE SE LE HICIERON AL MISMO\n");
    printf("9. PEDIR UN SERVICIO Y MOSTRAR LAS BICICLETAS A LAS QUE SE REALIZO ESE SERVICIO Y LA FECHA\n");
    printf("10. PEDIR UNA FECHA Y MOSTRAR TODOS LOS SERVICIOS REALIZADOS EN LA MISMA\n");
    printf("11. VOLVER AL MENU PRINCIPAL\n");
}

int informes_Menu(
    eBicicleta* listaBicicletas,
    int tamBicicletas,
    eColor* listaColores,
    int tamColores,
    eTipo* listaTipos,
    int tamTipos,
    eCliente* listaClientes,
    int tamClientes,
    eTrabajo* listaTrabajos,
    int tamTrabajos,
    eServicio* listaServicios,
    int tamServicios)
{
    int subMenu;
    int subMenu_opcionSeleccionada;
    int error = -1;

    do
    {
        informes_subMenu();
        subMenu = validaciones_obtenerOpcion(&subMenu_opcionSeleccionada, "\nOpcion invalida. Intente nuevamente\n", 1, 11);

        if(!subMenu)
        {
            switch(subMenu_opcionSeleccionada)
            {
            case 1:
                informes_encabezadoSubMenu();
                informes_bicicletas_mostrarPorColorSeleccionado(
                    listaBicicletas,
                    tamBicicletas,
                    listaColores,
                    tamColores,
                    listaTipos,
                    tamTipos,
                    listaClientes,
                    tamClientes
                );
                break;
            case 2:
                informes_encabezadoSubMenu();
                informes_bicicletas_mostrarPorTipoSeleccionado(
                    listaBicicletas,
                    tamBicicletas,
                    listaColores,
                    tamColores,
                    listaTipos,
                    tamTipos,
                    listaClientes,
                    tamClientes
                );
                break;
            case 3:
                informes_encabezadoSubMenu();
                informes_bicicletas_ordenarPorMenorRodado(
                    listaBicicletas,
                    tamBicicletas
                );
                bicicletas_imprimirLista(
                    listaBicicletas,
                    tamBicicletas,
                    listaTipos,
                    tamTipos,
                    listaColores,
                    tamColores,
                    listaClientes,
                    tamClientes
                );
                break;
            case 4:
                informes_encabezadoSubMenu();
                informes_bicicletas_ordenarPorTipo(
                    listaBicicletas,
                    tamBicicletas,
                    listaTipos,
                    tamTipos
                );
                bicicletas_imprimirLista(
                    listaBicicletas,
                    tamBicicletas,
                    listaTipos,
                    tamTipos,
                    listaColores,
                    tamColores,
                    listaClientes,
                    tamClientes
                );
                break;
            case 5:
                informes_encabezadoSubMenu();
                informes_bicicletas_contarPorTipoYColor(
                    listaBicicletas,
                    tamBicicletas,
                    listaTipos,
                    tamTipos,
                    listaColores,
                    tamColores,
                    listaClientes,
                    tamClientes
                );
                break;
            case 6:
                informes_encabezadoSubMenu();
                informes_bicicletas_coloresMasElegidos(
                    listaBicicletas,
                    tamBicicletas,
                    listaColores,
                    tamColores
                );
                break;
            case 7:
                informes_encabezadoSubMenu();
                informes_trabajos_TrabajosxBicicletas(
                    listaBicicletas,
                    tamBicicletas,
                    listaTipos,
                    tamTipos,
                    listaColores,
                    tamColores,
                    listaClientes,
                    tamClientes,
                    listaTrabajos,
                    tamTrabajos,
                    listaServicios,
                    tamServicios
                );
                break;
            case 8:
                informes_encabezadoSubMenu();
                informes_servicios_precio(
                    listaBicicletas,
                    tamBicicletas,
                    listaTipos,
                    tamTipos,
                    listaColores,
                    tamColores,
                    listaClientes,
                    tamClientes,
                    listaTrabajos,
                    tamTrabajos,
                    listaServicios,
                    tamServicios
                );
                break;
            case 9:
                printf("\nOpcion en mantenimiento\n");
                break;
            case 10:
                printf("\nOpcion en mantenimiento\n");
                break;
            case 11:
                printf("\nVolviendo al menu principal...\n");
                break;
            }
            error = 0;
            system("pause");
        }
    }
    while(subMenu_opcionSeleccionada != 11);

    return error;
}

int informes_bicicletas_mostrarPorColorSeleccionado(
    eBicicleta* listaBicicletas,
    int tamBicicletas,
    eColor* listaColores,
    int tamColores,
    eTipo* listaTipos,
    int tamTipos,
    eCliente* listaClientes,
    int tamClientes
)
{
    int error = -1;
    int colorIDValido;
    int colorValido;
    if(
        listaBicicletas != NULL &&
        tamBicicletas > 0 &&
        listaColores != NULL
        && tamColores > 0 &&
        listaTipos != NULL &&
        tamTipos > 0 &&
        listaClientes != NULL &&
        tamClientes > 0)
    {
        printf("\n Ingrese ID color\n");
        colores_imprimirLista(listaColores, tamColores);
        printf("\nIngrese ID: ");
        fflush(stdin);
        scanf("%d", &colorValido);
        colorIDValido = colores_buscarPorID(
                            listaColores,
                            tamColores,
                            colorValido
                        );
        while(colorIDValido < 0)
        {
            printf("\n Dato invalido. Ingrese ID color: ");
            fflush(stdin);
            scanf("%d", &colorValido);
            colorIDValido = colores_buscarPorID(
                                listaColores,
                                tamColores,
                                colorValido
                            );
        }
        //LISTAR
        informes_bicicletas_encabezado();
        for(int i = 0; i < tamBicicletas; i++)
        {
            if(listaBicicletas[i].idColor == colorValido)
            {
                bicicletas_imprimirItem(
                    listaBicicletas[i],
                    listaTipos,
                    tamTipos,
                    listaColores,
                    tamColores,
                    listaClientes,
                    tamClientes
                );
            }
        }

        error = 0;
    }
    return error;
}

int informes_bicicletas_mostrarPorTipoSeleccionado(
    eBicicleta* listaBicicletas,
    int tamBicicletas,
    eColor* listaColores,
    int tamColores,
    eTipo* listaTipos,
    int tamTipos,
    eCliente* listaClientes,
    int tamClientes
)
{
    int error = -1;
    int tipoIDValido;
    int tipoValido;
    if(
        listaBicicletas != NULL &&
        tamBicicletas > 0 &&
        listaColores != NULL
        && tamColores > 0 &&
        listaTipos != NULL &&
        tamTipos > 0 &&
        listaClientes != NULL &&
        tamClientes > 0)
    {
        printf("\n Ingrese ID tipo\n");
        tipos_imprimirLista(listaTipos, tamTipos);
        printf("\nIngrese ID: ");
        fflush(stdin);
        scanf("%d", &tipoValido);
        tipoIDValido = tipos_encontrarPorID(
                           listaTipos,
                           tamTipos,
                           tipoValido
                       );
        while(tipoIDValido < 0)
        {
            printf("\n Dato invalido. Ingrese ID tipo: ");
            fflush(stdin);
            scanf("%d", &tipoValido);
            tipoIDValido = tipos_encontrarPorID(
                               listaTipos,
                               tamTipos,
                               tipoValido
                           );
        }
        //LISTAR
        informes_bicicletas_encabezado();
        for(int i = 0; i < tamBicicletas; i++)
        {
            if(listaBicicletas[i].idTipo == tipoValido)
            {
                bicicletas_imprimirItem(
                    listaBicicletas[i],
                    listaTipos,
                    tamTipos,
                    listaColores,
                    tamColores,
                    listaClientes,
                    tamClientes
                );
            }
        }

        error = 0;
    }
    return error;
}

void informes_encabezadoSubMenu()
{
    system("cls");
    printf("_________________________________________________________________________________________________________\n");
    printf("                                            MENU DE INFORMES          \n");
    printf("_________________________________________________________________________________________________________\n");
    printf("                                          SISTEMA BICICLETERIA                    \n");
    printf("_________________________________________________________________________________________________________\n");
}

void informes_bicicletas_encabezado()
{
    system("cls");
    printf("_________________________________________________________________________________________________________\n");
    printf("                                                BICICLETAS      \n");
    printf("_________________________________________________________________________________________________________\n");
    printf("  ID            MARCA                TIPO                COLOR           RODADO             CLIENTE               \n");
    printf("_________________________________________________________________________________________________________\n");
}

void informes_trabajos_encabezado()
{
    system("cls");
    printf("_________________________________________________________________________________________________________\n");
    printf("                                                TRABAJOS      \n");
    printf("_________________________________________________________________________________________________________\n");
    printf("  ID            SERVICIO                      BICICLETA                     FECHA      \n");
    printf("_________________________________________________________________________________________________________\n");
}

int informes_bicicletas_ordenarPorMenorRodado(eBicicleta* lista,int tam)
{
    int error = -1;
    eBicicleta auxBici;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam-1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(lista[i].rodado > lista[j].rodado)
                {
                    auxBici = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxBici;
                }
            }
        }
        error = 0;
    }

    return error;
}

int informes_bicicletas_ordenarPorTipo(
    eBicicleta* lista,
    int tam,
    eTipo* tipos,
    int tamTipos
)
{
    int error = -1;
    eBicicleta auxBici;

    if(lista != NULL && tam > 0 && tipos != NULL && tamTipos > 0)
    {
        for(int i = 0; i < tam-1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(lista[i].idTipo > lista[j].idTipo)
                {
                    auxBici = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxBici;
                }
            }
        }
        error = 0;
    }

    return error;
}

int informes_bicicletas_contarPorTipoYColor(
    eBicicleta* listaBicicletas,
    int tamBicicletas,
    eTipo* listaTipos,
    int tamTipos,
    eColor* listaColores,
    int tamColores,
    eCliente* listaClientes,
    int tamClientes
)
{
    int error = -1;

    int colorIDValido;
    int tipoIDValido;
    int colorValido;
    int tipoValido;
    int contador = 0;

    if(listaBicicletas != NULL &&
            tamBicicletas > 0 &&
            listaTipos != NULL &&
            tamTipos > 0 &&
            listaColores != NULL &&
            tamColores > 0 &&
            listaClientes != NULL &&
            tamClientes > 0 )
    {
        //pedir Tipo
        system("cls");
        printf("\n Ingrese ID tipo\n");
        tipos_imprimirLista(listaTipos, tamTipos);
        printf("\nIngrese ID: ");
        fflush(stdin);
        scanf("%d", &tipoValido);
        tipoIDValido = tipos_encontrarPorID(
                           listaTipos,
                           tamTipos,
                           tipoValido
                       );
        while(tipoIDValido < 0)
        {
            printf("\n Dato invalido. Ingrese ID tipo: ");
            fflush(stdin);
            scanf("%d", &tipoValido);
            tipoIDValido = tipos_encontrarPorID(
                               listaTipos,
                               tamTipos,
                               tipoValido
                           );
        }
        //pedir Color
        system("cls");
        printf("\n Ingrese ID color\n");
        colores_imprimirLista(listaColores, tamColores);
        printf("\nIngrese ID: ");
        fflush(stdin);
        scanf("%d", &colorValido);
        colorIDValido = colores_buscarPorID(
                            listaColores,
                            tamColores,
                            colorValido
                        );
        while(colorIDValido < 0)
        {
            printf("\n Dato invalido. Ingrese ID color: ");
            fflush(stdin);
            scanf("%d", &colorValido);
            colorIDValido = colores_buscarPorID(
                                listaColores,
                                tamColores,
                                colorValido
                            );
        }
        //mostrar por tipo y color, sino no hay bicicletas con esas caracteristicas
        informes_bicicletas_encabezado();
        for(int i = 0; i < tamBicicletas; i++)
        {
            if(listaBicicletas[i].idTipo == tipoValido && listaBicicletas[i].idColor == colorValido)
            {
                bicicletas_imprimirItem(
                    listaBicicletas[i],
                    listaTipos,
                    tamTipos,
                    listaColores,
                    tamColores,
                    listaClientes,
                    tamClientes
                );
                contador++;
            }
        }
        if(contador == 0)
        {
            printf("\nNo hay bicicletas con esas caracteristicas\n");
        }
        else
        {
            printf("\nHay %d bicicleta/s con esas caracteristicas\n", contador);
        }


        error = 0;
    }

    return error;
}

int informes_bicicletas_coloresMasElegidos(
    eBicicleta* listaBicicletas,
    int tamBicicletas,
    eColor* listaColores,
    int tamColores
)
{
    int error = -1;
    int contadorGris = 0;
    int contadorNegro = 0;
    int contadorBlanco = 0;
    int contadorAzul = 0;
    int contadorRojo = 0;
    char descripcionColor[21];

    if(
        listaBicicletas != NULL &&
        tamBicicletas > 0 &&
        listaColores != NULL &&
        tamColores > 0)
    {
        for(int i = 0; i < tamBicicletas; i++)
        {
            switch(listaBicicletas[i].idColor)
            {
            case 5000:
                contadorGris++;
                break;
            case 5001:
                contadorNegro++;
                break;
            case 5002:
                contadorBlanco++;
                break;
            case 5003:
                contadorAzul++;
                break;
            case 5004:
                contadorRojo++;
                break;
            }
        }
        //Obtener el mayor contador
        system("cls");
        if(contadorGris > contadorNegro && contadorGris > contadorBlanco && contadorGris > contadorAzul && contadorGris > contadorRojo)
        {
            colores_cargarNombre(listaColores,tamColores, 5000, descripcionColor);
            printf("\nEl tipo mas elegido es %s\n", descripcionColor);
        }
        else if(contadorNegro >= contadorGris && contadorNegro > contadorBlanco && contadorNegro > contadorAzul && contadorNegro > contadorRojo)
        {
            colores_cargarNombre(listaColores,tamColores, 5001, descripcionColor);
            printf("\nEl tipo mas elegido es %s\n", descripcionColor);
        }
        else if(contadorBlanco >= contadorNegro && contadorBlanco > contadorGris && contadorBlanco > contadorAzul && contadorBlanco > contadorRojo)
        {
            colores_cargarNombre(listaColores,tamColores, 5002, descripcionColor);
            printf("\nEl tipo mas elegido es %s\n", descripcionColor);
        }
        else if(contadorAzul >= contadorBlanco && contadorAzul > contadorGris && contadorAzul > contadorNegro && contadorAzul > contadorRojo)
        {
            colores_cargarNombre(listaColores,tamColores, 5003, descripcionColor);
            printf("\nEl tipo mas elegido es %s\n", descripcionColor);
        }
        else
        {
            colores_cargarNombre(listaColores,tamColores, 5004, descripcionColor);
            printf("\nEl tipo mas elegido es %s\n", descripcionColor);
        }

        error = 0;
    }

    return error;
}

int informes_trabajos_TrabajosxBicicletas(
    eBicicleta* listaBicicletas,
    int tamBicicletas,
    eTipo* listaTipos,
    int tamTipos,
    eColor* listaColores,
    int tamColores,
    eCliente* listaClientes,
    int tamClientes,
    eTrabajo* listaTrabajos,
    int tamTrabajos,
    eServicio* listaServicios,
    int tamServicios)
{
    int error = -1;
    int biciValida;
    int biciIDValido;

    if(
        listaBicicletas != NULL &&
        tamBicicletas > 0 &&
        listaTipos != NULL &&
        tamTipos > 0 &&
        listaColores != NULL &&
        tamColores > 0 &&
        listaClientes != NULL &&
        tamClientes > 0 &&
        listaTrabajos != NULL &&
        tamTrabajos > 0 &&
        listaServicios != NULL &&
        tamServicios > 0
    )
    {
        //Pedir bici
        system("cls");
        printf("\n Ingrese ID bicicleta\n");
        bicicletas_imprimirLista(
            listaBicicletas,
            tamBicicletas,
            listaTipos,
            tamTipos,
            listaColores,
            tamColores,
            listaClientes,
            tamClientes
        );
        printf("\nIngrese ID: ");
        fflush(stdin);
        scanf("%d", &biciValida);
        biciIDValido = bicicletas_buscarPorID(
                           listaBicicletas,
                           tamBicicletas,
                           biciValida
                       );
        while(biciIDValido < 0)
        {
            printf("\n Dato invalido. Ingrese ID bicicleta: ");
            fflush(stdin);
            scanf("%d", &biciValida);
            biciIDValido = bicicletas_buscarPorID(
                               listaBicicletas,
                               tamBicicletas,
                               biciValida
                           );
        }

        //listar trabajos que se le hicieron a esa bicicleta
        informes_trabajos_encabezado();

        for(int i = 0; i < tamTrabajos; i++)
        {
            if(listaTrabajos[i].idBicicleta == biciValida)
            {
                trabajos_imprimirItem(listaTrabajos[i],
                                      listaBicicletas,
                                      tamBicicletas,
                                      listaServicios,
                                      tamServicios
                                     );
            }
        }
        error = 0;
    }
    return error;
}


int informes_servicios_precio(
    eBicicleta* listaBicicletas,
    int tamBicicletas,
    eTipo* listaTipos,
    int tamTipos,
    eColor* listaColores,
    int tamColores,
    eCliente* listaClientes,
    int tamClientes,
    eTrabajo* listaTrabajos,
    int tamTrabajos,
    eServicio* listaServicios,
    int tamServicios)
{
    int error = -1;
    int biciValida;
    int biciIDValido;
    int idServicioActual;
    float acumPrecio = 0;

    if(
        listaBicicletas != NULL &&
        tamBicicletas > 0 &&
        listaTipos != NULL &&
        tamTipos > 0 &&
        listaColores != NULL &&
        tamColores > 0 &&
        listaClientes != NULL &&
        tamClientes > 0 &&
        listaTrabajos != NULL &&
        tamTrabajos > 0 &&
        listaServicios != NULL &&
        tamServicios > 0
    )
    {
        //Pedir bici
        system("cls");
        printf("\n Ingrese ID bicicleta\n");
        bicicletas_imprimirLista(
            listaBicicletas,
            tamBicicletas,
            listaTipos,
            tamTipos,
            listaColores,
            tamColores,
            listaClientes,
            tamClientes
        );
        printf("\nIngrese ID: ");
        fflush(stdin);
        scanf("%d", &biciValida);
        biciIDValido = bicicletas_buscarPorID(
                           listaBicicletas,
                           tamBicicletas,
                           biciValida
                       );
        while(biciIDValido < 0)
        {
            printf("\n Dato invalido. Ingrese ID bicicleta: ");
            fflush(stdin);
            scanf("%d", &biciValida);
            biciIDValido = bicicletas_buscarPorID(
                               listaBicicletas,
                               tamBicicletas,
                               biciValida
                           );
        }

        //listar trabajos que se le hicieron a esa bicicleta
        informes_trabajos_encabezado();

        for(int i = 0; i < tamTrabajos; i++)
        {
            if(listaTrabajos[i].idBicicleta == biciValida)
            {
                idServicioActual = listaTrabajos[i].idServicio;
                for(int j = 0; j < tamServicios; j++)
                {
                    if(listaServicios[j].id == idServicioActual)
                    {
                        acumPrecio += listaServicios[j].precio;
                    }
                }
            }

        }

        printf("\nTotal trabajos realizados en esta bicicleta: $ %.2f\n", acumPrecio);
        error = 0;
    }
    return error;
}

int informes_serviciosxBicicletas(
    eBicicleta* listaBicicletas,
    int tambicicletas,
    eServicio* listaServicios,
    int tamServicios,
    eTrabajo* listaTrabajos,
    int tamTrabajos
)
{
    int error = -1;
    int servicioValido;
    int servicioIdValido = 0;

    if(
        listaBicicletas != NULL &&
        tambicicletas > 0 &&
        listaServicios != NULL &&
        tamServicios > 0
        listaTrabajos != NULL &&
        tamTrabajos > 0)
    {

        //pedir un servicio
        system("cls");
        printf("\n Ingrese ID Servicio\n");
        servicios_imprimirLista(
            listaServicios,
            tamServicios
        );
        printf("\nIngrese ID: ");
        fflush(stdin);
        scanf("%d", &servicioValido);
        servicioIdValido = servicios_buscarPorID(
                               listaServicios,
                               tamServicios,
                               servicioIdValido
                           );
        while(servicioIdValido < 0)
        {
            printf("\nDato invalido. Ingrese ID: ");
            fflush(stdin);
            scanf("%d", &servicioValido);
            servicioIdValido = servicios_buscarPorID(
                                   listaServicios,
                                   tamServicios,
                                   servicioIdValido
                               );
        }

        //mostrar las bicis que tuvieron ese servicio
        for(int i = 0; i < tamTrabajos; i++){

        }

        error = 0;
    }

    return error;
}
