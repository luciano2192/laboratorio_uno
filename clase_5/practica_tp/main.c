#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "practica.h"

#define CANT 4

int main()
{

    eSector sector[CANT] = {
        { 1 , "Recursos Humanos" },
        { 2 , "Comercial" },
        { 3 , "Desarrollo" },
        { 4 , "QA" },
    };


    eMenu menu[CANT] = {
        { 1 , "Milanesa con pure" , 159.99 },
        { 2 , "Pollo con ensalada" , 200.50 },
        { 3 , "Tarta de atun" , 110.40 },
        { 4 , "Empanadas fritas de carne" , 45.99 },
    };

    eAlmuerzo almuerzo[CANT] = {
        { 1 , 4 , 1 , 20190621 },
        { 2 , 3 , 2 , 20190505 },
        { 3 , 2 , 3 , 20181205 },
        { 4 , 1 , 4 , 20170403 },
    };
    /*
    eEmpleado empleado[CANT] = {
        { 1 , "Perez" , "Lucas" , 'M' , 02 , 11 , 2018 , 2 , 0 },
        { 2 , "Gomez" , "Santiago" , 'M' , 05 , 06 , 2014 , 4 , 0 },
        { 3 , "Diaz" , "Natalia" , 'F' , 24 , 02 , 2013 , 1 , 1 },
        { 4 , "Otra" , "Carolina" , 'F' , 15 , 03 , 2003 , 3 , 1 },
    };
    */

    //empleadosPorSector( sector , CANT , empleado , CANT );

    //menuPorEmpleado( menu , CANT , almuerzo , CANT , empleado , CANT );
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
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }

    } while( opcionMenu != 5 );


    return 0;
}
