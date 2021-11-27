#include "categoriaMago.h"

void CargarCategoriaMago(CategoriaMago &c)
{
    int opcion;
    do{
        printf("\nA continuacion se selecciona la categoria del Mago...");
        printf("\n1- BRUJO");
        printf("\n2- HADA");
        printf("\n3- HECHICERO");
        printf("\nElija una opcion:");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                c = BRUJO;
                break;
            case 2:
                c = HADA;
                break;
            case 3:
                c= HECHICERO;
                break;
            default:
                printf("\nOpcion seleccionada incorrecta, vuelva a intentarlo...");

        }
    }while(!(opcion >=1 && opcion <= 3));
}

void MostrarCategoriaMago(CategoriaMago c)
{
    switch(c){
        case BRUJO:
            printf("Brujo");
            break;
        case HADA:
            printf("Hada");
            break;
        case HECHICERO:
            printf("Hechicero");
            break;
    }
}
