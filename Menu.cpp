#include "Menu.h"
#include "boolean.h"

void menuPrincipal(int &opcion)
{

    printf("\n1- Ingresar Mago");
    printf("\n2- Mostrar Mago ingresado");
    printf("\n3- Ingresar una habilidad");
    printf("\n4- Mostrar habilidad ingresada");
    printf("\n0- Salir");

    printf("\nQue opcion desea realizar?\n");
    scanf("%d", &opcion);


}

void menuConsultasYListas(int &opcion)
{

    printf("\n1- Mostrar cuantos socios de cada categor�a m�gica ");
    printf("\n2- Mostrar cuantas habilidades de cada tipo hay registradas");
    printf("\n3- Mostrar cuantos de los socios registrados en el sistema nacieron antes de una fecha dada fecha");
    printf("\n4- Montar cu�ntas habilidades fueron ingresadas dentro de un rango de fechas dadas");
    printf("\n5- Listar todos los socios registrados en el sistema, ordenados por c�dula de menor a mayor");
    printf("\n6- Listar todos aquellos socios registrados en el sistema que a�n no han manifestado ninguna habilidad, ordenados por c�dula de menor a mayor");
    printf("\n7- Dada la c�dula m�gica de un socio, listar todas las habilidades correspondientes a dicho socio, ordenadas en forma cronol�gica inversa ");
    printf("\n8- Dada una fecha, listar todas las habilidades que hayan sido manifestadas en dicha fecha");
    printf("\n9- Listar los datos del socio m�s poderoso registrado en el sistema");
    printf("\n0- Salir");

    printf("\nQue opcion desea realizar?\n");
    scanf("%d", &opcion);

}
