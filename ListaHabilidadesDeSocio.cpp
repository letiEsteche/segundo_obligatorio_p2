#include "ListaHabilidadesDeSocio.h"


void Crear(Lista &L) {
    L = NULL;
}

boolean ListaVacia(Lista L) {
    return boolean(L == NULL);
}

void IngresarPrimeraHabilidad(Lista &habilidades, Habilidad h) {
    Lista aux2 = new NodoHabilidad;
    aux2->info = h;
    aux2->sig = habilidades;
    habilidades = aux2;
}

boolean TieneAlgunaHabilidad(Lista L, long cedula) {
    boolean cedulaTieneHabilidad = FALSE;
    while (L != NULL && !cedulaTieneHabilidad) {
        if (L->info.cedula == cedula) { //selectora
            cedulaTieneHabilidad = TRUE;
        }
        L = L->sig;
    }
    return cedulaTieneHabilidad;
}

Fecha FechaDeUltimaHabilidadRegistradaPorUnSocio(Lista L, long cedula) {
    Fecha aux;
    boolean encontre = FALSE;
    while (L != NULL && !encontre) {
        if (L->info.cedula == cedula) {//selectoras
            aux = L->info.ManifestacionHabilidad;//selectoras
            encontre = TRUE;
        }
        L = L->sig;
    }
    return aux;
}


void MostrarTodasLasHabilidades(Lista lista) {
    while (lista != NULL) {
        MostrarHabilidad(lista->info);
        lista = lista->sig;
    }
}

void ListarHabilidadesDeUnSocio(Lista L, long cedula)
{
    while(L!= NULL){
        if(L->info.cedula == cedula){
            MostrarHabilidad(L->info);
        }
        L= L->sig;

    }
}

void ListarHabilidadesEnUnaFechaDada(Lista L, Fecha f)
{
    while(L!=NULL){
        if(compararFechas(L->info.ManifestacionHabilidad, f))//selectora
            MostrarHabilidad(L->info);
        L=L->sig;
    }
}


// ------------------------------------------------


int ContarHabilidadesEntreDosFechasIngresadas(Lista L, Fecha primera, Fecha segunda)
{
    int contarHabilidades =0;
    while(L!=NULL){
        if(PrimeraFechaAnteriorOIgualALaSegunda(primera, L->info.ManifestacionHabilidad) &&
           PrimeraFechaPosteriorOIgualALaSegunda(L->info.ManifestacionHabilidad, segunda)){
               contarHabilidades++;
               MostrarHabilidad(L->info);
        }
         L = L->sig;
    }

    return contarHabilidades;

}
