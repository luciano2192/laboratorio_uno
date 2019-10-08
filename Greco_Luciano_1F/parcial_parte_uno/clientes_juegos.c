#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "clientes_juegos.h"

int menuABM() {
    int menu;

    printf("\n1) Alta. ");
    printf("\n2) Modificacion. ");
    printf("\n3) Baja. ");
    printf("\n4) Listar. ");
    printf("\n5) Salir.");
    printf("\nSeleccionar una opcion <1-5>: ");
    scanf( "%d" , &menu );

    return menu;
};

int menuModificacion() {
    int menu;

    printf("\n1) Apellido. ");
    printf("\n2) Nombre. ");
    printf("\n3) Sexo. ");
    printf("\n4) Domicilio.");
    printf("\n5) Telefono.");
    printf("\n6) Salir.");
    printf("\nSeleccionar una opcion <1-6>: ");
    scanf( "%d" , &menu );

    return menu;
};

int initClientes( eCliente* list , int len ) {
    int respuesta = -1;

    for( int i = 0 ; i < len ; i++ ) {
        list[i].isEmpty = 1;
    }

    if( estaVacio( list , len ) == 1 ) {
        respuesta = 0;
    }

    return respuesta;
}

int aumentar( eCliente* list , int cantidad ) {
   int i, maximo = 0;

   for( i = 0 ; i < cantidad ; i++ ) {
       if( (list[i].isEmpty == 0) && (list[i].codigo > maximo) ) {
           maximo = list[i].codigo;
       }
   }
   return maximo + 1;
};

int estaVacio( eCliente* list , int length ) {
 int i , respuesta = 0;

 for ( i = 0 ; i < length ; i++ ) {
   if( list[i].isEmpty == 1 ) {
     respuesta = 1;
   }
 }

 return respuesta;
};

char verificaSioNo( char* msj , char* msjError ) {
 char letra;
 printf( "\n%s\n" , msj );
 letra = toupper( getchar() );

 while( letra != 'S' && letra != 'N' ) {
   printf( "\n%s\n" , msjError );
   letra = toupper( getchar() );
 }
 return letra;
};

int hayLugar( eCliente* list , int length ) {
 int i , respuesta = -1;

 for ( i = 0 ; i < length ; i++ ) {
   if( list[i].isEmpty == 1 ) {
     respuesta = i;
     break;
   }
 };

 return respuesta;
};

void formatear( char* text ) {
 int i;

 text[0] = toupper(text[0]);

 while( text[i] != '\0' ) {
   text[i+1] = tolower(text[i+1]);
   i++;
 };
};

int altaCliente( eCliente list[] , int len , char apellido[] , char
nombre[] , char sexo , char domicilio[] , char telefono[] ) {
    int i , respuesta = -1;

    i = hayLugar( list , len );

    if( i != -1 ) {
        list[i].codigo = aumentar( list , len );
        formatear( apellido );
        formatear( nombre );
        formatear( domicilio );
        strcpy( list[i].apellido , apellido );
        strcpy( list[i].nombre , nombre );
        list[i].sexo = sexo;
        strcpy( list[i].domicilio , domicilio );
        strcpy( list[i].telefono , telefono );
        list[i].isEmpty = 1;
        printf("Ingreso exitoso !");
        respuesta = 0;
    } else {
        printf("No hay lugar disponible.");
    }

    return respuesta;
};

int buscarCod( eCliente* list , int len , int codigo ) {
 int i;
 int codCliente = 0;
  if( codigo > 0 && list != NULL && len > 0 ) {
   for ( i = 0 ; i < len ; i++ ) {
     if ( list[i].codigo == codigo ) {
       codCliente = list[i].codigo;
     }
   };
 } else {
   codCliente = -1;
 }
 return codCliente;
};

