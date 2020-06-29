#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Vuelo.h"

int parser_FromText(FILE* pFile, LinkedList* pArrayList)
{
    int salida = -1;
    int cantidadDatos = 0;
    int flag = 0;
    char a[200];
	char b[200];
	char c[200];
	char d[200];
	char e[200];
	char f[200];
	char g[200];
	char h[200];

    Vuelo* nuevoVuelo = NULL;

    if( pFile != NULL && pArrayList != NULL ) {
        while( !feof(pFile) ) {
            if( flag == 0 ) {
                fscanf( pFile , "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n" , a , b , c , d , e , f , g , h );
                flag = 1;
            }
            if( feof(pFile) ) {
                break;
            }
            cantidadDatos = fscanf( pFile , "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n" , a , b , c , d , e , f , g , h );
            if( cantidadDatos == 8 ) {
                nuevoVuelo = vuelo_newParametros( a , b , c , d , e , f , g , h );
                if( nuevoVuelo != NULL ) {
                    ll_add( pArrayList , nuevoVuelo );
                    salida = 0;
                }
            }
        }
    }
    return salida;
}

int parser_FromBinary(FILE* pFile, LinkedList* pArrayList)
{
    int salida = -1;
    int leido;
    Vuelo* nuevoVuelo = NULL;

    if( pFile != NULL && pArrayList != NULL ) {
        while( !feof(pFile) ) {
            if( feof(pFile) ) {
                break;
            }
            nuevoVuelo = vuelo_new();
            leido = fread( nuevoVuelo , sizeof(Vuelo) , 1 , pFile );
            if( leido != 0 ) {
                ll_add( pArrayList , nuevoVuelo );
                salida = 0;
            }
        }
    }
    return salida;
}
