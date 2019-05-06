#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "imput.h"
#include "lib.h"

#define ACUPADO 1
#define LIBRE -1

#define TRUE 1
#define FALSE 0

//-------------------------BUSCAR ESPACIO LIBRE-----------------------------------
/**
  *\brief busca una igualdad entre dos datos pasados por parametro.
  *\param datos de la estructura , la cantidad de elementos del array estructura y el valor que queremos encontrar.
  *\return la posicion del valor encontrado, en caso de no encontrar el valor, retorna -1.
**/
int buscarPrimerOcurrencia(t_Clientes str[],int cantidadElementos,int valor)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(str[i].estado == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}

/**
  *\brief busca una igualdad entre dos datos pasados por parametro.
  *\param datos de la estructura , la cantidad de elementos del array estructura y el valor que queremos encontrar.
  *\return la posicion del valor encontrado, en caso de no encontrar el valor, retorna -1.
**/
int buscarPrimerOcurrencia2(t_Clientes str[],int cantidadElementos,int valor)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(str[i].id == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}

/**
  *\brief busca una igualdad entre dos datos pasados por parametro.
  *\param datos de la estructura , la cantidad de elementos del array estructura y el valor que queremos encontrar.
  *\return la posicion del valor encontrado, en caso de no encontrar el valor, retorna -1.
**/
int buscarPrimerOcurrencia3(t_Publicacion str[],int cantidadElementos,int valor)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(str[i].estado == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}

/**
  *\brief busca una igualdad entre dos datos pasados por parametro.
  *\param datos de la estructura , la cantidad de elementos del array estructura y el valor que queremos encontrar.
  *\return la posicion del valor encontrado, en caso de no encontrar el valor, retorna -1.
**/
int buscarPrimerOcurrencia4(t_Publicacion str[],int cantidadElementos,int valor)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(str[i].idPublicacion == valor && str[i].estado != -1)
        {
            return i;
            break;
        }
    }
    return -1;
}

//------------------------INICIALIZAR DATOS-------------------------------------------
/**
  *\brief inicializa los valores unicos  con LIBRE(-1).
  *\param el array  y la cantidad de elementos del array.
**/
void inicializarArray(t_Clientes str[],int cantidadElementos)
{
    int i;
    for(i=0;i<cantidadElementos;i++)
    {
        str[i].estado = LIBRE;
        str[i].estadoPublicacion = -1;
        str[i].cantidadPublicaciones = 0;
        str[i].id = -1;
    }
}
/**
  *\brief inicializa los valores unicos  con LIBRE(-1).
  *\param el array  y la cantidad de elementos del array.
**/
void inicializarArray2(t_Publicacion str[],int cantidadElementos)
{
    int i;
    for(i=0;i<cantidadElementos;i++)
    {
        str[i].estado = LIBRE;

    }
}

//----------------MENUS DE OPCIONES----------------------------
/**
  *\brief imprime por pantalla el menu de ABM .
  *\param la ubicacion donde guardar la eleccion del usuario.
**/
void menu2(int *resultado)
{
    int i;
    char aux[15];
    getNumber("\n\n1:ALTA\n2:BAJA\n3:MODIFICAR\n4:LISTAR\n5:SALIR: ","opcion incorrecta: ",1,5,1,2,aux);
    *resultado = atoi(aux);

}

/**
  *\brief imprime por pantalla el menu de ABM .
  *\param la ubicacion donde guardar la eleccion del usuario.
**/
void menu(int *resultado)
{
    int i;
    char aux[15];
    getNumber("\n1:CLIENTES\n2:PUBLICACION\n3:INFORMES\n4:SALIR ","opcion incorrecta: ",1,4,1,2,aux);
    *resultado = atoi(aux);

}

/**
  *\brief imprime por pantalla el menu de ABM .
  *\param la ubicacion donde guardar la eleccion del usuario.
**/
void menu3(int *resultado)
{
    int i;
    char aux[15];
    getNumber("\n1:ALTA DE PUBLICACION\n2:PAUSAR PUBLICACION\n3:REANUDAR PUBLICACION\n4:LISTAR\n5:SALIR ","opcion incorrecta: ",1,5,1,2,aux);
    *resultado = atoi(aux);

}
void menu4(int *resultado)
{
    int i;
    char aux[15];
    getNumber("\n1:Cliente con más avisos activos.\n2: Cliente con más avisos pausados\n3:Cliente con más avisos.\n4 Cantidad de publicaciones de un rubro\n5:Rubro con más publicaciones activas\n6:Rubro con menos publicaciones activas\n7:SALIR\n "
              ,"opcion incorrecta: ",1,7,1,2,aux);
    *resultado = atoi(aux);

}

