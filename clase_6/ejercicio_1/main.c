#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* a;
    int b,c;

    b = 15; // Asignamos el valor 15 a la variable 'b'
    a = &b; // Obtenemos la posición de memoria de 'b' con el operador '&'
    c = *a; // Copiamos el contenido apuntado por el puntero 'a'

    printf( "\na = %d" , *a );
    printf( "\nb = %d" , b );
    printf( "\nc = %d" , c );

    return 0;
}
