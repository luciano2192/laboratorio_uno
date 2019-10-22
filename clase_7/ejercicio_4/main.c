#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[50];
    int edad;
    long int dni;
} ePersona;

int loadPerson(struct S_Person *pPerson);
void printPerson(struct S_Person *pPerson);

int main()
{

    return 0;
}

int loadPerson(struct S_Person *pPerson) {
    int i , retorno = 0;

    printf("Ingrese su nombre: ");
    printf("Ingrese su edad: ");
    printf("Ingrese su dni: ");


    if( pPerson->nombre[0] != '\0' && pPerson->edad > 0 && pPerson->dni > 0 ) {
        scanf( "%s" , pPerson->nombre );
        scanf( "%d" , &pPerson->edad );
        scanf( "%ld" , &pPerson->dni );
        retorno = 1;
    }

    return retorno;
};

void printPerson(struct S_Person* pPerson) {

    if(loadPerson(struct S_Person* pPerson)==1) {
        printf("%s\n",pPerson->nombre);
        printf("%d\n",pPerson->edad);
        printf("%ld",pPerson->dni);
    }
};
