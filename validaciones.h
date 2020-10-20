#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

/** \brief Valida el input de una opcion entera
 *
 * \param int* pResult puntero a resultado
 * \param char* errorMsj
 * \param int min el minimo de la opcion
 * \param int max el maximo de la opcion
 * \return int Retorna (-1) si hay un Error [Longitud invalida o puntero NULL
 *  o el minimo es mayor al maximo] - (0) si esta todo Ok
 *
 */
int validaciones_obtenerOpcion(int* pResultado, char* errorMsj, int min, int max);

/** \brief Le otorga formato a una cadena de caracteres
 *
 * \param char* Nombre cadena de caracteres
 *
 */
void validaciones_formatearCadena(char* cadena);

#endif // VALIDACIONES_H_INCLUDED
