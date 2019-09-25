typedef struct{
    int dia,mes,anio;
}eFecha;

typedef struct{
    int id;
    char apellido[51];
    char nombre[51];
    char sexo;
    //float salario;
    eFecha fechaIngreso;
    int idSector;
    //int isEmpty;
}eEmpleado;

typedef struct{
    int cod;
    char descripcion[51];
    float importe;
}eMenu;

typedef struct{
    int cod;
    char descripcion[51];
}eSector;

typedef struct{
    int id, menuId, empleadoId, eFecha;
}eAlmuerzo;

int menu();

void inicializar( eEmpleado pers[] , int cantidad );

void alta( eEmpleado pers[], int cantidad );

void mostrarUno( eEmpleado per );

void mostrarTodos( eEmpleado pers[], int cantidad );

void ordenarPersonaPorEdad (eEmpleado pers[] , int cantidad);

void modificacion( eEmpleado pers[] , int cantidad );

int menuModificacion();

void baja( eEmpleado pers[] , int cantidad );

void empleadosPorSector( eSector sector[] , int cantidadSector , eEmpleado empleado[] , int cantidadEmpleados );

void menuPorEmpleado( eMenu menu[] , int cantMenu , eAlmuerzo almuerzo[] , int cantAlmuerzo , eEmpleado empleado[] , int cantEmpleado );

void mostrarMenues( eMenu m[], int cantidad );

void mostrarMenues( eMenu m[], int cantidad );
