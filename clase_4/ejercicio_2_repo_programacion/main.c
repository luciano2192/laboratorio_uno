#include <stdio.h>
#include <stdlib.h>
#include "ejercicio.h"

#define CANT 3

int main(){

    ePersona pers[CANT];
    int idMenu;

    ePais paises[3] = {
        { 1 , "Argentina" },
        { 2 , "Brasil" },
        { 3 , "Uruguay" },
    };

    inicializar( pers , CANT );

    do {

        idMenu = menu();

        switch( idMenu ) {
            case 1:
                alta( pers , CANT );
                system("cls");
                break;
            case 2:
                baja( pers , CANT );
                break;
            case 3:
                modificacion( pers , CANT );
                break;
            case 4:
                mostrarTodos( pers , CANT );
                break;
            case 5:
                break;
        }

    } while ( idMenu != 5 );

    return 0;
}
