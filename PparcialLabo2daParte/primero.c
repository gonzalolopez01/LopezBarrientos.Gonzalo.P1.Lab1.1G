




int harcodearEmpleados(eEmpleado vec[], int tam, int cant, int* pNextId){
	int retOk = 0;
	eEmpleado empleados[10]={
                            {0, "Juan",   'm', 21, 1500,  {2,5,2022}, 1002,  0},
							{0, "Miguel",  'm', 32, 1830, {17,8,2020},1001,  0},
							{0, "Jose",    'm', 44, 2700, {3,5,2019}, 1001,  0},
							{0, "Lucas",   'm', 51, 750,  {13,5,2020},1002,  0},
							{0, "Lorena",  'f', 18, 1120, {3,5,2019}, 1004,  0},
							{0, "Rosa",    'f', 33, 2700, {25,6,2018},1003,  0},
							{0, "Manuel",  'm', 22, 751,  {1,4,2020}, 1002,  0},
							{0, "Miriam",  'f', 51, 800,  {5,3,2022}, 1001,  0},
							{0, "Andres",  'm', 18, 2300, {29,4,2021},1003,  0},
							{0, "Marta",   'f', 27, 453,  {2,3,2019}, 1004,  0}
							};

	if(vec != NULL && tam > 0 && tam <= 10 && cant <= tam){
		for(int i = 0; i < cant; i++){
			vec[i] = empleados[i];
			vec[i].id = *pNextId;
			(*pNextId)++;

		}
		retOk = 1;
	}
	return retOk;
}
int empleados_inicializarEmpleados(eEmpleado pEmpleado[], int tam){
    int retOk = 0;
    if(pEmpleado != NULL && tam > 0){
        for(int i=0; i<tam; i++){
        	pEmpleado[i].isEmpty = 1;
        }
        retOk = 1;
    }
    return retOk;
}

//***********************************

int empleados_menu(){

	int opcion;
    system("cls");
	printf("\t***ABM EMPLEADOS***\n\n");
	printf("1- Alta Empleado\n");
	printf("2- Baja Empleado\n");
	printf("3- Modificar Persona\n");
	printf("4- Ordenar Empleado\n");
	printf("5- Listar Empleado\n");
	printf("6- Listar Empleadas\n");
	printf("7- Informe Promedio de sueldos\n");
	printf("8- Informe Empleado con mayor edad.\n");
	printf("9- Listar Sectores\n");
	printf("10- Listar Empleados de un sector\n");


	printf("20- Salir\n");
	input_IntNumberMinMax(&opcion, "Ingrese opcion: ", "ERROR, valor invalido. ", 1, 20, "ERROR, opcion Invalida");
	return opcion;
}

//***********************************
