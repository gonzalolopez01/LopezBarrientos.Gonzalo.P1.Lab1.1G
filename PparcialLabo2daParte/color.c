#include "color.h"


int colores_cargarNombreColor(eColor colores[], int tam, int id, char desc[]){
	int retOk = 0;
	if(colores!=NULL && tam > 0 && desc != NULL){
		for(int i = 0; i< tam; i++){
			if(colores[i].id == id){
				strcpy(desc, colores[i].nombre);
				retOk = 1;
				break;
			}
		}
	}
	return retOk;
}
void colores_mostrarColor(eColor color){

	printf("%5d   %-10s\n", color.id, color.nombre);
}

int colores_listarColores(eColor vec[], int tam){
	int retOk = 0;
	if(vec != NULL && tam > 0){
        printf("    *** LISTADO DE COLORES  ***\n\n");
        printf("   id   Nombre\n");
         printf("--------------------------------\n");
		for(int i=0; i < tam; i++){
			colores_mostrarColor(vec[i]);
		}
		retOk = 1;
	}
	return retOk;
}

int colores_buscarColor(eColor vec[], int tam, int id, int* pIndice){
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
int colores_validarColor(eColor vec[],int tam, int id){

    int esValido = 0;
    int indice;
    if(colores_buscarColor(vec,tam,id,&indice)){
        if(indice != -1){
            esValido = 1;
        }
    }
	return esValido;
}
