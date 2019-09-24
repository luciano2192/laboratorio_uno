#include <stdio.h>
#include <stdlib.h>
#include "practica.h"

void autoincrementar( struct x[] , int id ) {
    int i;
    int length = strlen(x);

    for( i = 0 ; i < length ; i++ ) {
        id += length;
    }
}
