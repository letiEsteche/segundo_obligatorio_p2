#ifndef ABBTODOSLOSSOCIOS_H_INCLUDED
#define ABBTODOSLOSSOCIOS_H_INCLUDED
#include "Mago.h"
#include "ListaHabilidadesDeSocio.h"

//ABB de todos los socios ordenar por cedula de menor a mayor
typedef struct nodo_TodosLosSocios{
                                    Mago info;
                                    nodo_TodosLosSocios*hizq;
                                    nodo_TodosLosSocios*hder;
                                    }NodoSocio;
typedef NodoSocio * ABB;

/* crear un árbol vacío */
void Crear (ABB &a);

/* insertar un nuevo valor en el ABB */
/* precondición: el valor no existía previamente en el ABB */
void InsertarSocio (ABB &a, Mago m);

/* saber si un elemento pertenece al ABB, versión recursiva */
boolean ExisteSocio (ABB a, long cedula);

void Desplegar (ABB a);

int ContarCantidadDeBrujos(ABB a,int b);

int ContarCantidadDeHadas(ABB a, int h);

int ContarCantidadDeHechiceros(ABB a, int ch);

void ContarSociosDeCadaCategoria(ABB a);

//Dada una fecha de nacimiento, contar cuántos de los socios registrados en el sistema nacieron
//antes de dicha fecha. Se debe verificar previamente que la fecha ingresada sea válida.
void ContarCuantosSociosNacieronAntesDeFechaDada(ABB a, Fecha f, int c);

//Dadas dos fechas, contar cuántas habilidades fueron ingresadas dentro de dicho rango de
//fechas (incluidas ambas fechas). Se debe verificar previamente que ambas fechas ingresadas
//sean válidas y que la primera fecha sea menor o igual que la segunda.

void ContarHabilidadesEntreDosFechasIngresadas(ABB a, Fecha a, Fecha b);

//Listar todos los socios registrados en el sistema, ordenados por cédula de menor a mayor.
//Los datos de un mismo socio (cédula mágica, nombre, fecha de nacimiento, dimensión de
//origen y categoría mágica) deberán listarse todos en una misma línea
//recorrer en orden
void ListarTodosLosSocios(ABB a);

//Listar todos aquellos socios registrados en el sistema que aún no han manifestado ninguna
//habilidad, ordenados por cédula de menor a mayor. Los datos de un mismo socio (cédula
//mágica, nombre, fecha de nacimiento, dimensión de origen y categoría mágica) deberán
//listarse todos en una misma línea.
void ListarTodosLosSociosSinHabilidades(ABB a);

//Listar los datos del socio más poderoso registrado en el sistema. Es decir, del socio que ha
//manifestado la mayor cantidad de habilidades sobrenaturales de entre todos los socios
//registrados. En caso de que haya varios, basta con devolver uno cualquiera de ellos. En
//caso de que no haya ninguno, emitir un mensaje que así lo indique.
void ListarSocioConMasHabilidades(ABB a); //VER





#endif // ABBTODOSLOSSOCIOS_H_INCLUDED
