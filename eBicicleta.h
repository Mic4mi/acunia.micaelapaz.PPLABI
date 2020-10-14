#ifndef EBICICLETA_H_INCLUDED
#define EBICICLETA_H_INCLUDED

typedef struct{
    int id;
    char marca[30];
    int idTipo;
    int idColor;
    float rodado;
    int estaVacio;
}eBicicleta;

void menu();
int getOption(int* pResult, char* errorMsj, int min, int max);
int initBicis(eBicicleta* list, int len);
int findBiciById(eBicicleta* list, int len,int id);
int hardcodeBicis(eBicicleta* list, int len, int numberOfBicis);
//validacion, mover a otra biblioteca
void formatName(char* name);
//add
int addBici(eBicicleta* list, int len, int ID, eTipo* listaTipos, int lenTipos, eColor* listaColores, int lenColores);
//print
int printBicis(eBicicleta* list, int len, eTipo* tipos, int lenTipos, eColor* colores, int lenColores);
void showBici(eBicicleta bici, eTipo* tipos, int lenTipos, eColor* colores, int lenColores);

#endif // EBICICLETA_H_INCLUDED
