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
    int opcionMenu , auxId;
    char auxNombre[31] , auxApellido[31] , auxSexo , auxDomicilio[51] ,  auxTelefono[21];

    eCliente clientes[5];

    initClientes( clientes , 5 );

    do {

        opcionMenu = menuABM();

        switch( opcionMenu ) {
            case 1:
                getString( auxApellido , "Ingrese el apellido: " , "ERROR ! Ingrese nuevamente el apellido: " , 31 );
                getString( auxNombre , "Ingrese el nombre: " , "ERROR ! Ingrese nuevamente el nombre: " , 31 );
                getChar( &auxSexo , "Ingrese el sexo <F | M>: " , "ERROR ! Ingrese nuevamente el sexo: " );
                getString( auxDomicilio , "Ingrese el domicilio: " , "ERROR ! Ingrese nuevamente el domicilio: " , 51 );
                pedirTelefono( auxTelefono , "Ingrese el telefono: " , "ERROR ! Ingrese nuevamente el telefono: " , 21 );
                altaCliente( clientes , 5 , auxApellido , auxNombre , auxSexo , auxDomicilio , auxTelefono );
                break;
            case 2:
                getInt( &auxId , "Ingrese el id: " , "ERROR ! Ingrese nuevamente el id: " , 0 , 5 );
                modificarCliente( clientes , 5 , auxId );
                break;
            case 3:
                getInt( &auxId , "Ingrese el id: " , "ERROR ! Ingrese nuevamente el id: " , 0 , 5 );
                borrarCliente( clientes , 5 , auxId );
                break;
            case 4:
                //ordenarClientes( clientes , 5 );
                printClientes( clientes , 5 );
                break;
            case 5:
                break;
        }

    } while( opcionMenu != 5 );

    return 0;
}
