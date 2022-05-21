#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CUARTO_H_INCLUDED
#define CUARTO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[25];
    float precio;
}eServicio;

#endif // CUARTO_H_INCLUDED

int servicios_cargarServicio(eServicio servicios[], int tam, int id, char desc[]);

void servicios_mostrarServicio(eServicio servicio);
int servicios_listarServicios(eServicio vec[], int tam);

int servicios_buscarId(eServicio vec[], int tam, int id, int* pIndice);

int servicios_validarServicios(eServicio vec[],int tam, int id);
