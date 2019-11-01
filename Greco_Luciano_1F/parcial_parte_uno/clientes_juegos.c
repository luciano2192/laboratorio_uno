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
    printf("\n5) Alquilar juego.");
    printf("\n6) Salir.");
    printf("\nSeleccionar una opcion <1-6>: ");
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

int inicializar( eCliente *list , int len ) {
    int respuesta = -1;

    for( int i = 0 ; i < len ; i++ ) {
        list[i].isEmpty = 1;
    }

    if( estaVacio( list , len ) == 1 ) {
        respuesta = 0;
    }

    return respuesta;
}

int aumentar( eCliente *list , int cantidad ) {
   int i, maximo = 0;

   for( i = 0 ; i < cantidad ; i++ ) {
       if( (list[i].isEmpty == 0) && (list[i].codigo > maximo) ) {
           maximo = list[i].codigo;
       }
   }
   return maximo + 1;
};

int estaVacio( eCliente *list , int length ) {
 int i , respuesta = 0;

 for ( i = 0 ; i < length ; i++ ) {
   if( list[i].isEmpty == 0 ) {
     respuesta = 1;
     break;
   }
 }

 return respuesta;
};

char verificaSioNo( char* msj , char* msjError ) {
    char letra;
    printf( "\n%s\n" , msj );
    letra = toupper( getchar() );
    fflush(stdin);
    while( letra != 'S' && letra != 'N' ) {
        printf( "\n%s\n" , msjError );
        letra = toupper( getchar() );
    }
    return letra;
};

int hayLugar( eCliente *list , int len ) {
 int i , respuesta = -1;

 for ( i = 0 ; i < len ; i++ ) {
   if( list[i].isEmpty != 0 ) {
     respuesta = i;
     break;
   }
 };

 return respuesta;
};

void formatear( char text[] ) {
  int i , len = strlen(text);

  text[0] = toupper(text[0]);

  for( i = 1 ; i < len ; i++ ) {
    text[i] = tolower(text[i]);
  }
};

void altaCliente( eCliente list[] , int len , char apellido[] , char
nombre[] , char sexo , char domicilio[] , char telefono[] ) {
    int lugar = 0;

    lugar = hayLugar( list , len );

    if( lugar != -1 ) {
        list[lugar].codigo = aumentar( list , len );
        formatear(apellido);
        formatear(nombre);
        formatear(domicilio);
        strcpy( list[lugar].apellido , apellido );
        strcpy( list[lugar].nombre , nombre );
        list[lugar].sexo = sexo;
        strcpy( list[lugar].domicilio , domicilio );
        strcpy( list[lugar].telefono , telefono );
        list[lugar].isEmpty = 0;
        printf("INGRESO EXITOSO !");
    }
};

int buscarCod( eCliente *list , int len , int codigo ) {
    int i;
    int codCliente = -1;

    for ( i = 0 ; i < len ; i++ ) {
        if ( list[i].codigo == codigo ) {
            codCliente = i;
        }
    };

    if( codCliente != -1 ){
        return codCliente;
    } else {
        return codCliente;
    }
};


