#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char getChar( char msj[] , char errorMsj[] ) {

  int salida = 0;
  char caracter;

  do {
    printf( "\n%s" , msj );
    fflush(stdin);
    scanf( " %c" , &caracter );
    if( isalpha(caracter) == 0 ) {
      printf("%s",errorMsj);
    } else {
      caracter = toupper(caracter);
      salida = 1;
    }
  } while( salida == 0 );

  return caracter;
};


void miFgets( char nombre[] , int cantidad ){

    fflush(stdin);
    fgets(nombre, cantidad-2, stdin);

    nombre[cantidad-1] = '\0';
}

int sonLetras( char letras[] ) {

    int i , respuesta = 0;

    for( i = 0 ; i < strlen(letras) ; i++ ) {
        if( isalpha( letras[i] ) != 0 ) {
            respuesta = 1;
        }
    }

    return respuesta;
}


void getString( char *input , char msj[] , char errorMsj[] , int limit ) {

    int salida = 0 , len = 0;
    char aux[limit];

    do {
      printf( "\n%s" , msj );
      miFgets( aux , limit );
      len = strlen(aux);
      if( (sonLetras(aux) == 1) && (len < limit) ) {
        strcpy( input , aux );
        salida = 1;
      } else {
        printf( "\n%s" , errorMsj );
      }
    } while( salida == 0 );
}



float toFloat( char cadena[] ) {

 float cadenaFloat;

 if( esNumero( cadena ) == 1 ) {
   cadenaFloat = atof( cadena );
 } else {
   cadenaFloat = 0;
 }

 return cadenaFloat;
};


float getFloat( char msj[] , char errorMsj[] , float minLimit , float maxLimit ) {

  float auxFloat;
  int salida = 0;
  char aux[strlen(msj)];

  do {
    printf( "\n%s" , msj );
    scanf( "%s" , aux );
    if( esNumero(aux) == 0 ) {
      printf( "\n%s" , errorMsj );
    } else {
      auxFloat = toFloat(aux);
      if( auxFloat >= minLimit && auxFloat <= maxLimit ) {
        salida = 1;
      } else {
        printf( "\n%s" , errorMsj );
      }
    }
  } while( salida == 0 );

  return auxFloat;
}




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

int getInt( char msj[] , char errorMsj[] , int minLimit , int maxLimit ) {
    int auxInt , salida = 0;
    char aux[strlen(msj)];

    do {
        printf( "\n%s" , msj );
        scanf( "%s" , aux );
        if( esNumero(aux) == 0 ) {
          printf( "\n%s" , errorMsj );
        } else {
          auxInt = toInt(aux);
          if( auxInt >= minLimit && auxInt <= maxLimit ) {
            salida = 1;
          } else {
            printf( "\n%s" , errorMsj );
          }
        }
    } while( salida == 0 );

    return auxInt;
};
