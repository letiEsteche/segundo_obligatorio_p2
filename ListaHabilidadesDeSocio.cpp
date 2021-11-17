#include "ListaHabilidadesDeSocio.h"

void Crear(Lista &L)
{
    L = NULL;
}

void IngresarHabilidad(Lista &L, Habilidad h)
{
    if(ExisteSocio){
        if(TieneAlgunaHabilidad(h.cedula)){
            if(ValidarPrimeraFechaSeaMenorALaSegunda(FechaDeUltimaHabilidadRegistradaPorUnSocio(h.cedula), h.ManifestacionHabilidad)){
                //insertamos habilidad

            }
        }else{
            //ingresar habilidad
        }
    }
}

boolean TieneAlgunaHabilidad(long cedula)
{


}

void FechaDeUltimaHabilidadRegistradaPorUnSocio(long cedula)
{
    if()
}

boolean Vacio(Lista L)
{
    boolean es = FALSE;
    if(L == NULL)
        es = TRUE;
    return es;
}



void Resta(Lista &L)
{
    Lista aux = L;
    L = L-> sig;
    delete aux;
}

/*void InsFront(Lista &L, float e)
{
    Lista aux = new NodoHabilidad;
    aux -> info = e;
    aux -> sig = L;
    L = aux;
}
*/
