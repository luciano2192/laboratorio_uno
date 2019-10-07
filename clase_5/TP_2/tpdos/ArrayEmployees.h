typedef struct {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmpleado;

/** \brief Inicializa el array como vacio
 * \param list eEmpleado* puntero al array empleados
 * \param len int largo del array
 * \return int retorna (-1) si hay un error - (0) si NO hay error
 */
int initEmployees( eEmpleado* list , int len );

/** \brief busca un empleado por id.
* \param list eEmpleado*
* \param len int
* \param id int
* \return retorna posicion del empleado - si hay un error retorna (-1)
*/
int findEmployeeById( eEmpleado* list , int len , int id );


/** \brief imprime la lista de empleados
*
* \param list eEmpleado*
* \param length int
* \return lista de empleados cargados
*
*/
int printEmployees( eEmpleado* list , int length );

/** \brief agrega un empleado a la lista
* \param list eEmpleado*
* \param len int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int retorna (-1) si hay un error - (0) si NO hay error
*
*/
int addEmployee( eEmpleado* list , int len , char name[] , char
lastName[] , float salary , int sector );

/** \brief elimina un empleado
*
* \param list eEmpleado*
* \param len int
* \param id int
* \return int retorna (-1) si hay un error - (0) si NO hay error
*
*/
int removeEmployee( eEmpleado* list , int len , int id );

/** \brief ordena por sector y apellido
*
* \param list eEmpleado*
* \param len int
* \return int retorna (0) al finalizar
*
*/
int sortEmployees( eEmpleado* list , int len );

/** \brief verifica si hay lugar en la lista
*
* \param list eEmpleado*
* \param length int
* \return int retorna (-1) si hay error - si NO hay error el indice libre.
*
*/
int hayLugar( eEmpleado* list , int length );


void mostrarEmpleado( eEmpleado* list , int cantidad , int id );

/** \brief pone la primer letra en mayuscula, el resto en minuscula
*
* \param text char*
* \return 
*
*/
void formatear( char* text );

/** \brief aumenta automaticamente el id de los empleados
*
* \param list eEmpleado*
* \param cantidad int
* \return int retona el id a asignar.
*
*/
int aumentar( eEmpleado* list , int cantidad );

/** \brief verifica que se responda S o N
*
* \param msj char*
* \param msjError char*
* \return el caracter obtenido
*
*/
char verificaSioNo( char* msj , char* msjError );

/** \brief verifica que la lista este vacia
*
* \param list eEmpleado*
* \param len int
* \param id int
* \return 1 si esta vacio - 0 si NO esta vacio.
*
*/
int estaVacio( eEmpleado* list , int length );

/** \brief imprime un menu
*
*
*/
int menuModificacion();

/** \brief verifica que la lista este vacia
*
* \param list eEmpleado*
* \param len int
* \param id int
* return -1 si no se modifico nada - 0 si se medifico exitosamente.
*
*/
int modifyEmployee( eEmpleado* list , int len , int id );

/** \brief calcula promedio y total de salarios
*
* \param list eEmpleado*
* \param len int
* return -1 si hay un error - 0 si NO hay error.
*
*/
int promedioSalarios( eEmpleado* list , int len );
