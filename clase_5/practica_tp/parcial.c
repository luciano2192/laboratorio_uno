#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "practica.h"

void inicializar( eEmpleado pers[] , int cantidad ) {
    int i;

    for( i = 0 ; i < cantidad ; i++ ) {
        pers[i].isEmpty = 1;
    }
}

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
                miFgets( empleado[i].fechaIngreso.dia , 2 );

                printf("\nMes: ");
                miFgets( empleado[i].fechaIngreso.mes , 2 );

                printf("\nAnio: ");
                miFgets( empleado[i].fechaIngreso.anio , 4 );

                empleado[i].isEmpty = 0;
                flag = 1;
            }
        }
        if(flag == 0) {
            printf("No hay espacio suficiente");
        }
}
/*
void mostrarTodos( eEmpleado pers[], int cantidad ){
    int i;

    for( i = 0; i < cantidad; i++ ){
        if(pers[i].isEmpty == 0) {
            mostrarUno(pers[i]);
        }
    }
}*/
/*
void mostrarUno( eEmpleado per ){
        printf("%s\t%s\t%d\t%d\n", per.apellido, per.nombre, per.isEmpty);
}*/

/*
void ordenarPersonaPorEdad( eEmpleado pers[] , int cantidad ) {
    int i,j;
    eEmpleado auxPers;

    for( i = 0 ; i < cantidad-1 ; i++ ) {
        for( j = i + 1 ; i < cantidad ; j++ ) {
            if ( pers[i].edad > pers[j].edad ) {
                auxPers = pers[i];
                pers[i] = pers[j];
                pers[j] = auxPers;
            }
        }
    }
}
*/
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
}
/*
void filtrarPorPais( eEmpleado pers[] , int cantidadPersonas , ePais pais[] , int cantidadPaises ) {
    int i , j;
    int auxPais;

    printf("\nPais a buscar: ");
    scanf( "%d" , &auxPais );

    for( i = 0 ; i < cantidadPaises ; i++ ) {
        if( pais[i].id == auxPais ) {
            for( j = 0 ; j < cantidadPersonas ; j++ ){
                if( pers[j].ePaisId == auxPais ) {
                    printf("%s\t%s", pers[j].nombre , pais[i].descripcion );
                }
            }
        }
    }
}
*/
/*
void baja( eEmpleado pers[] , int cantidad ) {

    int auxId, i , flag = 0;
    char respuesta;

    printf("Ingrese id: ");
    scanf( "%d" , &auxId );

    for( i = 0 ; i < cantidad ; i++ ) {
        if( auxId == pers[i].id ) {
            mostrarUno( pers[i] );
            do {
                printf("¿ Esta seguro que desea darlo de baja ? s/n");
                scanf( "%c" , &respuesta );
            } while (respuesta != 's' && respuesta != 'n');
            if(respuesta == 's') {
                pers[i].isEmpty = 1;
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
}*/
/*
void modificacion( eEmpleado pers[] , int cantidad ) {
    int auxId, menuMod, i , flag = 0;
    char respuesta;

    printf("Ingrese id: ");
    scanf( "%d" , &auxId );

    for( i = 0 ; i < cantidad ; i++ ) {
        if( auxId == pers[i].id ) {
            //printf(""); muestro los datos de lo que encontro
            mostrarUno( pers[i] );
            do {
                printf("¿ Esta seguro que desea modificar el campo ? s/n");
                scanf( "%c" , &respuesta );
            } while (respuesta != 's' && respuesta != 'n');
            if(respuesta == 's') {
                do {
                    menuMod = menuModificacion();
                     switch( menuMod ) {
                        case 1:
                            printf("\nNombre: ");
                            fflush(stdin);
                            scanf("%s", pers[i].nombre);
                            break;
                        case 2:
                            printf("\nApellido: ");
                            fflush(stdin);
                            scanf("%s", pers[i].apellido);
                            break;
                        case 3:
                            printf("\nEdad: ");
                            fflush(stdin);
                            scanf( "%d", pers[i].edad );
                            break;
                        case 4:
                            break;
                    }
                } while ( menuMod != 5 );
            } else {
                printf("El registro no se dio de baja");
            }
        }
    }

    if( flag == 0 ) {
        printf("El dato no existe");
    }
}
*/
int menuModificacion() {
    int menu;

    printf("\n1) Nombre. ");
    printf("\n2) Apellido. ");
    printf("\n3) Edad. ");
    printf("\n4) Salir.");
    printf("\nSeleccionar una opcion <1-4>: ");
    scanf( "%d" , &menu );

    return menu;
}
/*
int obtenerUltimoLegajo( eEmpleado e[] , int cantidad ) {

    int i, flag = 0;

    for( i = 0 ; i < cantidad ; i++ ) {
        if( e[i].isEmpty != 1 && flag != 0 ) {

        }
    }
};*/

