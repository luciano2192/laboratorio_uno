#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char nombre[11];
    char nombre2[11];

    printf("Nombre: ");

    fgets( nombre , 11 , stdin );

    strcpy( nombre2 , nombre );

    if ( strcmp(nombre,nombre2) == 0 ) {
        printf( "Nombre 2: %s" , nombre2 );
        printf( "Son iguales" );
    } else {
        printf( "Nombre 2: %s" , nombre2 );
        printf("no son iguales");
    };

    return 0;
}
