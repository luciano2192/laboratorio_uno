#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn_funciones.h"
#include "Controller.h"
#include "Piloto.h"
#include "parser.h"
#include "Vuelo.h"

int menuPrincipal() {
    int opcion = -1;
    printf("\nMenu:"
        "\n1. Cargar archivo."
        "\n2. Imprimir vuelos."
        "\n3. Cantidad de pasajeros."
        "\n4. Cantidad de pasajeros a X destino."
        "\n5. Filtrar vuelos cortos."
        "\n6. Listar vuelos a Portugal."
        "\n7. Filtrar a Alex Lifeson."
        "\n8. Salir.");
    getDatoGenericoInt(&opcion,"Seleccione una opcion del menu<1-8>: ","ERROR! ingrese nuevamente una opcion valida.",1,8,3);
    return opcion;
}

int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    int salida = -1;
    int leido;
    FILE* pFile;

    if( path != NULL && pArrayList != NULL ) {
        pFile = fopen( path , "r" );
        if( pFile != NULL ) {
            leido = parser_FromText( pFile , pArrayList );
            if( leido == 0 ) {
                printf("\nDATOS CARGADOS CORRECTAMENTE.\n");
                salida = 1;
            } else {
                printf("\nERROR AL CARGAR LOS DATOS.");
            }
        }
        fclose( pFile );
    }
    return salida;
}

int controller_cargarArchivo( LinkedList* pArrayList ) {
    int salida = -1;
    char archivo[50];
    getDatoGenericoString( archivo , "Ingrese nombre del archivo: " , "ERROR ! ingrese nuevamente el nombre" , 200 );
    formatearString(archivo);
    strtok( archivo , "\n" );
    if( strcmp(archivo,"Vuelos.csv") == 0 ) {
        if( controller_loadFromText(archivo,pArrayList) == 1 ) {
            salida = 0;
        }
    }
    return salida;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayList)
{
    int salida = -1;
    int leido;
    FILE* pFile;

    if( path != NULL && pArrayList != NULL ) {
        pFile = fopen( path , "rb" );
        if( pFile != NULL ) {
            leido = parser_FromBinary( pFile , pArrayList );
            if( leido == 0 ) {
                printf("\nDATOS CARGADOS CORRECTAMENTE.\n");
                salida = 1;
            } else {
                printf("\nERROR AL CARGAR LOS DATOS.");
            }
        }
        fclose( pFile );
    }
    return salida;
}

int controller_ListVuelos(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos)
{
    int salida = -1;
    int listaVuelos;
    int cantidadVuelos = 0;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[10];
    char destino[100];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    Vuelo* vuelo = NULL;
    Piloto* piloto = NULL;

    if( pArrayListVuelos != NULL && pArrayListPilotos != NULL ){
        if( piloto_loadFromText("Pilotos.csv",pArrayListPilotos) == 1 ) {
            listaVuelos = ll_len(pArrayListVuelos);
            vuelo_columnasListaVuelos();
            for( int i = 0 ; i < listaVuelos ; i++ ) {
                vuelo = (Vuelo*)ll_get(pArrayListVuelos,i);
                vuelo_getIdPiloto(vuelo,&idPiloto);
                piloto = piloto_buscarPorID( pArrayListPilotos , idPiloto );
                vuelo_getIdVuelo(vuelo,&idVuelo);
                vuelo_getIdAvion(vuelo,&idAvion);
                vuelo_FechaToString(vuelo,fecha);
                vuelo_getDestino(vuelo,destino);
                vuelo_getCantPasajeros(vuelo,&cantPasajeros);
                vuelo_getHoraDespegue(vuelo,&horaDespegue);
                vuelo_getHoraLlegada(vuelo,&horaLlegada);
                printf( "\n%6d %12d %22s %20s %20s %15d %15d %15d" , idVuelo
                                                                   , idAvion
                                                                   , piloto->nombre
                                                                   , fecha
                                                                   , destino
                                                                   , cantPasajeros
                                                                   , horaDespegue
                                                                   , horaLlegada );
                cantidadVuelos++;
                if( cantidadVuelos%50 == 0 ) {
                    printf( "\n\n");
                    system("pause");
                }
            }
            salida = 0;
        }
    }
    return salida;
}

