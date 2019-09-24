typedef struct{
    int dia,mes,anio;
}eFecha;

typedef struct{
    int id;
    char apellido[51];
    char nombre[51];
    char sexo;
    float salario;
    eFecha fechaIngreso;
    int idSector;
    int isEmpty;
}eEmpleado;

typedef struct{
    int cod,descripcion,importe;
}eMenu;

typedef struct{
    int cod,descripcion;
}eSector;

typedef struct{
    int id, menuId, empleadoId, eFecha;
}eAlmuerzo;

int menu();

void inicializar( ePersona pers[] , int cantidad );

void alta( ePersona pers[], int cantidad );

void mostrarUno( ePersona per );

void mostrarTodos( ePersona pers[], int cantidad );

void ordenarPersonaPorEdad (ePersona pers[] , int cantidad);

void modificacion( ePersona pers[] , int cantidad );

int menuModificacion();

void baja( ePersona pers[] , int cantidad );
