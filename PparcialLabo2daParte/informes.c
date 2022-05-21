#include "informes.h"

int informes_menu(){

	int opcion;
    system("cls");
	printf("\t***INFORMES***\n\n");
	printf("1- Mascotas por colores seleccionado por el usuario.\n");
	printf("2- Promedio de mascotas vacunadas.\n");
	printf("3- Mascotas de menos edad.\n");
	printf("4- Mascotas separads por tipo.\n");
	printf("5- Mascotas por color y tipo elegidos por el usuario.\n");
	printf("6- Color con mas cantidad de mascotas.\n");
	printf("7- Trabajos por id de mascota elegida por el usuario.\n");
	printf("8- Costo de trabajos de mascota ingresada por el usuario.\n");
	printf("9-\n");
	printf("10- Servicios por Fecha\n");
	printf("11- Salir\n");
	input_IntNumberMinMax(&opcion, "Ingrese opcion: ", "ERROR, valor invalido. ", 1, 11, "ERROR, opcion Invalida");
	return opcion;
}

int informes(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamTi, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTr){
    int retOk = 0;
    if(mascotas!= NULL && tamM > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamTi > 0 && servicios != NULL && tamS > 0 && trabajos != NULL && tamTr > 0){

        char salir = 'n';
        do{
            switch(informes_menu()){
            case 1:
                informes_mascotasColor(mascotas, tamM, colores, tamC, tipos, tamTi);
                system("pause");
                break;
            case 2:
                informes_promedioVacunados(mascotas, tamM, colores, tamC, tipos, tamTi);
                system("pause");
                break;
            case 3:
                informes_mascotasMenosEdad(mascotas, tamM, colores, tamC, tipos, tamTi);
                system("pause");
                break;
            case 4:
                informes_mascotasTipo(mascotas, tamM, colores, tamC, tipos, tamTi);
                system("pause");
                break;
            case 5:
                informes_mascotasColorTipoxUsuario(mascotas, tamM, colores, tamC, tipos, tamTi);
                system("pause");
                break;
            case 6:
                informes_colorMasRepetido(mascotas, tamM, colores, tamC, tipos, tamTi);
                system("pause");
                break;
            case 7:
                informes_trabajosXidMascota(mascotas, tamM, colores, tamC, tipos, tamTi, trabajos, tamTr, servicios, tamS);
                system("pause");
                break;
            case 8:
                informes_costoTrabajosXidMascota(mascotas, tamM, colores, tamC, tipos, tamTi, trabajos, tamTr, servicios, tamS);
                system("pause");
                break;
            case 9:

                break;
            case 10:
                informes_serviciosXFecha(mascotas, tamM, colores, tamC, tipos, tamTi, trabajos, tamTr, servicios, tamS);
                system("pause");
                break;
            case 11:
                salir = 's';
                break;
            }
        }while(salir != 's');
        retOk = 1;
    }
    return retOk;
}

int informes_mascotasColor(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT){
    int retOk = 0;

    int idColor;

    if(mascotas != NULL && tamM > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0){
        mascotas_cargarColor(&idColor, colores, tamC);
        mascotas_mascotasXIdColore(mascotas, tamM, colores, tamC, tipos, tamT, idColor);
        printf("\n");
        retOk = 1;
    }
    return retOk;
}

int informes_promedioVacunados(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT){
    int retOk = 0;
    int qVacunados = 0;
    int qMascotas = 0;
    float promedio;

    if(mascotas != NULL && tamM > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0){
        for(int i = 0; i < tamM; i++){
            if(!mascotas[i].isEmpty){
                qMascotas++;
                if(mascotas[i].vacunado == 's'){
                    qVacunados++;
                }
            }
        }
        if(qVacunados == 0){
            printf("El promedio de vacunados es 0\n");
        }else{
            promedio = (float)(qVacunados * 100)/qMascotas;
            printf("El promedio de mascotas vacunadas es: %%%.2f\n", promedio);
        }
        retOk = 1;
    }
    return retOk;
}

int informes_mascotasMenosEdad(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT){
    int retOk = 1;
    int menor;
    int flag = 1;

    if(mascotas != NULL && tamM > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0){
        for (int i = 0; i<tamM; i++){
            if(!mascotas[i].isEmpty && (flag || mascotas[i].edad < menor)){
                menor = mascotas[i].edad;
                flag = 0;
            }
        }
        printf(" ***Mascota/s que tiene/n %d año/s de edad **** \n", menor);
        printf("   id       nombre        Tipo       Color   Edad   Vacunado\n");
        printf("-----------------------------------------------------------------------\n");
        for (int i=0; i<tamM; i++ ){
            if(!mascotas[i].isEmpty && mascotas[i].edad == menor){
                mascotas_mostrarMascotaFila(mascotas[i], colores, tamC, tipos, tamT);
                flag = 0;
            }
        }
        if(flag){
            printf("No hay mascotas\n");
        }

        retOk = 1;
    }
    return retOk;
}
int informes_mascotasTipo(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT){
    int retOk = 1;
    if(mascotas != NULL && tamM > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0){

        for(int i= 0; i < tamT; i++){
            mascotas_mascotasXIdTipo(mascotas, tamM, colores, tamC, tipos, tamT, tipos[i].id);

        }
        retOk = 1;
    }
    return retOk;
}
int informes_mascotasColorTipoxUsuario(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT){
    int retOk = 1;
    int idTipo;
    int idColor;
    char tipo[20];
    char color[20];

    int contador = 0;

    if(mascotas != NULL && tamM > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0){
        mascotas_cargarColor(&idColor, colores, tamC);
        mascotas_cargarTipo(&idTipo, tipos, tamT);

        colores_cargarNombreColor(colores, tamC, idColor, color);
        tipos_cargarDescripcion(tipos, tamT, idTipo, tipo);


        for(int i = 0; i < tamM; i++){
            if(!mascotas[i].isEmpty && mascotas[i].idColor == idColor && mascotas[i].idTipo == idTipo){
                contador++;

            }
        }
        if(contador == 0){
            printf("*** No hay mascotas de color %s y del tipo %s***\n", color, tipo );
        }else{
            printf("*** Hay %d mascotas de color %s y del tipo %s***\n", contador ,color, tipo );
        }
        retOk = 1;
    }
    return retOk;
}

