#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#endif // CONTROLLER_H_INCLUDED

int menuPrincipal();
int controller_loadFromText(char* path, LinkedList* pArrayList);
int controller_loadFromBinary(char* path, LinkedList* pArrayList);
int controller_cargarArchivo( LinkedList* pArrayList );
int controller_ListVuelos(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos);
int controller_cantPasajeros(LinkedList* pArrayListVuelos);
int controller_cantPasajerosADestinoX(LinkedList* pArrayListVuelos);
int controller_cargarVuelosCortos( LinkedList* pArrayList );
int controller_saveVuelosCortos(char* path, LinkedList* pArrayList);
int controller_ListVuelosDestinoX(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos);
