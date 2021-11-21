#ifndef ABBTODOSLOSSOCIOS_H_INCLUDED
#define ABBTODOSLOSSOCIOS_H_INCLUDED

#include "Mago.h"
#include "ListaHabilidadesDeSocio.h"

//ABB de todos los socios ordenar por cedula de menor a mayor
typedef struct nodo_TodosLosSocios {
                                    Mago info;
                                    nodo_TodosLosSocios *hizq;
                                    nodo_TodosLosSocios *hder;
                                    } NodoSocio;
typedef NodoSocio *ABB;

/* crear un �rbol vac�o */
void Crear(ABB &a);

/* insertar un nuevo valor en el ABB */
/* precondici�n: el valor no exist�a previamente en el ABB */
void InsertarSocio(ABB &a, Mago m);

/* saber si un elemento pertenece al ABB, versi�n recursiva */
boolean ExisteSocio(ABB a, long cedula);


int ContarCantidadDeBrujos(ABB a, int b);

int ContarCantidadDeHadas(ABB a, int h);

int ContarCantidadDeHechiceros(ABB a, int ch);

void ContarSociosDeCadaCategoria(ABB a, int &countBrujos, int &countHadas, int &countHechiceros);

//Dada una fecha de nacimiento, contar cu�ntos de los socios registrados en el sistema nacieron
//antes de dicha fecha. Se debe verificar previamente que la fecha ingresada sea v�lida.
int ContarCuantosSociosNacieronAntesDeFechaDada(ABB a, Fecha f);

//Dadas dos fechas, contar cu�ntas habilidades fueron ingresadas dentro de dicho rango de
//fechas (incluidas ambas fechas). Se debe verificar previamente que ambas fechas ingresadas
//sean v�lidas y que la primera fecha sea menor o igual que la segunda.
int ContarCuantosSociosNacieronAntesDeFechaDada(ABB a, Fecha f);

//Listar todos los socios registrados en el sistema, ordenados por c�dula de menor a mayor.
//Los datos de un mismo socio (c�dula m�gica, nombre, fecha de nacimiento, dimensi�n de
//origen y categor�a m�gica) deber�n listarse todos en una misma l�nea
//recorrer en orden
void DesplegarTodosLosSocios(ABB a);

//Listar todos aquellos socios registrados en el sistema que a�n no han manifestado ninguna
//habilidad, ordenados por c�dula de menor a mayor. Los datos de un mismo socio (c�dula
//m�gica, nombre, fecha de nacimiento, dimensi�n de origen y categor�a m�gica) deber�n
//listarse todos en una misma l�nea.
//void ListarTodosLosSociosSinHabilidades(ABB a, Lista listaHabilidades);

//Listar los datos del socio m�s poderoso registrado en el sistema. Es decir, del socio que ha
//manifestado la mayor cantidad de habilidades sobrenaturales de entre todos los socios
//registrados. En caso de que haya varios, basta con devolver uno cualquiera de ellos. En
//caso de que no haya ninguno, emitir un mensaje que as� lo indique.
void ListarSocioConMasHabilidades(ABB a); //VER




#endif // ABBTODOSLOSSOCIOS_H_INCLUDED
