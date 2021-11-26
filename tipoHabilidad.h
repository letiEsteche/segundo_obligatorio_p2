#ifndef TIPOHABILIDAD_H_INCLUDED
#define TIPOHABILIDAD_H_INCLUDED
#include<stdio.h>

typedef enum{NATURAL, POCONATURAL, SOBRENATURAL} TipoHabilidad;

void CargarTipoDeHabilidadMago(TipoHabilidad &c);

void MostrarTipoDeHabilidadMago(TipoHabilidad c);

int ContarTipoDeHabilidades(TipoHabilidad c, int contarNatural, int contarSobrenatural, int contarPoconatural);

#endif // TIPOHABILIDAD_H_INCLUDED
