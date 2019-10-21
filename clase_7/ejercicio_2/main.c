#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 1

typedef struct {
    char nombre[20];
    int edad;
} eAlumno;


int main()
{
    int i;
    eAlumno alu , *ptrAlu , alus[3] , *ptrAlus;
    ptrAlu = alu;
    ptrAlus = alus;

    //------------------------------------------*
    printf("Ingrese su nombre: ");
    scanf( "%s" , alu->nombre );
    printf("Ingrese su edad: ");
    scanf( "%d" , &alu->edad );

    for(i=0;i<CANTIDAD;i++) {
        printf("Nombre: %s" , alu->nombre);
        printf(" Edad: %d\n" , alu->edad);
    };

    //------------------------------------------*

    printf("Ingrese nombre: ");
    scanf( "%s" , (*alu).nombre );
    printf("Ingrese edad: ");
    scanf( "%d" , &(*alu).edad );

    for(i=0;i<CANTIDAD;i++) {
        printf("Nombre: %s" , (*(alu+i)).nombre);
        printf(" Edad: %d\n" , (*(alu+i)).edad);
    };

    //------------------------------------------*

    for(i=0;i<3;i++) {
        printf("Ingrese su nombre: ");
        scanf( "%s" , (alus+i)->nombre );
        printf("Ingrese su edad: ");
        scanf( "%d" , &(alus+i)->edad );
    }

    for(i=0;i<3;i++) {
        printf("Nombre: %s" , (ptrAlus+i)->nombre);
        printf(" Edad: %d\n" , (ptrAlus+i)->edad);
    };

    //------------------------------------------*
    for(i=0;i<3;i++) {
        printf("Ingrese su nombre: ");
        scanf( "%s" , (*(alus+i)).nombre );
        printf("Ingrese su edad: ");
        scanf( "%d" , &(*(alus+i)).edad );
    }

    for(i=0;i<3;i++) {
        printf("Nombre: %s" , (*(ptrAlus+i)).nombre);
        printf(" Edad: %d\n" , (*(ptrAlus+i)).edad);
    };

    return 0;
}
