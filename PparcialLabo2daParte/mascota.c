#include "mascota.h"



int harcodearMascotas(eMascota vec[], int tam, int cant, int* pNextId){
	int retOk = 0;
	eMascota mascotas[10]={
                            {0, "Lolo",     1001, 5001,  12, 's', 0},
							{0, "Morena",   1000, 5004,  3,  'n', 0},
							{0, "Pipo",     1002, 5003,  2,  's', 0},
							{0, "Sanguche", 1003, 5000,  13, 's', 0},
							{0, "Mario",    1002, 5004,  4,  'n', 0},
							{0, "Roque",     1000, 5001, 12, 's', 0},
							{0, "Ramon",    1001, 5003,  5,  's', 0},
							{0, "Sarita",   1002, 5003,  6,  'n', 0},
							{0, "Raul",     1004, 5002,  2,  's', 0},
							{0, "Michu",   1003, 5004,   1,  'n', 0}
							};

	if(vec != NULL && tam > 0 && cant <= tam){
		for(int i = 0; i < cant; i++){
			vec[i] = mascotas[i];
			vec[i].id = *pNextId;
			(*pNextId)++;

		}
		retOk = 1;
	}
	return retOk;
}
int mascotas_inicializarMascotas(eMascota mascotas[], int tam){
    int retOk = 0;
    if(mascotas != NULL && tam > 0){
        for(int i=0; i<tam; i++){
        	mascotas[i].isEmpty = 1;
        }
        retOk = 1;
    }
    return retOk;
}

//***********************************

int mascotas_menu(){

	int opcion;
    system("cls");
	printf("\t***ABM MASCOTAS***\n\n");
	printf("1- Alta Mascota\n");
	printf("2- Modificar Mascota\n");
	printf("3- Baja Mascota\n");
	printf("4- Listar Mascotas\n");
	printf("5- Listar Tipos\n");
	printf("6- Listar Colores\n");
	printf("7- Listar Servicios\n");
	printf("8- Alta Trabajo\n");
	printf("9- Listar Trabajos\n");
	printf("10 - Informes\n");

	printf("11- Salir\n");
	input_IntNumberMinMax(&opcion, "Ingrese opcion: ", "ERROR, valor invalido. ", 1, 11, "ERROR, opcion Invalida");
	return opcion;
}

//***********************************

