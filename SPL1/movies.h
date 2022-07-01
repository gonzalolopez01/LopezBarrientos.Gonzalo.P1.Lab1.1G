#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

typedef struct{
    int id;
    char nombre[50];
    char genero[50];
    int duracion;
}ePelicula;


#endif // MOVIES_H_INCLUDED

ePelicula* elemento_new();
ePelicula* elemento_newParametrosStr(char* id, char* nombre, char* genero, char* duracion);
void elemento_delete(ePelicula* pElemento);

int elemento_setId(ePelicula* this, int id);
int elemento_getId(ePelicula* this, int* id);

int elemento_setNombre(ePelicula* this, char* nombre);
int elemento_getNombre(ePelicula* this, char* nombre);

int elemento_setGenero(ePelicula* this, char* genero);
int elemento_getGenero(ePelicula* this, char* genero);

int elemento_setDuracion(ePelicula* this, int duracion);
int elemento_getDuracion(ePelicula* this, int* duracion);

int elemento_mostrarElementoFila(ePelicula* pElemento);

void* elemento_map(void* elemento);
int obtenerAleatorioEntero(int min, int max);

int elemento_criterioGenero(void* aux1, void* aux2);
