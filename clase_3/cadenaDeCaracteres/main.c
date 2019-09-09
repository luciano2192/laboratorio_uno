#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cantidadCadena = 0;
    char nombre[11];

    printf("Nombre:");
    //scanf("%s" , nombre);
    //gets( nombre ); // no se usa, es solo para windows y es insegura.
    fflush( stdin );
    fgets( nombre , 11 , stdin );
    printf("ingreso: %s" , nombre);
    cantidadCadena = strlen( nombre ); // cuenta la cantidad de caracteres de la cadena
    printf( "\ncantidad cadena: %d" , cantidadCadena );
    nombre[cantidadCadena - 1] = nombre[cantidadCadena]; // reemplazo el ENTER por el \0
    cantidadCadena = strlen( nombre );
    printf("\ningreso: %s" , nombre);
    printf( "\ncantidad cadena: %d" , cantidadCadena );
    return 0;
}

void miPropioFgets( char *cadena ) {
    int cantidad;

    fgets( cadena , sizeof(cadena)-2 , stdin );
    cantidad = strlen( cadena );
    cadena[cantidad-1] = '\0';
}
