#include <stdio.h>
#include <stdlib.h>
#include "practica.h"

int main()
{

    eSector sector[4] = {
        { 1 , "Recursos Humanos" },
        { 2 , "Comercial" },
        { 3 , "Desarrollo" },
        { 4 , "QA" },
    };

    eMenu menu[4] = {
        { 1 , "Milanesa con pure" , 159.99 },
        { 2 , "Pollo con ensalada" , 200.50 },
        { 3 , "Tarta de atun" , 110.40 },
        { 4 , "Empanadas fritas de carne" , 45.99 },
    };

    eEmpleado empleado[4] = {
        { 1 , "Perez" , "Lucas" , 'M' , 02 , 11 , 2018 , 2 , 159.99 },
        { 2 , "Gomez" , "Santiago" , 'M' , 05 , 06 , 2014 , 4 , 200.50 },
        { 3 , "Diaz" , "Natalia" , 'F' , 24 , 02 , 2013 , 1 , 110.40 },
        { 4 , "Otra" , "Carolina" , 'F' , 15 , 03 , 2003 , 3 , 45.99 },
    };

    empleadosPorSector( sector , 4 , empleado , 4 );

    return 0;
}
