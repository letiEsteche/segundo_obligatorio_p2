#include "ListaHabilidadesDeSocio.h"


void Crear(Lista &L) {
    L = NULL;
}

boolean ListaVacia(Lista L) {
    return boolean(L == NULL);
}

void IngresarPrimeraHabilidad(Lista &habilidades, Habilidad h) {
    Lista aux = new NodoHabilidad;
    aux->info = h;
    aux->sig = NULL;
    habilidades = aux;
}

boolean TieneAlgunaHabilidad(Lista L, long cedula) {
    boolean cedulaTieneHabilidad = FALSE;
    while (L != NULL) {
        if (L->info.cedula == cedula) {
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
        if (L->info.cedula == cedula) {
            aux = L->info.ManifestacionHabilidad;
            encontre = TRUE;
        }
        L = L->sig;
    }
    return aux;
}



void AgregarHabilidadALaLista(Lista &habilidades, Habilidad h) {
    if (habilidades == NULL) {
        Lista aux1 = new NodoHabilidad;
        aux1->info = h;
        aux1->sig = NULL;
        habilidades->sig = aux1;
    } else if (FechaIngresadaMayorOigualALaUltimaFechaDeManifestacion(h.ManifestacionHabilidad, habilidades->info.ManifestacionHabilidad)) {
        Lista aux2 = new NodoHabilidad;
        aux2->info = h;
        aux2->sig = habilidades;
        habilidades = aux2;
    }
}

void MostrarTodasLasHabilidades(Lista lista) {
    while (lista != NULL) {
        MostrarHabilidad(lista->info);
        lista = lista->sig;
    }
}







// ------------------------------------------------


int ContarHabilidadesEntreDosFechasIngresadas(Lista L, TipoHabilidad t)
{
    Fecha f, h;
    if(t == NULL)
        return 0;
    else{
        if(PrimeraFechaAnteriorOIgualALaSegunda(f, h)){
            if(L->info.tipo == 'NATURAL' || L->info.tipo == 'POCONATURAL' || L->info.tipo == 'SOBRENATURAL')
                return 1 + ContarHabilidadesEntreDosFechasIngresadas(L->sig, t);

        }else
            return ContarHabilidadesEntreDosFechasIngresadas(L->sig, t);
    }
}

