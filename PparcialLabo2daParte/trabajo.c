#include "trabajo.h"

int harcodearTrabajo(eTrabajo vec[], int tam, int cant, int* pNextId){
	int retOk = 0;
	eTrabajo trabajos[10]={
                            {0, 100,     20000, {14,12,2020},0},
                            {0, 102,     20000, {17,12,2022},0},
                            {0, 100,     20000, {6,7,2022},0},
                            {0, 103,     20001, {21,12,2020},0},
                            {0, 103,     20000, {1,4,2020},0},
                            {0, 102,     20002, {1,12,2021},0},
                            {0, 101,     20000, {21,12,2020},0},
                            {0, 105,     20002, {23,3,2020},0},
                            {0, 106,     20000, {1,12,2021},0},
                            {0, 109,     20001, {22,10,2020},0}
							};

	if(vec != NULL && tam > 0 && tam <= 10 && cant <= tam){
		for(int i = 0; i < cant; i++){
			vec[i] = trabajos[i];
			vec[i].id = *pNextId;
			(*pNextId)++;

		}
		retOk = 1;
	}
	return retOk;
}


int trabajo_inicializarTrabajo(eTrabajo vec[], int tam){
    int retOk = 0;
    if( vec != NULL && tam > 0){
        for(int i=0; i < tam; i++){
            vec[i].isEmpty = 1;
        }
        retOk = 1;
    }
    return retOk;
}


int trabajos_mostrarTrabajoFila(eTrabajo trabajo, eMascota mascotas[], int tamM, eServicio servicios[], int tamS){
	int retOk = 0;
	if(mascotas != NULL && servicios != NULL && tamM > 0 && tamS > 0){
		char servicio[20];
		char nombre[20];

		mascotas_cargarNombreCadena(mascotas, tamM, trabajo.idMascota, nombre);
		servicios_cargarServicio(servicios,tamS, trabajo.idServicio, servicio);

		printf("%6d    %-18s %-14s %02d/%02d/%d\n", trabajo.id,
                                            nombre,
                                            servicio,
                                            trabajo.fecha.dia,
                                            trabajo.fecha.mes,
                                            trabajo.fecha.anio);
		retOk = 1;
	}
	return retOk;
}
int trabajos_listarTrabajos(eTrabajo vec[], int tam, eMascota mascotas[], int tamM, eServicio servicios[], int tamS){
	int retOK = 0;
	int flag = 1;
	if(vec != NULL && tam > 0 && mascotas != NULL && tamM > 0 && servicios != NULL && tamS > 0){


		system("cls");
        printf("            *** LISTA DE TRABAJOS ***\n");
        printf("   id     nombre            Servicio          Fecha\n");
        printf("-----------------------------------------------------------------------\n");
		for (int i=0; i<tam; i++){
			if(!vec[i].isEmpty){

				trabajos_mostrarTrabajoFila(vec[i], mascotas, tamM, servicios, tamS);
				flag=0;
			}
		}
		if(flag){
			printf("no hay trabajos en el sistema\n");
		}
		retOK = 1;
	}
    return retOK;
}

//**************************************

//validar mascota
//validar servicio


int trabajos_cargarIdMascota(int* idMascota, eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT){
	int retOk = 0;
	if(idMascota != NULL && mascotas != NULL && tamM > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0){
		mascotas_listarMascotas(mascotas, tamM, colores, tamC, tipos, tamT);
		input_IntegerNumber(idMascota, "Ingrese id de Mascota: ", "ERROR, ");
		while(!mascotas_validarMascota(mascotas,tamM,*idMascota)){
			input_IntegerNumber(idMascota, "Id inexistente. Ingrese nuevamente: ", "ERROR, ");
		}
		retOk = 1;
	}
	return retOk;
}
int trabajos_cargarIdServicio(int* idServicio, eServicio servicios[], int tamS){
	int retOk = 0;
	if(idServicio != NULL && servicios != NULL && tamS > 0){
		servicios_listarServicios(servicios, tamS);
		input_IntegerNumber(idServicio, "Ingrese id de Servicio: ", "ERROR, ");
		while(!servicios_validarServicios(servicios,tamS,*idServicio)){
			input_IntegerNumber(idServicio, "Id inexistente. Ingrese nuevamente: ", "ERROR, ");
		}
		retOk = 1;
	}
	return retOk;
}

