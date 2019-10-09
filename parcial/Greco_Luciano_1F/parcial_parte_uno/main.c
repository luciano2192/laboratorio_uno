#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "clientes_juegos.h"

#define CLIENTES 4

eJuego juegos[4] = {
    { 33 , "Mario Kart (Arcade)" , 68.8 },
    { 55 , "Pacman (Arcade)" , 54.2 },
    { 76 , "Street Fighter (Arcade)" , 99.5 },
    { 15 , "Puzzle Bubble (Arcade)" , 32.9 },
};

eCliente clientes[CLIENTES] =  {
    { 1 , "Lote" , "Luis" , 'M' , "San Carlos 23" , "1234567" , 0 },
    { 2 , "Gati" , "Sandra" , 'F' , "San Mateo 178" , "1567237" , 0 },
    { 3 , "Santos" , "Gabriela" , 'F' , "San Blas 815" , "15567237" , 0 },
    { 4 , "Gonzalez" , "Jimena" , 'F' , "Tupac Amaru 150" , "15634567" , 0 },
};

eAlquiler alquileres[CLIENTES] = {
    { 1 , 55 , 4 , 20190513 },
    { 2 , 33 , 3 , 20190122 },
    { 3 , 55 , 3 , 20180330 },
    { 4 , 76 , 1 , 20190810 },
};

int main()
{
    int opcionMenu , auxId , menorAProm ;
    char auxNombre[31] , auxApellido[31] , auxSexo , auxDomicilio[51] ,  auxTelefono[21];
    float auxPromedio = 0;

    //eCliente clientes[CLIENTES];
    //initClientes( clientes , CLIENTES );

    ordenarJuegos( juegos , 4 );
    printJuegos( juegos , 4 );
    auxPromedio = promedioJuegosAlquilados( juegos , CLIENTES , alquileres , CLIENTES );
    menorAProm = noSuperanPromedio( auxPromedio , juegos , CLIENTES );
    printf("menor promedio: %d" , menorAProm);
    juegosAlquiladosX( juegos , CLIENTES , alquileres , CLIENTES , clientes , CLIENTES );

    do {

        opcionMenu = menuABM();

        switch( opcionMenu ) {
            case 1:
                getString( auxApellido , "Ingrese el apellido: " , "ERROR ! Ingrese nuevamente el apellido: " , 31 );
                getString( auxNombre , "Ingrese el nombre: " , "ERROR ! Ingrese nuevamente el nombre: " , 31 );
                pedirSexo( &auxSexo , "Ingrese el sexo <F | M>: " , "ERROR ! Ingrese nuevamente el sexo: " );
                getString( auxDomicilio , "Ingrese el domicilio: " , "ERROR ! Ingrese nuevamente el domicilio: " , 51 );
                pedirTelefono( auxTelefono , "Ingrese el telefono: " , "ERROR ! Ingrese nuevamente el telefono: " , 21 );
                altaCliente( clientes , CLIENTES , auxApellido , auxNombre , auxSexo , auxDomicilio , auxTelefono );
                break;
            case 2:
                getInt( &auxId , "Ingrese el id: " , "ERROR ! Ingrese nuevamente el id: " , 0 , CLIENTES );
                modificarCliente( clientes , CLIENTES , auxId );
                break;
            case 3:
                getInt( &auxId , "Ingrese el id: " , "ERROR ! Ingrese nuevamente el id: " , 0 , CLIENTES );
                borrarCliente( clientes , CLIENTES , auxId );
                break;
            case 4:
                ordenarClientes( clientes , CLIENTES );
                printClientes( clientes , CLIENTES );
                break;
            case 5:
                break;
        }

    } while( opcionMenu != 5 );

    return 0;
}
