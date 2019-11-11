#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee) {

    FILE *auxFile;
    Employee *empleado;
    int r,i=0;
    char varId[128],varNombre[128],varHoras[128],varSueldo[128];

    if(auxFile == NULL){
        return -1;
    }

    r = fscanf(auxFile,"%[^,],%[^,],%[^,],%[^\n]\n",varId,varNombre,varHoras,varSueldo);

    do{
        r = fscanf(auxFile,"%[^,],%[^,],%[^,],%[^\n]\n",varId,varNombre,varHoras,varSueldo);
        if(r==4){
            empleado = employee_newParametros( varId , varNombre , varHoras , varSueldo );
            ll_add(pArrayListEmployee , empleado);
            i++;
        }
        else {
            break;
        }
    }while( !feof(auxFile) && i<r );

    return i;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee *empleado;

    int varId , varHoras , varSueldo;
    char varNombre[128];
    int r , salida = 0;

    if(pFile == NULL){
        return -1;
    }

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",varId,varNombre,varHoras,varSueldo);

    while( !feof(pFile) ) {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",varId,varNombre,varHoras,varSueldo);
        empleado = employee_newParametros( varId , varNombre , varHoras , varSueldo );
        if(r==4){
            ll_add( pArrayListEmployee , empleado );
        }
        if(feof(pFile)){
            break;
        } else {
            salida = 1;
            break;
        }
    };

    fclose(pFile);

    return salida;

    return 1;
}