int modificarCliente( eCliente* list , int len , int codigo ) {

    int cod , respuesta = -1 , auxTel , menuMod;
    char verificar , auxSexo;
    char auxNombre[31] , auxApellido[31] , auxDomicilio[51] , auxTelefono[21];

    cod = buscarCod( list , len , codigo );

    if( cod != -1 ) {
        printf("¿ Que desea modificar ?");
        menuMod = menuModificacion();

        switch( menuMod ) {
            case 1:
              verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
              if( verificar == 'S') {
                getString( auxApellido , "Ingrese el apellido: " , "ERROR ! Ingrese nuevamente el apellido: " , 31 );
                strcpy( list[codigo].apellido , auxApellido );
              }
              respuesta = 0;
            break;
            case 2:
              verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
              if( verificar == 'S') {
                getString( auxNombre , "Ingrese el nombre: " , "ERROR ! Ingrese nuevamente el nombre: " , 31 );
                strcpy( list[codigo].nombre , auxNombre );
              }
              respuesta = 0;
            break;
            case 3:
            verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
              if( verificar == 'S') {
                getChar( &auxSexo , "Ingrese el sexo <F | M>: " , "ERROR ! Ingrese nuevamente el sexo: " );
                list[codigo].sexo = auxSexo;
              }
              respuesta = 0;
            break;
            case 4:
              verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
              if( verificar == 'S') {
                getString( auxDomicilio , "Ingrese el domicilio: " , "ERROR ! Ingrese nuevamente el domicilio: " , 51 );
                strcpy( list[codigo].domicilio , auxDomicilio );
              }
              respuesta = 0;
            break;
            case 5:
              verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
              if( verificar == 'S') {
                getString( auxTelefono , "Ingrese el telefono: " , "ERROR ! Ingrese nuevamente el telefono: " , 21 );
                auxTel = toInt( auxTelefono );
                *list[codigo].telefono = auxTel;
              }
              respuesta = 0;
            break;
            case 6:
              respuesta = 0;
            break;
        }
    }
  return respuesta;
}

int borrarCliente( eCliente* list , int len , int codigo ) {

 int i , respuesta = -1;
 char verificar;

 i = buscarCod( list , len , codigo );

 if( i != -1 ) {
   verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
   if( verificar == 'S') {
     list[i].isEmpty = 0;
     respuesta = 0;
     printf("Dato eliminado con exito.");
   }
 } else {
   printf("Dato inexistente.");
 }

 return respuesta;
}

int ordenarClientes( eCliente* list , int len ) {
  int i , j;
  eCliente aux;

  for( i = 0 ; i < len-1 ; i++ ) {
    for( j = i + 1 ; j < len ; j++ ) {
      if ( strcmp( list[i].apellido , list[j].apellido ) > 0 )  {
        aux = list[i];
        list[i] = list[j];
        list[j] = aux;
      } else {
          if( strcmp( list[i].apellido , list[j].apellido ) == 0 && strcmp( list[i].nombre , list[j].nombre ) > 0 ) {
            aux = list[i];
            list[i] = list[j];
            list[j] = aux;
          }
      }
    }
  };

  return 0;
}

int printClientes( eCliente* list , int len ) {
  int i;
  printf( "\nLISTADO DE CLIENTES\n" );
  printf( "\nID\tAPELLIDO\tNOMBRE\n" );
  for ( i = 0 ; i < len ; i++ ) {

    printf( "\n%d\t%s\t%s\n" , list[i].codigo , list[i].apellido , list[i].nombre );

  };
  return 0;
};

int ordenarJuegos( eJuego* list , int len ) {
  int i , j;
  eJuego aux;

  for( i = 0 ; i < len-1 ; i++ ) {
    for( j = i + 1 ; j < len ; j++ ) {
      if ( strcmp( list[i].descripcion , list[j].descripcion ) > 0 )  {
        aux = list[i];
        list[i] = list[j];
        list[j] = aux;
      }
    }
  };

  return 0;
}

int printJuegos( eJuego* list , int len ) {
  int i;
  printf( "\nLISTADO DE JUEGOS\n" );
  printf( "\nID\tDESCRIPCION\tPRECIO\n" );
  for ( i = 0 ; i < len ; i++ ) {

    printf( "%d\t%s\t%.2f\n" , list[i].codigo , list[i].descripcion , list[i].importe );

  };
  return 0;
};

char pedirSexo( char* input , char msj[] , char errorMsj[] ) {
  char auxLetra;

  while( auxLetra != 'F' && auxLetra != 'M' ) {
    getChar( &auxLetra , msj , errorMsj );
  }

  if( auxLetra == 'F' || auxLetra == 'M' ) {
    *input = auxLetra; 
  }

  return auxLetra;
};
