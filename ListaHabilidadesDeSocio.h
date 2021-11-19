#ifndef LISTAHABILIDADESDESOCIO_H_INCLUDED
#define LISTAHABILIDADESDESOCIO_H_INCLUDED
#include "Habilidad.h"
#include "ABBTodosLosSocios.h"


//Dada la cédula mágica de un socio, listar todas las habilidades correspondientes a dicho
//socio, ordenadas en forma cronológica inversa

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


//usar en mago mas poderoso
int CantidadDeHabilidadesPorCedula(Lista L, long cedula);

//Contar cuántas habilidades de cada tipo (naturales, poco naturales y sobrenaturales) hay
//registradas en el sistema.
void CantidadHabilidadDeCadaTipo(Lista L, int &n, int &p, int &s);

//Dada la cédula mágica de un socio, listar todas las habilidades correspondientes a dicho
//socio, ordenadas en forma cronológica inversa (desde las más recientes hacia las más
//antiguas). Los datos de una misma habilidad (nombre, fecha de manifestación, cédula mágica
//del socio y tipo de habilidad) deberán listarse todos en una misma línea. Se debe verificar
//previamente que el socio correspondiente exista en el sistema.
void ListarHabilidadesDeUnSocio(Lista L, long cedula);

//Dada una fecha, listar todas las habilidades que hayan sido manifestadas en dicha fecha.
//Los datos de una misma habilidad (nombre, fecha de manifestación, cédula mágica del socio
//y tipo de habilidad) deberán listarse todos en una misma línea. Se debe verificar previamente
//que la fecha ingresada sea válida.
//void ListarHabilidadesEnUnaFechaDada(Lista L, fecha f);




#endif // LISTAHABILIDADESDESOCIO_H_INCLUDED