//---------------------------------ALTA BAJA Y MODIFICACION-----------------------------------
void Alta(t_Clientes str[],int cantidadElementos,int *idIncremental)
{
    int espacioLibre;
    char auxiliar[51];
    int i;
    int aux;
    espacioLibre = buscarPrimerOcurrencia(str,5,-1);

    if(espacioLibre != -1)
    {
        getName("\nIngrese nombre: ","error",1,51,str[espacioLibre].nombre);
        getName("\nIngrese apellido: ","error",1,51,str[espacioLibre].apellido);
        str[espacioLibre].estado = 1;
        str[espacioLibre].id = idIncremental;
    }
    else
    {
        printf("\nNo encontro lugar");
    }
}
/**
  *\brief Da el alta , pidiendo al usuario todos los datos necesarios.
  *\param El array Y la cantidad de elementos del array.
**/
void baja(t_Clientes str[],int cantidadElementos)
{
   int espacioLibre;
   char auxDato[51];
   espacioLibre = buscarPrimerOcurrencia(str,5,1);
   if(espacioLibre != -1)
   {
    mostrarLista(str,cantidadElementos);
    getNumber("\nque id desea dar de baja","error",1,cantidadElementos,1,cantidadElementos,auxDato);
    espacioLibre = buscarPrimerOcurrencia2(str,5,atoi(auxDato));

        if(espacioLibre != -1 && str[espacioLibre].estado != -1)
        {
            str[espacioLibre].estado = -1;
            printf("\nBaja exitosa");
        }
        else
        {
            printf("\nEl dato no existe");
        }
   }
   else
   {
       printf("\nno hay datos cargados");
   }
}
/**
  *\brief Modifica un dato del array.
  *\param El array , la cantidad de elementos.
**/
void modificacion(t_Clientes str[],int cantidadElementos)
{
    int espacioLibre;
    char auxDato[51];
    espacioLibre = buscarPrimerOcurrencia(str,5,1);
    if(espacioLibre != -1)
    {
        mostrarLista(str,cantidadElementos);
        getNumber("\ningrese la id a modificar","error",1,cantidadElementos,1,cantidadElementos,auxDato);
        espacioLibre = buscarPrimerOcurrencia2(str,5,atoi(auxDato));
        if(espacioLibre != -1)
        {
            getName("\nIngrese nuevo nombre:  ","error",1,51,str[espacioLibre].nombre);
            getName("\nIngrese nuevo apellido:  ","error",1,51,str[espacioLibre].apellido);
        }
        else
        {
            printf("\nEl dato no existe");
        }
    }
    else
    {
        printf("\nno hay datos cargados");
    }
}
//---------------------------------ALTA BAJA MODIFICACION-----------------------------------
void Alta2(t_Publicacion str[],t_Publicaciones str2[],t_Clientes str3[],int cantidadElementos)
{
    int espacioLibre;
    char auxiliar[51];
    espacioLibre = buscarPrimerOcurrencia3(str,5,-1);

    if(espacioLibre != -1)
    {
        mostrarLista2(str2,cantidadElementos);
        getNumber("\nSelecione la ID del aviso: ","error",1,cantidadElementos,1,2,auxiliar);
        str[espacioLibre].idPublicacion = atoi(auxiliar);
        mostrarLista(str3,cantidadElementos);
        getNumber("\nSelecione la ID del cliente: ","error",1,cantidadElementos,1,2,auxiliar);
        str[espacioLibre].idClientes = atoi(auxiliar);
        str[espacioLibre].estado = 1;

        str2[str[espacioLibre].idPublicacion-1].cantidadAltas = ++str2[str[espacioLibre].idPublicacion-1].cantidadAltas;
        str2[str[espacioLibre].idPublicacion-1].estadoRubro = 1;
        str3[str[espacioLibre].idClientes-1].estadoPublicacion = 1;
        str3[str[espacioLibre].idClientes-1].cantidadPublicaciones = ++str3[str[espacioLibre].idClientes-1].cantidadPublicaciones;
        printf("\nalta exitosa");
    }
    else
    {
        printf("\nNo encontro lugar");
    }
}
/**
  *\brief Da el alta , pidiendo al usuario todos los datos necesarios.
  *\param El array Y la cantidad de elementos del array.
**/
void baja2(t_Clientes str3[],t_Publicacion str[],t_Publicaciones str2[],int cantidadElementos,int cantidadElementos2)
{
   int espacioLibre;
   int i,j;
   char auxDato[51];
   espacioLibre = buscarPrimerOcurrencia3(str,cantidadElementos*cantidadElementos2,1);
   if(espacioLibre != -1)
   {
    listadoMuchosAmuchos(str3,str,str2,cantidadElementos,cantidadElementos2);
    getNumber("\nque id de aviso desea pausar: ","error",1,cantidadElementos,1,cantidadElementos,auxDato);
    espacioLibre = buscarPrimerOcurrencia4(str,5,atoi(auxDato));

        if(espacioLibre != -1)
        {
            str[espacioLibre].estado = 0;
            str3[str[espacioLibre].idClientes-1].estadoPublicacion = 0;
            for(i=0;i<cantidadElementos2;i++)
            {
                if(str[espacioLibre].idClientes-1 == str[i].idClientes)
                {
                   for(j=0;j<cantidadElementos2;j++)
                   {
                       if(str[i].idClientes == str2[j].idRubro)
                       {
                           str2[j].estadoRubro = 0;
                           break;
                       }
                   }
                   break;
                }
            }
            printf("\nAviso pausado");
        }
        else
        {
            printf("\nEl dato no existe");
        }
   }
   else
   {
       printf("\nno hay datos cargados");
   }
}
/**
  *\brief Modifica un dato del array.
  *\param El array , la cantidad de elementos.
**/
void modificacion2(t_Clientes str3[],t_Publicacion str[],t_Publicaciones str2[],int cantidadElementos,int cantidadElementos2)
{
    int espacioLibre;
    int i,j,k;
    char auxDato[51];
    espacioLibre = buscarPrimerOcurrencia3(str,5,0);
    if(espacioLibre != -1)
    {
        listadoMuchosAmuchos2(str3,str,str2,cantidadElementos,cantidadElementos2);
        getNumber("\ningrese la id a reanudar","error",1,cantidadElementos,1,cantidadElementos,auxDato);
        espacioLibre = buscarPrimerOcurrencia4(str,5,atoi(auxDato));
        if(espacioLibre != -1)
        {
            str[espacioLibre].estado = 1;
            for(i=0;i<cantidadElementos;i++)
            {
                if(str[espacioLibre].idClientes == str3[i].id)
                {
                    for(j=0;j<cantidadElementos*cantidadElementos2;j++)
                    {
                       if(str3[i].id == str[j].idClientes)
                       {
                           for(k=0;k<cantidadElementos2;k++)
                           {
                               if(str[j].idPublicacion == str2[k].idRubro)
                               {
                                   str2[k].estadoRubro = 1;
                                   str3[i].estadoPublicacion = 1;
                                   break;
                               }
                           }
                           break;
                       }
                     }
                     break;
                }

            }
            printf("\nPublicacion reanudada");
        }
        else
        {
            printf("\nEl dato no existe");
        }
    }
    else
    {
        printf("\nno hay datos cargados");
    }
}
//-----------------------------LISTAR DATOS POR PANTALLA---------------------------------------

