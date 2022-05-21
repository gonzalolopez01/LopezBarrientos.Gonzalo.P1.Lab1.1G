#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eTipo;


#endif // TIPO_H_INCLUDED

int tipos_cargarDescripcion(eTipo tipos[], int tam, int id, char desc[]);

void tipos_mostrarTipos(eTipo tipo);
int tipos_listarTipos(eTipo vec[], int tam);

int tipos_buscarTipo(eTipo vec[], int tam, int id, int* pIndice);
int tipos_validarTipo(eTipo vec[],int tam, int id);