int mascotas_mostrarMascota(eMascota mascota, eColor colores[], int tamC, eTipo tipos[], int tamT){
	int retOk = 0;
	if(colores != NULL && tipos != NULL && tamC > 0 && tamT > 0){
		char descripcion[20];
		char nombre[20];
		colores_cargarNombreColor(colores, tamC, mascota.idColor, nombre);
		tipos_cargarDescripcion(tipos, tamT, mascota.idTipo, descripcion);

		printf("Id: %d\nNombre: %s\nTipo: %s\nColor: %s\nEdad: %d\nVacunado: %c\n", mascota.id,
                                                                                    mascota.nombre,
                                                                                    descripcion,
                                                                                    nombre,
                                                                                    mascota.edad,
                                                                                    mascota.vacunado);
		retOk = 1;
	}
	return retOk;
}
int mascotas_mostrarMascotaFila(eMascota mascota, eColor colores[], int tamC, eTipo tipos[], int tamT){
	int retOk = 0;
	if(colores != NULL && tipos != NULL && tamC > 0 && tamT > 0){
		char descripcion[20];
		char nombre[20];
		//sectores_cargarDescripcionSector(sectores, tamS, empleado.idSector, descripcion);
		colores_cargarNombreColor(colores, tamC, mascota.idColor, nombre);
		tipos_cargarDescripcion(tipos, tamT, mascota.idTipo, descripcion);

		printf("%6d %12s %10s %10s %6d %7c\n", mascota.id,
                                            mascota.nombre,
                                            descripcion,
                                            nombre,
                                            mascota.edad,
                                            mascota.vacunado);
		retOk = 1;
	}
	return retOk;
}
int mascotas_listarMascotas(eMascota vec[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT){
	int retOK = 0;
	int flag = 1;
	if(vec != NULL && tam > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0){

		system("cls");
        printf("                   *** LISTA DE MASCOTAS ***\n");
        printf("   id       nombre        Tipo       Color   Edad   Vacunado\n");
        printf("-----------------------------------------------------------------------\n");
		for (int i=0; i<tam; i++){
			if(!vec[i].isEmpty){
				//empleados_mostrarEmpleadoFila(vec[i]); //mostrarEmpleado(*(vec+i));
				mascotas_mostrarMascotaFila(vec[i], colores, tamC, tipos, tamT);
				flag=0;
			}
		}
		if(flag){
			printf("no hay mascotas en el sistema\n");
		}
		retOK = 1;
	}
    return retOK;
}

int mascotas_ordenarMascotasTipoNombre(eMascota vec[], int tam, eTipo tipos[], int tamT){
    int retOk = 0;
    eMascota auxMascota;

    char tipoI[20];
    char tipoJ[20];

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {
                tipos_cargarDescripcion(tipos, tamT, vec[i].idTipo, tipoI);
                tipos_cargarDescripcion(tipos, tamT, vec[j].idTipo, tipoJ);
                if((strcmp(tipoI, tipoJ) > 0) ||
                   (strcmp(tipoI, tipoJ) == 0 && (strcmp(vec[i].nombre,vec[j].nombre) > 0))){

                    auxMascota = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxMascota;
                }
            }
        }

        retOk = 1;
    }
    return retOk;
}
//*************************************

int mascotas_cargarNombre(char nombre[]){
	int retOk = 0;
	if(nombre != NULL){
		input_AlphaText(nombre, 50, "Ingrese Nombre: ", "ERROR. ");
		stringToProperName(nombre);
		retOk = 1;
	}
	return retOk;
}
int mascotas_cargarTipo(int* idTipo, eTipo tipos[], int tamT){
	int retOk = 0;
	if(idTipo != NULL && tipos != NULL && tamT > 0){
		tipos_listarTipos(tipos, tamT);
		input_IntegerNumber(idTipo, "Ingrese id de Tipo: ", "ERROR, ");
		while(!tipos_validarTipo(tipos,tamT,*idTipo)){
			input_IntegerNumber(idTipo, "Id inexistente. Ingrese nuevamente: ", "ERROR, ");
		}
		retOk = 1;
	}
	return retOk;
}
int mascotas_cargarColor(int* idColor, eColor colores[], int tamC){
	int retOk = 0;
	if(idColor != NULL && colores != NULL && tamC > 0){
		colores_listarColores(colores, tamC);
		input_IntegerNumber(idColor, "Ingrese id de Color: ", "ERROR, ");
		while(!colores_validarColor(colores,tamC,*idColor)){
			input_IntegerNumber(idColor, "Id inexistente. Ingrese nuevamente: ", "ERROR, ");
		}
		retOk = 1;
	}
	return retOk;
}

int mascotas_cargarEdad(int* edad){
	int retOk = 0;
	if(edad != NULL){
		input_IntNumberMin(edad, "Ingrese edad: ", "ERROR. ", 1, "ERROR, fuera de rango. ");
		retOk = 1;
	}
	return retOk;
}

int mascotas_cargarEsVacunado(char* vacunado){
	int retOk = 0;
	if (vacunado != NULL) {
		printf("Es Vacunado[s/n]: ");
		fflush(stdin);
		scanf("%c",vacunado);
		//printf("%c\n",vacunado);
		while(*vacunado != 's' && *vacunado != 'n'){
            printf("Es Vacunado[s/n]: ");
            fflush(stdin);
            scanf("%c",vacunado);
		}
		*vacunado = tolower(*vacunado);
		retOk = 1;
	}
	return retOk;
}


