#include "Menu.h"
#include "ABBTodosLosSocios.h"
#include "ListaHabilidadesDeSocio.h"

int main()
{
    ABB a;
    Habilidad h;
    Fecha f;

    Mago m;
    m.nombre = "leticia";
    m.cedula = 111;
    m.categoria = BRUJO;
    m.DimensionOrigen= "Montevideo";
    m.nacimiento.dia=1;
    m.nacimiento.mes=12;
    m.nacimiento.anio=1900;

    Mago n;
    n.nombre = "algo";
    n.cedula = 222;
    n.categoria = BRUJO;
    n.DimensionOrigen= "Montevideo";
    n.nacimiento.dia=1;
    n.nacimiento.mes=12;
    n.nacimiento.anio=1900;

    Mago l ;
    l.nombre = "agua";
    l.cedula = 333;
    l.categoria = BRUJO;
    l.DimensionOrigen= "Montevideo";
    l.nacimiento.dia=1;
    l.nacimiento.mes=12;
    l.nacimiento.anio=1900;

    Mago w ;
    w.nombre = "vaso";
    w.cedula = 444;
    w.categoria = HECHICERO;
    w.DimensionOrigen= "Montevideo";
    w.nacimiento.dia=1;
    w.nacimiento.mes=12;
    w.nacimiento.anio=1900;

    Mago x ;
    x.nombre = "plato";
    x.cedula = 555;
    x.categoria = HADA;
    x.DimensionOrigen= "Montevideo";
    x.nacimiento.dia=1;
    x.nacimiento.mes=12;
    x.nacimiento.anio=1900;
    Crear(a);


    InsertarSocio(a, l);
    InsertarSocio(a,m);
    InsertarSocio(a,x);
    InsertarSocio(a, n);
    InsertarSocio(a,w);

    if(ExisteSocio(a, 555))
        printf("si");

    DesplegarTodosLosSocios(a);
    int brujos = 0;
    int hadas = 0;
    int hechiceros = 0;
    ContarSociosDeCadaCategoria(a, brujos, hadas, hechiceros);
    printf("\nBrujos:%d \nHadas:%d \nHechiceros:%d", brujos, hadas, hechiceros);

//    CargarHabilidad(h);
//    MostrarHabilidad(h);
//
//    cargarFecha(f);
//    printf("La cantidad de magos que nacieron antes de esta fecha son: %d", ContarCuantosSociosNacieronAntesDeFechaDada(a, f));



}
