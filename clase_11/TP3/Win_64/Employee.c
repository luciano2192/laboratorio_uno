#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"

Employee* employee_new() {
    Employee *this = malloc(sizeof(Employee));
    return this;
};

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr) {

    Employee *empleado = employee_new();
    int id , horas , sueldo;
    id = atoi( idStr );
    horas = atoi( horasTrabajadasStr );
    sueldo = atoi( sueldoStr );
    employee_setId( empleado , id );
    employee_setNombre( empleado , nombreStr );
    employee_setHorasTrabajadas( empleado , horas );
    employee_setSueldo( empleado , sueldo );

    return empleado;
};

void employee_delete(Employee* this) {
    free(this);
};

int employee_setId(Employee* this,int id) {
    int resultado = 0;

    if( id > 0 ) {
        this->id = id;
        resultado = 1;
    }

    return resultado;
};

int employee_getId(Employee* this,int* id) {
    int resultado = 0;

    if( id != NULL ){
        *id = this->id;
    }

    return resultado;
};

int employee_setNombre(Employee* this,char* nombre) {
    int resultado = 0;

    if(nombre != NULL ) {
        strcpy( this->nombre , nombre );
        resultado = 1;
    }

    return resultado;
};

int employee_getNombre(Employee* this,char* nombre) {
    *nombre = this->nombre;
};

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas) {
    if( horasTrabajadas > 0 ) {
        this->horasTrabajadas = horasTrabajadas;
    }
};

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas) {
    *horasTrabajadas = this->horasTrabajadas;
};

int employee_setSueldo(Employee* this,int sueldo) {
   if( sueldo > 0 ) {
        this->sueldo = sueldo;
    }
};

int employee_getSueldo(Employee* this,int* sueldo) {
    *sueldo = this->sueldo;
};
