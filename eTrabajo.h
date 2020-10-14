#ifndef ETRABAJO_H_INCLUDED
#define ETRABAJO_H_INCLUDED
#include "eFecha.h"

typedef struct{
    int id; //autoincremental
    int idBicicleta; //validar
    int idServicio; // validar
    eFecha fecha; //validar dia mes y anio
    int estaVacio;
}eTrabajo;

#endif // ETRABAJO_H_INCLUDED
