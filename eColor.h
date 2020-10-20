#ifndef ECOLOR_H_INCLUDED
#define ECOLOR_H_INCLUDED

typedef struct
{
    int id; // comienza en 5000
    char nombreColor[21];
} eColor;

/** \brief Imprime el contenido del array de colores
 *
 * \param lista eColor*
 * \param int tam Tama�o
 * \return int Retorna (-1) si hay un Error [longitud invalida o puntero NULL o no hay espacio] - (0) si esta todo Ok
 *
 */
int colores_imprimirLista(eColor* colores, int tam);

/** \brief Imprime 1 color de la lista de bicicletas
 *
 * \param un eColor
 *
 */
void colores_imprimirItem(eColor color);

/** \brief Encuentra un color por ID retornando su indice en el array
 *
 * \param eColor* lista
 * \param tam int tama�o
 * \param id int
 * \return Retorna la posicion del color en el array o (-1) si [Longitud invalida o puntero NULL
 * o color no encontrado]
 *
 */
int colores_buscarPorID(eColor* lista, int tam, int id);

/** \brief Carga en una cadena de caracteres el nombre del color
 *
 * \param eColor* lista
 * \param int len tama�o
 * \param int ID color
 * \param char* descripcion puntero a descripci�n
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
int colores_cargarNombre(
    eColor* lista,
    int tam,
    int ID,
    char* nombre
);

#endif // ECOLOR_H_INCLUDED
