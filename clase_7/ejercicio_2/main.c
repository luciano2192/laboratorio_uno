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
    eAlumno alu[CANTIDAD] , *ptrAlu;
    ptrAlu = alu;
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
    printf("Ingrese su nombre: ");
    scanf( "%s" , ptrAlu->nombre );
    printf("Ingrese su edad: ");
    scanf( "%d" , &ptrAlu->edad );

    for(i=0;i<CANTIDAD;i++) {
        printf("Nombre: %s" , ptrAlu->nombre);
        printf(" Edad: %d\n" , ptrAlu->edad);
    };
    //------------------------------------------*
    printf("Ingrese nombre: ");
    scanf( "%s" , (*ptrAlu).nombre );
    printf("Ingrese edad: ");
    scanf( "%d" , &(*ptrAlu).edad );

    for(i=0;i<CANTIDAD;i++) {
        printf("Nombre: %s" , (*(ptrAlu+i)).nombre);
        printf(" Edad: %d\n" , (*(ptrAlu+i)).edad);
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


    return 0;
}
