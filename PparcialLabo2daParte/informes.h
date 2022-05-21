#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "fecha.h"
#include "inputs.h"

#include "mascota.h"
#include "servicio.h"
#include "trabajo.h"

#endif // INFORMES_H_INCLUDED

int informes_menu();
int informes(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamTi, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTr);
int informes_mascotasColor(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT);
int informes_promedioVacunados(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT);
int informes_mascotasMenosEdad(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT);
int informes_mascotasTipo(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT);
int informes_mascotasColorTipoxUsuario(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT);
int informes_colorMasRepetido(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT);
int informes_trabajosXidMascota(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eTrabajo trabajos[], int tamTr, eServicio servicios[], int tamS);
int informes_costoTrabajosXidMascota(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eTrabajo trabajos[], int tamTr, eServicio servicios[], int tamS);
int informes_serviciosXFecha(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eTrabajo trabajos[], int tamTr, eServicio servicios[], int tamS);
