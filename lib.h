typedef struct
{

}TIPO3;
typedef struct
{

}TIPO2;
typedef struct
{
   int estado;
   int idTIPO1

   char nombre[51];
   char apellido[51];

}TIPO1;





//-------------------------BUSCAR ESPACIO LIBRE-----------------------------------
int buscarPrimerOcurrencia(TIPO1 str[],int cantidadElementos,int valor);
int buscarPrimerOcurrencia2(TIPO1 str[],int cantidadElementos,int valor);
int buscarPrimerOcurrencia3(TIPO3 str[],int cantidadElementos,int valor);
int buscarPrimerOcurrencia4(TIPO3 str[],int cantidadElementos,int valor);

//------------------------INICIALIZAR DATOS-------------------------------------------
void inicializarArray(TIPO1 str[],int cantidadElementos);
//----------------MENUS DE OPCIONES----------------------------
void menu(int *resultado);
//---------------------------------ALTA BAJA Y MODIFICACION-----------------------------------
void alta(TIPO1 str[],int cantidadElementos,int *idIncremental);
void baja(TIPO1 str[],int cantidadElementos);
void modificacion(TIPO1 str[],int cantidadElementos);

void cargarDATO3(TIPO1 str[],TIPO2 str2[],TIPO3 str3[],int cantidadElementos,int cantidadElementos2);
void baja2(TIPO1 str3[],TIPO3 str[],TIPO2 str2[],int cantidadElementos,int cantidadElementos2);
//-----------------------------LISTAR DATOS POR PANTALLA---------------------------------------
void mostrarLista(TIPO1 str[],int cantidadElementos,int valorOcupado);
void mostrarLista2(TIPO2 str[],int cantidadElementos);
void listadoMuchosAmuchos ( TIPO1 str[], TIPO2 str2[], TIPO3 str3[], int cantidadElementos, int cantidadElementos2 );
//-----------------------------HARCODEAR DATOS------------------------------------------------
void hardcodearDATO1(TIPO1 str[]);
void hardcodearDATO2(TIPO2 str[]);

