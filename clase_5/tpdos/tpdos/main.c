#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "input.h"
#include "ArrayEmployees.h"

#define LEN 51
#define CANT 2

int main() {

    int opcionMenu , auxSector , auxId;
    float auxSalario;
    char auxNombre[LEN] , auxApellido[LEN];

    eEmpleado empleados[CANT];
    
    initEmployees( empleados , CANT );

    do {
        opcionMenu = menuABM();

        switch( opcionMenu ) {
            case 1:
                getString( auxNombre , "Ingrese el nombre: " , "ERROR ! Ingrese nuevamente el nombre: " , LEN );
                getString( auxApellido , "Ingrese el apellido: " , "ERROR ! Ingrese nuevamente el apellido: " , LEN );
                getFloat( &auxSalario , "Ingrese el salario: " , "ERROR ! Ingrese nuevamente el salario: " , 1 , 1000 );
                getInt( &auxSector , "Ingrese el sector: " , "ERROR ! Ingrese nuevamente el sector: " , 1 , 3 );
                addEmployee( empleados , CANT , auxNombre , auxApellido , auxSalario , auxSector );
                break;
            case 2:
                getInt( &auxId , "Ingrese el id: " , "ERROR ! Ingrese nuevamente el id: " , 0 , CANT );
                modifyEmployee( empleados , CANT , auxId );
                break;
            case 3:
                getInt( &auxId , "Ingrese el id: " , "ERROR ! Ingrese nuevamente el id: " , 0 , CANT );
                removeEmployee( empleados , CANT , auxId );
                break;
            case 4:
                sortEmployees( empleados , CANT );
                printEmployees( empleados , CANT );
                promedioSalarios( empleados , CANT );
                break;
            case 5:
                break;
        }

    } while( opcionMenu != 5 );
    return 0;
}
