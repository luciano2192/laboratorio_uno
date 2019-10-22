#include <stdio.h>
#include <stdlib.h>


struct persona {
    char nombre[50];
    int edad;
    long int dni;
};

int loadPerson(struct S_Person* pPerson);

int main()
{
    printf("Hello world!\n");
    return 0;
}

int loadPerson(struct S_Person *pPerson) {
    int i , retorno = 0;

    printf("Ingrese su nombre: ");
    printf("Ingrese su edad: ");
    printf("Ingrese su dni: ");


    if( pPerson->nombre != NULL && pPerson->edad > 0 && pPerson->dni > 0 ) {
        scanf( "%s" , pPerson->nombre );
        scanf( "%d" , &pPerson->edad );
        scanf( "%ld" , &pPerson->dni );
        retorno = 1;
    }

    return retorno;
};

