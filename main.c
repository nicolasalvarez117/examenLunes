#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "imput.h"
#include "lib.h"


#define CANTIDAD
#define CANTIDAD2

int main()
{
    TIPO1 arrayDATO1[CANTIDAD];
    TIPO2 arrayDATO2[CANTIDAD2];
    TIPO3 arrayDATO3[CANTIDAD*CANTIDAD2];

    inicializarArray(arrayDATO1,CANTIDAD);
    inicializarArray2(arrayDATO2,CANTIDAD2);

    hardcodearDATO1(arrayDATO1);
    hardcodearDATO2(arrayDATO2);

    int opcion,opcion2;
    int idIncremental = 6;
    char auxiliar[51];

    do
    {
       menu(&opcion);
       switch(opcion)
       {
        case 1:
           do
            {
                menu2(&opcion2)
                switch(opcion2)
                {
                case 1:
                    alta(arrayDATO1,CANTIDAD,&idIncremental);
                    break;
                case 2:
                    baja(arrayDATO,CANTIDAD);
                    break;
                case 3:
                    modificacion(arrayDATO1,CANTIDAD);
                    break;
                }
            }while(opcion2 != 4);
            break; /**FINALIZA EL CASE 1 PRINCIPAL.**/
        /*case 2:
            do
            {
                menu3(&opcion2);
                switch(opcion2)
                {
                case 1:
                    cargarDATO3();
                    break;
                case 2:
                    baja2();
                    break;
                case 3:
                    modificacion2(arrayDATO2,CANTIDAD2);
                    break;

                }
            }while(opcion2 != 4);
            break; /**FINALIZA EL CASE 2 PRINCIPAL.**/
       }




    }while(opcion != 6);


    return 0;
}
