#ifndef LISTAHABILIDADESDESOCIO_H_INCLUDED
#define LISTAHABILIDADESDESOCIO_H_INCLUDED
#include "Habilidad.h"
#include "ABBTodosLosSocios.h"


//Dada la c�dula m�gica de un socio, listar todas las habilidades correspondientes a dicho
//socio, ordenadas en forma cronol�gica inversa

typedef struct nodo_HabilidadesDeSocio{
                                        Habilidad info;
                                        nodo_HabilidadesDeSocio*sig;
                                        } NodoHabilidad;
typedef NodoHabilidad*Lista;


void Crear(Lista &L);


void IngresarHabilidad(Lista &L, Habilidad h);


boolean Vacio(Lista L);


float Primero(Lista L);


void Resta(Lista &L);


void InsFront(Lista &L, float e);

int CantidadDeHabilidadesPorCedula(Lista L, long cedula);

//Contar cu�ntas habilidades de cada tipo (naturales, poco naturales y sobrenaturales) hay
//registradas en el sistema.
void CantidadHabilidadDeCadaTipo(Lista L);

//Dada la c�dula m�gica de un socio, listar todas las habilidades correspondientes a dicho
//socio, ordenadas en forma cronol�gica inversa (desde las m�s recientes hacia las m�s
//antiguas). Los datos de una misma habilidad (nombre, fecha de manifestaci�n, c�dula m�gica
//del socio y tipo de habilidad) deber�n listarse todos en una misma l�nea. Se debe verificar
//previamente que el socio correspondiente exista en el sistema.
void ListarHabilidadesDeUnSocio(Lista L, long cedula);

//Dada una fecha, listar todas las habilidades que hayan sido manifestadas en dicha fecha.
//Los datos de una misma habilidad (nombre, fecha de manifestaci�n, c�dula m�gica del socio
//y tipo de habilidad) deber�n listarse todos en una misma l�nea. Se debe verificar previamente
//que la fecha ingresada sea v�lida.
void ListarHabilidadesEnUnaFechaDada(Lista L, fecha f);




#endif // LISTAHABILIDADESDESOCIO_H_INCLUDED
