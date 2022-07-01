#include "movies.h"

ePelicula* elemento_new(){
	ePelicula* newElemento = NULL;

	return newElemento = (ePelicula*) malloc(sizeof(ePelicula));
}

ePelicula* elemento_newParametrosStr(char* id, char* nombre, char* genero, char* duracion){
	ePelicula* pElemento = elemento_new();
	if(pElemento != NULL){
		if(elemento_setId(pElemento, atoi(id)) ||
			elemento_setNombre(pElemento, nombre) ||
			elemento_setGenero(pElemento, genero) ||
			elemento_setDuracion(pElemento, atoi(duracion))){

			elemento_delete(pElemento);
			pElemento = NULL;
		}
	}

	return pElemento;
}
void elemento_delete(ePelicula* pElemento){
	free(pElemento);
}
//ID----------------------------------------------------
int elemento_setId(ePelicula* this, int id){//hacer validacion con static
	int ret = -1;
	if(this != NULL){
		this->id = id;
		ret = 0;
	}

	return ret;
}

int elemento_getId(ePelicula* this, int* id){
	int ret = -1;
	if(this != NULL && id != NULL){
		*id = this->id;
		ret = 0;
	}
	return ret;
}
//NOMBRE----------------------------------------------------
int elemento_setNombre(ePelicula* this, char* nombre){
	int ret = -1;
	if(this != NULL && nombre != NULL){//hacer un is valid

		strcpy(this->nombre, nombre);
		ret = 0;
	}
	return ret;
}

int elemento_getNombre(ePelicula* this, char* nombre){
	int ret = -1;
	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		ret = 0;
	}
	return ret;
}
//genero---------------------------------------------------
int elemento_setGenero(ePelicula* this, char* genero){
	int ret = -1;
	if(this != NULL && genero != NULL){

		strcpy(this->genero, genero);
		ret = 0;
	}
	return ret;
}

int elemento_getGenero(ePelicula* this, char* genero){
	int ret = -1;
	if(this != NULL && genero != NULL){
		strcpy(genero, this->genero);
		ret = 0;
	}
	return ret;
}

//duracion----------------------------------------------------
int elemento_setDuracion(ePelicula* this, int duracion){
	int ret = -1;
	if(this != NULL){
		this->duracion = duracion;
		ret = 0;
	}
	return ret;
}
int elemento_getDuracion(ePelicula* this, int* duracion){
	int ret = -1;
	if(this != NULL && duracion!= NULL){
		*duracion = this->duracion;
		ret = 0;
	}
	return ret;
}

//------------------------------------
int elemento_mostrarElementoFila(ePelicula* pElemento){
	int ret = -1;
	if(pElemento != NULL){
		int id;
		char nombre[50];
		char genero[50];
		int duracion;

		elemento_getId(pElemento, &id);
		elemento_getNombre(pElemento, nombre);
		elemento_getGenero(pElemento, genero);
		elemento_getDuracion(pElemento, &duracion);

		printf("|%5d|%30s|%30s|%5d|\n", id, nombre, genero, duracion);
		ret = 0;
	}
	return ret;
}

//-------------------------------------------------------------
void* elemento_map(void* elemento){

	ePelicula* elementoAux = NULL;
	if(elemento != NULL){
		elementoAux = (ePelicula*) elemento;

		int duracion = obtenerAleatorioEntero(100, 240);

		elemento_setDuracion(elementoAux, duracion);

	}
	return (void*) elementoAux;
}
int obtenerAleatorioEntero(int min, int max){
	int num;
		num = (rand() % (max - min +1) + min);

	return num;
}

int elemento_criterioGenero(void* aux1, void* aux2)
{
	int compare = 0;
	ePelicula* pAux1;
	ePelicula* pAux2;
	pAux1 = (ePelicula*)aux1;
	pAux2 = (ePelicula*)aux2;

	char pAux1Name[50];
	char pAux2Name[50];

	if(pAux1!=NULL && pAux2!=NULL){
		elemento_getGenero(pAux1, pAux1Name);
		elemento_getGenero(pAux2, pAux2Name);
		compare = strcmpi(pAux1Name,pAux2Name);
	}
	return compare;
}
