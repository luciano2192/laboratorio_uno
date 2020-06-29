#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Vuelo.h"
#include "Piloto.h"
#include "utn_funciones.h"

int main()
{
    int opcion = 0;
    LinkedList* listaVuelos = ll_newLinkedList();
    LinkedList* listaPilotos = ll_newLinkedList();

    do{
        opcion = menuPrincipal();
        switch(opcion)
        {
            case 1:
                controller_cargarArchivo( listaVuelos );
                break;
            case 2:
                controller_ListVuelos( listaVuelos , listaPilotos );
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:
                break;
        }
    } while(opcion != 8);

    return 0;
}
