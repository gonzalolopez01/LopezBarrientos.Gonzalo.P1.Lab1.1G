
#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include "inputs.h"
#include "LinkedList.h"
#include "Controller.h"


int main(void) {

	srand(time(NULL));


	LinkedList* lista = NULL;
	lista = ll_newLinkedList();

	LinkedList* listaMap = NULL;


	//int cant = 0;
	//int pId = 1;
	//int isSaved = 1;
	//int isLoaded = 0;
	char salir = 'n';
	char path[50];
    char confirm;

	do {
		switch (controller_menu_option()) {
		case 1:
			//printf("%d\n", controller_loadFromText("movies.csv", lista));
			if(input_strFileFormat(path, 50, "Nombre del archivo (sugerido movies.csv o data.csv): ", "Error. ") == 0){
				if(isThereFileTxt(path) && isStrFileFormat(path) == 1){
					ll_clear(lista);
					controller_loadFromText(path, lista);
					printf("Se cargaron las peliculas.\n");
				}else{
					printf("Archivo inexistente o formato incorrecto.\n");
				}
			}
			break;
		case 2:
			controller_listarElementos(lista);
			break;
		case 3:
			listaMap = controller_mapearElementos(lista);
			break;
		case 4:
			break;
		case 5:
		    controller_OrdenarPorGenero(listaMap, 1);
		    controller_listarElementos(listaMap);

			break;
		case 6:
            input_strFileFormat(path, 50, "Nombre del archivo (extension csv/txt): ", "Error. Nombre del archivo (extension csv/txt): ");
            while(isStrFileFormat(path) == 2){
                input_strFileFormat(path, 50, "Error. Nombre del archivo (extension csv/txt): ", "Error. Nombre del archivo (extension csv/txt):");
            }
            if(isThereFileBin(path) == 1){
                confirm = input_ClosedQuestion("Existe un archivo con ese nombre, desea sobreescribirlo?[s/n]", "Valor invalido. ");
                if(confirm == 's'){
                    controller_saveAsText(path, listaMap);
                    printf("El archivo se guardo con exito.\n");
                }else{
                    printf("Archivado de datos cancelado.\n");
                }
            }else{
                controller_saveAsText(path, listaMap);
                printf("El archivo se guardo con exito.\n");
            }
			break;
		case 7:
			salir = 's';

			break;
		default:
			//printf("---opcion invalida---\n");
			break;
		}
	} while (salir != 's');



	return 0;
}