int controller_cantPasajeros(LinkedList* pArrayListVuelos)
{
    int salida = -1;
    int cantidadPasajeros = 0;
    if( pArrayListVuelos != NULL ) {
        cantidadPasajeros = ll_count(pArrayListVuelos,vuelo_contarPasajeros);
        salida = 0;
    }
    if( salida == 0 ) {
        printf( "\nLA CANTIDAD TOTAL DE PASAJEROS ES DE :%d \n" , cantidadPasajeros );
        system("pause");
    }
    return salida;
}
/*
int controller_cantPasajerosADestinoX(LinkedList* pArrayListVuelos)
{
    int salida = -1;
    char destino[100];
    int lista;
    int cantidadPasajeros = 0;
    Vuelo* vuelo = NULL;
    if( pArrayListVuelos != NULL ) {
        lista = ll_len(pArrayListVuelos);
        getDatoGenericoString( destino , "Ingrese el destino: " , "ERROR ! ingrese nuevamente el destino" , 100 );
        formatearString( destino );
        strtok( destino , "\n" );
        for( int i = 0 ; i < lista ; i++ ) {
            vuelo = ll_get(pArrayListVuelos,i);
            if( strcmp(destino,vuelo->destino) == 0 ) {
                cantidadPasajeros += vuelo->cantPasajeros;
            }
        }
        salida = 0;
    }
    if( salida == 0 ) {
        printf( "\nLA CANTIDAD DE PASAJEROS A %s ES DE :%d \n" , destino , cantidadPasajeros );
        system("pause");
    }
    return salida;
}*/

int controller_cantPasajerosADestinoX(LinkedList* pArrayListVuelos)
{
    int salida = -1;
    int cantidadPasajeros = 0;
    LinkedList* listaFiltrada = NULL;
    if( pArrayListVuelos != NULL ) {
        listaFiltrada = ll_filter(pArrayListVuelos,vuelo_filtrarDestinoIrlanda);
        if( listaFiltrada != NULL ) {
            cantidadPasajeros = ll_count(listaFiltrada,vuelo_contarPasajeros);
            salida = 0;
        }
    }
    if( salida == 0 ) {
        printf( "\nLA CANTIDAD DE PASAJEROS AL DESTINO SELECCIONADO ES DE :%d \n" , cantidadPasajeros );
        system("pause");
    }
    return salida;
}

int controller_cargarVuelosCortos( LinkedList* pArrayList ) {
    int salida = -1;
    char archivo[50];
    LinkedList* listaFiltrada = NULL;
    if( pArrayList != NULL ) {
        getDatoGenericoString( archivo , "Ingrese nombre del archivo: " , "ERROR ! ingrese nuevamente el nombre" , 50 );
        formatearString(archivo);
        strtok( archivo , "\n" );
        listaFiltrada = ll_filter(pArrayList,vuelo_filtrarVuelosConDuracionMenorA3Horas);
        if( controller_saveVuelosCortos(archivo,listaFiltrada) == 0 ) {
            salida = 0;
        }
    }
    return salida;
}