void mostrarLista(t_Clientes str[],int cantidadElementos)
{
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        if(str[i].estado != -1)
        {
           printf("\n%d %s %s",str[i].id,str[i].nombre,str[i].apellido);
        }
    }
}

void mostrarLista2(t_Publicaciones str[],int cantidadElementos)
{
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        if(str[i].idRubro != -1)
        {
           printf("\n%d %s",str[i].idRubro,str[i].descripcion);
        }
    }
}

void listadoMuchosAmuchos ( t_Clientes str[], t_Publicacion str3[], t_Publicaciones str2[], int cantidadElementos, int cantidadElementos2 )
{
    int i, j, k;


  for( i = 0; i < cantidadElementos2; i++)
  {
        for( j = 0; j < (cantidadElementos * cantidadElementos2); j++ )
        {
         if( str2[i].idRubro == str3[j].idPublicacion && str3[j].estado == 1 )
         {
			for( k = 0; k < cantidadElementos; k++ ){
				if( str[k].estado != -1 && str3[j].idPublicacion == str[k].id ){
					printf("\nID del aviso: %d %s %s", str3[j].idPublicacion, str[k].nombre, str2[i].descripcion );
				}

			}
         }
        }
  }
}

void listadoMuchosAmuchos2( t_Clientes str[], t_Publicacion str3[], t_Publicaciones str2[], int cantidadElementos, int cantidadElementos2 )
{
    int i, j, k;


  for( i = 0; i < cantidadElementos2; i++)
  {
        for( j = 0; j < (cantidadElementos * cantidadElementos2); j++ )
        {
         if( str2[i].idRubro == str3[j].idPublicacion && str3[j].estado == 0)
         {
			for( k = 0; k < cantidadElementos; k++ ){
				if( str[k].estado != -1 && str3[j].idPublicacion == str[k].id ){
					printf("\nID del aviso pausado: %d %s %s", str3[j].idPublicacion, str[k].nombre, str2[i].descripcion );
				}

			}
         }
        }
  }
}


