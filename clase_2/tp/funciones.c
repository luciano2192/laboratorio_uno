int i;


int suma( int operandoUno , int operandoDos ) {
    return operandoUno + operandoDos;
}

int resta( int operandoUno , int operandoDos ) {
    return operandoUno - operandoDos;
}

int multiplicacion( int operandoUno , int operandoDos ) {
    return operandoUno * operandoDos;
}

int division( int operandoUno , int operandoDos ) {
    return operandoUno / operandoDos;
}

int factorial( int operando ) {
    int factorial = 1;

    for( i = operando; i > 0; i--) {
        factorial *= i;
    }

    return (factorial);
}
