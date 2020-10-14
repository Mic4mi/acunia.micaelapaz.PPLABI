#ifndef ETIPO_H_INCLUDED
#define ETIPO_H_INCLUDED

typedef struct{
    int id; //comienza en 1000
    char descripcion[30];
}eTipo;

int showTipos(eTipo* tipos, int len);
void showTipo(eTipo tipo);
int findTipoById(eTipo* list, int len, int id);
int cargarDescTipo(eTipo* lista, int len, int ID, char* descripcion);
#endif // ETIPO_H_INCLUDED