//--------------------Harcodear datos------------------------
/**
  *\brief Simula una carga de datos para la prueba del programa.
  *\param el array donde cargar los datos.
**/
void hardcodearDatosDATO(t_Clientes str[])
{
    int i;
    int id[]={1,2,3,4,5};
    char nombres[][50]={"Maria","Pedro","Jose","Pedro","Pablo"};
    char apellidos[][50] ={"gonzales","alvarez","rodriguez","avila","urti"};
    int estado[5] = {1,1,1,1,1};

    for(i=0; i<5; i++)
    {
        str[i].id = id[i];
        str[i].estado = estado[i];
        strncpy(str[i].nombre,nombres[i],50);
        strncpy(str[i].apellido,apellidos[i],50);
    }
}
/**
  *\brief Simula una carga de datos para la prueba del programa.
  *\param el array donde cargar los datos.
**/
void hardcodearDatosDATO2(t_Publicaciones str[])
{
    int i;
    int id[]={1,2,3,4,5};
    char descripcion[][50]={"VENDO AUTO","VENDO MOTO","SE NECESITA EMPLEADO","LIMPIO CASAS","VENDO CELULAR"};


    for(i=0; i<5; i++)
    {
        str[i].idRubro = id[i];
        strncpy(str[i].descripcion,descripcion[i],50);

    }
}

void listaClienteMayorPublicacionesActivas(t_Clientes str[], int cantidadElementos)
{
    int i;
    int flag = 1;
    int maximo = 0;
    int posicion = 0;

  for(i=0;i<cantidadElementos;i++)
  {
    if(str[i].estadoPublicacion == 1 && str[i].estado != -1)
    {
        if(str[i].cantidadPublicaciones > maximo || flag)
        {
            maximo = str[i].cantidadPublicaciones;
            posicion = i;
            flag = 0;
        }
    }


  }
    if(maximo)
    {
        printf("%s",str[posicion].nombre);
    }
    else
    {
        printf("\nNo se cargaron datos");
    }
}

void listaClienteMayorAvisosPausados(t_Clientes str[], int cantidadElementos)
{
    int i;
    int flag = 1;
    int maximo = 0;
    int posicion = 0;

  for(i=0;i<cantidadElementos;i++)
  {
    if((str[i].estadoPublicacion == 0) && str[i].estado != -1)
    {
        if(str[i].cantidadPublicaciones > maximo || flag)
        {
            maximo = str[i].cantidadPublicaciones;
            posicion = i;
            flag = 0;
        }
    }


  }
    if(maximo)
    {
        printf("%s",str[posicion].nombre);
    }
    else
    {
        printf("\nNo se cargaron datos");
    }
}

void listaClienteMayorPublicaciones(t_Clientes str[], int cantidadElementos)
{
    int i;
    int flag = 1;
    int maximo = 0;
    int posicion = 0;

  for(i=0;i<cantidadElementos;i++)
  {
    if((str[i].estadoPublicacion == 1 || str[i].estadoPublicacion == 0) && str[i].estado != -1)
    {
        if(str[i].cantidadPublicaciones > maximo || flag)
        {
            maximo = str[i].cantidadPublicaciones;
            posicion = i;
            flag = 0;
        }
    }


  }
    if(maximo)
    {
        printf("%s",str[posicion].nombre);
    }
    else
    {
        printf("\nNo se cargaron datos");
    }
}
void listaMayorRubrosActivos(t_Publicaciones str[], int cantidadElementos)
{
    int i;
    int flag = 1;
    int maximo = 0;
    int posicion = 0;

  for(i=0;i<cantidadElementos;i++)
  {
    if(str[i].estadoRubro == 1)
    {
        if(str[i].cantidadAltas > maximo || flag)
        {
            maximo = str[i].cantidadAltas;
            posicion = i;
            flag = 0;
        }
    }


  }
    if(maximo)
    {
        printf("%s",str[posicion].descripcion);
    }
    else
    {
        printf("\nNo se cargaron datos");
    }
}

void listaMenorRubrosActivos(t_Publicaciones str[], int cantidadElementos)
{
    int i;
    int flag = 1;
    int maximo = 0;
    int posicion = 0;

  for(i=0;i<cantidadElementos;i++)
  {
    if(str[i].estadoRubro == 1)
    {
        if(str[i].cantidadAltas < maximo || flag)
        {
            maximo = str[i].cantidadAltas;
            posicion = i;
            flag = 0;
        }
    }


  }
    if(maximo)
    {
        printf("%s",str[posicion].descripcion);
    }
    else
    {
        printf("\nNo se cargaron datos");
    }
}
