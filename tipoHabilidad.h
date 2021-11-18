#ifndef TIPOHABILIDAD_H_INCLUDED
#define TIPOHABILIDAD_H_INCLUDED
#include<stdio.h>

typedef enum{NATURAL, POCONATURAL, SOBRENATURAL} TipoHabilidad;

void CargarTipoDeHabilidadMago(TipoHabilidad &c);

void MostrarTipoDeHabilidadMago(TipoHabilidad c);

#endif // TIPOHABILIDAD_H_INCLUDED
