#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "clientes_juegos.h"

eJuego juegos[4] = {
    { 33 , "Mario Kart" , 68.8 },
    { 55 , "Pacman" , 54.2 },
    { 76 , "Street Fighter" , 99.5 },
    { 15 , "Puzzle Bubble" , 32.9 },
};

int main()
{
    int opcionMenu;
    char auxNombre[31] , auxApellido[31] , auxSexo , auxDomicilio[51] ,  auxTelefono[21];

    eCliente clientes[2];

    initClientes( clientes , 2 );

    do {

        opcionMenu = menuABM();

        switch( opcionMenu ) {
            case 1:
                getString( auxApellido , "Ingrese el apellido: " , "ERROR ! valor incorrecto" , 31 );
                getString( auxNombre , "Ingrese el nombre: " , "ERROR ! valor incorrecto" , 31 );
                auxSexo = pedirSexo( "Ingrese el sexo <F | M>: " , "ERROR ! valor incorrecto" );
                getString( auxDomicilio , "Ingrese el domicilio: " , "ERROR ! valor incorrecto" , 51 );
                pedirTelefono( auxTelefono , "Ingrese el telefono: " , "ERROR ! valor incorrecto" , 21 );
                altaCliente( clientes , 2 , auxApellido , auxNombre , auxSexo , auxDomicilio , auxTelefono );
                break;
            case 2:
                /*
                getInt( &auxId , "Ingrese el id: " , "ERROR ! Ingrese nuevamente el id: " , 0 , 5 );
                modificarCliente( clientes , 2 , auxId );
                */
                break;
            case 3:
                /*
                getInt( &auxId , "Ingrese el id: " , "ERROR ! Ingrese nuevamente el id: " , 0 , 5 );
                borrarCliente( clientes , 2 , auxId );*/
                break;
            case 4:
                //ordenarClientes( clientes , 5 );
                printClientes( clientes , 2 );
                break;
            case 5:
                break;
        }

    } while( opcionMenu != 5 );

    return 0;
}
