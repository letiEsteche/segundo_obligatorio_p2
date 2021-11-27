#include "Menu.h"
#include "ListaHabilidadesDeSocio.h"
#include "ABBTodosLosSocios.h"

int main()
{

    int opcion, Brujos=0, Hadas=0, Hechiceros=0, natural=0, sobrenatural=0, poconatural=0, cantMax;
    Mago m;
    long cedula;
    ABB socios;
    Crear(socios);
    Habilidad h;
    Lista habilidades;
    Crear(habilidades);
    TipoHabilidad t;
    Fecha f, g;

        printf("\t#################################################\n");
        printf("\t#_SOCIEDAD DE MAGOS UNIDOS RECONTRA FANTASTICOS_#\n");
        printf("\t#################################################\n\n");





    do{
        printf("\n\t\t_MENU PRINCIPAL_\n");
        menuPrincipal(opcion);


        switch(opcion){
            case 1: //Ingresar mago

                   CargarMago(m);

                    if(ExisteSocio(socios, m.cedula) == TRUE){
                        printf("La cedula del socio ya esta ingresada\n");
                    }else{
                        InsertarSocio(socios, m);
                    }
                    break;
            case 2: //mostrar mago ingresado
                    MostrarMago(m);
                    break;

            case 3: //ingresar habilidad
                    CargarHabilidad(h);

                    if (ExisteSocio(socios, m.cedula)) {
                        if (ListaVacia(habilidades)) {
                            IngresarPrimeraHabilidad(habilidades, h);
                        } else {
                            if (FechaIngresadaMayorOigualALaUltimaFechaDeManifestacion(h.ManifestacionHabilidad, habilidades->info.ManifestacionHabilidad)) {
                                IngresarPrimeraHabilidad(habilidades, h);
                            } else {
                                    printf("La fecha de la habilidad ha ingresar es anterior la de la ultima habilidad registrada ");
                            }
                        }
                    } else {
                            printf("No existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\nAgregue socio primero\n");
                        }

                    if (ExisteSocio(socios, m.cedula)) {
                        if (ListaVacia(habilidades)) {
                            IngresarPrimeraHabilidad(habilidades, h);
                        } else {
                            if (FechaIngresadaMayorOigualALaUltimaFechaDeManifestacion(h.ManifestacionHabilidad, habilidades->info.ManifestacionHabilidad)) {
                                IngresarPrimeraHabilidad(habilidades, h);
                            } else {
                                    printf("La fecha de la habilidad ha ingresar es anterior la de la ultima habilidad registrada ");
                            }
                        }
                    } else {
                            printf("No existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\nAgregue socio primero\n");
                        }
                                    break;

            case 4: //mostrar habilidad
                    MostrarHabilidad(h);
                    break;

            case 5: //
                    printf("\t\t_MENU DE CONSULTAS Y LISTADOS_\n\n");
                    do{
                    menuConsultasYListas(opcion);

                        switch(opcion){
                            case 1: //Mostrar cuantos socios de cada categoria magica
                                    ContarSociosDeCadaCategoria(socios, Brujos, Hadas, Hechiceros);
                                    printf("\nCantidad de socios por tipo:");
                                    printf("\nBrujos: %d \nHadas: %d \nHechiceros: %d\n", Brujos, Hadas, Hechiceros);
                                    break;

            /*no funciona*/         case 2: //Mostrar cuantas habilidades de cada tipo hay registradas
                                    if (ListaVacia(habilidades))
                                        printf("\nNo hay habilidades ingresadas.");
                                    else{
                                        ContarTipoDeHabilidades(t, natural, sobrenatural, poconatural);
                                        printf("La cantidad de habilidades por tipo es: ");
                                        printf("\nNatural: %d \nSobrenatural: %d\nPoconatural: %d");
                                    }
                                    break;

              /*no funciona*/       case 3: //Mostrar cuantos de los socios registrados en el sistema nacieron antes de una fecha dada fecha
                                    printf("\nIngrese una fecha: ");
                                    cargarFecha(f);
                                    printf("La cantidad de socios que nacieron antes de la fecha son %d\n",ContarCuantosSociosNacieronAntesDeFechaDada(socios, f));
                                    break;

              /*no funciona*/       case 4: //Mostrar cuantas habilidades fueron ingresadas dentro de un rango de fechas dadas
                                    printf("Ingrese una fecha: ");
                                    cargarFecha(f);
                                    printf("\nIngrese otra fecha mayor a la anterior: ");
                                    cargarFecha(g);
                                    printf("La cantidad de habilidades ingresadas en el rango de fecha es %d\n",ContarHabilidadesEntreDosFechasIngresadas(habilidades,f, g));
                                    break;

                            case 5: //Listar todos los socios registrados en el sistema, ordenados por cedula de menor a mayor
                                    DesplegarTodosLosSocios(socios);
                                    printf("\n");
                                    break;

      /*no funciona*/               case 6: //Listar todos aquellos socios registrados en el sistema que aun no han manifestado ninguna habilidad
                                    printf("\n\nLos socios sin habilidades son: \n");

                                    if (TieneAlgunaHabilidad(habilidades, m.cedula))
                                         printf("Todos los socios tienen habilidades");
                                    else
                                        ListarTodosLosSociosSinHabilidades(socios, habilidades);
                                    break;

/*muestra dos veces la misma habilidad*/ case 7: //Dada la cedula magica de un socio, listar todas las habilidades correspondientes a dicho socio
                                    printf("\nHabilidades de una cedula, ingrese una cedula: ");
                                    scanf("%d", &cedula);
                                    ListarHabilidadesDeUnSocio(habilidades, cedula);
                                    break;

                            case 8: //Dada una fecha, listar todas las habilidades que hayan sido manifestadas en dicha fecha
                                    printf("\nMostrar habilidad en una fecha");
                                    printf("Ingrese una fecha: ");
                                    cargarFecha(f);
                                    ListarHabilidadesEnUnaFechaDada(habilidades, f);
                                    break;

                            case 9: //Listar los datos del socio mas poderoso registrado en el sistema
                                    Mago MasPoderoso;

                                    printf("\nLa cantidad de habilidades por cedula es %d",CantidadDeHabilidadesPorCedula(habilidades, cedula));
                                    cantMax = CantidadDeHabilidadesPorCedula(habilidades, cedula);
                                    ListarSocioConMasHabilidades(socios, habilidades, MasPoderoso, cantMax);
                                    printf("\nSocio con mas habilidades tiene %d\n", cantMax);
                                    MostrarMago(MasPoderoso);

                                    break;

                            case 0: // salir
                                    printf("\n\n");
                                    break;

                            default:
                                    printf("\nLa opcion seleccionada es invalida, por favor seleccione otra opcion.\n");
                                    break;
                        }
                    }while(opcion != 0);
                    break;


            case 6: // salir
                    printf("Hasta luego...");
                    break;
            default:
                    printf("\nLa opcion seleccionada es invalida, por favor seleccione otra opcion.\n");
                    break;
        }
    }while(opcion !=6);









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

 /*   // ------------------------------------------------ Crear árbol de socios

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

    Mago m4;
    m4.nombre = "Harry Potter";
    m4.cedula = 444;
    m4.categoria = BRUJO;
    m4.DimensionOrigen = "Inglaterra";
    m4.nacimiento.dia = 1;
    m4.nacimiento.mes = 12;
    m4.nacimiento.anio = 1903;

    // ------------------------------------------------ Insertar socio

    InsertarSocio(socios, m1);
    InsertarSocio(socios, m3);
    InsertarSocio(socios, m2);
    InsertarSocio(socios, m4);

    // ------------------------------------------------ Existe socio

//    if (ExisteSocio(socios, 111)) {
//        printf("\nsi existe el socio\n");
//    } else {
//        printf("\nNO existe el socio\n");
//    }

    // ------------------------------------------------ Mostrar socios

    DesplegarTodosLosSocios(socios);

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
    h1.cedula = 111;
    h1.ManifestacionHabilidad.anio = 1500;
    h1.ManifestacionHabilidad.mes = 12;
    h1.ManifestacionHabilidad.dia = 7;
    h1.tipo = NATURAL;

    Habilidad h2;
    h2.nombreHabilidad = "Rapidez";
    h2.cedula = 111;
    h2.ManifestacionHabilidad.anio = 1500;
    h2.ManifestacionHabilidad.mes = 12;
    h2.ManifestacionHabilidad.dia = 10;
    h2.tipo = NATURAL;

    Habilidad h3;
    h3.nombreHabilidad = "Invisibilidad";
    h3.cedula = 333;
    h3.ManifestacionHabilidad.anio = 1500;
    h3.ManifestacionHabilidad.mes = 12;
    h3.ManifestacionHabilidad.dia = 10;
    h3.tipo = NATURAL;

    Habilidad h4;
    h4.nombreHabilidad = "Rayos laser";
    h4.cedula = 444;
    h4.ManifestacionHabilidad.anio = 1500;
    h4.ManifestacionHabilidad.mes = 12;
    h4.ManifestacionHabilidad.dia = 11;
    h4.tipo = NATURAL;

    Habilidad h5;
    h5.nombreHabilidad = "Aire control";
    h5.cedula = 444;
    h5.ManifestacionHabilidad.anio = 1500;
    h5.ManifestacionHabilidad.mes = 12;
    h5.ManifestacionHabilidad.dia = 4;
    h5.tipo = NATURAL;

    Habilidad h6;
    h6.nombreHabilidad = "Fuego control";
    h6.cedula = 555;
    h6.ManifestacionHabilidad.anio = 1500;
    h6.ManifestacionHabilidad.mes = 12;
    h6.ManifestacionHabilidad.dia = 8;
    h6.tipo = NATURAL;

    // ------------------------------------------------ Cargar habilidad

    printf("\n\n\n");

    if (ExisteSocio(socios, h1.cedula)) {
        if (ListaVacia(habilidades)) {
            IngresarPrimeraHabilidad(habilidades, h1);
        } else {
            if (FechaIngresadaMayorOigualALaUltimaFechaDeManifestacion(h1.ManifestacionHabilidad, habilidades->info.ManifestacionHabilidad)) {
                IngresarPrimeraHabilidad(habilidades, h1);
            } else {
                    printf("La fecha de la habilidad ha ingresar es anterior la de la ultima habilidad registrada ");
            }
        }
    } else {
            printf("No existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\nAgregue socio primero\n");
        }

    if (ExisteSocio(socios, h2.cedula)) {
        if (ListaVacia(habilidades)) {
            IngresarPrimeraHabilidad(habilidades, h2);
        } else {
            if (FechaIngresadaMayorOigualALaUltimaFechaDeManifestacion(h2.ManifestacionHabilidad, habilidades->info.ManifestacionHabilidad)) {
                IngresarPrimeraHabilidad(habilidades, h2);
            } else {
                    printf("La fecha de la habilidad ha ingresar es anterior la de la ultima habilidad registrada ");
            }
        }
    } else {
            printf("No existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\nAgregue socio primero\n");
        }



/*
    if (ExisteSocio(socios, h2.cedula)) {
        AgregarHabilidadALaLista(habilidades, h2);
    } else {
        printf("No existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\n");
    }

    if (ExisteSocio(socios, h3.cedula)) {
        AgregarHabilidadALaLista(habilidades, h3);
    } else {
        printf("No existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\n");
    }

    if (ExisteSocio(socios, h4.cedula)) {
        AgregarHabilidadALaLista(habilidades, h4);
    } else {
        printf("No existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\n");
    }

    if (ExisteSocio(socios, h5.cedula)) {
        AgregarHabilidadALaLista(habilidades, h5);
    } else {
        printf("No existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\n");
    }

    if (ExisteSocio(socios, h6.cedula)) {
        AgregarHabilidadALaLista(habilidades, h6);
    } else {
        printf("No existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\n");
    }
printf("\nMostrar todas las habilidades registradas:");
    MostrarTodasLasHabilidades(habilidades);


//-----------------------------------------------socios sin habilidades
    printf("\n\nLos socios sin habilidades son:");
    ListarTodosLosSociosSinHabilidades(socios, habilidades);


//----------------------------------------mostrar todas las habilidades de una cedula
printf("\nHabilidades de una cedula");
ListarHabilidadesDeUnSocio(habilidades,h1.cedula);

//---------------------------------------mostrar habilidades de una fecha
printf("\nMostrar habilidad en una fecha");
ListarHabilidadesEnUnaFechaDada(habilidades, h1.ManifestacionHabilidad);

//-------------------------------------------contar habilidades entre dos fechas
printf("\n");
printf("La cantidad de habilidad en rango de fecha es %d",ContarHabilidadesEntreDosFechasIngresadas(habilidades, h2.ManifestacionHabilidad, h1.ManifestacionHabilidad));

//----------------------------------------Contar cantidad de habilidades por cedula

printf("\nLa cantidad de habilidades por cedula es %d",CantidadDeHabilidadesPorCedula(habilidades, h1.cedula));



//---------------------------------------------mostrar socio mas poderoso

Mago MasPoderoso = socios->info;
int cantMax = CantidadDeHabilidadesPorCedula(habilidades, socios->info.cedula);

ListarSocioConMasHabilidades(socios, habilidades, MasPoderoso, cantMax);
printf("\nSocio con mas habilidades tiene
       %d", cantMax);
MostrarMago(MasPoderoso);


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

*/

}


