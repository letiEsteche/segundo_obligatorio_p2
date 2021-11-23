#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "boolean.h"

typedef struct {
                int dia;
                int mes;
                int anio;
                } Fecha;

void cargarFecha(Fecha &fecha);

void mostrarFecha(Fecha fecha);

boolean validarFecha(Fecha fecha);

boolean compararFechas(Fecha a, Fecha b);

boolean PrimeraFechaAnteriorOIgualALaSegunda(Fecha f, Fecha h);

boolean PrimeraFechaPosteriorOIgualALaSegunda(Fecha f, Fecha h);

boolean FechaIngresadaMayorOigualALaUltimaFechaDeManifestacion(Fecha f, Fecha h);

#endif // FECHA_H_INCLUDED
