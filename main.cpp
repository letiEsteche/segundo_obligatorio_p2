#include "Menu.h"
#include "ABBTodosLosSocios.h"

int main() {
 /*   ABB a;
    Habilidad h;
    TipoHabilidad t;
    Fecha f,p;
    Lista i;

    Mago m;
    m.nombre = "leticia";
    m.cedula = 111;
    m.categoria = BRUJO;
    m.DimensionOrigen = "Montevideo";
    m.nacimiento.dia = 1;
    m.nacimiento.mes = 12;
    m.nacimiento.anio = 1900;

    Mago n;
    n.nombre = "algo";
    n.cedula = 222;
    n.categoria = BRUJO;
    n.DimensionOrigen = "Montevideo";
    n.nacimiento.dia = 1;
    n.nacimiento.mes = 12;
    n.nacimiento.anio = 1900;

    Mago l;
    l.nombre = "agua";
    l.cedula = 333;
    l.categoria = BRUJO;
    l.DimensionOrigen = "Montevideo";
    l.nacimiento.dia = 1;
    l.nacimiento.mes = 12;
    l.nacimiento.anio = 1900;

    Mago w;
    w.nombre = "vaso";
    w.cedula = 444;
    w.categoria = HECHICERO;
    w.DimensionOrigen = "Montevideo";
    w.nacimiento.dia = 1;
    w.nacimiento.mes = 12;
    w.nacimiento.anio = 1900;

    Mago x;
    x.nombre = "plato";
    x.cedula = 555;
    x.categoria = HADA;
    x.DimensionOrigen = "Montevideo";
    x.nacimiento.dia = 1;
    x.nacimiento.mes = 12;
    x.nacimiento.anio = 1900;
    Crear(a);


    InsertarSocio(a, l);
    InsertarSocio(a, m);
    InsertarSocio(a, x);
    InsertarSocio(a, n);
    InsertarSocio(a, w);

    if (ExisteSocio(a, 555))
        printf("si");

    DesplegarTodosLosSocios(a);
    int brujos = 0;
    int hadas = 0;
    int hechiceros = 0;
    ContarSociosDeCadaCategoria(a, brujos, hadas, hechiceros);
    printf("\nBrujos:%d \nHadas:%d \nHechiceros:%d", brujos, hadas, hechiceros);

    CargarHabilidad(h);
    MostrarHabilidad(h);

    cargarFecha(f);
    printf("\nLa cantidad de magos que nacieron antes de esta fecha son: %d", ContarCuantosSociosNacieronAntesDeFechaDada(a, f));

//Dadas dos fechas, contar cuántas habilidades fueron ingresadas dentro de dicho rango de
//fechas (incluidas ambas fechas).
    printf("\nIngresar dos fechas para contar cuantas habilidades fueron ingresadas en ese rango");
    Fecha b;
    printf("\nCargar una fecha: ");
    cargarFecha(f);
    printf("\nCargar otra fecha: ");
    cargarFecha(b);


    printf("Las habilidades entre el rango de fecha es %d",ContarHabilidadesEntreDosFechasIngresadas(i,t));

    printf("Fecha de utlima habilidad registrada");
//    FechaDeUltimaHabilidadRegistradaPorUnSocio(i);

*/
    ABB a;
    Lista L;
    Crear(L);
    Habilidad h1, h2;

    h1.nombreHabilidad = "inteligencia";
    h1.cedula = 222;
    h1.ManifestacionHabilidad.anio=1990;
    h1.ManifestacionHabilidad.mes=12;
    h1.ManifestacionHabilidad.dia=1;
    h1.tipo = NATURAL;

    h2.nombreHabilidad= "rapidez";
    h2.cedula= 111;
    h2.ManifestacionHabilidad.anio=1991;
    h2.ManifestacionHabilidad.mes=12;
    h2.ManifestacionHabilidad.dia=1;
    h2.tipo = NATURAL;

    IngresarHabilidad(L,h2);
    IngresarHabilidad(L,h1);

    MostrarTodasLasHabilidades(L);




}
