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
    TIPO1 arrayDATO[CANTIDAD];
    TIPO2 arrayDATO2[CANTIDAD2];
    TIPO3 arrayDATO3[CANTIDAD*CANTIDAD2];

    inicializarArray(arrayDATO,CANTIDAD);
    inicializarArray2(arrayDATO2,CANTIDAD2);

    hardcodearDatosDATO(arrayDATO);
    hardcodearDatosDATO2(arrayDATO2);

    int opcion,opcion2;

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
                    Alta(arrayDATO,CANTIDAD);
                    break;
                case 2:
                    baja(arrayDATO,CANTIDAD);
                    break;
                case 3:
                    modificacion(arrayDATO,CANTIDAD);
                    break;
                }
            }while(opcion2 != 4);
            break; /**FINALIZA EL CASE 1 PRINCIPAL.**/
        case 2:
            do
            {
                menu3(&opcion2);
                switch(opcion2)
                {
                case 1:
                    Alta2(arrayDATO2,CANTIDAD2);
                    break;
                case 2:
                    baja2(arrayDATO2,CANTIDAD2);
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