int informes_colorMasRepetido(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT){
    int retOk = 1;
    int mayor;
    int flag = 1;

    if(mascotas != NULL && tamM > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0){
        int coloresAux[tamC];
        for(int i = 0; i < tamC; i++){
            coloresAux[i] = 0;
        }
        for(int i = 0; i < tamC; i++){
            for(int j = 0; j < tamM; j++){
                if(!mascotas[j].isEmpty && mascotas[j].idColor == colores[i].id ){
                    coloresAux[i]++;
                }
            }
        }
        for (int i = 0; i<tamC; i++){ //busco mayor
            if(flag || coloresAux[i] > mayor){
                mayor = coloresAux[i];
                flag = 0;
            }
        }
        printf("El/los Color/es con mas cantidad de mascotas es/son: \n");
        for (int i=0; i<tamC; i++ ){
            if(coloresAux[i] == mayor){

                printf("-%s- \n", colores[i].nombre);
            }
        }

        retOk = 1;
    }
    return retOk;
}

int informes_trabajosXidMascota(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eTrabajo trabajos[], int tamTr, eServicio servicios[], int tamS){
    int retOk = 1;
    int idMascota;
    if(mascotas != NULL && tamM > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0 && trabajos != NULL && tamTr > 0 && servicios != NULL && tamS > 0){

        trabajos_cargarIdMascota(&idMascota, mascotas, tamM, colores, tamC, tipos, tamT);
        trabajos_listarTrabajosXidMascota(trabajos, tamTr, mascotas, tamM, servicios, tamS, idMascota);
        retOk = 1;
    }

    return retOk;
}
int informes_costoTrabajosXidMascota(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eTrabajo trabajos[], int tamTr, eServicio servicios[], int tamS){
    int retOk = 1;
    int idMascota;
    char nombre[20];
    if(mascotas != NULL && tamM > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0 && trabajos != NULL && tamTr > 0 && servicios != NULL && tamS > 0){

        trabajos_cargarIdMascota(&idMascota, mascotas, tamM, colores, tamC, tipos, tamT);
        mascotas_cargarNombreCadena(mascotas, tamM, idMascota,nombre);
        printf("Costos de trabajo para la mascota %s es: ", nombre);
        trabajos_costoTrabajosXidMascota(trabajos, tamTr, mascotas, tamM, servicios, tamS, idMascota);
        retOk = 1;
    }

    return retOk;
}

int informes_serviciosXFecha(eMascota mascotas[], int tamM, eColor colores[], int tamC, eTipo tipos[], int tamT, eTrabajo trabajos[], int tamTr, eServicio servicios[], int tamS){
	int retOK = 0;
	int flag = 1;

	eFecha auxFecha;


	if(mascotas != NULL && tamM > 0 && colores != NULL && tamC > 0 && tipos != NULL && tamT > 0 && trabajos != NULL && tamTr > 0 && servicios != NULL && tamS > 0){

		system("cls");
		trabajos_listarTrabajos(trabajos, tamTr, mascotas, tamM, servicios, tamS);
		input_date(&auxFecha.dia, &auxFecha.mes, &auxFecha.anio, 2018, 2022);
		printf("\n\nSERVICIOS EN LA FECHA %02d/%02d/%d\n", auxFecha.dia, auxFecha.mes, auxFecha.anio);
        printf("-----------------------------------------------------------------------\n");
		for(int i = 0; i < tamTr; i++){
            if(!trabajos[i].isEmpty && trabajos[i].fecha.dia == auxFecha.dia &&
                                            trabajos[i].fecha.mes == auxFecha.mes &&
                                            trabajos[i].fecha.anio == auxFecha.anio){
                trabajos_mostrarTrabajoFila(trabajos[i], mascotas, tamM, servicios, tamS);
                flag = 0;
            }
		}

		if(flag){
			printf("no hay Trabajos en esta fecha %02d/%02d/%d\n", auxFecha.dia, auxFecha.mes, auxFecha.anio);
		}
		retOK = 1;
	}
    return retOK;
}
