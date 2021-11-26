#ifndef LISTAHABILIDADESDESOCIO_H_INCLUDED
#define LISTAHABILIDADESDESOCIO_H_INCLUDED

#include "Habilidad.h"

typedef struct HabilidadesDeSocioStruct {
                                            Habilidad info;
                                            HabilidadesDeSocioStruct *sig;
                                        } NodoHabilidad;

typedef NodoHabilidad *Lista;

// ------------------------------------------------ Funciones y procedimientos

void Crear(Lista &L);

boolean ListaVacia(Lista L);

void IngresarPrimeraHabilidad(Lista &habilidades, Habilidad h);

boolean TieneAlgunaHabilidad(Lista L, long cedula);
// precondicion fecha y ver si lista esta vacia

Fecha FechaDeUltimaHabilidadRegistradaPorUnSocio(Lista L, long cedula);

void IngresarHabilidad(Lista &habilidades, Habilidad h);

void AgregarHabilidadALaLista(Lista &habilidades, Habilidad h);

void MostrarTodasLasHabilidades(Lista lista);







// ------------------------------------------------


int ContarHabilidadesEntreDosFechasIngresadas(Lista l, TipoHabilidad t);


//usar en mago mas poderoso
int CantidadDeHabilidadesPorCedula(Lista L, long cedula);

//Contar cu�ntas habilidades de cada tipo (naturales, poco naturales y sobrenaturales) hay
//registradas en el sistema.
void CantidadHabilidadDeCadaTipo(Lista L, int &n, int &p, int &s);

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
void ListarHabilidadesEnUnaFechaDada(Lista L, Fecha f);

int ContarHabilidadesEntreDosFechasIngresadas(Lista L, Fecha primera, Fecha segunda);

#endif // LISTAHABILIDADESDESOCIO_H_INCLUDED
