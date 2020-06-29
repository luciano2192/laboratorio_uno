#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Vuelo.h"
#include "Controller.h"
#include "utn_funciones.h"

void vuelo_columnasListaVuelos() {
    printf("\n------------------------------------------------------LISTADO DE VUELOS-------------------------------------------------------------------");
    printf("\n------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\n| ID VUELO |  ID AVION |        PILOTO         |      FECHA      |        DESTINO       | CANT. PASAJEROS | HORA DESPEGUE | HORA LLEGADA |");
    printf("\n------------------------------------------------------------------------------------------------------------------------------------------");
}

Vuelo* vuelo_new()
{
    Vuelo* nuevoVuelo = (Vuelo*)malloc(sizeof(Vuelo));
    if( nuevoVuelo != NULL ) {
        vuelo_setIdVuelo( nuevoVuelo , 0 );
        vuelo_setIdAvion( nuevoVuelo , 0 );
        vuelo_setIdPiloto( nuevoVuelo , 0 );
        vuelo_setFecha( nuevoVuelo , 0 , 0 , 0 );
        vuelo_setDestino( nuevoVuelo , "" );
        vuelo_setCantPasajeros( nuevoVuelo , 0 );
        vuelo_setCantPasajeros( nuevoVuelo , 0 );
        vuelo_setHoraDespegue( nuevoVuelo , 0 );
        vuelo_setHoraLlegada( nuevoVuelo , 0 );
    }
    return nuevoVuelo;
}


Vuelo* vuelo_newParametros(char* idVuelo,char* idAvion,char* idPiloto,char* fecha,char* destino,char* cantPasajeros,char* horaDespegue,char* horaLlegada)
{
    int dia;
    int mes;
    int anio;
    Vuelo* nuevoVuelo = NULL;

    if( idVuelo != NULL && idAvion != NULL && idPiloto != NULL && fecha != NULL && destino != NULL && cantPasajeros != NULL && horaDespegue != NULL && horaLlegada != NULL ) {
        nuevoVuelo = vuelo_new();
        vuelo_descomponerFecha( fecha , &dia , &mes , &anio );
        vuelo_setIdVuelo( nuevoVuelo , atoi(idVuelo) );
        vuelo_setIdAvion( nuevoVuelo , atoi(idAvion) );
        vuelo_setIdPiloto( nuevoVuelo , atoi(idPiloto) );
        vuelo_setFecha( nuevoVuelo , dia , mes , anio );
        vuelo_setDestino( nuevoVuelo , destino );
        vuelo_setCantPasajeros( nuevoVuelo , atoi(cantPasajeros) );
        vuelo_setHoraDespegue( nuevoVuelo , atoi(horaDespegue) );
        vuelo_setHoraLlegada( nuevoVuelo , atoi(horaLlegada) );
    }
    return nuevoVuelo;
}

int vuelo_descomponerFecha(char* fecha , int *datoDia , int *datoMes , int *datoAnio ) {
    int salida = -1;
    char dia[10];
    char mes[10];
    char anio[10];
    if( fecha != NULL ) {

        dia[0]=fecha[0];
        dia[1]=fecha[1];
        mes[0]=fecha[3];
        mes[1]=fecha[4];
        anio[0]=fecha[6];
        anio[1]=fecha[7];
        anio[2]=fecha[8];
        anio[3]=fecha[9];

        *datoDia=atoi(dia);
        *datoMes=atoi(mes);
        *datoAnio=atoi(anio);
        salida = 0;
    }
    return salida;
}

void vuelo_delete(Vuelo* this) {
    if( this != NULL ) {
        free( this );
    }
}

int vuelo_setIdVuelo(Vuelo* this,int idVuelo)
{
    int salida = -1;
	if( this != NULL && idVuelo > 0 )
	{
		this->idVuelo = idVuelo;
		salida = 0;
	}
	return salida;
}

int vuelo_getIdVuelo(Vuelo* this,int* idVuelo)
{
    int salida = -1;
	if( this != NULL && idVuelo != NULL )
	{
		*idVuelo = this->idVuelo;
		salida = 0;
	}
	return salida;
}

int vuelo_setIdAvion(Vuelo* this,int idAvion)
{
    int salida = -1;
	if( this != NULL && idAvion > 0 )
	{
		this->idAvion = idAvion;
		salida = 0;
	}
	return salida;
}

int vuelo_getIdAvion(Vuelo* this,int* idAvion)
{
    int salida = -1;
	if( this != NULL && idAvion != NULL )
	{
		*idAvion = this->idAvion;
		salida = 0;
	}
	return salida;
}

int vuelo_setIdPiloto(Vuelo* this,int idPiloto)
{
    int salida = -1;
	if( this != NULL && idPiloto > 0 )
	{
		this->idPiloto = idPiloto;
		salida = 0;
	}
	return salida;
}

int vuelo_getIdPiloto(Vuelo* this,int* idPiloto)
{
    int salida = -1;
	if( this != NULL && idPiloto != NULL )
	{
		*idPiloto = this->idPiloto;
		salida = 0;
	}
	return salida;
}

int vuelo_setFecha(Vuelo* this,int dia,int mes,int anio)
{
    int salida = -1;
	if( this != NULL && dia > 0 && mes > 0 && anio > 0 )
	{
		this->fecha.dia = dia;
		this->fecha.mes = mes;
		this->fecha.anio = anio;
		salida = 0;
	}
	return salida;
}

