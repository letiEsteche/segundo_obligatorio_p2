#ifndef HABILIDAD_H_INCLUDED
#define HABILIDAD_H_INCLUDED

#include "string.h"
#include"fecha.h"
#include "tipoHabilidad.h"


typedef struct {
    string nombreHabilidad;
    Fecha ManifestacionHabilidad;
    long cedula;
    TipoHabilidad tipo;
} Habilidad;

void CargarHabilidad(Habilidad &h);

void MostrarHabilidad(Habilidad h);

string DarNombreHabilidad(Habilidad h);

Fecha DarFechaDeManifestacionHabilidad(Habilidad h);

long DarCedulaHabilidad(Habilidad h);

TipoHabilidad DarTipoDeHabilidad(Habilidad h);

void escribirHabilidad(Habilidad habilidad, FILE *archivo);

void leerHabilidad(Habilidad &habilidad, FILE *archivo);


#endif // HABILIDAD_H_INCLUDED
