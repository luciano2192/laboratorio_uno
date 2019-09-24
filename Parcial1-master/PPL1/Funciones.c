#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "automoviles.h"


int cargarHarcodePropietario(ePropietario listadoPropietario[],int tamanioPropietario)
{
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char tarjeta[][20]= {"1111115115970359","2222223709842615","3333339846125430","4444449784621573"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};
    int id[]= {18,35,15,29};
    int i;
    for(i=0; i<4; i++)
    {
        strcpy(listadoPropietario[i].NombreyApellido,nombre[i]);
        strcpy(listadoPropietario[i].tarjetadeCredito,tarjeta[i]);
        strcpy(listadoPropietario[i].Direccion,direccion[i]);
        listadoPropietario[i].IdPropietario=id[i];
        listadoPropietario[i].estado=1;
    }
    return 1;
}


int agregarPersona(ePropietario listadoPropietario[],int len)
{
    int indice;
    int retorno=0;
    indice=obtenerEspacioLibre(listadoPropietario, len);
    if(indice!=-1)
    {
        listadoPropietario[indice].IdPropietario=getInt("Ingresa el Id de la persona: ",listadoPropietario[indice].IdPropietario);
        getString("Ingrese el nombre y apellido de la persona: ",listadoPropietario[indice].NombreyApellido);
        stringToUpper(listadoPropietario[indice].NombreyApellido);
        getString("Ingrese la direccion de la persona: ",listadoPropietario[indice].Direccion);
        stringToUpper(listadoPropietario[indice].Direccion);
        printf("Ingresa tarjeta de credito de la persona: ");
        gets(listadoPropietario[indice].tarjetadeCredito);
        validarTarjetaDeCredito(listadoPropietario[indice].tarjetadeCredito);
        listadoPropietario[indice].estado=1;
        retorno=1;
    }
    else
    {
        printf("\nNo hay mas lugares libres");
    }
    return retorno;
}

