#include <stdio.h>
#include <stdlib.h>

#include "color.h"
#include "tipo.h"
#include "mascota.h"
#include "servicio.h"
#include "trabajo.h"

#include "informes.h"

#define TAMM 20
#define TAMC 5
#define TAMTIPO 5

#define TAMS 3
#define TAMT 10

int main()
{

    //int flag1 = 0;
    //int flag8 = 0;
    int nextIdMascota = 100;
    int nextIdTrabajo = 200;
    eMascota mascotas[TAMM];

	eTipo tipos[TAMTIPO] = {
                            {1000, "Ave"},
                            {1001, "Perro"},
                            {1002, "Roedor"},
                            {1003, "Gato"},
                            {1004, "Pez"}
                            };
    eColor colores[TAMC] = {
                            {5000, "Negro"},
                            {5001, "Blanco"},
                            {5002, "Rojo"},
                            {5003, "Gris"},
                            {5004, "Azul"}
                            };

    eServicio servicios[TAMS] = {
                                {20000, "Corte", 450},
                                {20001, "Desparasitado", 800},
                                {20002, "Castrado", 600}
                                };

    eTrabajo trabajos[TAMT];


    mascotas_inicializarMascotas(mascotas,TAMM);
    harcodearMascotas(mascotas, TAMM,10,&nextIdMascota);

    trabajo_inicializarTrabajo(trabajos,TAMT);
    harcodearTrabajo(trabajos,TAMT,10,&nextIdTrabajo);




    char salir = 'n';
	do{
		switch(mascotas_menu()){
		case 1:
		    mascotas_altaMascota(mascotas, TAMM, colores, TAMC, tipos, TAMTIPO, &nextIdMascota);
            /*
            if(mascotas_altaMascota(mascotas, TAMM, colores, TAMC, tipos, TAMTIPO, &nextIdMascota)){
                flag1 = 1;
            }*/
			break;
		case 2:
		    mascotas_modificarMascota(mascotas, TAMM, colores, TAMC, tipos, TAMTIPO);
		    /*
		    if(flag1){
                mascotas_modificarMascota(mascotas, TAMM, colores, TAMC, tipos, TAMTIPO);
		    }else{
                printf("Primero debe realizar un alta de mascota.\n");
		    }*/
			break;
		case 3:
		    mascotas_bajaMascota(mascotas, TAMM, colores, TAMC, tipos, TAMTIPO);
		    /*
		    if(flag1){
                mascotas_bajaMascota(mascotas, TAMM, colores, TAMC, tipos, TAMTIPO);
		    }else{
                printf("Primero debe realizar un alta de mascota.\n");
		    }*/
			break;
		case 4:
		    mascotas_ordenarMascotasTipoNombre(mascotas, TAMM, tipos,TAMTIPO);
		    mascotas_listarMascotas(mascotas, TAMM, colores, TAMC, tipos, TAMTIPO);
		    /*
		    if(flag1){
                mascotas_ordenarMascotasTipoNombre(mascotas, TAMM, tipos,TAMTIPO);
                mascotas_listarMascotas(mascotas, TAMM, colores, TAMC, tipos, TAMTIPO);
		    }else{
                printf("Primero debe realizar un alta de mascota.\n");
		    }*/
			break;
		case 5:
            tipos_listarTipos(tipos, TAMTIPO);
			break;
		case 6:
            colores_listarColores(colores, TAMC);
			break;
		case 7:
            servicios_listarServicios(servicios, TAMS);
			break;
		case 8:
		    trabajos_altaTrabajo(trabajos, TAMT, mascotas, TAMM, colores, TAMC, tipos, TAMTIPO, servicios, TAMS, &nextIdTrabajo);
		    /*
		    if(flag1){
                trabajos_altaTrabajo(trabajos, TAMT, mascotas, TAMM, colores, TAMC, tipos, TAMTIPO, servicios, TAMS, &nextIdTrabajo);
                flag8 = 1;
            }else{
                printf("Primero debe realizar un alta de mascota.\n");
		    }*/
			break;
        case 9:
            trabajos_listarTrabajos(trabajos,TAMT,mascotas,TAMM,servicios,TAMS);
            /*
            if(flag8){
                trabajos_listarTrabajos(trabajos,TAMT,mascotas,TAMM,servicios,TAMS);
            }else{
                printf("Primero debe realizar un alta de trabajo.\n");
            }*/
            break;
        case 10:
            informes(mascotas, TAMM, colores, TAMC, tipos, TAMTIPO, servicios, TAMS, trabajos, TAMT);
            break;
        case 11:
            salir = input_ClosedQuestion("Desea salir del programa?[s/n] ", "ERROR, ");
            if(salir == 's'){
                printf("FIN DEL PROGRAMA\n");
            }
			break;
		}
		system("pause");
	}while(salir != 's');



    return 0;
}
