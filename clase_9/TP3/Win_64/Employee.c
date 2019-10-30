#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

Employee* employee_new() {
    return Employee *this = malloc(sizeof(Employee));
};

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr) {

    Employee *empleado;
    employee_setId(empleado,atoi(idStr));
    employee_setNombre(empleado,nombreStr);
    employee_setHorasTrabajadas(empleado,horasTrabajadasStr);
    employee_setSueldo(empleado,sueldoStr);
    return empleado;
};

int employee_setId(Employee* this,int id) {
    if( id > 0 ) {
        this->id = id;
    }
};

int employee_getId(Employee* this,int* id) {
    *id = this->id;
};

int employee_setNombre(Employee* this,char* nombre) {
    strcpy( this->nombre , nombre );
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
        this->horasTrabajadas = horasTrabajadas;
    }
};

int employee_getSueldo(Employee* this,int* sueldo) {
    *sueldo = this->horasTrabajadas;
};
