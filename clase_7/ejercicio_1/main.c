#include <stdio.h>
#include <stdlib.h>

void mostrarCadena( char *punteroCadena );

int main()
{
    char cadena[31] = {"luciano"};
    char *puntero;

    puntero = cadena;

    mostrarCadena( puntero );

    return 0;
}

void mostrarCadena( char *punteroCadena ) {
    while( *punteroCadena != '\0' ) {
        printf( "%c" , *punteroCadena );
        punteroCadena++;
    }
}
