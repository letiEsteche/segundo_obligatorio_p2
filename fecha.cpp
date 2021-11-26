#include "fecha.h"

void cargarFecha(Fecha &fecha) {
    boolean fechaValida = FALSE;

    do {
        printf("\nIngrese el dia de la fecha:");
        scanf("%i", &fecha.dia);

        printf("\nIngrese el mes de la fecha:");
        scanf("%i", &fecha.mes);

        printf("\nIngrese el anio de la fecha:");
        scanf("%i", &fecha.anio);

        if (validarFecha(fecha)) {
            fechaValida = TRUE;
        } else {
            printf("\nLa fecha ingresada es invalida, vuelva a intentarlo...\n");
        }

    } while (fechaValida == FALSE);
}

void mostrarFecha(Fecha fecha) {
    printf("%i/%i/%i", fecha.dia, fecha.mes, fecha.anio);
}

boolean validarFecha(Fecha fecha) {
    int dia = fecha.dia;
    int mes = fecha.mes;
    int anio = fecha.anio;
    int diaMaximo;
    boolean fechaCorrecta = TRUE;

    if (mes >= 1 && mes <= 12) {
        switch (mes) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                diaMaximo = 31;
                break;

            case 4:
            case 6:
            case 9:
            case 11:
                diaMaximo = 30;
                break;

            case 2:
                if (anio % 4 == 0) {
                    diaMaximo = 29;
                } else {
                    diaMaximo = 28;
                }
        }

        if (dia < 1 || dia > diaMaximo) {
            fechaCorrecta = FALSE;
        }

        if (anio < 0 || anio > 2021) {
            fechaCorrecta = FALSE;
        }
    } else {
        fechaCorrecta = FALSE;
    }

    return fechaCorrecta;
}

boolean compararFechas(Fecha a, Fecha b) {
    boolean sonIguales = TRUE;

    if (a.anio != b.anio) {
        sonIguales = FALSE;
    }

    if (a.mes != b.mes) {
        sonIguales = FALSE;
    }

    if (a.dia != b.dia) {
        sonIguales = FALSE;
    }

    return sonIguales;
}
                                            //2019     2020
boolean PrimeraFechaAnteriorOIgualALaSegunda(Fecha f, Fecha h) {
    boolean primeraFechaMenorASegunda = TRUE;

    if (f.anio > h.anio) {
        primeraFechaMenorASegunda = FALSE;
    } else if (f.anio == h.anio) {
        if (f.mes > h.mes) {
            primeraFechaMenorASegunda = FALSE;
        } else if (f.mes == h.mes) {
            if (f.dia > h.dia) {
                primeraFechaMenorASegunda = FALSE;
            }
        }
    }

    return primeraFechaMenorASegunda;
}

boolean FechaIngresadaMayorOigualALaUltimaFechaDeManifestacion(Fecha f, Fecha h)
{
    boolean FechaQueIngresoEsMayorOIgualALaFechaDeLaUltimaManifestacion = TRUE;
    if (f.anio < h.anio) {
        FechaQueIngresoEsMayorOIgualALaFechaDeLaUltimaManifestacion = FALSE;
    } else if (f.anio == h.anio) {
        if (f.mes < h.mes) {
            FechaQueIngresoEsMayorOIgualALaFechaDeLaUltimaManifestacion = FALSE;
        } else if (f.mes == h.mes) {
            if (f.dia < h.dia) {
                FechaQueIngresoEsMayorOIgualALaFechaDeLaUltimaManifestacion = FALSE;
            }
        }
    }
    return FechaQueIngresoEsMayorOIgualALaFechaDeLaUltimaManifestacion;
}

                                            // 2020      2019
boolean PrimeraFechaPosteriorOIgualALaSegunda(Fecha f, Fecha h) {
    boolean primeraFechaMayorASegunda = TRUE;

    if (f.anio < h.anio) {
        primeraFechaMayorASegunda = FALSE;
    } else if (f.anio == h.anio) {
        if (f.mes < h.mes) {
            primeraFechaMayorASegunda = FALSE;
        } else if (f.mes == h.mes) {
            if (f.dia < h.dia) {
                primeraFechaMayorASegunda = FALSE;
            }
        }
    }
    return primeraFechaMayorASegunda;
}
