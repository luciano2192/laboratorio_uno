#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "input.h"
#include "ArrayEmployees.h"

#define LEN 51

int initEmployees( eEmpleado* list , int len ) {
    int respuesta = -1;

    for( int i = 0 ; i < len ; i++ ) {
        list[i].isEmpty = 1;
    }

    if( estaVacio( list , len ) == 1 ) {
        respuesta = 0;
    }

    return respuesta;
}


int findEmployeeById( eEmpleado* list , int len , int id ) {
 int i;
 int idEmpleado = 0;
  if( id > 0 && list != NULL && len > 0 ) {
   for ( i = 0 ; i < len ; i++ ) {
     if ( list[i].id == id ) {
       idEmpleado = list[i].id;
     }
   };
 } else {
   idEmpleado = -1;
 }
 return idEmpleado;
};


int printEmployees( eEmpleado* list , int length ) {
  int i;
  printf( "\nLISTADO DE EMPLEADOS\n" );
  printf( "\nID\tAPELLIDO\tNOMBRE\tSALARIO\tSECTOR\n" );
  for ( i = 0 ; i < length ; i++ ) {
    if( list[i].isEmpty == 0 ) {
      printf( "%d\t%s\t%s\t%2.f\t%d\n" , list[i].id , list[i].lastName , list[i].name , list[i].salary , list[i].sector);
    }
  };
  return 0;
};


int addEmployee( eEmpleado* list , int len , char name[] , char
lastName[] , float salary , int sector ) {
    int i , respuesta = -1;

    i = hayLugar( list , len );
    printf("el lugar:%d" , i );
    if( i != -1 ) {
        list[i].id = aumentar( list , len );
        formatear( name );
        formatear( lastName );
        strcpy( list[i].name , name );
        strcpy( list[i].lastName , lastName );
        list[i].salary = salary;
        list[i].sector = sector;
        list[i].isEmpty = 1;
        printf("Ingreso exitoso !");
        respuesta = 0;
    } else {
        printf("No hay lugar disponible.");
    }

    return respuesta;
};


int removeEmployee( eEmpleado* list , int len , int id ) {

 int i , respuesta = -1;
 char verificar;

 i = findEmployeeById( list , len , id );

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

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees( eEmpleado* list , int len ) {
  int i , j;
  eEmpleado aux;
 
  for( i = 0 ; i < len-1 ; i++ ) {
    for( j = i + 1 ; i < len ; j++ ) {
      if ( list[i].sector > list[j].sector )  {
        aux = list[i];
        list[i] = list[j];
        list[j] = aux;
      } else {
          if( list[i].sector == list[j].sector && strcmp( list[i].lastName , list[j].lastName ) > 0 ) {
            aux = list[i];
            list[i] = list[j];
            list[j] = aux;
          }
      }
    }
  };

  return 0;
}

int estaVacio( eEmpleado* list , int length ) {
 int i , respuesta = 0;

 for ( i = 0 ; i < length ; i++ ) {
   if( list[i].isEmpty == 1 ) {
     respuesta = 1;
   }
 }

 return respuesta;
};


int hayLugar( eEmpleado* list , int length ) {
 int i , respuesta = -1;

 for ( i = 0 ; i < length ; i++ ) {
   if( list[i].isEmpty == 1 ) {
     respuesta = i;
     break;
   }
 };

 return respuesta;
};


void mostrarEmpleado( eEmpleado* list , int cantidad , int id ) {
 int empleadoID, i;
 if( list != NULL && cantidad > 0 && id > 0 ) {
   empleadoID = findEmployeeById(list, cantidad, id);
   for ( i = 0 ; i < cantidad ; i++ ) {
     if ( list[i].id == empleadoID ) {
       printf("ID\tNOMBRE\n");
       printf("%d\t%s\n", list[i].id, list[i].name);
     };
   };
 };
};


void formatear( char* text ) {
 int i;

 text[0] = toupper(text[0]);

 while( text[i] != '\0' ) {
   text[i+1] = tolower(text[i+1]);
   i++;
 };
};


int aumentar( eEmpleado* list , int cantidad ) {
   int i, maximo = 0;

   for( i = 0 ; i < cantidad ; i++ ) {
       if( (list[i].isEmpty == 0) && (list[i].id > maximo) ) {
           maximo = list[i].id;
       }
   }
   return maximo + 1;
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


int menuModificacion() {
    int menu;

    printf("\n1) Nombre. ");
    printf("\n2) Apellido. ");
    printf("\n3) Salario. ");
    printf("\n4) Sector.");
    printf("\n5) Salir.");
    printf("\nSeleccionar una opcion <1-5>: ");
    scanf( "%d" , &menu );

    return menu;
};


int modifyEmployee( eEmpleado* list , int len , int id ) {

    int auxId , auxSector , menuMod , respuesta = -1;
    char verificar;
    float auxSalario;
    char auxNombre[LEN] , auxApellido[LEN];

    id = findEmployeeById( list , len , id );

    if( id != -1 ) {
        printf("¿ Que desea modificar ?");
        menuMod = menuModificacion();

        switch( menuMod ) {
            case 1:
              verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
              if( verificar == 'S') {
                getString( auxNombre , "Ingrese el nombre: " , "ERROR ! Ingrese nuevamente el nombre: " , LEN );
                strcpy( list[id].name , auxNombre );
              }
              respuesta = 0;
            break;
            case 2:
              verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
              if( verificar == 'S') {
                getString( auxApellido , "Ingrese el apellido: " , "ERROR ! Ingrese nuevamente el apellido: " , LEN );
                strcpy( list[id].lastName , auxApellido );
              }
              respuesta = 0;
            break;
            case 3:
            verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
              if( verificar == 'S') {
                getFloat( &auxSalario , "Ingrese el salario: " , "ERROR ! Ingrese nuevamente el salario: " , 1 , 1000 );
                list[id].salary = auxSalario;
              }
              respuesta = 0;
            break;
            case 4:
              verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
              if( verificar == 'S') {
                 getInt( &auxSector , "Ingrese el sector: " , "ERROR ! Ingrese nuevamente el sector: " , 1 , 3 );
                list[id].sector = auxSector;
              }
              respuesta = 0;
            break;
            case 5:
              respuesta = 0;
            break;
        }
    }
  return respuesta;
}
