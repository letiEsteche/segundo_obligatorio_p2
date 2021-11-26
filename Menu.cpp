#include "Menu.h"
#include "boolean.h"

void menuPrincipal(int &opcion)
{

    printf("\n1- Ingresar Mago");
    printf("\n2- Mostrar Mago ingresado");
    printf("\n3- Ingresar una habilidad");
    printf("\n4- Mostrar habilidad ingresada");
    printf("\n5- Mostrar Menu de consultas y listados");
    printf("\n0- Salir");

    printf("\nQue opcion desea realizar?\n");
    scanf("%d", &opcion);


}

void menuConsultasYListas(int &opcion)
{

    printf("\n1- Mostrar cuantos socios de cada categoria magica");
    printf("\n2- Mostrar cuantas habilidades de cada tipo hay registradas");
    printf("\n3- Mostrar cuantos de los socios registrados en el sistema nacieron antes de una fecha dada fecha");
    printf("\n4- Mostrar cuantas habilidades fueron ingresadas dentro de un rango de fechas dadas");
    printf("\n5- Listar todos los socios registrados en el sistema, ordenados por cedula de menor a mayor");
    printf("\n6- Listar todos aquellos socios registrados en el sistema que aun no han manifestado ninguna habilidad");
    printf("\n7- Dada la cedula magica de un socio, listar todas las habilidades correspondientes a dicho socio");
    printf("\n8- Dada una fecha, listar todas las habilidades que hayan sido manifestadas en dicha fecha");
    printf("\n9- Listar los datos del socio mas poderoso registrado en el sistema");
    printf("\n0- Salir");

    printf("\nQue opcion desea realizar?\n");
    scanf("%d", &opcion);

}
