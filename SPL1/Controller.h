#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "parser.h"
#include "inputs.h"
#include "movies.h"

int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_listarElementos(LinkedList* pArrayList);
int controller_menu_option();

int controller_saveAsText(char* path , LinkedList* pArrayList);

LinkedList* controller_mapearElementos(LinkedList* pArrayList);

int controller_OrdenarPorGenero(LinkedList* pArrayList, int order);

