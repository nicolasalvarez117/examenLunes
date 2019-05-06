
typedef struct
{
    int idPublicacion;
    int idClientes;
    int estado;

}t_Publicacion;

typedef struct
{
    int idRubro;
    char descripcion[61];

    int cantidadAltas;
    int estadoRubro;

}t_Publicaciones;

typedef struct
{
    int id;
    int estado;

    int estadoPublicacion;
    int cantidadPublicaciones;
    char nombre[51];
    char apellido[51];



}t_Clientes;







//-------------------------BUSCAR ESPACIO LIBRE-----------------------------------
int buscarPrimerOcurrencia(t_Clientes str[],int cantidadElementos,int valor);
int buscarPrimerOcurrencia2(t_Clientes str[],int cantidadElementos,int valor);
int buscarPrimerOcurrencia3(t_Publicacion str[],int cantidadElementos,int valor);
int buscarPrimerOcurrencia4(t_Publicacion str[],int cantidadElementos,int valor);

//------------------------INICIALIZAR DATOS-------------------------------------------
void inicializarArray(t_Clientes str[],int cantidadElementos);
void inicializarArray2(t_Publicacion str[],int cantidadElementos);
//----------------MENUS DE OPCIONES----------------------------
void menu2(int *resultado);
void menu(int *resultado);
void menu3(int *resultado);
void menu4(int *resultado);
//---------------------------------ALTA BAJA Y MODIFICACION-----------------------------------
void alta(t_Clientes str[],int cantidadElementos,int *idIncremental);
void baja(t_Clientes str[],int cantidadElementos);
void modificacion(t_Clientes str[],int cantidadElementos);

void alta2(t_Publicacion str[],t_Publicaciones str2[],t_Clientes str3[],int cantidadElementos);
void baja2(t_Clientes str3[],t_Publicacion str[],t_Publicaciones str2[],int cantidadElementos,int cantidadElementos2);
void modificacion2(t_Clientes str3[],t_Publicacion str[],t_Publicaciones str2[],int cantidadElementos,int cantidadElementos2);
//-----------------------------LISTAR DATOS POR PANTALLA---------------------------------------

void mostrarLista(t_Clientes str[],int cantidadElementos);
void mostrarLista2(t_Publicaciones str[],int cantidadElementos);

void listadoMuchosAmuchos ( t_Clientes str[], t_Publicacion str3[], t_Publicaciones str2[], int cantidadElementos, int cantidadElementos2 );
void listadoMuchosAmuchos2( t_Clientes str[], t_Publicacion str3[], t_Publicaciones str2[], int cantidadElementos, int cantidadElementos2 );
//--------------------Harcodear datos------------------------
void hardcodearDatosDATO(t_Clientes str[]);
void hardcodearDatosDATO2(t_Publicaciones str[]);

void listaClienteMayorPublicacionesActivas(t_Clientes str[],int cantidadElementos);
void listaClienteMayorAvisosPausados(t_Clientes str[], int cantidadElementos);
void listaClienteMayorAvisos(t_Clientes str[], int cantidadElementos);
void listaMayorRubrosActivos(t_Publicaciones str[], int cantidadElementos);
void listaMenorRubrosActivos(t_Publicaciones str[], int cantidadElementos);