int trabajos_cargarFecha(eFecha *fecha){
    int retOk = 0;
	if(fecha != NULL){
        input_date(&fecha->dia, &fecha->mes, &fecha->anio, 2018, 2022);
		retOk = 1;
	}
	return retOk;
}

int trabajos_cargarTrabajo(eTrabajo* pTrabajo, eMascota mascotas[], int tamM, eColor colores[], int tamC,
                                                eTipo tipos[], int tamT, eServicio servicios[], int tamS){
    int retOk = 0;
    if(pTrabajo != NULL && mascotas != NULL && tamM > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0 &&
        servicios != NULL && tamS > 0){

    	eTrabajo auxTrabajo;

        trabajos_cargarIdMascota(&auxTrabajo.idMascota, mascotas, tamM, colores, tamC, tipos, tamT);
        trabajos_cargarIdServicio(&auxTrabajo.idServicio, servicios, tamS);
        trabajos_cargarFecha(&auxTrabajo.fecha);

    	*pTrabajo= auxTrabajo;

        retOk = 1;
    }
    return retOk;
}

//-------------------------------------------------------------
int trabajos_buscarLibre(eTrabajo vec[], int tam, int* pIndex){
    int retOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL){
        *pIndex = -1; //sin lugar vacio
        if(vec != NULL && tam > 0){
            for(int i=0; i < tam; i++){
                if(vec[i].isEmpty){
                    *pIndex = i;
                    break;
                }
            }
        }
        retOk = 1;
    }
	return retOk;
}
int trabajos_altaTrabajo(eTrabajo vec[], int tam, eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eServicio servicios[], int tamS, int* pNextId){
	int retOk = 0;
	int indice;
	eTrabajo trabajoAux;

	if (vec != NULL && tam > 0 && mascotas != NULL && tamM > 0 && colores != NULL && tamC > 0 && tipos != NULL  && tamT > 0 && servicios != NULL && tamS > 0 && pNextId != NULL) {
		trabajos_buscarLibre(vec, tam, &indice);
		if (indice != -1) {
			if (trabajos_cargarTrabajo(&trabajoAux, mascotas, tamM, colores, tamC, tipos, tamT, servicios, tamS)) {
				vec[indice] = trabajoAux;
				vec[indice].isEmpty = 0;
				vec[indice].id = *pNextId;
				(*pNextId)++;
				printf("Trabajo cargado exitosamente.\n");
				retOk = 1;
			}
		} else {
			printf("No hay lugar disponible.\n");
		}
	}
	return retOk;
}
//********************************************************************

int trabajos_listarTrabajosXidMascota(eTrabajo vec[], int tam, eMascota mascotas[], int tamM, eServicio servicios[], int tamS, int idMascota){
	int retOK = 0;
	int flag = 1;

	char nombre[20];
	if(vec != NULL && tam > 0 && mascotas != NULL && tamM > 0 && servicios != NULL && tamS > 0){


        mascotas_cargarNombreCadena(mascotas, tamM, idMascota, nombre);
		system("cls");
        printf("            *** TRABAJOS A LA MASCOTA: %s ***\n", nombre);
        printf("   id     nombre            Servicio          Fecha\n");
        printf("-----------------------------------------------------------------------\n");
		for (int i=0; i<tam; i++){
			if(!vec[i].isEmpty && vec[i].idMascota == idMascota){

				trabajos_mostrarTrabajoFila(vec[i], mascotas, tamM, servicios, tamS);
				flag=0;
			}
		}
		if(flag){
			printf("no hay trabajos en el sistema para la mascota: %s\n", nombre);
		}
		retOK = 1;
	}
    return retOK;
}
int trabajos_costoTrabajosXidMascota(eTrabajo vec[], int tam, eMascota mascotas[], int tamM, eServicio servicios[], int tamS, int idMascota){
	int retOK = 0;

    float costoTotal = 0;
	char nombre[20];
	if(vec != NULL && tam > 0 && mascotas != NULL && tamM > 0 && servicios != NULL && tamS > 0){

		for (int i=0; i<tam; i++){
			if(!vec[i].isEmpty && vec[i].idMascota == idMascota){
                for(int j = 0; j < tamS; j++){
                    if(vec[i].idServicio == servicios[j].id){
                        costoTotal = costoTotal + servicios[j].precio;
                    }
                }


			}
		}
		if(costoTotal == 0){
			printf("no hay trabajos en el sistema para esta mascota.\n");
		}else{
            printf("%.2f\n", costoTotal);
		}
		retOK = 1;
	}
    return retOK;
}
