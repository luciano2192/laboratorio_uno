typedef struct {
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo;
    char domicilio[51];
    char telefono[21];
    int isEmpty;
} eCliente;

typedef struct {
    int codigo;
    char descripcion[51];
    float importe;
    int isEmpty;
} eJuego;

typedef struct {
    int dia , mes , anio;
} eFecha;

typedef struct {
    int codAlquiler;
    eJuego codJuego;
    eCliente codCliente;
    eFecha fecha;
    int isEmpty;
} eAlquiler;


int menuABM();

int menuModificacion();

int buscarCod( eCliente* list , int len , int codigo );

int aumentar( eCliente* list , int cantidad );

char verificaSioNo( char* msj , char* msjError );

int hayLugar( eCliente* list , int length );

void formatear( char text[] );

void altaCliente( eCliente list[] , int len , char apellido[] , char
nombre[] , char sexo , char domicilio[] , char telefono[] );

int estaVacio( eCliente* list , int length );

int inicializar( eCliente* list , int len );

void borrarCliente( eCliente* list , int len , int codigo );

void ordenarClientes( eCliente *list , int len );

void printCliente( eCliente *list , int cod );

int printClientes( eCliente* list , int len );

int modificarCliente( eCliente* list , int len , int codigo );

int buscarCod( eCliente* list , int len , int codigo );

int buscarCod( eCliente* list , int len , int codigo );

int ordenarJuegos( eJuego* list , int len );

int printJuegos( eJuego* list , int len );

char pedirSexo( char msj[] , char errorMsj[] );

void clonarCliente( eCliente origen[] , eCliente destino[] , int len );