/*
int controller_saveVuelosCortos(char* path, LinkedList* pArrayList)
{
    int salida = -1;
    int lista;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[10];
    char destino[100];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    int horasVuelo;
    FILE* pFile;
    Vuelo* vuelo = NULL;

    if( path != NULL && pArrayList != NULL ) {
        lista = ll_len( pArrayList );
        if( lista > 0 ) {
            pFile = fopen( path , "w");
            if( pFile != NULL ) {
                fprintf( pFile , "idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n" );
                for( int i = 0 ; i < lista ; i++ ) {
                    vuelo = (Vuelo*)ll_get(pArrayList,i);
                    if( vuelo != NULL ) {
                        vuelo_getIdVuelo(vuelo,&idVuelo);
                        vuelo_getIdAvion(vuelo,&idAvion);
                        vuelo_getIdPiloto(vuelo,&idPiloto);
                        vuelo_FechaToString(vuelo,fecha);
                        vuelo_getDestino(vuelo,destino);
                        vuelo_getCantPasajeros(vuelo,&cantPasajeros);
                        vuelo_getHoraDespegue(vuelo,&horaDespegue);
                        vuelo_getHoraLlegada(vuelo,&horaLlegada);
                        horasVuelo = horaDespegue - horaLlegada;
                        if( horasVuelo < 3) {
                            fprintf( pFile , "%d,%d,%d,%s,%s,%d,%d,%d\n" , idVuelo
                                                                         , idAvion
                                                                         , idPiloto
                                                                         , fecha
                                                                         , destino
                                                                         , cantPasajeros
                                                                         , horaDespegue
                                                                         , horaLlegada);
                        } else {
                            break;
                        }
                        salida = 0;
                    } else {
                        break;
                    }
                }
                fclose( pFile );
            }
        }
    }
    if( salida == 0 ) {
        printf("\nDATOS GUARDADOS CON EXITO.");
    } else {
        printf("\nERROR AL GUARDAR LOS DATOS.");
    }
    return salida;
}
*/


int controller_saveVuelosCortos(char* path, LinkedList* pArrayList)
{
    int salida = -1;
    int lista;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[10];
    char destino[100];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    FILE* pFile;
    Vuelo* vuelo = NULL;
    if( path != NULL && pArrayList != NULL ) {
        lista = ll_len( pArrayList );
        if( lista > 0 ) {
            pFile = fopen( path , "w");
            if( pFile != NULL ) {
                fprintf( pFile , "idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n" );
                for( int i = 0 ; i < lista ; i++ ) {
                    vuelo = (Vuelo*)ll_get(pArrayList,i);
                    if( vuelo != NULL ) {
                        vuelo_getIdVuelo(vuelo,&idVuelo);
                        vuelo_getIdAvion(vuelo,&idAvion);
                        vuelo_getIdPiloto(vuelo,&idPiloto);
                        vuelo_FechaToString(vuelo,fecha);
                        vuelo_getDestino(vuelo,destino);
                        vuelo_getCantPasajeros(vuelo,&cantPasajeros);
                        vuelo_getHoraDespegue(vuelo,&horaDespegue);
                        vuelo_getHoraLlegada(vuelo,&horaLlegada);
                        fprintf( pFile , "%d,%d,%d,%s,%s,%d,%d,%d\n" , idVuelo
                                                                     , idAvion
                                                                     , idPiloto
                                                                     , fecha
                                                                     , destino
                                                                     , cantPasajeros
                                                                     , horaDespegue
                                                                     , horaLlegada);
                        salida = 0;
                    } else {
                        break;
                    }
                }
                fclose( pFile );
            }
        }
    }
    if( salida == 0 ) {
        printf("\nDATOS GUARDADOS CON EXITO.");
    } else {
        printf("\nERROR AL GUARDAR LOS DATOS.");
    }
    return salida;
}

