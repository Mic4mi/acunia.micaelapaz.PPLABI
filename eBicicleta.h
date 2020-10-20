#ifndef EBICICLETA_H_INCLUDED
#define EBICICLETA_H_INCLUDED
#include "eColor.h"
#include "eTipo.h"

typedef struct{
    int id;
    char marca[30];
    int idTipo;
    int idColor;
    float rodado;
    int estaVacio;
}eBicicleta;

/** \brief Imprime el menu principal
 *
 */
void menu();

/** \brief Para indicar que todas las posiciones del array estan vacias,
 * esta función pone todas las banderas (estaVacio) en TRUE
 * \param lista eBicicleta* puntero al array de bicicletas
 * \param tam int longitud del Array
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
int iniciarBicicletas(eBicicleta* lista, int tam);

/** \brief Encuentra un bicicleta por ID retornando su indice en el array
 *
 * \param eBicicleta* lista
 * \param tam int tamaño
 * \param id int
 * \return Retorna la posicion de la bicicleta en el array o (-1) si [Longitud invalida o puntero NULL
 * o bicicleta no encontrada]
 *
 */
int encontrarBicicletaPorID(eBicicleta* lista, int tam, int id);

/** \brief Con una biblioteca de datos, rellena posiciones libres en un array de eBicicleta
 *
 * \param eBicicleta* lista
 * \param int tam Tamaño
 * \param int numeroDeBicis cantidad de eBicicletas a cargar en el array
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] -
 * (int) entero que indica la cantidad de eBicicletas cargadas si esta todo Ok
 */
int hardcodearBicicletas(eBicicleta* lista, int tam, int numberoDeBicis);

/** \brief añade en una lista existente de bicicletas los valores recibidos como parametros
 * en la primera posición que encuentra libre
 * \param lista eBicicleta*
 * \param tam int
 * \param ID int
 * \param lista eTipo*
 * \param tamTipos int
 * \param lista eColor*
 * \param tamColores int
 * \return int Retorna (-1) si hay un Error [longitud invalida o puntero NULL o no hay espacio] - (0) si esta todo Ok
 *
 */
int agregarBicicleta(eBicicleta* lista, int tam, int ID, eTipo* listaTipos, int tamTipos, eColor* listaColores, int tamColores);

/** \brief Permite abrir un submenu para modificar datos de una bicicleta
 *
 * \param lista eBicicleta*
 * \param tam int
 * \param lista eTipo*
 * \param tamTipos int
 * \param lista eColor*
 * \param tamColores int
 * \return int Retorna (-1) si hay un Error [longitud invalida o puntero NULL
 * o no encuentra el id de la bicicleta] - (0) si esta todo Ok - (1) Si el usuario cancela la modificacion
 *
 */
int modificarBicicleta(eBicicleta* lista, int tam, eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor);

/** \brief Elmina un empleado por su id (pone la bandera EstaVacio en 1)
 *
 * \param lista eBicicleta*
 * \param tam int
 * \param lista eTipo*
 * \param tamTipos int
 * \param lista eColor*
 * \param tamColores int
 * \return int Retorna (-1) si hay un Error [longitud invalida o puntero NULL
 * o no encuentra el id de la bicicleta] - (0) si esta todo Ok - (1) Si el usuario cancela la baja
 *
 */
int eliminarBicicleta(eBicicleta* lista, int tam, eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor);

/** \brief Imprime el contenido del array de bicicleta
 *
 * \param list eBicicleta*
 * \param int tam Tamaño
 * \param lista eTipo*
 * \param tamTipos int
 * \param lista eColor*
 * \param tamColores int
 * \return int Retorna (-1) si hay un Error [longitud invalida o puntero NULL o no hay espacio] - (0) si esta todo Ok
 *
 */
int imprimirBicicletas(eBicicleta* lista, int tam, eTipo* tipos, int tamTipos, eColor* colores, int tamColores);

/** \brief Imprime 1 bicicleta de la lista de bicicletas
 *
 * \param una eBicicleta
 * \param lista eTipo*
 * \param tamTipos int
 * \param lista eColor*
 * \param tamColores int
 *
 */
void mostrarBicicleta(eBicicleta bici, eTipo* tipos, int tamTipos, eColor* colores, int tamColores);

/** \brief Carga en una cadena de caracteres la marca de la biciclieta
 *
 * \param eBicicleta* lista
 * \param int len Bicicletas
 * \param int ID Bicicleta
 * \param char* descripcion puntero a descripción
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
int cargarDescMarca(eBicicleta* lista, int len, int ID, char* descripcion);


#endif // EBICICLETA_H_INCLUDED
