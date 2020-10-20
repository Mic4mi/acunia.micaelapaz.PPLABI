#ifndef ETRABAJO_H_INCLUDED
#define ETRABAJO_H_INCLUDED
#include "eFecha.h"
#include "eServicio.h"
#include "eBicicleta.h"

typedef struct
{
    int id; //autoincremental
    int idBicicleta; //validar
    int idServicio; // validar
    eFecha fecha; //validar dia mes y anio
    int estaVacio;
} eTrabajo;


/** \brief Para indicar que todas las posiciones del array estan vacias,
 * esta función pone todas las banderas (estaVacio) en TRUE
 * \param lista eTrabajo* puntero al array de trabajos
 * \param tam int longitud del Array
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
int trabajos_inicializar(eTrabajo* lista, int tam);

/** \brief Con una biblioteca de datos, rellena posiciones libres en un array de eTrabajo
 *
 * \param eTrabajo* lista
 * \param int tam Tamaño
 * \param int numeroDeTrabajos cantidad de eTrabajo a cargar en el array
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] -
 * (int) entero que indica la cantidad de eTrabajo cargadas si esta todo Ok
 */
int trabajos_hardcodear(eTrabajo* lista, int tam, int numeroDeTrabajos);

/** \brief añade en una lista existente de trabajos los valores recibidos como parametros
 * en la primera posición que encuentra libre
 * \param lista eTrabajo*
 * \param tam int
 * \param ID int
 * \param lista eBicicleta*
 * \param tamBicis int tamaño
 * \param lista eServicio*
 * \param tamServicios int tamaño
 * \param lista eTipo*
 * \param tamTipos int
 * \param lista eColor*
 * \param tamColores int
 * \return int Retorna (-1) si hay un Error [longitud invalida o puntero NULL o no hay espacio] - (0) si esta todo Ok
 *
 */
int trabajos_agregar(
    eTrabajo* lista,
    int tam,
    int ID,
    eBicicleta* listaBicis,
    int tamBicis,
    eServicio* listaServicios,
    int tamServicios,
    eTipo* tiposDeBici,
    int tamTiposBicis,
    eColor* coloresDeBicis,
    int tamColores);

/** \brief Imprime el contenido del array de trabajo
 *
 * \param lista eTrabajo*
 * \param tam int
 * \param lista eBicicleta*
 * \param tamBicis int tamaño
 * \param lista eServicio*
 * \param tamServicios int tamaño
 * \return int Retorna (-1) si hay un Error [longitud invalida o puntero NULL o no hay espacio] - (0) si esta todo Ok
 *
 */
int trabajos_imprimirLista(
    eTrabajo* lista,
    int tam,
    eBicicleta* bicicletas,
    int tamBicis,
    eServicio* servicios,
    int tamServicios);

/** \brief Imprime 1 bicicleta de la lista de bicicletas
 *
 * \param un eTrabajo
 * \param lista eBicicleta*
 * \param tamBicis int tamaño
 * \param lista eServicio*
 * \param tamServicios int tamaño
 *
 */
void trabajos_imprimirItem(
    eTrabajo trabajo,
    eBicicleta* bicicletas,
    int tamBicis,
    eServicio* servicios,
    int tamServicios);
#endif // ETRABAJO_H_INCLUDED
