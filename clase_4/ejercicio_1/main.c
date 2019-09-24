#include <stdio.h>
#include <stdlib.h>

int main() {



    return 0;
}

void baja( ePersona pers[] , int cantidad ) {

    int auxId, i , flag = 0;
    char respuesta;

    printf("Ingrese id: ");
    scanf( "%d" , &auxId );

    for( i = 0 ; i < cantidad ; i++ ) {
        if( auxId == pers[i].id ) {
            printf(""); muestro los datos de lo que encontro
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
}

void modificacion( ePersona pers[] , int cantidad ) {
    int auxId, menuMod, i , flag = 0;
    char respuesta;

    printf("Ingrese id: ");
    scanf( "%d" , &auxId );

    for( i = 0 ; i < cantidad ; i++ ) {
        if( auxId == pers[i].id ) {
            printf(""); muestro los datos de lo que encontro
            do {
                printf("¿ Esta seguro que desea modificar el campo ? s/n");
                scanf( "%c" , &respuesta );
            } while (respuesta != 's' && respuesta != 'n');
            if(respuesta == 's') {
                do {
                    menuMod = menuModificacion();
                     switch( idMenu ) {
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
                            scanf("%d", pers[i].edad);
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
