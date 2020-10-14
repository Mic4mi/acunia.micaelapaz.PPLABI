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

#endif // EBICICLETA_H_INCLUDED
