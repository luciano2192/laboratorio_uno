#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "ArrayEmployees.h"

void miFgets( char nombre[] , int cantidad ){

    fflush(stdin);
    fgets(nombre, cantidad-2, stdin);

    nombre[cantidad-1] = '\0';
}


int menuABM() {
    int menu;

    printf("\n1) Alta. ");
    printf("\n2) Modificacion. ");
    printf("\n3) Baja. ");
    printf("\n4) Imprimir todos. ");
    printf("\n5) Salir.");
    printf("\nSeleccionar una opcion <1-5>: ");
    scanf( "%d" , &menu );

    return menu;
};

int esNumero( char cadena[] ) {
int i , respuesta;
for( i = 0 ; i < strlen(cadena) ; i++ ) {
  if ( (cadena[i] < '0' || cadena[i] > '9') && cadena[i] != '\0' ){
     respuesta = 0;
  } else {
     respuesta = 1;
  }
}
return respuesta;
};

int toInt( char cadena[] ) {

 int cadenaInt;

 if( esNumero(cadena) == 1 ) {
   cadenaInt = atoi(cadena);
 } else {
   cadenaInt = 0;
 }

 return cadenaInt;
};

float toFloat( char cadena[] ) {

 float cadenaFloat;

 if( esNumero( cadena ) == 1 ) {
   cadenaFloat = atof( cadena );
 } else {
   cadenaFloat = 0;
 }

 return cadenaFloat;
};

int getInt( int* input , char msj[] , char errorMsj[] , int minLimit , int maxLimit ) {
    int auxInt , respuesta = -1;
    char aux[51];

    if( input != NULL && msj != NULL && errorMsj != NULL && minLimit < maxLimit ) {
       do {
        printf( "%s" , msj );
        scanf( "%s" , aux );
        if( esNumero( aux ) != 0 ) {
          auxInt = toInt(aux);
          if( auxInt >= minLimit && auxInt <= maxLimit ) {
            *input = auxInt;
            respuesta = 0;
            fflush(stdin);
            break;
          } else {
            printf( "%s" , errorMsj );
          }
        } else {
          printf( "%s" , errorMsj );
        }
      } while( respuesta == -1 );
    }
    return respuesta;
};


int getFloat( float* input , char msj[] , char errorMsj[] , float minLimit , float maxLimit ) {
    float auxFloat;
    int respuesta = -1;
    char aux[51];

    if( input != NULL && msj != NULL && errorMsj != NULL && minLimit < maxLimit ) {
       do {
        printf( "%s" , msj );
        scanf( "%s" , aux );
        if( esNumero( aux ) != 0 ) {
          auxFloat = toFloat( aux );
          if( auxFloat >= minLimit && auxFloat <= maxLimit ) {
            *input = auxFloat;
            respuesta = 0;
            fflush(stdin);
            break;
          }
        } else {
          printf( "%s" , errorMsj );
        }
      } while( respuesta == -1 );
    }
    return respuesta;
};

int sonLetras( char letras[] ) {

    int i , respuesta = -1;

    for( i = 0 ; i < strlen(letras) ; i++ ) {
        if( isalpha( letras[i] ) != 0 ) {
            respuesta = 1;
        }
    }

    return respuesta;
}

int getString( char* input , char msj[] , char errorMsj[] , int limit ) {

    int respuesta = -1;
    char aux[200];

    if( input != NULL && msj != NULL && errorMsj != NULL && limit > 0 ) {
       do {
        printf( "%s" , msj );
        miFgets( aux , 200 );
        if( sonLetras( aux ) == 1 && strlen( aux ) <= limit ) {
            strcpy( input , aux );
            respuesta = 0;
            fflush(stdin);
            break;
        } else {
          printf( "%s" , errorMsj );
        }
      } while( respuesta == -1 );
    }
    return respuesta;

}

int getChar( char* input , char msj[] , char errorMsj[] ) {

    int respuesta = -1;
    char aux;

    if( input != NULL && msj != NULL && errorMsj != NULL ) {
       do {
        printf( "%s" , msj );
        scanf( "%c" , &aux );
        if( isalpha( aux ) == 1 ) {
            *input = aux;
            respuesta = 0;
            fflush(stdin);
            break;
        } else {
          printf( "%s" , errorMsj );
        }
      } while( respuesta == -1 );
    }
    return respuesta;

}