int modificarCliente( eCliente* list , int len , int codigo ) {

    int cod , respuesta = -1 , menuMod;
    char verificar , auxSexo;
    char auxNombre[31] , auxApellido[31] , auxDomicilio[51] , auxTelefono[21];

    cod = buscarCod( list , len , codigo );
    fflush(stdin);

    if( cod != -1 ) {

        printf( "DATOS ENCONTRADOS" );
        printCliente( list , cod );

        printf("¿ Que desea modificar ?");
        menuMod = menuModificacion();

        switch( menuMod ) {
            case 1:
                getString( auxApellido , "Ingrese el apellido: " , "ERROR ! valor incorrecto" , 31 );
                verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
                    if( verificar == 'S') {
                        formatear(auxApellido);
                        strcpy( list[cod].apellido , auxApellido );
                    }
                respuesta = 0;
            break;
            case 2:
                getString( auxNombre , "Ingrese el nombre: " , "ERROR ! valor incorrecto" , 31 );
                verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
                    if( verificar == 'S') {
                        formatear(auxNombre);
                        strcpy( list[cod].nombre , auxNombre );
                    }
                respuesta = 0;
            break;
            case 3:
                auxSexo = pedirSexo( "Ingrese el sexo <F | M>: " , "ERROR ! valor incorrecto" );
                verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
                    if( verificar == 'S') {
                        list[cod].sexo = auxSexo;
                    }
                respuesta = 0;
            break;
            case 4:
                getString( auxDomicilio , "Ingrese el domicilio: " , "ERROR ! valor incorrecto" , 51 );
                verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
                    if( verificar == 'S') {
                        formatear(auxDomicilio);
                        strcpy( list[cod].domicilio , auxDomicilio );
                    }
                respuesta = 0;
            break;
            case 5:
                pedirTelefono( auxTelefono , "Ingrese el telefono: " , "ERROR ! valor incorrecto" , 21 );
                verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
                    if( verificar == 'S') {
                        strcpy( list[cod].telefono , auxTelefono );
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

void borrarCliente( eCliente *list , int len , int cod ) {

 int i;
 char verificar;

 i = buscarCod( list , len , cod );

    if( i != -1 && list[i].isEmpty != 1 ) {

    printf("DATOS ENCONTRADOS");
    printCliente( list , i );

    verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
        if( verificar == 'S') {
            list[i].isEmpty = 1;
            printf("DATO ELIMINADO CON EXITO.");
        }
    } else {
        printf("DATO INEXISTENTE.");
    }
}

void clonarCliente( eCliente origen[] , eCliente destino[] , int len ) {
    int i;

    for(i=0;i<len;i++) {
        destino[i] = origen[i];
    }
}

void ordenarClientes( eCliente *list , int len ) {
    int i , j;
    eCliente aux;

    for( i = 0 ; i < len-1 ; i++ ) {
        if( list[i].isEmpty == 0 ) {
            for( j = i + 1 ; j < len ; j++ ) {
                if ( strcmp( list[i].apellido , list[j].apellido ) > 0 )  {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                if( (strcmp( list[i].apellido , list[j].apellido ) == 0) && (strcmp( list[i].nombre , list[j].nombre ) > 0) ) {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
    };
}

void printCliente( eCliente *list , int cod ) {
    printf("\n%d\t%s\t%s\t%c\t%s\t%s",list[cod].codigo,list[cod].apellido,list[cod].nombre,list[cod].sexo,list[cod].domicilio,list[cod].telefono);
};

int printClientes( eCliente *list , int len ) {
    int i , vacio , resp = 0;
    vacio = estaVacio( list , len );
    if ( vacio == 1 ) {
        printf("\nLISTADO DE CLIENTES\n");
        printf("CODIGO\tAPELLIDO\tNOMBRE\tSEXO\tDOMICILIO\tTELEFONO\n");
        for ( i = 0 ; i < len ; i++ ) {
            if( list[i].isEmpty == 0 ) {
                printCliente( list , i );
            }
        };
    } else {
        resp = 1;
        printf("\nNO HAY DATOS CARGADOS.");
    }
    return resp;
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


char pedirSexo( char msj[] , char errorMsj[] ) {
  char auxLetra;

  while( auxLetra != 'F' && auxLetra != 'M' ) {
    auxLetra = getChar( msj , errorMsj );
  }

  return auxLetra;
};

void altaAlquilerJuego( eAlquiler alquileres[] , eJuego juegos[] , eCliente clientes[] , int len , int juegos ) {

    int vacio = estaVacio(clientes , len);

    if( vacio != 0 ) {
        printClientes(clientes , len);
        printJuegos(juegos , CANTJUEGOS);


    }
}

//---------------------------------------------------

/*
float promedioJuegosAlquilados( eJuego* juego , int lenJue , eAlquiler* alquiler , int lenAlq ) {

  int i , j , cantidadJuegos = 0 ;
  float suma = 0, promedio = 0 , respuesta = -1;

    for ( i = 0 ; i < lenAlq ; i++ ) {
        for ( j = 0 ; j < lenJue ; j++ ) {
            if ( alquiler[i].codJuego == juego[j].codigo ) {
                suma += juego[j].importe;
                cantidadJuegos++;
            }
        }
    }

    promedio = suma / cantidadJuegos;

    if( suma > 0 && promedio > 0 ) {

        printf( "\nPROMEDIO JUEGOS ALQUILADOS\n" );
        printf( "\nTOTAL\tPROMEDIO\n" );
        printf( "\n%.2f\t%.2f\n" , suma , promedio );

        respuesta = promedio;
    };


    return respuesta;
}

int noSuperanPromedio( float prom , eJuego* list , int len ) {

    int i , cant = 0;

    for ( i = 0 ; i < len ; i++ ) {
        if( list[i].importe < prom ) {
            cant++;
        }
    };

    return cant;
}

void juegosAlquiladosX( eJuego* juego , int lenJue , eAlquiler* alquiler , int lenAlq , eCliente* cliente , int lenCli ) {

    int i , j , k ;

    for ( i = 0 ; i < lenAlq ; i++ ) {
        for ( j = 0 ; j < lenJue ; j++ ) {
            if( alquiler[i].codJuego == juego[j].codigo ) {
                for ( k = 0 ; k < lenCli ; k++ ) {
                    if( cliente[k].codigo == alquiler[i].codCliente ) {
                        printf( "%s\t%s\n" , cliente[k].nombre , juego[j].descripcion );
                    }
                }
            }
        }
    }
};
*/
