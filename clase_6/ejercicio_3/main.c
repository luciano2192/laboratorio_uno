#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 72;
    int *punteroInt;
    int **punteroPuntero;

    punteroInt = &a; // Obtenemos la posici�n de memoria
    punteroPuntero = &punteroInt; // Obtenemos la posici�n de memoria

    printf( "\n a = %d" , a );
    printf( "\n punteroInt = %d" , *punteroInt );
    printf( "\n punteroPuntero = %d" , **punteroPuntero );

    return 0;
}
