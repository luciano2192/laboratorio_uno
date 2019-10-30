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

    char varId[128],varNombre[128],varHoras[128],varSueldo[128];
    int r,i=0;

    auxFile = fopen("data.csv","r");

    if(auxFile == NULL){
        return -1;
    }

    r = fscanf(auxFile,"%[^,],%[^,],%[^,],%[^\n]\n",varId,varNombre,varHoras,varSueldo);

    do{
        r = fscanf(auxFile,"%[^,],%[^,],%[^,],%[^\n]\n",varId,varNombre,varHoras,varSueldo);
        empleado = employee_newParametros( varId , varNombre , varHoras , varSueldo );
        if(r==4){
            fprintf(pArchivo,"%s - %s - %s - %s\n",var1,var2,var3,var4);
            arrayPersonas[i].id = atoi(var1);
            strncpy(arrayPersonas[i].nombre,var2,sizeof(arrayPersonas[i].nombre));
            strncpy(arrayPersonas[i].apellido,var3,sizeof(arrayPersonas[i].apellido));
            arrayPersonas[i].edad = atoi(var4);
            i++;
        }
        else
            break;
    }while(!feof(pFile) && i<len);

    fclose(pFile);
    fclose(pArchivo);

    return i;

    return 1;
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

    return 1;
}
