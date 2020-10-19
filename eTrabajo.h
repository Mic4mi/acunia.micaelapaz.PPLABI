#ifndef ETRABAJO_H_INCLUDED
#define ETRABAJO_H_INCLUDED
#include "eFecha.h"
#include "eServicio.h"
#include "eBicicleta.h"

typedef struct{
    int id; //autoincremental
    int idBicicleta; //validar
    int idServicio; // validar
    eFecha fecha; //validar dia mes y anio
    int estaVacio;
}eTrabajo;


//TRABAJOS
int initTrabajos(eTrabajo* list, int len);
int altaTrabajo(eTrabajo* list, int len, int ID, eBicicleta* listaBicis, int lenBicis, eServicio* listaServicios, int lenServicios, eTipo* tiposDeBici, int lenTiposBicis, eColor* coloresDeBicis, int lenColores);
//harcodeo
int hardcodeTrabajos(eTrabajo* list, int len, int numberOfTrabajos);
//IMPRIMIR
int printTrabajos(eTrabajo* list, int len, eBicicleta* bicicletas, int lenBicis, eServicio* servicios, int lenServicios);
void showTrabajo(eTrabajo trabajo, eBicicleta* bicicletas, int lenBicis, eServicio* servicios, int lenServicios);
#endif // ETRABAJO_H_INCLUDED