int mascotas_cargarMascota(eMascota* pMascota, eColor colores[], int tamC, eTipo tipos[], int tamT){
    int retOk = 0;
    if(pMascota != NULL && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0){
    	eMascota auxMascota;

        mascotas_cargarNombre(auxMascota.nombre);
        mascotas_cargarTipo(&auxMascota.idTipo, tipos, tamT);
        mascotas_cargarColor(&auxMascota.idColor, colores, tamC);
        mascotas_cargarEdad(&auxMascota.edad);
    	mascotas_cargarEsVacunado(&auxMascota.vacunado);
    	//printf("chau");

    	*pMascota = auxMascota;

        retOk = 1;
    }
    return retOk;
}
int mascotas_buscarLibre(eMascota vec[], int tam, int* pIndex){
	int retOk = 0;
	if(vec != NULL && tam > 0 && pIndex != NULL){
        *pIndex = -1; //sin lugar vacio
		for(int i=0; i < tam; i++){
			if(vec[i].isEmpty){
				*pIndex = i;
				break;
			}
		}
		retOk = 1;
	}
	return retOk;
}
int mascotas_altaMascota(eMascota vec[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT, int* pNextId){
	int retOk = 0;
	int indice;
	eMascota mascotaAux;
	if (vec != NULL && tam > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0 && pNextId != NULL) {
		mascotas_buscarLibre(vec, tam, &indice);
		if (indice != -1) {
			if (mascotas_cargarMascota(&mascotaAux, colores, tamC, tipos, tamT)) {
				vec[indice] = mascotaAux;
				vec[indice].isEmpty = 0;
				vec[indice].id = *pNextId;
				(*pNextId)++;
				printf("Mascota cargado exitosamente.\n");
				retOk = 1;
			}
		} else {
			printf("No hay lugar disponible.\n");
		}
	}
	return retOk;
}
//*******************

int mascotas_buscarId(eMascota vec[], int tam, int id, int* pIndice){
	int retOk = 0;
	if (vec != NULL && tam > 0 && pIndice != NULL) {
		*pIndice = -1;//id no existe
		for(int i = 0; i<tam; i++) {
			if(id == vec[i].id && !vec[i].isEmpty){
				*pIndice = i;
				break;
			}
		}
		retOk = 1;
	}
	return retOk;
}
int mascotas_bajaMascota(eMascota vec[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT){
	int retOk = 0;
	int indice;
	int id;
	char confirma;
	if(vec != NULL && tam > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0){
		mascotas_listarMascotas(vec, tam, colores, tamC, tipos, tamT);
		input_IntNumberMin(&id, "Ingrese id: ", "ERROR. ", 1, "Valor invalido. ");
		if(mascotas_buscarId(vec, tam, id, &indice)){
			if(indice == -1){
				printf("El id %d no esta registrado en el sistema\n", id);
			} else {
			    mascotas_mostrarMascota(vec[indice],colores, tamC, tipos, tamT);
				//mascotas_mostrarMascotaFila(vec[indice], colores, tamC, tipos, tamT);
				confirma = input_ClosedQuestion("Confirma la baja? [s/n] ", "ERROR. ");
				if(confirma == 's'){
					vec[indice].isEmpty = 1;
					retOk = 1;
				} else {
					printf("Baja cancelada\n");
				}
			}
		}
	}
	return retOk;
}

int mascotas_menuModificarMascota(){

	int opcion;
    //system("cls");
	printf("***Modificar Mascota***\n");
	printf("1- Tipo\n");
	printf("2- Vacunado\n");
	printf("3- Salir\n");
	input_IntNumberMinMax(&opcion, "Ingrese opcion: ", "ERROR, valor invalido. ", 1, 3, "ERROR, opcion Invalida");
	return opcion;
}

int mascotas_modificarMascota(eMascota vec[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT){
	int retOk = 0;
	int indice;
	int id;
	char confirma;

	//campos auxiliares
	int auxTipo;
	char auxVacunado;


	if (vec != NULL && tam > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0) {
		mascotas_listarMascotas(vec, tam, colores, tamC, tipos, tamT);
		input_IntNumberMin(&id, "Ingrese id: ", "ERROR. ", 1,"Valor invalido. ");
		if (mascotas_buscarId(vec, tam, id, &indice)) {
			if (indice == -1) {
				printf("El id %d no esta registrado en el sistema.\n", id);
			} else {
			    system("cls");
				mascotas_mostrarMascota(vec[indice], colores, tamC, tipos, tamT);
				switch(mascotas_menuModificarMascota()){
				case 1:
					mascotas_cargarTipo(&auxTipo,tipos,tamT);
					confirma = input_ClosedQuestion("Confirma el cambio? [s/n] ", "ERROR, opcion invalida. ");
					if(confirma == 's'){
						vec[indice].idTipo = auxTipo;
						printf("Modificacion realizada con exito\n");
					}
					break;
				case 2:
					mascotas_cargarEsVacunado(&auxVacunado);
					confirma = input_ClosedQuestion("Confirma el cambio? [s/n] ", "ERROR, opcion invalida. ");
					if(confirma == 's'){
						vec[indice].vacunado = auxVacunado;
						printf("Modificacion realizada con exito.");
					}
					break;
				}
			}
		}
		retOk = 1;
	}
	return retOk;
}

int mascotas_cargarNombreCadena(eMascota mascotas[], int tam, int idFK, char desc[]){
	int retOk = 0;
	if(mascotas!=NULL && tam > 0 && desc != NULL){
		for(int i = 0; i< tam; i++){
			if(!mascotas[i].isEmpty && mascotas[i].id == idFK){
                strcpy(desc, mascotas[i].nombre);
                retOk = 1;
                break;
			}
		}
		if(!retOk){
            strcpy(desc,"-Inexistente-");
		}
	}
	return retOk;
}

int mascotas_validarMascota(eMascota vec[],int tam, int id){
    int esValido = 0;
    if(vec != NULL && tam > 0){
        int indice;
        if(mascotas_buscarId(vec,tam,id,&indice)){
            if(indice != -1){
                esValido = 1;
            }
        }
    }

	return esValido;
}


//-----------------------------


int mascotas_mascotasXIdTipo(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, int idTipo){

    int retOk = 0;
    int flag = 1;
    char descripcion[20];

    if( mascotas != NULL && tamM > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0)
    {
        tipos_cargarDescripcion(tipos, tamT, idTipo, descripcion);

        printf("Mascotas Tipo: %s\n\n", descripcion);

         printf("   id       nombre        Tipo       Color   Edad   Vacunado\n");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0; i < tamM; i++)
        {
            if(!mascotas[i].isEmpty && mascotas[i].idTipo == idTipo){

                mascotas_mostrarMascotaFila(mascotas[i], colores, tamC, tipos, tamT);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay mascotas para este tipo %s\n", descripcion);
        }

        retOk = 1;
    }
    return retOk;
}

int mascotas_mascotasXIdColore(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, int idColor){

    int retOk = 0;
    int flag = 1;
    char descripcion[20];

    if( mascotas != NULL && tamM > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0)
    {
        colores_cargarNombreColor(colores, tamC, idColor, descripcion);

        printf("Mascotas Colores: %s\n\n", descripcion);

        printf("   id       nombre        Tipo       Color   Edad   Vacunado\n");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0; i < tamM; i++)
        {
            if( !mascotas[i].isEmpty && mascotas[i].idColor == idColor){

                mascotas_mostrarMascotaFila(mascotas[i], colores, tamC, tipos, tamT);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay mascotas para este Color %s\n", descripcion);
        }

        retOk = 1;
    }
    return retOk;
}
