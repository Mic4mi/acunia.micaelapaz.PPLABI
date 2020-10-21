#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

/** \brief Imprime un submenu de opciones de informes
 *
 *
 */
void informes_subMenu();

/** \brief Imprime el encabezado de un submenu de opciones de informes
 *
 *
 */
void informes_encabezadoSubMenu();

/** \brief Imprime el encabezado para bicicletas
 *
 *
 */
void informes_bicicletas_encabezado();

/** \brief Imprime el encabezado para trabajos
 *
 *
 */
void informes_trabajos_encabezado();

/** \brief Imprime un submenu de informes
 *
 * \param eBicicleta* listaBicicletas
 * \param int tamBicicletas
 * \param  eColor* listaColores
 * \param  int tamColores
 * \param eTipo* listaTipos
 * \param int tamTipos
 * \param eCliente* listaClientes
 * \param int tamClientes
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
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
    int tamServicios);

/** \brief Muestra por color seleccionado
 *
 * \param eBicicleta* listaBicicletas
 * \param int tamBicicletas
 * \param  eColor* listaColores
 * \param  int tamColores
 * \param eTipo* listaTipos
 * \param int tamTipos
 * \param eCliente* listaClientes
 * \param int tamClientes
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
int informes_bicicletas_mostrarPorColorSeleccionado(
    eBicicleta* listaBicicletas,
    int tamBicicletas,
    eColor* listaColores,
    int tamColores,
    eTipo* listaTipos,
    int tamTipos,
    eCliente* listaClientes,
    int tamClientes
);

/** \brief Imprime por tipo seleccionado
 *
 * \param eBicicleta* listaBicicletas
 * \param int tamBicicletas
 * \param  eColor* listaColores
 * \param  int tamColores
 * \param eTipo* listaTipos
 * \param int tamTipos
 * \param eCliente* listaClientes
 * \param int tamClientes
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
int informes_bicicletas_mostrarPorTipoSeleccionado(
    eBicicleta* listaBicicletas,
    int tamBicicletas,
    eColor* listaColores,
    int tamColores,
    eTipo* listaTipos,
    int tamTipos,
    eCliente* listaClientes,
    int tamClientes
);

/** \brief Ordena un array de bicicletas por rodado
 *
 * \param eBicicleta* listaBicicletas
 * \param int tamBicicletas
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
int informes_bicicletas_ordenarPorMenorRodado(eBicicleta* lista,int tam);

/** \brief Ordena un array de bicicletas por tipo
 *
 * \param eBicicleta* listaBicicletas
 * \param int tamBicicletas
 * \param eTipo* listaTipos
 * \param int tamTipos
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
int informes_bicicletas_ordenarPorTipo(
    eBicicleta* lista,
    int tam,
    eTipo* tipos,
    int tamTipos
);

/** \brief Cuenta e imprime la cantidas de eBicicleta de un array
 * de bicicletas por tipo y color seleccionado
 *
 * \param eBicicleta* listaBicicletas
 * \param int tamBicicletas
 * \param eTipo* listaTipos
 * \param  eColor* listaColores
 * \param  int tamColores
 * \param int tamTipos
 * \param eCliente* listaClientes
 * \param int tamClientes
 * \return int Retorna (-1) si hay un error
 * [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
int informes_bicicletas_contarPorTipoYColor(
    eBicicleta* listaBicicletas,
    int tamBicicletas,
    eTipo* listaTipos,
    int tamTipos,
    eColor* listaColores,
    int tamColores,
    eCliente* listaClientes,
    int tamClientes
);

/** \brief Imprime cual fue el color mas elegido
 *
 * \param eBicicleta* listaBicicletas
 * \param int tamBicicletas
 * \param eColor* listaColores
 * \param int tamColores
 * \return int Retorna (-1) si hay un error
 * [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
int informes_bicicletas_coloresMasElegidos(
    eBicicleta* listaBicicletas,
    int tamBicicletas,
    eColor* listaColores,
    int tamColores
);

/** \brief Imprime los trabajos realizados a una bicicleta
 *
 * \param eBicicleta* listaBicicletas
 * \param int tamBicicletas
 * \param  eColor* listaColores
 * \param  int tamColores
 * \param eTipo* listaTipos
 * \param int tamTipos
 * \param eCliente* listaClientes
 * \param int tamClientes
 * \param eTrabajo* listaTrabajos
 * \param int tamTrabajos
 * \param eServicio* listaServicios
 * \param int tamServicios
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
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
    int tamServicios);

/** \brief Imprime los precios realizados a una bicicleta
 *
 * \param eBicicleta* listaBicicletas
 * \param int tamBicicletas
 * \param  eColor* listaColores
 * \param  int tamColores
 * \param eTipo* listaTipos
 * \param int tamTipos
 * \param eCliente* listaClientes
 * \param int tamClientes
 * \param eTrabajo* listaTrabajos
 * \param int tamTrabajos
 * \param eServicio* listaServicios
 * \param int tamServicios
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
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
    int tamServicios);

/** \brief Imprime los servicios realizados a una bicicleta
 *
 * \param eBicicleta* listaBicicletas
 * \param int tamBicicletas
 * \param  eColor* listaColores
 * \param  int tamColores
 * \param eTipo* listaTipos
 * \param int tamTipos
 * \param eCliente* listaClientes
 * \param int tamClientes
 * \param eTrabajo* listaTrabajos
 * \param int tamTrabajos
 * \param eServicio* listaServicios
 * \param int tamServicios
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
int informes_serviciosxBicicletas(
    eBicicleta* listaBicicletas,
    int tambicicletas,
    eServicio* listaServicios,
    int tamServicios,
    eTrabajo* listaTrabajos,
    int tamTrabajos,
    eTipo* listaTipos,
    int tamTipos,
    eColor* listaColores,
    int tamColores,
    eCliente* listaclientes,
    int tamClientes
);

/** \brief Imprime los servicios realizados en una fecha
 *
 * \param eTrabajo* listaTrabajos
 * \param int tamTrabajos
 * \param eServicio* listaServicios
 * \param int tamServicios
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
int informes_fecha_servicios(
    eServicio* listaServicio,
    int tamServicio,
    eTrabajo* listaTrabajos,
    int tamTrabajos);

#endif // INFORMES_H_INCLUDED
