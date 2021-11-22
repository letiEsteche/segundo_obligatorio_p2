#include "Menu.h"
#include "ListaHabilidadesDeSocio.h"
#include "ABBTodosLosSocios.h"

int main() {

    // ------------------------------------------------ Primera fecha es posterior o igual a la segunda

//    Fecha f1;
//    f1.anio = 2000;
//    f1.mes = 12;
//    f1.dia = 14;
//
//    Fecha f2;
//    f2.anio = 2000;
//    f2.mes = 12;
//    f2.dia = 13;
//
//    if (PrimeraFechaPosteriorOIgualALaSegunda(f1, f2)) {
//        printf("\nLa primera fecha es posterior o igual a la segunda");
//    } else {
//        printf("\nLa primera fecha NO es posterior o igual a la segunda");
//    }

    // ------------------------------------------------ Primera fecha es anterior o igual a la segunda

//    Fecha f3;
//    f1.anio = 2000;
//    f1.mes = 12;
//    f1.dia = 12;
//
//    Fecha f4;
//    f2.anio = 1999;
//    f2.mes = 12;
//    f2.dia = 13;
//
//    if (PrimeraFechaAnteriorOIgualALaSegunda(f3, f4)) {
//        printf("\nLa primera fecha es anterior o igual a la segunda");
//    } else {
//        printf("\nLa primera fecha NO es anterior o igual a la segunda");
//    }

    // ------------------------------------------------ Crear árbol de socios

    ABB socios;
    Crear(socios);

    // ------------------------------------------------ Crear socios

    Mago m1;
    m1.nombre = "Leticia";
    m1.cedula = 111;
    m1.categoria = BRUJO;
    m1.DimensionOrigen = "Montevideo";
    m1.nacimiento.dia = 1;
    m1.nacimiento.mes = 12;
    m1.nacimiento.anio = 1901;

    Mago m2;
    m2.nombre = "Santiago";
    m2.cedula = 222;
    m2.categoria = HADA;
    m2.DimensionOrigen = "Colonia";
    m2.nacimiento.dia = 1;
    m2.nacimiento.mes = 12;
    m2.nacimiento.anio = 1902;

    Mago m3;
    m3.nombre = "Florencia";
    m3.cedula = 333;
    m3.categoria = HECHICERO;
    m3.DimensionOrigen = "Montevideo";
    m3.nacimiento.dia = 1;
    m3.nacimiento.mes = 12;
    m3.nacimiento.anio = 1903;

    // ------------------------------------------------ Insertar socio

    InsertarSocio(socios, m1);
    InsertarSocio(socios, m3);
    InsertarSocio(socios, m2);

    // ------------------------------------------------ Existe socio

//    if (ExisteSocio(socios, 111)) {
//        printf("\nsi existe el socio\n");
//    } else {
//        printf("\nNO existe el socio\n");
//    }

    // ------------------------------------------------ Mostrar socios

//    DesplegarTodosLosSocios(socios);

    // ------------------------------------------------ Cantidad de socios por tipo

//    int brujos = 0;
//    int hadas = 0;
//    int hechiceros = 0;
//    ContarSociosDeCadaCategoria(socios, brujos, hadas, hechiceros);
//    printf("\n\nCantidad de socios por tipo:");
//    printf("\nBrujos:%d \nHadas:%d \nHechiceros:%d", brujos, hadas, hechiceros);

    // ------------------------------------------------ Crear lista de habilidades

    Lista habilidades;
    Crear(habilidades);

    // ------------------------------------------------ Comprobar lista vacía

//    if (ListaVacia(habilidades)) {
//        printf("\nLa lista esta vacia");
//    } else {
//        printf("\nLa lista NO esta vacia");
//    }

    // ------------------------------------------------ Crear habilidades

    Habilidad h1;
    h1.nombreHabilidad = "Inteligencia";
    h1.cedula = 222;
    h1.ManifestacionHabilidad.anio = 1500;
    h1.ManifestacionHabilidad.mes = 12;
    h1.ManifestacionHabilidad.dia = 7;
    h1.tipo = NATURAL;

    Habilidad h2;
    h2.nombreHabilidad = "Rapidez";
    h2.cedula = 222;
    h2.ManifestacionHabilidad.anio = 1500;
    h2.ManifestacionHabilidad.mes = 12;
    h2.ManifestacionHabilidad.dia = 10;
    h2.tipo = NATURAL;

    Habilidad h3;
    h3.nombreHabilidad = "Invisibilidad";
    h3.cedula = 222;
    h3.ManifestacionHabilidad.anio = 1500;
    h3.ManifestacionHabilidad.mes = 12;
    h3.ManifestacionHabilidad.dia = 10;
    h3.tipo = NATURAL;

    Habilidad h4;
    h4.nombreHabilidad = "Rayos laser";
    h4.cedula = 222;
    h4.ManifestacionHabilidad.anio = 1500;
    h4.ManifestacionHabilidad.mes = 12;
    h4.ManifestacionHabilidad.dia = 11;
    h4.tipo = NATURAL;

    Habilidad h5;
    h5.nombreHabilidad = "Aire control";
    h5.cedula = 111;
    h5.ManifestacionHabilidad.anio = 1500;
    h5.ManifestacionHabilidad.mes = 12;
    h5.ManifestacionHabilidad.dia = 4;
    h5.tipo = NATURAL;

    Habilidad h6;
    h6.nombreHabilidad = "Fuego control";
    h6.cedula = 111;
    h6.ManifestacionHabilidad.anio = 1500;
    h6.ManifestacionHabilidad.mes = 12;
    h6.ManifestacionHabilidad.dia = 8;
    h6.tipo = NATURAL;

    // ------------------------------------------------ Cargar habilidad

    printf("\n\n\n");

    if (ExisteSocio(socios, h1.cedula)) {
        IngresarHabilidad(habilidades, h1);
    } else {
        printf("No existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\n");
    }

    if (ExisteSocio(socios, h2.cedula)) {
        IngresarHabilidad(habilidades, h2);
    } else {
        printf("No existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\n");
    }

    if (ExisteSocio(socios, h3.cedula)) {
        IngresarHabilidad(habilidades, h3);
    } else {
        printf("No existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\n");
    }

    if (ExisteSocio(socios, h4.cedula)) {
        IngresarHabilidad(habilidades, h4);
    } else {
        printf("No existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\n");
    }

    if (ExisteSocio(socios, h5.cedula)) {
        IngresarHabilidad(habilidades, h5);
    } else {
        printf("No existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\n");
    }

    if (ExisteSocio(socios, h6.cedula)) {
        IngresarHabilidad(habilidades, h6);
    } else {
        printf("No existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\n");
    }

    MostrarTodasLasHabilidades(habilidades);

    // ------------------------------------------------ Tiene alguna habilidad

//    printf("\nEl socio con cedula %ld tiene alguna habilidad: ", h1.cedula);
//    if (TieneAlgunaHabilidad(habilidades, h1.cedula)) {
//        printf("Si");
//
//        // ------------------------------------------------ Fecha de la ultima habilidad registrada
//        Fecha fechaDeManifestacionDeUltimaHabilidad = FechaDeUltimaHabilidadRegistradaPorUnSocio(habilidades,
//                                                                                                 h1.cedula);
//        printf("\nLa fecha de manifestacion de la ultima habilidad del socio es: ");
//        mostrarFecha(fechaDeManifestacionDeUltimaHabilidad);
//
//    } else {
//        printf("No");
//    }





}
