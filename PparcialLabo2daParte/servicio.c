#include "servicio.h"

int servicios_cargarServicio(eServicio servicios[], int tam, int id, char desc[]){
	int retOk = 0;
	if(servicios!=NULL && tam > 0 && desc != NULL){
		for(int i = 0; i< tam; i++){
			if(servicios[i].id == id){
				strcpy(desc, servicios[i].descripcion);
				retOk = 1;
				break;
			}
		}
	}
	return retOk;
}
void servicios_mostrarServicio(eServicio servicio){

	printf("%5d   %-14s %6.2f\n", servicio.id, servicio.descripcion, servicio.precio);
}

int servicios_listarServicios(eServicio vec[], int tam){
	int retOk = 0;
	if(vec != NULL && tam > 0){
        printf("    *** LISTADO DE SERVICIOS  ***\n\n");
        printf("   id   Descripcion     PRECIO\n");
         printf("------------------------------------\n");
		for(int i=0; i < tam; i++){
			servicios_mostrarServicio(vec[i]);
		}
		retOk = 1;
	}
	return retOk;
}
//******************
int servicios_buscarId(eServicio vec[], int tam, int id, int* pIndice){
	int retOk = 0;
	if (vec != NULL && tam > 0 && pIndice != NULL) {
		*pIndice = -1;//id no existe
		for(int i = 0; i<tam; i++) {
			if(id == vec[i].id){
				*pIndice = i;
				break;
			}
		}
		retOk = 1;
	}
	return retOk;
}

int servicios_validarServicios(eServicio vec[],int tam, int id){
    int esValido = 0;
    int indice;
    if(servicios_buscarId(vec,tam,id,&indice)){
        if(indice != -1){
            esValido = 1;
        }
    }
	return esValido;
}
