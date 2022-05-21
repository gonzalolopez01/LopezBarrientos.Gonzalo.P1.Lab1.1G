#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputs.h"
#include "color.h"
#include "tipo.h"

#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    char vacunado;
    int isEmpty;
}eMascota;


#endif // PRIMERO_H_INCLUDED

int harcodearMascotas(eMascota vec[], int tam, int cant, int* pNextId);
int mascotas_inicializarMascotas(eMascota mascotas[], int tam);

int mascotas_menu();

int mascotas_mostrarMascota(eMascota mascota, eColor colores[], int tamC, eTipo tipos[], int tamT);
int mascotas_mostrarMascotaFila(eMascota mascota, eColor colores[], int tamC, eTipo tipos[], int tamT);
int mascotas_listarMascotas(eMascota vec[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);
int mascotas_ordenarMascotasTipoNombre(eMascota vec[], int tam, eTipo tipos[], int tamT);

int mascotas_cargarNombre(char nombre[]);
int mascotas_cargarTipo(int* idTipo, eTipo tipos[], int tamT);
int mascotas_cargarColor(int* idColor, eColor colores[], int tamC);
int mascotas_cargarEdad(int* edad);
int mascotas_cargarEsVacunado(char* vacunado);
int mascotas_cargarMascota(eMascota* pMascota, eColor colores[], int tamC, eTipo tipos[], int tamT);
int mascotas_buscarLibre(eMascota vec[], int tam, int* pIndex);
int mascotas_altaMascota(eMascota vec[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT, int* pNextId);



int mascotas_buscarId(eMascota vec[], int tam, int id, int* pIndice);
int mascotas_bajaMascota(eMascota vec[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);
int mascotas_menuModificarMascota();
int mascotas_modificarMascota(eMascota vec[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);

int mascotas_cargarNombreCadena(eMascota mascotas[], int tam, int id, char desc[]);
int mascotas_validarMascota(eMascota vec[],int tam, int id);

//-------------------

int mascotas_mascotasXIdColore(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, int idColor);
int mascotas_mascotasXIdTipo(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, int idTipo);