int vuelo_getFecha(Vuelo* this,int* dia,int* mes,int* anio)
{
    int salida = -1;
	if( this != NULL && dia != NULL && mes != NULL && anio != NULL )
	{
		*dia = this->fecha.dia;
		*mes = this->fecha.mes;
		*anio = this->fecha.anio;
		salida = 0;
	}
	return salida;
}

int vuelo_FechaToString( Vuelo* this , char* stringFecha )
{
    int salida = -1;
	if( this != NULL )
	{
		sprintf( stringFecha , "%d/%d/%d" , this->fecha.dia , this->fecha.mes , this->fecha.anio );
		salida = 0;
	}
	return salida;
}

int vuelo_setDestino(Vuelo* this,char* destino)
{
    int salida = -1;
    if( this != NULL && destino != NULL ) {
        strcpy(this->destino,destino);
        salida = 0;
    }
    return salida;
}

int vuelo_getDestino(Vuelo* this,char* destino)
{
    int salida = -1;
	if( this != NULL && destino != NULL )
	{
		strcpy(destino,this->destino);
		salida = 0;
	}
	return salida;
}

int vuelo_setCantPasajeros(Vuelo* this,int cantPasajeros)
{
    int salida = -1;
	if( this != NULL && cantPasajeros > 0 )
	{
		this->cantPasajeros = cantPasajeros;
		salida = 0;
	}
	return salida;
}

int vuelo_getCantPasajeros(Vuelo* this,int* cantPasajeros)
{
    int salida = -1;
	if( this != NULL && cantPasajeros != NULL )
	{
		*cantPasajeros = this->cantPasajeros;
		salida = 0;
	}
	return salida;
}

int vuelo_setHoraDespegue(Vuelo* this,int horaDespegue)
{
    int salida = -1;
	if( this != NULL && horaDespegue > 0 )
	{
		this->horaDespegue = horaDespegue;
		salida = 0;
	}
	return salida;
}

int vuelo_getHoraDespegue(Vuelo* this,int* horaDespegue)
{
    int salida = -1;
	if( this != NULL && horaDespegue != NULL )
	{
		*horaDespegue = this->horaDespegue;
		salida = 0;
	}
	return salida;
}

int vuelo_setHoraLlegada(Vuelo* this,int horaLlegada)
{
    int salida = -1;
	if( this != NULL && horaLlegada > 0 )
	{
		this->horaLlegada = horaLlegada;
		salida = 0;
	}
	return salida;
}

int vuelo_getHoraLlegada(Vuelo* this,int* horaLlegada)
{
    int salida = -1;
	if( this != NULL && horaLlegada != NULL )
	{
		*horaLlegada = this->horaLlegada;
		salida = 0;
	}
	return salida;
}
/*
int employee_CompareByName(Employee* e1, Employee* e2)
{
    int salida = -1;
    if( e1 != NULL && e2 != NULL ) {
        strcmp(e1->nombre, e2->nombre);
        salida = 0;
    }
    return salida;
}
int employee_CompareById(Employee* e1, Employee* e2)
{
    if( e1 != NULL && e2 != NULL ) {
        if(e1->id > e2->id)
        {
            return 1;
        }
        else
        {
            if(e1->id < e2->id)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
        return strcmp(e1->nombre, e2->nombre);
    }
}


int vuelo_validarDestino( char* destino , int len ) {
    int salida = -1;
    if( destino != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( isalpha(destino[i]) || isspace(destino[i]) ) {
                salida = 0;
            }
        }
    }
    return salida;
}

*/

int vuelo_buscarVueloPorID( LinkedList* pArrayList , int id ) {
    int indice = -1;
    int idVuelo;
    Vuelo* vuelo;
    int lista = ll_len(pArrayList);
    if( pArrayList != NULL )
    {
        for( int i = 0 ; i < lista ; i++ )
        {
            vuelo = ll_get(pArrayList, i);
            vuelo_getIdVuelo( vuelo , &idVuelo );
            if( idVuelo == id ) {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int vuelo_contarPasajeros(void* this)
{
    int salida = -1;
    int cantidadPasajeros;
    Vuelo* vuelo = NULL;
    if( this != NULL ) {
        vuelo = (Vuelo*)this;
        vuelo_getCantPasajeros(vuelo,&cantidadPasajeros);
        salida = cantidadPasajeros;
    }
    return salida;
}

int vuelo_filtrarDestinoIrlanda(void* element) {
    int salida = -1;
    Vuelo* vuelo = NULL;
    if( element != NULL ) {
        vuelo = (Vuelo*)element;
        if( strcmp("Irlanda",vuelo->destino) == 0 ) {
            salida = 1;
        } else {
            salida = 0;
        }
    }
    return salida;
}

int vuelo_filtrarVuelosConDuracionMenorA3Horas(void* element) {
    int salida;
    int horaDespegue;
    int horaLlegada;
    int totalHoras;
    Vuelo* vuelo = NULL;
    if( element != NULL ) {
        vuelo = (Vuelo*)element;
        vuelo_getHoraDespegue(vuelo,&horaDespegue);
        vuelo_getHoraLlegada(vuelo,&horaLlegada);
        totalHoras = horaLlegada - horaDespegue;
        if( totalHoras  < 3 ) {
            salida = 1;
        } else {
            salida = 0;
        }
    }

    return salida;
}
