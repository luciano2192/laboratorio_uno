#include <stdio.h>
#include <stdlib.h>

// PROTOTIPO FUNCION
int suma( int , int );


int main()
{
    int op1, op2, res;
    printf("operador 1: ");
    scanf("%d",&op1);
    printf("operador 2: ");
    scanf("%d",&op2);
    res = suma(op1,op2); // LLAMADA FUNCION
    printf("la suma es: %d", res);

    return 0;
}

// DEFINICION FUNCION
int suma( int operador1 , int operador2 ) {

    int resultado;
    resultado = operador1 + operador2;
    return resultado;
}
