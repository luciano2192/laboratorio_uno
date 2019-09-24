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

void autoincrementar( struct x[] , int id );
