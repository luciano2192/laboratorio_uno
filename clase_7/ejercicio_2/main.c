#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char nombre[20];
    int edad;
} eAlumno;


int main()
{
    int i;
    eAlumno alu[1] , *ptrAlu , alus[3] , *ptrAlus;
    ptrAlu = alu;
    ptrAlus = alus;

    //------------------------------------------*
    printf("Ingrese su nombre: ");
    scanf( "%s" , alu->nombre );
    printf("Ingrese su edad: ");
    scanf( "%d" , &alu->edad );

    printf("Nombre: %s" , ptrAlu->nombre);
    printf(" Edad: %d\n" , ptrAlu->edad);

    //------------------------------------------*

    printf("Ingrese nombre: ");
    scanf( "%s" , (*alu).nombre );
    printf("Ingrese edad: ");
    scanf( "%d" , &(*alu).edad );

    printf("Nombre: %s" , (*(ptrAlu)).nombre);
    printf(" Edad: %d\n" , (*(ptrAlu)).edad);

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
