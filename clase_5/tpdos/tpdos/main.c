#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tpdos.h"

#define CANT 4

int main()
{
    eEmpleado empleado[CANT];

    inicializar( empleado , CANT );

    int opcionMenu;
    do {
        opcionMenu = menuABM();

        switch( opcionMenu ) {
            case 1:
                alta( empleado , CANT );
                break;
            case 2:
                baja( empleado , CANT );
                break;
            case 4:
                mostrarTodos( empleado , CANT );
                break;
            case 5:
                break;
        }

    } while( opcionMenu != 5 );
    return 0;
}
