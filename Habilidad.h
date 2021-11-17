#ifndef HABILIDAD_H_INCLUDED
#define HABILIDAD_H_INCLUDED
#include "string.h"
#include"fecha.h"
#include "tipoHabilidad.h"


typedef struct{
                string nombreHabilidad;
                Fecha ManifestacionHabilidad;
                long cedula;
                TipoHabilidad tipo;
                }Habilidad;

#endif // HABILIDAD_H_INCLUDED
