#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "mascota.h"
#include "color.h"
#include "tipo.h"

#include "servicio.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED


int harcodearTrabajo(eTrabajo vec[], int tam, int cant, int* pNextId);
int trabajo_inicializarTrabajo(eTrabajo vec[], int tam);

int trabajos_mostrarTrabajoFila(eTrabajo trabajo, eMascota mascotas[], int tamM, eServicio servicios[], int tamS);
int trabajos_listarTrabajos(eTrabajo vec[], int tam, eMascota mascotas[], int tamM, eServicio servicios[], int tamS);

int trabajos_cargarIdMascota(int* idMascota, eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT);
int trabajos_cargarIdServicio(int* idServicio, eServicio servicios[], int tamS);
int trabajos_cargarFecha(eFecha *fecha);
int trabajos_cargarTrabajo(eTrabajo* pTrabajo, eMascota mascotas[], int tamM, eColor colores[], int tamC,
                                                eTipo tipos[], int tamT, eServicio servicios[], int tamS);
int trabajos_buscarLibre(eTrabajo vec[], int tam, int* pIndex);
int trabajos_altaTrabajo(eTrabajo vec[], int tam, eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eServicio servicios[], int tamS, int* pNextId);


int trabajos_listarTrabajosXidMascota(eTrabajo vec[], int tam, eMascota mascotas[], int tamM, eServicio servicios[], int tamS, int idMascota);
int trabajos_costoTrabajosXidMascota(eTrabajo vec[], int tam, eMascota mascotas[], int tamM, eServicio servicios[], int tamS, int idMascota);
