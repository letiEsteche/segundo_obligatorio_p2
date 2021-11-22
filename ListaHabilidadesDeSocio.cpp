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

void IngresarHabilidad(Lista &habilidades, Habilidad h) {
    Lista aux = new NodoHabilidad;
    aux->info = h;
    aux->sig = habilidades;
    habilidades = aux;
}

void MostrarTodasLasHabilidades(Lista lista) {
    while (lista != NULL) {
        MostrarHabilidad(lista->info);
        lista = lista->sig;
    }
}

void CantidadHabilidadDeCadaTipo(Lista L, int &n, int &p, int &s) {
    while (L != NULL) {
        if (L->info.tipo == NATURAL) {
            n++;
        } else if (L->info.tipo == POCONATURAL) {
            p++;
        } else if (L->info.tipo == SOBRENATURAL) {
            s++;
        }
        L = L->sig;
    }
}

int ContarHabilidadesEntreDosFechasIngresadas(Lista L, Fecha desde, Fecha hasta)
{
    int contador = 0;
    while (L != NULL) {
        if (PrimeraFechaPosteriorOIgualALaSegunda(desde, hasta)) {
            contador++;
        }
        L = L->sig;
    }
}






