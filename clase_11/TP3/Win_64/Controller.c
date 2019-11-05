#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "./utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int salida = 0;
    FILE *auxFile;

    auxFile = fopen( path , "r" );

    if( auxFile != NULL ) {
        parser_EmployeeFromText(auxFile , pArrayListEmployee);
        fclose(auxFile);
        salida = 1;
    }

    return salida;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int salida = 0;
    FILE *auxFile;

    auxFile = fopen( path , "rb" );

    if( auxFile != NULL ) {
        parser_EmployeeFromBinary(auxFile , pArrayListEmployee);
        fclose(auxFile);
        salida = 1;
    }

    return salida;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    /*
    hacer for, dentro llget
    declaro una estructura para guardar los datos
    los getter y despues el printf
    return 1;
    */
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

void menu() {

    int opcion = 0;

    system("cls");
    printf("::::::::::MENU::::::::::");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
    printf("3. Alta de empleado");
    printf("4. Modificar datos de empleado");
    printf("5. Baja de empleado");
    printf("6. Listar empleados");
    printf("7. Ordenar empleados");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).");
    printf("10. Salir");
    fflush(stdin);

    opcion = getInt( "Seleccionar opcion entre <1-10>: " , "Error ! valor incorrecto." , 1 , 10 );

    return opcion;
}

