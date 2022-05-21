#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
}eColor;

#endif // COLOR_H_INCLUDED

int colores_cargarNombreColor(eColor colores[], int tam, int id, char desc[]);

void colores_mostrarColor(eColor color);
int colores_listarColores(eColor vec[], int tam);

int colores_buscarColor(eColor vec[], int tam, int id, int* pIndice);

int colores_validarColor(eColor vec[],int tam, int id);
