#ifndef ETIPO_H_INCLUDED
#define ETIPO_H_INCLUDED

typedef struct{
    int id; //comienza en 1000
    char descripcion[30];
}eTipo;

/** \brief Imprime el contenido del array de tipos
 * \param lista eTipo*
 * \param int tam Tamaño
 * \return int Retorna (-1) si hay un Error [longitud invalida o puntero NULL o no hay espacio] - (0) si esta todo Ok
 *
 */
int tipos_imprimirLista(eTipo* tipos, int tam);

/** \brief Imprime 1 tipo de la lista de bicicletas
 *
 * \param un eTipo
 *
 */
void tipos_imprimirItem(eTipo tipo);

/** \brief Encuentra un tipo por ID retornando su indice en el array
 *
 * \param eColor* lista
 * \param tam int tamaño
 * \param id int
 * \return Retorna la posicion del tipo en el array o (-1) si [Longitud invalida o puntero NULL
 * o tipo no encontrado]
 *
 */
int tipos_encontrarPorID(eTipo* lista, int tam, int id);

/** \brief Carga en una cadena de caracteres la descripción del tipo
 *
 * \param etipo* lista
 * \param int len tamaño
 * \param int ID color
 * \param char* descripcion puntero a descripción
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
int tipos_cargarDesc(eTipo* lista, int tam, int ID, char* descripcion);

#endif // ETIPO_H_INCLUDED
