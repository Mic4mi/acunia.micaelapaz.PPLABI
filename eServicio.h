#ifndef ESERVICIO_H_INCLUDED
#define ESERVICIO_H_INCLUDED

typedef struct{
    int id; //comienza en 20000
    char descripcion[30];
    float precio;
}eServicio;

int showServicios(eServicio* servicios, int len);
void showServicio(eServicio servicio);
int findServicioById(eServicio* list, int len, int id);
int cargarDescServ(eServicio* lista, int len, int ID, char* descripcion);

#endif // ESERVICIO_H_INCLUDED
