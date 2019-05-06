#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "imput.h"
#include "lib.h"


#define CANTIDAD 5
#define CANTIDAD2 5

int main()
{
    t_Clientes arrayClientes[CANTIDAD]; /**Array donde se guardaran los datos del cliente**/
    t_Publicaciones arrayPublicaciones[CANTIDAD2]; /**Array donde iran hardcodeadas las publicaciones**/
    t_Publicacion arrayPublicacion[CANTIDAD*CANTIDAD2];/**Array donde se cargaran las publicaciones solicitadas por los clientes**/
//------------------------------------------------------------------------------
    inicializarArray(arrayClientes,CANTIDAD);
    inicializarArray2(arrayPublicacion,CANTIDAD*CANTIDAD2);
//-----------------------------------------------------------------------------
    hardcodearDatosDATO(arrayClientes);
    hardcodearDatosDATO2(arrayPublicaciones);
//----------------------------------------------------------------------
    int opcion,opcion2,i;
    int idIncremental = 6;
    char aux[51];
//-------------------------------------------------------------------------
    for(i=0;i<CANTIDAD2;i++)
    {
        arrayPublicaciones[i].cantidadAltas = 0;
        arrayPublicaciones[i].estadoRubro = -1;
    }
//---------------------------------------------------------------------------
    do
    {
 //-------------------------------------------------------------------------
       menu(&opcion);
       switch(opcion)
       {
        case 1:
           do
            {
                menu2(&opcion2);
                switch(opcion2)
                {
                case 1:
                    alta(arrayClientes,CANTIDAD,idIncremental);
                    idIncremental++;
                    break;
                case 2:
                    baja(arrayClientes,CANTIDAD);
                    break;
                case 3:
                    modificacion(arrayClientes,CANTIDAD);
                    break;
                case 4:
                    mostrarLista(arrayClientes,CANTIDAD);
                    break;
                }
            }while(opcion2 != 5);
            break; /**FINALIZA EL CASE 1 PRINCIPAL.**/
//----------------------------------------------------------------------------
        case 2:
            do
            {
                menu3(&opcion2);
                switch(opcion2)
                {
                case 1:
                    alta2(arrayPublicacion,arrayPublicaciones,arrayClientes,CANTIDAD2);
                    break;
                case 2:
                    baja2(arrayClientes,arrayPublicacion,arrayPublicaciones,CANTIDAD,CANTIDAD2);
                    break;
                case 3:
                    modificacion2(arrayClientes,arrayPublicacion,arrayPublicaciones,CANTIDAD,CANTIDAD2);
                    break;
                case 4:
                    listadoMuchosAmuchos(arrayClientes,arrayPublicacion,arrayPublicaciones,CANTIDAD,CANTIDAD2);
                    break;

                }
            }while(opcion2 != 5);
            break; /**FINALIZA EL CASE 2 PRINCIPAL.**/
//-------------------------------------------------------------------------------------------------------
        case 3:
            system("cls");
            menu4(&opcion2);
            switch(opcion2)
            {
                case 1:
                    listaClienteMayorPublicacionesActivas(arrayClientes,CANTIDAD);
                    break;
                case 2:
                    listaClienteMayorAvisosPausados(arrayClientes,CANTIDAD);
                    break;
                case 3:
                    listaClienteMayorPublicaciones(arrayClientes,CANTIDAD);
                    break;
                case 4:
                    mostrarLista2(arrayPublicaciones,CANTIDAD2);
                    getNumber("\nIngrese el rubro: ","error",1,CANTIDAD2,1,2,aux);
                    i = atoi(aux);
                    printf("Cantidad de altas de este rubro %d",arrayPublicaciones[i-1].cantidadAltas);
                    break;
                case 5:
                    listaMayorRubrosActivos(arrayPublicaciones,CANTIDAD2);
                    break;
                case 6:
                    listaMenorRubrosActivos(arrayPublicaciones,CANTIDAD2);
                    break;

            }
            break;
//---------------------------------------------------------------------------------
        }
    }while(opcion != 4);


    return 0;
}
