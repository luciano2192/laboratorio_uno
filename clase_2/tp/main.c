#include <stdio.h>
#include <stdlib.h>
#include "./funciones.h"

int operandoUno = 0;
int operandoDos = 0;
int menu;
int resultadoSuma = 0;
int resultadoResta = 0;
int resultadoMultiplicacion = 0;
int resultadoDivision = 0;
int resultadoFactorial = 0;
int resultadoFactorialDos = 0;

int main()
{
    do {
        printf("\n1) Ingresar el primero operando. A=%d" , operandoUno);
        printf("\n2) Ingresar el segundo operando. B=%d" , operandoDos);
        printf("\n3) Calcular todas las operaciones.");
        printf("\n4) Informar los resultados.");
        printf("\n5) Salir.\n");
        printf("\nSeleccionar una opcion <1-5>: ");
        scanf( "%d" , &menu );
        system("cls");

        switch( menu ) {
            case 1:
                printf("\nIngrese el primer operando: ");
                scanf( "%d" , &operandoUno );
                system("cls");
            break;
            case 2:
                printf("\nIngrese el segundo operando: ");
                scanf( "%d" , &operandoDos );
                system("cls");
            break;
            case 3:
                resultadoSuma = suma( operandoUno , operandoDos );
                resultadoResta = resta( operandoUno , operandoDos );
                if ( operandoDos == 0 ) {
                    printf("ERROR ! no se puede dividir por cero");
                    break;
                } else {
                    resultadoDivision = (float) division( operandoUno , operandoDos );
                }
                resultadoMultiplicacion = multiplicacion( operandoUno , operandoDos );
                resultadoFactorial = factorial( operandoUno );
                resultadoFactorialDos = factorial( operandoDos );
                system("cls");
                break;
            case 4:
                printf( "\nEl resultado del primer operando + el segundo es: %d" , resultadoSuma );
                printf( "\nEl resultado del primer operando - el segundo es: %d" , resultadoResta );
                printf( "\nEl resultado del primer operando dividido el segundo es: %d" , resultadoDivision );
                printf( "\nEl resultado del primer operando multiplacado por el segundo es: %d" , resultadoMultiplicacion );
                printf( "\nEl factorial del primer operando es: %d" , resultadoFactorial );
                printf( "\nEl factorial del segundo operando es: %d" , resultadoFactorialDos );
                printf( "\n" );
                operandoUno = 0;
                operandoDos = 0;
                break;
            case 5: break;
        };

    } while (menu != 5);


    return 0;
}



