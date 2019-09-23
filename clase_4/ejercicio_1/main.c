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
