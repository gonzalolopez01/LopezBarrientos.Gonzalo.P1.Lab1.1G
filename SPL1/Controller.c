
#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	int returnAux = -1;//error de punteros
	if(path != NULL && pArrayList != NULL){
		returnAux = -2; // pfile null
		FILE* pFile = NULL;
		pFile = fopen(path,"r");
		if(pFile != NULL) {
			returnAux = 0;
			returnAux = parser_elementosFromText(pFile, pArrayList);
		}
		fclose(pFile);
	}
	return returnAux;
}
//----------------------------------------------------------------------
int controller_listarElementos(LinkedList* pArrayList)
{
	int returnAux = -1;
	int len;
	ePelicula *pElemento;
	if (pArrayList != NULL) {
		printf("|ID             |NOMBRE                      |GENERO            |DURACION   |\n");
		len = ll_len(pArrayList);
		for (int i = 0; i < len; i++) {
			pElemento = ll_get(pArrayList, i);

			elemento_mostrarElementoFila(pElemento);
		}
		returnAux = 0;
	}
	return returnAux;
}

LinkedList* controller_mapearElementos(LinkedList* pArrayList){
	LinkedList* listaMap = NULL;
	if(pArrayList != NULL){
		listaMap = ll_map(pArrayList, elemento_map);
	}
	return listaMap;
}
int controller_OrdenarPorGenero(LinkedList* pArrayList, int order)
{
	int returnAux = -1;
	if (pArrayList != NULL && (order == 0 || order == 1)) {
		if(!ll_sort(pArrayList, elemento_criterioGenero, order)){
		returnAux = 0;
		}
	}
	return returnAux;
}
int controller_saveAsText(char* path , LinkedList* pArrayList){
	int returnAux = -1;
	int len;
	int i;
	ePelicula* pAux;

	int id;
	char nombre[50];
	char genero[50];
	int duracion;

	if (pArrayList!= NULL){
		len = ll_len(pArrayList);
		FILE* pFile;
		pFile = fopen(path,"w");
		fprintf(pFile,"id,nombre,genero,duracion\n");
		if(pFile!=NULL && len > 0){
			for(i=0; i<len; i++){
				pAux = ll_get(pArrayList, i);
				elemento_getId(pAux, &id);
				elemento_getNombre(pAux, nombre);
				elemento_getGenero(pAux, genero);
				elemento_getDuracion(pAux, &duracion);

				if(pAux!=NULL){
					fprintf(pFile,"%d,%s,%s,%d\n", id, nombre, genero, duracion);
				}else{
					break;
				}
			}
			if(i == len){
				returnAux = 0;
			}
		}
		fclose(pFile);
	}
	return returnAux;
}
int controller_menu_option() {
	int option;
	printf("****************************************************************************\n");
	printf("Peliculas\n");
	printf("****************************************************************************\n");
	printf("Menu:\n");
	printf("1. Cargar archivo.\n");
	printf("2. Imprimir Lista.\n");
	printf("3. Asignar duracion.\n");
	printf("4. .\n");
	printf("5. ordenar por genero y duracion\n");
	printf("6. guardar\n");
	printf("7. Salir\n");
	printf("*****************************************************************************\n");
	input_IntegerNumber(&option, "Ingrese la opcion deseada: ", "Error, valor incorrecto \n");
	return option;
}
