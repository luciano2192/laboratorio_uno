#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED

typedef struct {
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct {
    int idVuelo;
    int idAvion;
    int idPiloto;
    eFecha fecha;
    char destino[100];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
} Vuelo;

#endif // VUELO_H_INCLUDED

void vuelo_columnasListaVuelos();
Vuelo* vuelo_new();
Vuelo* vuelo_newParametros(char* idVuelo,char* idAvion,char* idPiloto,char* fecha,char* destino,char* cantPasajeros,char* horaDespegue,char* horaLlegada);
int vuelo_descomponerFecha(char* fecha , int *datoDia , int *datoMes , int *datoAnio );
void vuelo_delete(Vuelo* this);
int vuelo_setIdVuelo(Vuelo* this,int idVuelo);
int vuelo_getIdVuelo(Vuelo* this,int* idVuelo);
int vuelo_setIdAvion(Vuelo* this,int idAvion);
int vuelo_getIdAvion(Vuelo* this,int* idAvion);
int vuelo_setIdPiloto(Vuelo* this,int idPiloto);
int vuelo_getIdPiloto(Vuelo* this,int* idPiloto);
int vuelo_setFecha(Vuelo* this,int dia,int mes,int anio);
int vuelo_getFecha(Vuelo* this,int* dia,int* mes,int* anio);
int vuelo_setDestino(Vuelo* this,char* destino);
int vuelo_getDestino(Vuelo* this,char* destino);
int vuelo_setCantPasajeros(Vuelo* this,int cantPasajeros);
int vuelo_getCantPasajeros(Vuelo* this,int* cantPasajeros);
int vuelo_setHoraDespegue(Vuelo* this,int horaDespegue);
int vuelo_getHoraDespegue(Vuelo* this,int* horaDespegue);
int vuelo_setHoraLlegada(Vuelo* this,int horaLlegada);
int vuelo_getHoraLlegada(Vuelo* this,int* horaLlegada);
int vuelo_buscarVueloPorID( LinkedList* pArrayList , int id );
int vuelo_FechaToString( Vuelo* this , char* stringFecha );
int vuelo_contarPasajeros(void* this);
int vuelo_filtrarDestinoIrlanda(void* element);
int vuelo_filtrarVuelosConDuracionMenorA3Horas(void* element);
