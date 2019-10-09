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
    int codAlquiler;
    int codJuego;
    int codCliente;
    int isEmpty;
} eAlquiler;


int menuABM();

int menuModificacion();

int buscarCod( eCliente* list , int len , int codigo );

int aumentar( eCliente* list , int cantidad );

char verificaSioNo( char* msj , char* msjError );

int hayLugar( eCliente* list , int length );

void formatear( char* text );

int altaCliente( eCliente list[] , int len , char apellido[] , char
nombre[] , char sexo , char domicilio[] , char telefono[] );

int estaVacio( eCliente* list , int length );

int initClientes( eCliente* list , int len );

int borrarCliente( eCliente* list , int len , int codigo );

int ordenarClientes( eCliente* list , int len );

int printClientes( eCliente* list , int len );

int modificarCliente( eCliente* list , int len , int codigo );

int buscarCod( eCliente* list , int len , int codigo );

int buscarCod( eCliente* list , int len , int codigo );

int ordenarJuegos( eJuego* list , int len );

int printJuegos( eJuego* list , int len );

char pedirSexo( char* input , char msj[] , char errorMsj[] );

float promedioJuegosAlquilados( eJuego* juego , int lenJue , eAlquiler* alquiler , int lenAlq );

int noSuperanPromedio( float prom , eJuego* list , int len );

void juegosAlquiladosX( eJuego* juego , int lenJue , eAlquiler* alquiler , int lenAlq , eCliente* cliente , int lenCli );

