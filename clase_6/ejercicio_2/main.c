#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[5] , *p , i;
    p = &vec[0];
    // p = vec; es lo mismo que la linea 7
    printf("\n\nCargando en el vector------>\n");

    for( i = 0 ; i < 5 ; i++ ) {
        vec[i] = 5 * i;
    };

    for( i = 0 ; i < 5 ; i++ ) {
        printf( "\n%d" , *(p+i) );
    };

    printf("\n\nCargando directamente al puntero------>\n");

    for( i = 0 ; i < 5 ; i++ ) {
        *(p+i) = 6 * i;
    };

    for( i = 0 ; i < 5 ; i++ ) {
        printf( "\n%d" , vec[i] );
    };

    return 0;
}
