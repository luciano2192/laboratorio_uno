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
    int cod,descripcion,importe;
}eMenu;

typedef struct{
    int cod,descripcion;
}eSector;

typedef struct{
    int id, menuId, empleadoId, eFecha;
}eAlmuerzo;