void mostrarSector( eSector s ){
    printf("%d\t%s\n", s.cod, s.descripcion );
};

void mostrarSectores( eSector s[], int cantidad ){
    int i;

    for( i = 0; i < cantidad; i++ ){
        mostrarSector( s[i] );
    }
};

void empleadosPorSector( eSector sector[] , int cantidadSector , eEmpleado empleado[] , int cantidadEmpleados ) {

    int i , j , aux;
    mostrarSectores( sector , cantidadSector );
    printf( "Seleccione un sector: " );
    scanf( "%d" , &aux );

    for ( i = 0 ; i < cantidadSector ; i++ ) {
        if ( sector[i].cod == aux ) {
            for ( j = 0 ; j < cantidadEmpleados ; j++ ) { // falta agregar isEmpty
                if ( empleado[j].idSector == aux ) {
                    printf( "%s\t%s\t%s\n", empleado[j].nombre , empleado[j].apellido , sector[i].descripcion );
                }
            }
        }
    }
};

void mostrarMenu( eMenu m ){
    printf( "%d\t%s\t%.2f\n", m.cod, m.descripcion , m.importe );
};

void mostrarMenues( eMenu m[], int cantidad ){
    int i;

    for( i = 0; i < cantidad; i++ ){
        mostrarMenu( m[i] );
    }
};

void menuPorEmpleado( eMenu menu[] , int cantMenu , eAlmuerzo almuerzo[] , int cantAlmuerzo , eEmpleado empleado[] , int cantEmpleado ) {

    int i , j , k ,auxMenu;
    mostrarMenues( menu , cantMenu );
    printf( "Seleccione un menu: " );
    scanf( "%d" , &auxMenu );

    for ( i = 0 ; i < cantMenu ; i++ ) {
        if ( auxMenu == menu[i].cod ) {
            for ( j = 0 ; j < cantAlmuerzo ; j++ ) { // falta agregar isEmpty
                if ( auxMenu == almuerzo[j].menuId ) {
                    for ( k = 0 ; k < cantEmpleado ; k++ ) {
                        if ( almuerzo[j].empleadoId == empleado[k].id ) { // falta agregar isEmpty
                            printf( "%s\t%s\n" , empleado[k].nombre , menu[i].descripcion );
                        }
                    }
                }
            }
        }
    }
};

int buscar( eEmpleado e[] , int cantidad , int id ) {
 int i;
 int idEmpleado = 0;

 for ( i = 0 ; i < cantidad ; i++ ) {
   if ( e[i].id == id ) {
     idEmpleado = e[i].id;
   }
 }
 return idEmpleado;
};

void modificar() {
 int idMenu;

 do {
   idMenu = menuModificar();
   switch(idMenu) {

     case 1:
       system("cls");
     break;
     case 5:
     break;
   }


 } while (idMenu != 5);
}



int menuModificar() {
   int menu;
   printf("¿ Que desea modificar ?\n");

   printf("\n1) Nombre. ");
   printf("\n2) Apellido. ");
   printf("\n3) Salario. ");
   printf("\n4) Sector. ");
   printf("\n5) Salir.");
   printf("\nSeleccionar una opcion <1-5>: ");
   scanf( "%d" , &menu );

   return menu;
};

int esNumero( char cadena[] , int cantidad ) {
 int i , res = 0;
 for( i = 0 ; i < cantidad ; i++ ) {
   if ( isdigit(cadena[i]) ){
     res = 1;
   } else {
     res = 0;
   }
 }
 return res;
};

void miFgets(char nombre[], int cantidad){

    fflush(stdin);
    fgets(nombre, cantidad-2, stdin);

    nombre[cantidad-1] = '\0';
}

int aumentar( eEmpleado empleado[] , int cantidad ) {
    int i, maximo = 0;

    for( i = 0 ; i < cantidad ; i++ ) {

        if( empleado[i].isEmpty == 0 && empleado[i].id > maximo ) {
            maximo = empleado[i].id;
        }
    }
    return maximo++;
};