int buscarPorIdPropietario(ePropietario listadoPropietario[],int len,int id)
{
    int indice=-1;
    int i;
    for(i=0; i<len; i++)
    {
        if(listadoPropietario[i].estado==1)
        {
            if(listadoPropietario[i].IdPropietario==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int obtenerEspacioLibre(ePropietario listadoPropietario[],int len)
{
    int indice=-1;
    int i;
    for(i=0; i<len; i++)
    {
        if(listadoPropietario[i].estado==0)
        {
            indice=i;
        }
    }
    return indice;
}

void inicializarEstados(ePropietario listadoPropietario[],int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        listadoPropietario[i].estado=0;
    }
}

int mostrarMenu()
{
    int opcion;

    printf("1. ALTA\n");
    printf("2. MODIFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. Gestionar automoviles\n");
    printf("6. Recaudaciones\n");
    printf("7. Mostrar datos filtrados\n");
    printf("9. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    opcion=validarEntero(opcion,"una opcion: ",1,9);

    return opcion;

}

int validarEntero(int numero,char texto[],int min,int max)
{
    while(numero<min || numero>max)
    {

        printf("\nReingrese %s",texto);
        scanf("%d",&numero);
    }
    return numero;
}

char* getString(char mensaje[], char* caracter)
{

    printf("%s",mensaje);
    gets(caracter);
    fflush(stdin);
    return caracter;
}

int getInt(char mensaje[],int A)
{

    char auxstring[100];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    A=validarStringEntero(auxstring);
    return A;
}

char getChar(char mensaje[],char caracter)
{
    fflush(stdin);
    printf("%s",mensaje);
    scanf("%c",&caracter);
    return caracter;
}

void stringToUpper(char caracter[])
{
    int i;
    int largo;
    caracter[0]=toupper(caracter[0]);
    largo=strlen(caracter);
    for(i=0; i<largo; i++)
    {
        if(caracter[i]==' ')
        {
            i=i+1;
            caracter[i]=toupper(caracter[i]);
        }
    }
}

char* stringMayusculas(char cadena[])
{
    int largo;
    largo=strlen(cadena);
    int i;
    for(i=0; i<largo; i++)
    {
        cadena[i]=toupper(cadena[i]);
    }
    return cadena;
}


/*void borrarPersona(ePropietario listadoPropietario[],int flag, int len)
{
    int id;
    int indice;
    char caracter;
    if(flag==1)
    {
        mostrarListaPropietario(listadoPropietario, len, flag);
        printf("\n¿Que persona queres borrar? (Ingresar ID) ");
        scanf("%d",&id);
        fflush(stdin);
        indice=buscarPorIdPropietario(listadoPropietario,len,id);
        caracter=deseaContinuar("Desea realizar esta modificacion? (S/N) ");
        if(indice!=-1&& caracter=='s')
        {
            listadoPropietario[indice].estado=0;
            listadoPropietario[indice].IdPropietario=0;
            strcpy(listadoPropietario[indice].NombreyApellido,"");
            strcpy(listadoPropietario[indice].Direccion,"");
            strcpy(listadoPropietario[indice].tarjetadeCredito,"");
        }
        else if(caracter=='n')
        {
            printf("La baja se ha cancelado.");
        }
        else
        {
            printf("\nDNI no encontrado");
        }
    }
    else
    {
        printf("\nPara borrar un usuario es necesario que se haya ingresado alguno en el sistema ");
    }


}*/

void mostrarLista(ePropietario listadoPropietario[],int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(listadoPropietario[i].estado==1)
        {
            printf("\n\nNombre y Apellido: %s\nDireccion: %s\nID: %d\nTarjeta de credito: %s",listadoPropietario[i].NombreyApellido,listadoPropietario[i].Direccion,listadoPropietario[i].IdPropietario,listadoPropietario[i].tarjetadeCredito);
        }
    }
}

void mostrarPropietarioPorNombre(ePropietario listadoPropietario[],int tamPropietario)
{
    int opcion;
    opcion=getInt("\n1-Ascendente\n2-Descendente\nComo desea ordenar los propietarios? ",opcion);
    ordenarPropietariosParte2(listadoPropietario,tamPropietario,opcion);
}

void modificarPropietario(ePropietario listadoPropietario[],int len,int flag)
{
    if(flag==1)
    {
        fflush(stdin);
        int Id=0;
        int indice;
        char caracter;
        char auxiliar[20];
        mostrarListaPropietario(listadoPropietario,len,flag);
        Id=getInt("\nIngresa el Id del usuario que queres modificar ",Id);
        indice=buscarPorIdPropietario(listadoPropietario,len,Id);
        if(indice!=-1)
        {
            modificarStringPropietario(listadoPropietario,indice,auxiliar);
            caracter=deseaContinuar("Desea realizar esta modificacion? (S/N) ");
            if(caracter=='s')
            {
                strcpy(listadoPropietario[indice].tarjetadeCredito,auxiliar);
                printf("\nTarjeta modificada ");
            }
            else
            {
                printf("Modificacion no realizada ");
            }
        }
        else
        {
            printf("No se ha encontrado el Id");
        }

    }
    else
    {
        printf("\nNo es posible modificar propietarios porque no hay ninguno ingresado\n");
    }

}

void validarTarjetaDeCredito(char tarjeta[])
{
    int largo;
    largo=strlen(tarjeta);
    int i;
    for(i=0; i<16; i++)
    {
        while(largo!=16 && tarjeta[i]>='0' && tarjeta[i]<='9')
        {
            printf("\nTarjeta ingrsada invalida. Los digitos ingresados deben ser mayores a 0 y no se deben ingresar letras. Ingresela nuevamente ");
            gets(tarjeta);
            largo=strlen(tarjeta);
            i=0;
        }
    }
}

int validarStringEntero(char datoAValidar[])
{
    int A;
    int validar;
    validar=strlen(datoAValidar);
    int i;
    for(i=0; i<validar;)
    {
        if(isdigit(datoAValidar[i])==0||datoAValidar[i]==' ')
        {
            do
            {
                printf("\nIngresa un numero valido ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(isdigit(datoAValidar[i])==0||datoAValidar[i]==' ');
        }
        else
        {
            i=i+1;
        }
    }
    A=atoi(datoAValidar);
    return A;
}

char* validarStringCadena(char datoAValidar[])
{
    int validar;
    validar=strlen(datoAValidar);
    while(validar==0)
    {
        printf("\nLa palabra ingresada no es valida. Ingresela nuevamente ");
        gets(datoAValidar);
        fflush(stdin);
        validar=strlen(datoAValidar);
    }
    int i;
    for(i=0; i<validar;)
    {
        if(isalpha(datoAValidar[i])==0&&datoAValidar[i]!=' ')
        {
            do
            {
                printf("\nIngresa una palabra valida ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(isalpha(datoAValidar[i])==0);
        }
        else if(datoAValidar[0]== ' ')
        {
            do
            {
                printf("\nIngresa una palabra valida ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(datoAValidar[0]==' ');
        }
        else
        {
            i=i+1;
        }

    }
    return datoAValidar;
}

char deseaContinuar(char mensaje[])
{
    char seguir;
    do
    {
        seguir=getChar(mensaje,seguir);
        seguir=tolower(seguir);
        fflush(stdin);
    }
    while(seguir!='s'&&seguir!='n');
    return seguir;
}

void mostrarListaPropietario(ePropietario listadoPropietario[],int len,int flag)
{
    if(flag==1)
    {
        printf("ID\tNombre\t\t\tTarjeta de credito\t\tDireccion\n");
        int i;
        int largo;
        for(i=0; i<len; i++)
        {
            if(listadoPropietario[i].estado==1)
            {
                printf("%d\t%s",listadoPropietario[i].IdPropietario,listadoPropietario[i].NombreyApellido);
                largo=strlen(listadoPropietario[i].NombreyApellido);
                if(largo<16)
                {
                    printf("\t");
                }
                printf("\t\t%s\t\t\%s\n",listadoPropietario[i].tarjetadeCredito,listadoPropietario[i].Direccion);
            }

        }
    }
    else
    {
        printf("\nNo es posible mostrar propietarios porque no hay ninguno ingresado\n");
    }

}
void mostrarUnoPropietario(ePropietario listadoPropietario[],int tamanio,int i)
{
    printf("%d\t%s\t  %s\t\t%s\t%d\n",listadoPropietario[i].IdPropietario,listadoPropietario[i].NombreyApellido,listadoPropietario[i].tarjetadeCredito,listadoPropietario[i].Direccion,listadoPropietario[i].edad);
}

/*void mostrarPropietarioPorNombre(ePropietario listadoPropietario[],int tamPropietario)
{
    ordenarPropietarios(listadoPropietario,tamPropietario);
}*/

void ordenarPropietarios(ePropietario listadoPropietario[],int tamPropietario)
{
    ePropietario aux;
    int i;
    int j;
    for(i=0; i<tamPropietario-1; i++)
    {
        if(listadoPropietario[i].estado==1)
        {
            for(j=i+1; j<tamPropietario; j++)
            {
                if(listadoPropietario[j].estado==1&&strcmp(listadoPropietario[i].NombreyApellido,listadoPropietario[j].NombreyApellido)>0)
                {
                    aux=listadoPropietario[i];
                    listadoPropietario[i]=listadoPropietario[j];
                    listadoPropietario[j]=aux;
                }
            }

        }

    }


}

void ordenarPropietariosParte2(ePropietario listadoPropietario[],int tamPropietario,int opcion)
{
    ePropietario aux;
    int i;
    int j;
    if(opcion==1)
    {
        for(i=0; i<tamPropietario-1; i++)
        {
            for(j=i+1; j<tamPropietario; j++)
            {
                if(strcmp(listadoPropietario[i].NombreyApellido,listadoPropietario[j].NombreyApellido)>0)
                {
                    aux=listadoPropietario[i];
                    listadoPropietario[i]=listadoPropietario[j];
                    listadoPropietario[j]=aux;
                }
            }
        }
        mostrarListaPropietario(listadoPropietario,tamPropietario,1);
    }
    else if(opcion==2)
    {
        for(i=0; i<tamPropietario-1; i++)
        {
            for(j=i+1; j<tamPropietario; j++)
            {
                if(strcmp(listadoPropietario[i].NombreyApellido,listadoPropietario[j].NombreyApellido)<0)
                {
                    aux=listadoPropietario[i];
                    listadoPropietario[i]=listadoPropietario[j];
                    listadoPropietario[j]=aux;
                }
            }
        }
        mostrarListaPropietario(listadoPropietario,tamPropietario,1);
    }
    else
    {
        printf("\nOpcion no encontrada\n");
    }
}


char* modificarStringPropietario(ePropietario listadoPropietario[],int indice,char caracter[])
{
    printf("\nIngresa la nueva tarjeta de credito (Debe seguir el formato de 16 digitos numericos): ");
    gets(caracter);
    validarTarjetaDeCredito(caracter);

    return caracter;
}

void mostrarListaOrdenadaPorNombre(ePropietario listadoPropietario[], int len, int flag)
{
    ordenarPropietarios(listadoPropietario,len);
    mostrarListaPropietario(listadoPropietario,len,flag);
}
