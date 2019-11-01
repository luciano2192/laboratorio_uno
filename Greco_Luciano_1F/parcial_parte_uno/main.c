#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "clientes_juegos.h"

#define TOTAL 2
#define CANTJUEGOS 4

eJuego juegos[CANTJUEGOS] = {
    { 33 , "Mario Kart" , 68.8 },
    { 55 , "Pacman" , 54.2 },
    { 76 , "Street Fighter" , 99.5 },
    { 15 , "Puzzle Bubble" , 32.9 },
};
/*
eCliente clientes[TOTAL] = {
{1,"greco","luciano",'f',"fda 3","34134",0},
{2,"alba","tony",'f',"hgfhf 5","135634",0},
};
*/
int main()
{
    int opcionMenu , auxId , resPrint;
    char auxNombre[31] , auxApellido[31] , auxSexo , auxDomicilio[51] ,  auxTelefono[21];

    eCliente clientes[TOTAL];
    eCliente auxClientes[TOTAL];
    eAlquiler alquileres[TOTAL];
    eJuego juegos[CANTJUEGOS];

    inicializar( clientes , TOTAL );
    inicializar( alquileres , TOTAL );
    //inicializar( juegos , CANTJUEGOS );

    do {

        opcionMenu = menuABM();

        switch( opcionMenu ) {
            case 1:
                if( hayLugar(clientes , TOTAL) == -1 ) {
                    printf("NO HAY LUGAR DISPONIBLE.");
                } else {
                    getString( auxApellido , "Ingrese el apellido: " , "ERROR ! valor incorrecto" , 31 );
                    getString( auxNombre , "Ingrese el nombre: " , "ERROR ! valor incorrecto" , 31 );
                    auxSexo = pedirSexo( "Ingrese el sexo <F | M>: " , "ERROR ! valor incorrecto" );
                    getString( auxDomicilio , "Ingrese el domicilio: " , "ERROR ! valor incorrecto" , 51 );
                    pedirTelefono( auxTelefono , "Ingrese el telefono: " , "ERROR ! valor incorrecto" , 21 );
                    altaCliente( clientes , TOTAL , auxApellido , auxNombre , auxSexo , auxDomicilio , auxTelefono );
                }
                break;
            case 2:
                resPrint = printClientes( clientes , TOTAL );
                if( resPrint != 1 ) {
                    auxId = getInt( "Ingrese el id: " , "ERROR ! valor incorrecto" , 0 , TOTAL );
                    modificarCliente( clientes , TOTAL , auxId );
                }
                break;
            case 3:
                resPrint = printClientes( clientes , TOTAL );
                if( resPrint != 1 ) {
                    auxId = getInt( "Ingrese el id: " , "ERROR ! valor incorrecto" , 0 , TOTAL );
                    borrarCliente( clientes , TOTAL , auxId );
                }
                break;
            case 4:
                clonarCliente( clientes , auxClientes , TOTAL );
                ordenarClientes( auxClientes , TOTAL );
                printClientes( auxClientes , TOTAL );
                break;
            case 5:
                //alquilar juegos
                break;
            case 6:
                break;
        }
    } while( opcionMenu != 5 );

    return 0;
}
