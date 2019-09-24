#include <stdio.h>
#include <stdlib.h>
#include "practica.h"

int main()
{

    eSector sector[4] = {
        { 1 , "Recursos Humanos" };
        { 2 , "Comercial" };
        { 3 , "Desarrollo" };
        { 4 , "QA" };
    }

    eMenu menu[4] = {
        { 1 , "Milanesa con pure" , 159.99 };
        { 2 , "Pollo con ensalada" , 200.50 };
        { 3 , "Tarta de atun" , 110.40 };
        { 4 , "Empanadas fritas de carne" , 45.99 };
    }

    return 0;
}
