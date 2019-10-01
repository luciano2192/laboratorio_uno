#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tpdos.h"

void inicializar( eEmpleado pers[] , int cantidad ) {
    int i;

    for( i = 0 ; i < cantidad ; i++ ) {
        pers[i].isEmpty = 1;
    }
};

void miFgets( char nombre[] , int cantidad ){

    fflush(stdin);
    fgets(nombre, cantidad-2, stdin);

    nombre[cantidad-1] = '\0';
}

int aumentar( eEmpleado empleado[] , int cantidad ) {
    int i, maximo = 0;

    for( i = 0 ; i < cantidad ; i++ ) {
        if( (empleado[i].isEmpty == 0) && (empleado[i].id > maximo) ) {
            maximo = empleado[i].id;
        }
    }
    return maximo + 1;
};


int menuABM() {
    int menu;

    printf("\n1) Alta. ");
    printf("\n2) Baja. ");
    printf("\n3) Modificacion. ");
    printf("\n4) Imprimir todos. ");
    printf("\n5) Salir.");
    printf("\nSeleccionar una opcion <1-5>: ");
    scanf( "%d" , &menu );

    return menu;
};

void alta( eEmpleado empleado[], int cantidad ){
    int i;
    int flag = 0;

        for( i = 0; i < cantidad; i++ ){
            if ( empleado[i].isEmpty != 0 ) {
                printf( "\nApellido: " );
                fflush( stdin );
                miFgets( empleado[i].apellido , 51 );

                printf("\nNombre: ");
                fflush( stdin );
                miFgets( empleado[i].nombre , 51 );

                printf("\nDia: ");
                scanf( "%d" , &empleado[i].fechaIngreso.dia );

                printf("\nMes: ");
                scanf( "%d" , &empleado[i].fechaIngreso.mes );

                printf("\nAnio: ");
                scanf( "%d" , &empleado[i].fechaIngreso.anio );

                empleado[i].id = aumentar( empleado , cantidad );
                empleado[i].isEmpty = 0;
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            printf("No hay espacio suficiente");
        }
};

void baja( eEmpleado empleado[] , int cantidad ) {

    int auxId , i , flag = 0;
    char respuesta;
    mostrarTodos( empleado , cantidad );

    printf("Ingrese id: ");
    scanf( "%d" , &auxId );

    for( i = 0 ; i < cantidad ; i++ ) {
        if( auxId == empleado[i].id ) {
            mostrarUno( empleado[i] );
            do {
                printf("¿ Esta seguro que desea darlo de baja ? s/n");
                scanf( "%c" , &respuesta );
            } while (respuesta != 's' && respuesta != 'n');
            if(respuesta == 's') {
                empleado[i].isEmpty = 1;
                flag = 1;
                break;
            } else {
                printf("El registro no se dio de baja");
            }
        }
    }

    if( flag == 0 ) {
        printf("El dato no existe");
    }
};

int buscar( eEmpleado empleado[] , int cantidad , int id ) {
 int i;
 int idEmpleado = 0;

 for ( i = 0 ; i < cantidad ; i++ ) {
   if ( empleado[i].id == id ) {
     idEmpleado = empleado[i].id;
   };
 };
 return idEmpleado;
};

void mostrarUno( eEmpleado empleado ){
        printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\n", empleado.id , empleado.apellido, empleado.nombre, empleado.isEmpty , empleado.fechaIngreso.dia , empleado.fechaIngreso.mes , empleado.fechaIngreso.anio );
}

void mostrarTodos( eEmpleado empleado[], int cantidad ){
    int i , flag = 0;

    for( i = 0 ; i < cantidad ; i++ ){
        if( empleado[i].isEmpty == 0 ) {
            mostrarUno( empleado[i] );
        } else {
            flag = 1;
        }
    }

    if (flag == 1) {
        printf("no hay datos cargados.");
    }
};
