#ifndef ESERVICIO_H_INCLUDED
#define ESERVICIO_H_INCLUDED

typedef struct{
    int id; //comienza en 20000
    char descripcion[30];
    float precio;
}eServicio;


/** \brief Imprime el contenido del array de servicios
 *
 * \param lista eServicio*
 * \param int tam Tamaño
 * \return int Retorna (-1) si hay un Error [longitud invalida o puntero NULL o no hay espacio] - (0) si esta todo Ok
 *
 */
int imprimirServicios(eServicio* servicios, int tam);

/** \brief Imprime 1 servicio de la lista de bicicletas
 *
 * \param un eColor
 *
 */
void mostrarServicio(eServicio servicio);

/** \brief Encuentra un servicio por ID retornando su indice en el array
 *
 * \param eServicio* lista
 * \param tam int tamaño
 * \param id int
 * \return Retorna la posicion del servicio en el array o (-1) si [Longitud invalida o puntero NULL
 * o servicio no encontrado]
 *
 */
int econtrarServicioPorID(eServicio* lista, int tam, int id);

/** \brief Carga en una cadena de caracteres el nombre del servicio
 *
 * \param eServicio* lista
 * \param int len tamaño
 * \param int ID servicio
 * \param char* descripcion puntero a descripción
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
int cargarDescServ(eServicio* lista, int tam, int ID, char* descripcion);

#endif // ESERVICIO_H_INCLUDED
