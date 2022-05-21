#include "tipo.h"

int tipos_cargarDescripcion(eTipo tipos[], int tam, int id, char desc[]){
	int retOk = 0;
	if(tipos!=NULL && tam > 0 && desc != NULL){
		for(int i = 0; i< tam; i++){
			if(tipos[i].id == id){
				strcpy(desc, tipos[i].descripcion);
				retOk = 1;
				break;
			}
		}
	}
	return retOk;
}
void tipos_mostrarTipos(eTipo tipo){

	printf("%5d   %-10s\n", tipo.id, tipo.descripcion);
}

int tipos_listarTipos(eTipo vec[], int tam){
	int retOk = 0;
	if(vec != NULL && tam > 0){
        printf("    *** LISTADO DE TIPOS  ***\n\n");
        printf("   id   Descripcion\n");
         printf("-------------------------------\n");
		for(int i=0; i < tam; i++){
			tipos_mostrarTipos(vec[i]);
		}
		retOk = 1;
	}
	return retOk;
}

int tipos_buscarTipo(eTipo vec[], int tam, int id, int* pIndice){
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
int tipos_validarTipo(eTipo vec[],int tam, int id){

    int esValido = 0;
    int indice;
    if(tipos_buscarTipo(vec,tam,id,&indice)){
        if(indice != -1){
            esValido = 1;
        }
    }
	return esValido;
}

