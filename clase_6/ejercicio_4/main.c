#include <stdio.h>
#include <stdlib.h>

void imprimir1( int array[] , int len );
void imprimir2( int array[] , int len );
void imprimir3( int *array , int len );
void imprimir4( int *array , int len );

int main()
{

    int numeros[4] = { 34 , 12 , 16 , 77 };

    imprimir1( numeros , 4 );
    printf("\n-------------------------------------\n");
    imprimir2( numeros , 4 );
    printf("\n-------------------------------------\n");
    imprimir3( numeros , 4 );
    printf("\n-------------------------------------\n");
    imprimir4( numeros , 4 );

    return 0;
}

void imprimir1( int array[] , int len ) {
    int i;

    for( i = 0 ; i < len ; i++ ) {
        printf( "\t%d" , array[i] );
    };
};

void imprimir2( int array[] , int len ) {
    int i;
    int *pI;
    pI = &array[0];

    for( i = 0 ; i < len ; i++ ) {
        printf( "\t%d" , *(pI+i) );
    };
};

void imprimir3( int *array , int len ) {
    int i;

    for( i = 0 ; i < len ; i++ ) {
        printf( "\t%d" , array[i] );
    };
};

void imprimir4( int *array , int len ) {
    int i;
    int *pI;
    pI = &array[0];

    for( i = 0 ; i < len ; i++ ) {
        printf( "\t%d" , *(pI+i) );
    };
};
