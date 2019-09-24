typedef struct{
    int dia,mes,anio;
}eFecha;

typedef struct{
    int id;
    char apellido[31];
    char nombre[31];
    int edad;
    eFecha fechaNacimiento;
    int ePaisId;
    int isEmpty;
}ePersona;

typedef struct{
    int id;
    char descripcion[31];
}ePais;

int menu();

void inicializar( ePersona pers[] , int cantidad );

void alta( ePersona pers[], int cantidad );

void mostrarUno( ePersona per );

void mostrarTodos( ePersona pers[], int cantidad );

void ordenarPersonaPorEdad (ePersona pers[] , int cantidad);

void modificacion( ePersona pers[] , int cantidad );

int menuModificacion();

void baja( ePersona pers[] , int cantidad );
