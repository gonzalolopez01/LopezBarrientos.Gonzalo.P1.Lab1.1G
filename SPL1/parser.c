#include "parser.h"


int parser_elementosFromText(FILE* pFile , LinkedList* pArrayList)//devuelve cantidad de parseados
{
	int ret = -1;
	if(pFile != NULL && pArrayList!= NULL){
		ret = 0;

		char id[20];
		char nombre[20];
		char genero[20];
		char duracion[20];

		ePelicula* pElemento;
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, genero, duracion);
		while(!feof(pFile)){
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, genero, duracion) == 4){
				pElemento = elemento_newParametrosStr(id, nombre, genero, duracion);
				if(pElemento!= NULL){
					ll_add(pArrayList, pElemento);
					ret++;
				}
			}
		}
	}
    return ret;
}

/*
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int ret = -1;
	sPassenger* pPassenger;
	if(pFile != NULL && pArrayListPassenger!= NULL){
		ret = 0;
		while(!feof(pFile)){
			pPassenger = Passenger_new();
			fread(pPassenger,sizeof(sPassenger),1,pFile);
			if(feof(pFile)){
				break;
			}
			ll_add(pArrayListPassenger, pPassenger);
			ret++;
		}
	}
	return ret;
}*/

