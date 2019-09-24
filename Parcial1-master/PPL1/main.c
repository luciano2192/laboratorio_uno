#include <stdio.h>
#include <stdlib.h>
#include "Egreso.h"
#define tamanioPropietario 20
#define tamanioAutomovil 40
#define tamanioEgresos 20

int main()
{
    ePropietario listadoPropietario[tamanioPropietario];
    eAutomovil listadoAutomovil[tamanioAutomovil];
    eEgreso listadoEgresos[tamanioEgresos];
    inicializarEstados(listadoPropietario, tamanioPropietario);
    inicializarEstadosAutomovil(listadoAutomovil,tamanioAutomovil);
    inicializarEgresos(listadoEgresos,tamanioEgresos);
    int indice;
    int opcion;
    int flagPropietario=cargarHarcodePropietario(listadoPropietario, tamanioPropietario);
    int flagAutomovil=0;
    int flagEgreso=0;

    do
    {
        printf("MENU PRINCIPAL\n");
        printf("1- Gestionar propietarios");
        printf("\n2- Gestionar automoviles");
        printf("\n3- Recaudaciones");
        printf("\n4- Mostrar datos filtrados");
        printf("\n5- Salir\n");
        opcion=getInt("\nEliga una opcion ",opcion);
        fflush(stdin);
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("MENU DE PROPIETARIOS\n");
            printf("1- Alta propietario");
            printf("\n2- Mostrar propietario");
            printf("\n3- Modificar propietario");
            printf("\n4- Borrar propietario");
            printf("\n5- Salir del menu de propietarios");
            opcion=getInt("\nEliga una opcion ",opcion);
            fflush(stdin);
            switch(opcion)
            {
            case 1:
                indice=obtenerEspacioLibre(listadoPropietario,tamanioPropietario);
                flagPropietario=agregarPersona(listadoPropietario,tamanioPropietario);
                break;
            case 2:
                mostrarListaPropietario(listadoPropietario,tamanioPropietario,flagPropietario);
                break;
            case 3:
                modificarPropietario(listadoPropietario,tamanioPropietario,flagPropietario);
                break;
            case 4:
                flagEgreso=darDeBajaPropietario(listadoPropietario,listadoAutomovil,listadoEgresos,tamanioAutomovil,tamanioPropietario,tamanioEgresos,"Esta seguro que quiere dar de baja al propietario? (S/N) ",flagPropietario);
                break;
            case 5:
                break;
            default:
                printf("\nOpcion no encontrada ");
                break;
            }
            break;
        case 2:
            system("cls");
            printf("MENU DE AUTOMOVILES");
            printf("\n1- Alta automovil");
            printf("\n2- Mostrar Automoviles");
            printf("\n3- Egreso automovil");
            printf("\n4- Salir del menu de automoviles");
            opcion=getInt("\nEliga una opcion ",opcion);
            fflush(stdin);
            switch(opcion)
            {
            case 1:
                indice=buscarLibreAutomovil(listadoAutomovil,tamanioAutomovil);
                flagAutomovil=altaAutomovil(listadoAutomovil,listadoPropietario,tamanioAutomovil,tamanioPropietario,indice,flagPropietario);
                break;
            case 2:
                mostrarListaAutomovil(listadoAutomovil,tamanioAutomovil,flagAutomovil);
                break;
            case 3:
                flagEgreso=darDeBajaAutomovil(listadoAutomovil,listadoPropietario,listadoEgresos,tamanioAutomovil,tamanioPropietario,"Estas seguro que queres realizar el egreso de este automovil? (S/N) ",tamanioEgresos,flagAutomovil);
                break;
            case 4:
                break;
            default:
                printf("\nOpcion no encontrada ");
                break;
            }
            break;
        case 3:
            system("cls");
            printf("MENU DE RECAUDACIONES");
            printf("\n1- Mostrar recaudacion total");
            printf("\n2- Mostrar recaudacion por marca");
            printf("\n3- Salir del menu de recaudaciones");
            opcion=getInt("\nEliga una opcion ",opcion);
            fflush(stdin);
            switch(opcion)
            {
            case 1:
                mostrarRecaudaciones(listadoEgresos,tamanioEgresos,1);
                break;
            case 2:
                mostrarRecaudacionesPorMarca(listadoEgresos,tamanioEgresos,1);
                break;
            case 3:
                break;
            default:
                printf("\nOpcion no encontrada ");
                break;
            }
            break;
        case 4:
            system("cls");
            printf("MENU DE DATOS FILTRADOS");
            printf("\n1- Mostrar propietario con sus coches");
            printf("\n2- Mostrar propietarios que posean un coche marca Audi");
            printf("\n3- Autos ordenados por patente");
            printf("\n4- Propietarios ordenados por nombre");
            printf("\n5- Mostrar los propietarios que superan cierta edad");
            printf("\n6- Salir del menu de filtros");
            opcion=getInt("\nEliga una opcion ",opcion);
            fflush(stdin);
            switch(opcion)
            {
            case 1:
                mostrarUsuarioConSusAutomoviles(listadoPropietario,listadoAutomovil,tamanioPropietario,tamanioAutomovil,flagAutomovil);
                break;
            case 2:
                mostrarPropietarioAudi(listadoPropietario,listadoAutomovil,tamanioPropietario,tamanioAutomovil,flagAutomovil);
                break;
            case 3:
                mostrarOrdenadosPorPatente(listadoPropietario,listadoAutomovil,tamanioPropietario,tamanioAutomovil,flagAutomovil);
                break;
            case 4:
                mostrarPropietarioPorNombre(listadoPropietario,tamanioPropietario);
                break;
            case 5:
                //mostrarPropietariosSuperanEdad(listadoPropietario,tamanioPropietario);
                break;
            case 6:
                break;
            default:
                printf("\nOpcion no encontrada ");
                break;
            }
            break;
            case 5:
                opcion=7;
                break;
            default:
                printf("\nOpcion no encontrada ");
                break;



        }

            printf("\n");
            system("pause");
            system("cls");


    }while(opcion!=7);

return 0;
}
