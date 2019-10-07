typedef struct {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmpleado;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees( eEmpleado* list , int len );

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/

int findEmployeeById( eEmpleado* list , int len , int id );


/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees( eEmpleado* list , int length );

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/

int addEmployee( eEmpleado* list , int len , char name[] , char
lastName[] , float salary , int sector );

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee( eEmpleado* list , int len , int id );

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees( eEmpleado* list , int len );

int hayLugar( eEmpleado* list , int length );

void mostrarEmpleado( eEmpleado* list , int cantidad , int id );

void formatear( char* text );

int aumentar( eEmpleado* list , int cantidad );

/* Funcion usada para verificar el ingreso de caracteres.Chequea para que
solo sean admitidas las letras S o N.
Se ingresa void y devuelve un entero sin signo
0 si se ingreso la N
1 si se ingreso la S
*/
char verificaSioNo( char* msj , char* msjError );

int estaVacio( eEmpleado* list , int length );

int menuModificacion();

int modifyEmployee( eEmpleado* list , int len , int id );
