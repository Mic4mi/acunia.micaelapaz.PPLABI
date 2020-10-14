#ifndef ECOLOR_H_INCLUDED
#define ECOLOR_H_INCLUDED

typedef struct{
    int id; // comienza en 5000
    char nombreColor[21];
}eColor;

int showColores(eColor* colores, int len);
void showColor(eColor color);
int findColorById(eColor* list, int len, int id);

#endif // ECOLOR_H_INCLUDED
