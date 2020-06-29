#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn_funciones.h"
#include "Controller.h"
#include "Piloto.h"
#include "Vuelo.h"

Piloto* piloto_new()
{
    Piloto* nuevoPiloto = (Piloto*)malloc(sizeof(Piloto));
    if( nuevoPiloto != NULL ) {
        piloto_setIdPiloto( nuevoPiloto , 0 );
        piloto_setNombre( nuevoPiloto , "" );
    }
    return nuevoPiloto;
}


Piloto* piloto_newParametros(char* idPiloto,char* nombre)
{
    Piloto* nuevoPiloto = NULL;

    if( idPiloto != NULL && idPiloto != NULL ) {
        nuevoPiloto = piloto_new();
        piloto_setIdPiloto( nuevoPiloto , atoi(idPiloto) );
        piloto_setNombre( nuevoPiloto , nombre );
    }
    return nuevoPiloto;
}

int piloto_setIdPiloto(Piloto* this,int idPiloto)
{
    int salida = -1;
	if( this != NULL && idPiloto > 0 )
	{
		this->idPiloto = idPiloto;
		salida = 0;
	}
	return salida;
}

int piloto_getIdPiloto(Piloto* this,int* idPiloto)
{
    int salida = -1;
	if( this != NULL && idPiloto != NULL )
	{
		*idPiloto = this->idPiloto;
		salida = 0;
	}
	return salida;
}

int piloto_setNombre(Piloto* this,char* nombre)
{
    int salida = -1;
    if( this != NULL && nombre != NULL ) {
        strcpy(this->nombre,nombre);
        salida = 0;
    }
    return salida;
}

int piloto_getNombre(Piloto* this,char* nombre)
{
    int salida = -1;
	if( this != NULL && nombre != NULL )
	{
		strcpy(nombre,this->nombre);
		salida = 0;
	}
	return salida;
}

int parser_PilotoFromText(FILE* pFile, LinkedList* pArrayList)
{
    int salida = -1;
    int cantidadDatos = 0;
    int flag = 0;
    char a[200];
	char b[200];

    Piloto* nuevoPiloto = NULL;

    if( pFile != NULL && pArrayList != NULL ) {
        while( !feof(pFile) ) {
            if( flag == 0 ) {
                fscanf( pFile , "%[^,],%[^\n]\n" , a , b );
                flag = 1;
            }
            if( feof(pFile) ) {
                break;
            }
            cantidadDatos = fscanf( pFile , "%[^,],%[^\n]\n" , a , b );
            if( cantidadDatos == 2 ) {
                nuevoPiloto = piloto_newParametros( a , b );
                if( nuevoPiloto != NULL ) {
                    ll_add( pArrayList , nuevoPiloto );
                    salida = 0;
                }
            }
        }
    }
    return salida;
}

int piloto_loadFromText(char* path, LinkedList* pArrayList)
{
    int salida = -1;
    int leido;
    FILE* pFile;

    if( path != NULL && pArrayList != NULL ) {
        pFile = fopen( path , "r" );
        if( pFile != NULL ) {
            leido = parser_PilotoFromText( pFile , pArrayList );
            if( leido == 0 ) {
                salida = 1;
            }
        }
        fclose( pFile );
    }
    return salida;
}

Piloto* piloto_buscarPorID( LinkedList* pArrayList , int id ) {
    int idPiloto;
    Piloto* piloto;
    Piloto* auxPiloto;
    int lista = ll_len(pArrayList);
    if( pArrayList != NULL )
    {
        for( int i = 0 ; i < lista ; i++ )
        {
            auxPiloto = ll_get(pArrayList, i);
            piloto_getIdPiloto( auxPiloto , &idPiloto );
            if( idPiloto == id ) {
                piloto = auxPiloto;
                break;
            }
        }
    }
    return piloto;
}

int piloto_filtrarPilotoAlexLifeson(void* element) {
    int salida = -1;
    Vuelo* vuelo = NULL;
    if( element != NULL ) {
        vuelo = (Vuelo*)element;
        if( vuelo->idPiloto == 1 ) {
            salida = 0;
        } else {
            salida = 1;
        }
    }
    return salida;
}