int controller_ListVuelosDestinoX(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos)
{
    int salida = -1;
    char auxDestino[100];
    int listaVuelos;
    int cantidadVuelos = 0;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[10];
    char destino[100];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    Vuelo* vuelo = NULL;
    Piloto* piloto = NULL;

    if( pArrayListVuelos != NULL && pArrayListPilotos != NULL ){
        if( piloto_loadFromText("Pilotos.csv",pArrayListPilotos) == 1 ) {
            listaVuelos = ll_len(pArrayListVuelos);
            getDatoGenericoString( auxDestino , "Ingrese el destino: " , "ERROR ! ingrese nuevamente el destino" , 100 );
            formatearString(auxDestino);
            strtok( auxDestino , "\n" );
            vuelo_columnasListaVuelos();
            for( int i = 0 ; i < listaVuelos ; i++ ) {
                vuelo = (Vuelo*)ll_get(pArrayListVuelos,i);
                if( strcmp(auxDestino,vuelo->destino) == 0 ) {
                    vuelo_getIdPiloto(vuelo,&idPiloto);
                    piloto = piloto_buscarPorID( pArrayListPilotos , idPiloto );
                    vuelo_getIdVuelo(vuelo,&idVuelo);
                    vuelo_getIdAvion(vuelo,&idAvion);
                    vuelo_FechaToString(vuelo,fecha);
                    vuelo_getDestino(vuelo,destino);
                    vuelo_getCantPasajeros(vuelo,&cantPasajeros);
                    vuelo_getHoraDespegue(vuelo,&horaDespegue);
                    vuelo_getHoraLlegada(vuelo,&horaLlegada);
                    printf( "\n%6d %12d %22s %20s %20s %15d %15d %15d" , idVuelo
                                                                       , idAvion
                                                                       , piloto->nombre
                                                                       , fecha
                                                                       , destino
                                                                       , cantPasajeros
                                                                       , horaDespegue
                                                                       , horaLlegada );
                    cantidadVuelos++;
                    if( cantidadVuelos%50 == 0 ) {
                        printf( "\n\n");
                        system("pause");
                    }
                }
            }
            salida = 0;
        }
    }
    return salida;
}


int controller_ListVuelosFiltrandoPiloto(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos)
{
    int salida = -1;
    LinkedList* listaVuelosFiltrada = NULL;

    if( pArrayListVuelos != NULL && pArrayListPilotos != NULL ){
        listaVuelosFiltrada = ll_filter(pArrayListVuelos,piloto_filtrarPilotoAlexLifeson);
        if( listaVuelosFiltrada != NULL ) {
            if( controller_ListVuelos(listaVuelosFiltrada,pArrayListPilotos) == 0 ) {
                salida = 0;
            }
        }
    }
    return salida;
}

/*

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int salida = -1;
    int opcion;

    if( pArrayListEmployee != NULL ) {
        do{
            opcion = menuOrdenar();
            switch(opcion)
            {
                case 1:
                    ll_sort( pArrayListEmployee , employee_ordenarPorNombre , 1 );
                    printf("\nORDENAMIENTO FINALIZADO.\n");
                    salida = 0;
                    break;
                case 2:
                    ll_sort( pArrayListEmployee , employee_ordenarPorHoras , 1 );
                    printf("\nORDENAMIENTO FINALIZADO.\n");
                    salida = 0;
                case 3:
                    ll_sort( pArrayListEmployee , employee_ordenarPorSueldo , 1 );
                    printf("\nORDENAMIENTO FINALIZADO.\n");
                    salida = 0;
                    break;
                case 4:
                    break;
            }
        }while(opcion != 4);
    }
    return salida;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int salida = -1;
    int lista;
    FILE* pFile;
    Employee* empleado = NULL;

    if( path != NULL && pArrayListEmployee != NULL ) {
        lista = ll_len( pArrayListEmployee );
        if( lista > 0 ) {
            pFile = fopen( path , "wb");
            if( pFile != NULL ) {
                for( int i = 0 ; i < lista ; i++ ) {
                    empleado = (Employee*)ll_get( pArrayListEmployee , i );
                    if( empleado != NULL ) {
                        fwrite( empleado , sizeof(Employee) , 1 , pFile );
                        salida = 0;
                    } else {
                        break;
                    }
                }
                fclose( pFile );
            }
        }
    }
    if( salida == 0 ) {
        printf("\nDATOS GUARDADOS CON EXITO.");
    } else {
        printf("\nERROR AL GUARDAR LOS DATOS.");
    }
    return salida;
}

int controller_asignarID( LinkedList* pArrayListEmployee ) {
    int id = 0;
    int lista;
    Employee* empleado;

    if( pArrayListEmployee != NULL ) {
        lista = ll_len( pArrayListEmployee );
        if( lista > 0 ) {
            for( int i = 0 ; i < lista ; i++ ) {
                empleado = (Employee*)ll_get( pArrayListEmployee , i );
                if( empleado != NULL ) {
                    if( empleado->id > id ) {
                        id = empleado->id;
                    }
                }
            }
            id+=1;
        } else {
            id = 1;
        }
    }
    return id;
}

*/
