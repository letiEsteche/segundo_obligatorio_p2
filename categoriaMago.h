#ifndef CATEGORIAMAGO_H_INCLUDED
#define CATEGORIAMAGO_H_INCLUDED
#include<stdio.h>

typedef enum{BRUJO, HADA, HECHICERO} CategoriaMago;

void CargarCategoriaMago(CategoriaMago &c);

void MostrarCategoriaMago(CategoriaMago c);



#endif // CATEGORIAMAGO_H_INCLUDED
