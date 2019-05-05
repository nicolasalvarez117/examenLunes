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
int buscarPrimerOcurrencia(TIPO1 str[],int cantidadElementos,int valor)
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

//------------------------INICIALIZAR DATOS-------------------------------------------
/**
  *\brief inicializa los valores unicos  con LIBRE(-1).
  *\param el array  y la cantidad de elementos del array.
**/
void inicializarArray(TIPO1 str[],int cantidadElementos)
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
void menu(int *resultado)
{
    int i;
    char aux[15];
    getNumber("1:ALTA\n2:BAJA\n3:MODIFICAR\n4:SALIR: ","opcion incorrecta: ",1,4,1,2,aux);
    *resultado = atoi(aux);

}

/**
  *\brief imprime por pantalla el menu de ABM .
  *\param la ubicacion donde guardar la eleccion del usuario.
**/
void menu2(int *resultado)
{
    int i;
    char aux[15];
    getNumber("1:ASOCIADOS\n2:SALIR: ","opcion incorrecta: ",1,2,1,2,aux);
    *resultado = atoi(aux);

}

//---------------------------------ALTA BAJA Y MODIFICACION-----------------------------------
void Alta(TIPO1 str[],int cantidadElementos)
{
    int espacioLibre;
    char auxiliar[51];
    espacioLibre = buscarPrimerOcurrencia(str,5,-1);

    if(espacioLibre != -1)
    {
        getName("MENSAJE","MENSAJEerror",1,51,str[espacioLibre].nombre);
        getName("MENSAJE","MENSAJEerror",1,51,str[espacioLibre].apellido);
        getNumber("MENSAJE","MENSAJEerror",1,120,1,4,str[espacioLibre].edad);

        //str[espacioLibre].id = ++str[espacioLibre].id;  ID,AUTO INCREMENTAL O LEGAJO
        str[espacioLibre].estado = 1;
    }
    else
    {
        printf("No encontro lugar");
    }
}
/**
  *\brief Da el alta , pidiendo al usuario todos los datos necesarios.
  *\param El array Y la cantidad de elementos del array.
**/
void baja(TIPO1 str[],int cantidadElementos)
{
   int espacioLibre;
   char auxDato[51];
   espacioLibre = buscarPrimerOcurrencia(str,5,1);
   if(espacioLibre != -1)
   {
    mostrarLista(str,cantidadElementos,-1);
    getNumber("que id desea dar de baja","error",1,cantidadElementos,1,cantidadElementos,auxDato);
    espacioLibre = buscarPrimerOcurrencia(str,5,atoi(auxDato));

        if(espacioLibre != -1)
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
void modificacion(TIPO1 str[],int cantidadElementos)
{
    int espacioLibre;
    char auxDato[51];
    espacioLibre = buscarPrimerOcurrencia(str,5,1);
    if(espacioLibre != -1)
    {
        mostrarLista(str,cantidadElementos,-1);
        getNumber("ingrese la id a modificar","error",1,cantidadElementos,1,cantidadElementos,auxDato);
        espacioLibre = buscarPrimerOcurrencia(str,5,atoi(auxDato));
        if(espacioLibre != -1)
        {
            getName("\nIngrese nuevo nombre:  ","error",1,51,str[espacioLibre].nombre);
            getName("\nIngrese nuevo apellido:  ","error",1,51,str[espacioLibre].apellido);
        }
        else
        {
            printf("El dato no existe");
        }
    }
    else
    {
        printf("no hay datos cargados");
    }
}
//-----------------------------LISTAR DATOS POR PANTALLA---------------------------------------

void mostrarLista(TIPO1 str[],int cantidadElementos,int valorOcupado)
{
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        if(str[i].estado != -1)
        {
           printf("%d %s %s %s ",str[i].id,str[i].dni,str[i].nombre,str[i].apellido);
        }
    }
}

void listadoMuchosAmuchos ( TIPO1 str[], TIPO2 str2[], TIPO3 str3[], int cantidadElementos, int cantidadElementos2 )
{
    int i, j, k;

    printf("\n****** LISTADO DE MUCHOS A MUCHOS ******\n\n");


  for( i = 0; i < cantidadElementos2; i++)
  {
        for( j = 0; j < (cantidadElementos * cantidadElementos2); j++ )
        {
         if( str2[i].id == str3[j].Id )
         {
			for( k = 0; k < cantidadElementos; k++ ){
				if( str[k].estado != -1 && str3[j].id == str[k].id ){
					printf("%d %s %s", str[k].id, str[k].nombre, str2[i].descripcion );
				}

			}
         }
        }
  }
}


