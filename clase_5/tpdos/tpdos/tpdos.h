typedef struct{
    int dia,mes,anio;
} eFecha;

typedef struct{
    int id;
    char apellido[51];
    char nombre[51];
    eFecha fechaIngreso;
    int isEmpty;
} eEmpleado;


void inicializar( eEmpleado pers[] , int cantidad );

void miFgets(char nombre[], int cantidad);

int aumentar( eEmpleado empleado[] , int cantidad );

int menuABM();

void alta( eEmpleado empleado[], int cantidad );

void mostrarUno( eEmpleado empleado );

void mostrarUno( eEmpleado empleado );
