#include <stdio.h>
#include <stdlib.h>
//luciano
int main()
{
    int legajo;
    char nombre[31];
    char sexo;
    float salario;

    printf( "Ingrese su legajo: " );
    scanf( "%d" , &legajo );
    printf( "\nIngrese su nombre: " );
    scanf( "%s" , nombre );
    fflush(stdin); // para limpiar el buffer, en linux se usa setbuf(NULL, stdin);
    // solo hay que limpiar el buffer si luego tengo %s o %c;
    printf( "\nIngrese su sexo: " );
    scanf( "%c" , &sexo );
    printf( "\nIngrese el salario: " );
    scanf( "%f" , &salario );
    system("cls"); // limpia la pantalla;

    //printf( "El legajo es: %d\n" , legajo);
    //printf( "El nombre es: %s\n" , nombre);
    //printf( "EL sexo es: %c\n" , sexo);
    //printf( "El salario es: %f\n" , salario);

    printf( "Legajo\tNombre\tSexo\tSalario");
    printf( "\n%d\t%s\t%c\t%.2f" , legajo,nombre,sexo,salario );

    return 0;
}
