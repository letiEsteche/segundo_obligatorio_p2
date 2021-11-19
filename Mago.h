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

void CargarMago(Mago &m);

void MostrarMago(Mago m);

string DarNombre(Mago m);

long DarCedula(Mago m);

Fecha DarFecha(Mago m);

string DarDimensionOrigen(Mago m);

CategoriaMago DarCategroriaMago (Mago m);



#endif // MAGO_H_INCLUDED
