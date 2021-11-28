#include "Menu.h"
#include "ListaHabilidadesDeSocio.h"
#include "ABBTodosLosSocios.h"

int main() {


    int opcion, Brujos = 0, Hadas = 0, Hechiceros = 0, natural = 0, sobrenatural = 0, poconatural = 0, cantMax;

    Mago m;
    long cedula;
    ABB socios;
    Crear(socios);
    Habilidad h;
    Lista habilidades;
    Crear(habilidades);
    TipoHabilidad t;
    Fecha f, g;
    FILE *archivo;

    printf("\t#################################################\n");
    printf("\t#_SOCIEDAD DE MAGOS UNIDOS RECONTRA FANTASTICOS_#\n");
    printf("\t#################################################\n\n");

    // cargar socios
    leerArbolSocios(socios);
    // guardar habilidades
    leerListaHabilidad(habilidades);

    do {
        printf("\n\t\t_MENU PRINCIPAL_\n");
        menuPrincipal(opcion);

        switch (opcion) {
            case 1: //Ingresar mago
                CargarMago(m);
                if (!ExisteSocio(socios, m.cedula)) {
                    InsertarSocio(socios, m);
                } else {
                    printf("La cedula del socio ya esta ingresada\n");
                }
                break;
            case 2: //mostrar magos ingresados
                if(socios != NULL)
                    DesplegarTodosLosSocios(socios);
                else
                    printf("\nNo hay socios ingresados");
                printf("\n");
                break;

            case 3: //ingresar habilidad
                CargarHabilidad(h);
                if (ExisteSocio(socios, h.cedula)) {
                    if (ListaVacia(habilidades)) {
                        IngresarPrimeraHabilidad(habilidades, h);
                    } else {
                        if (FechaIngresadaMayorOigualALaUltimaFechaDeManifestacion(h.ManifestacionHabilidad, habilidades->info.ManifestacionHabilidad)) {
                            IngresarPrimeraHabilidad(habilidades, h);
                        } else {
                            printf("\nLa fecha de la habilidad que quiere ingresar es anterior a la ultima habilidad registrada ");
                        }
                    }
                } else {
                    printf("\nNo existe ningun usuario en el sistema que contenga la cedula introducia en la habilidad\nAgregue socio primero\n");
                }
                printf("\n");
                break;

            case 4: //mostrar habilidad
                if(habilidades != NULL)
                    MostrarTodasLasHabilidades(habilidades);
                else
                    printf("\nNo hay habilidades ingresadas");
                printf("\n");
                break;

            case 5: //
                printf("\t\t_MENU DE CONSULTAS Y LISTADOS_\n\n");
                do {
                    menuConsultasYListas(opcion);

                    switch (opcion) {
                        case 1: //Mostrar cuantos socios de cada categoria magica
                            ContarSociosDeCadaCategoria(socios, Brujos, Hadas, Hechiceros);
                            printf("\nCantidad de socios por tipo:");
                            printf("\nBrujos: %d \nHadas: %d \nHechiceros: %d\n", Brujos, Hadas, Hechiceros);
                            printf("\n");
                            break;

                        case 2: //Mostrar cuantas habilidades de cada tipo hay registradas
                            if (ListaVacia(habilidades))
                                printf("\nNo hay habilidades ingresadas.");
                            else {
                                CantidadHabilidadDeCadaTipo(habilidades, natural, sobrenatural, poconatural);
                                printf("La cantidad de habilidades por tipo es: ");
                                printf("\nNatural: %d \nSobrenatural: %d\nPoconatural: %d", natural, sobrenatural, poconatural);
                                printf("\n");
                            }
                            break;

                        case 3: //Mostrar cuantos de los socios registrados en el sistema nacieron antes de una fecha dada fecha
                            printf("\nIngrese una fecha: ");
                            cargarFecha(f);

                            printf("La cantidad de socios que nacieron antes de la fecha son %d\n",
                                   ContarCuantosSociosNacieronAntesDeFechaDada(socios, f));
                            printf("\n");
                            break;

                        case 4: //Mostrar cuantas habilidades fueron ingresadas dentro de un rango de fechas dadas
                            printf("Ingrese una fecha: ");
                            cargarFecha(f);
                            printf("\nIngrese otra fecha mayor a la anterior: ");
                            cargarFecha(g);
                            if(PrimeraFechaAnteriorOIgualALaSegunda(f, g))
                                printf("\nLa cantidad de habilidades ingresadas en el rango de fecha es %d\n",
                                                ContarHabilidadesEntreDosFechasIngresadas(habilidades, f, g));
                            else{
                                printf("ERROR, primera fecha no es mayor a segunda fecha");
                            }
                            printf("\n");
                            break;



                        case 5: //Listar todos los socios registrados en el sistema, ordenados por cedula de menor a mayor
                            DesplegarTodosLosSocios(socios);
                            printf("\n");
                            break;

                        case 6: //Listar todos aquellos socios registrados en el sistema que aun no han manifestado ninguna habilidad

                            if (TieneAlgunaHabilidad(habilidades, cedula))
                                printf("Todos los socios tienen habilidades");
                            else
                                printf("\n\nLos socios sin habilidades son: \n");
                                ListarTodosLosSociosSinHabilidades(socios, habilidades);
                            printf("\n");
                            break;

                        case 7: //Dada la cedula magica de un socio, listar todas las habilidades correspondientes a dicho socio
                            printf("\nHabilidades de una cedula, ingrese una cedula: ");
                            scanf("%d", &cedula);
                            if (ExisteSocio(socios, cedula)){
                                if (TieneAlgunaHabilidad(habilidades, cedula))
                                    ListarHabilidadesDeUnSocio(habilidades, cedula);
                                else
                                    printf("La cedula ingresada no tiene habilidades");
                            }else
                                printf("La cedula ingresada no es socio");

                            printf("\n");
                            break;

                    case 8: //Dada una fecha, listar todas las habilidades que hayan sido manifestadas en dicha fecha
                            printf("\nMostrar habilidad en una fecha.");
                            printf("Ingrese una fecha: ");
                            cargarFecha(f);
                            if(HayHabilidadEnFechaDada(habilidades, f))
                                ListarHabilidadesEnUnaFechaDada(habilidades, f);
                            else
                                printf("No hay habilidades en fecha ingresada");

                            printf("\n");
                            break;

                        case 9: //Listar los datos del socio mas poderoso registrado en el sistema
                            cantMax = CantidadDeHabilidadesPorCedula(habilidades, cedula);
                            ListarSocioConMasHabilidades(socios, habilidades, m, cantMax);
                            printf("\nSocio con mas habilidades tiene %d\n", cantMax);
                            MostrarMago(m);
                            printf("\n");
                            break;

                        case 0: // salir
                            printf("\n\n");
                            break;

                        default:
                            printf("\nLa opcion seleccionada es invalida, por favor seleccione otra opcion.\n");
                            printf("\n");
                            break;
                    }
                } while (opcion != 0);
                break;


            case 6: // salir
                // guardar socios
                archivo = fopen("Socios.txt", "wb");
                escribirArbolSocios(socios, archivo);
                fclose(archivo);

                // guardar habilidades
                escribirListaHabilidad(habilidades);

                printf("Hasta luego...");
                break;

            default:
                printf("\nLa opcion seleccionada es invalida, por favor seleccione otra opcion.\n");
                printf("\n");
                break;
        }

    } while (opcion != 6);


}


