#ifndef MAGO_H_INCLUDED
#define MAGO_H_INCLUDED
#include "string.h"
#include"fecha.h"
#include "categoriaMago.h"

typedef struct{
                string nombre;
                long cedula;
                Fecha nacimiento;
                string DimensionOrigen;
                CategoriaMago categoria;
                }Mago;



#endif // MAGO_H_INCLUDED
