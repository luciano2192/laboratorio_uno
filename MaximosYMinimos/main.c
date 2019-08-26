#include <stdio.h>
#include <stdlib.h>
//luciano
int main()
{
    int i;
    int flag = 0;
    int max;
    int min;
    int aux;

    for( i=0 ; i<5 ;i++ )
    {
        printf( "Ingrese un numero: " );
        scanf( "%d",&aux );

        if( flag == 0 )
        {
            max = aux;
            min = aux;
            flag = 1;
        }
        if( aux < min )
        {
            min = aux;
        }
        if( aux > max ) {
            max = aux;
        }
    }

    printf( "El maximo es:%d\n" , max );
    printf( "El minimo es:%d\n" , min );
    return 0;
}
