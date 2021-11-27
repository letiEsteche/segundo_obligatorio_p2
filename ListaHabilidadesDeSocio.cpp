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
        if (DarCedulaHabilidad(L->info) == cedula) {
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
        if (DarCedulaHabilidad(L->info) == cedula) {
            aux = DarFechaDeManifestacionHabilidad(L->info);
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

void ListarHabilidadesDeUnSocio(Lista L, long cedula) {
    while (L != NULL) {
        if (DarCedulaHabilidad(L->info) == cedula) {
            MostrarHabilidad(L->info);
        }
        L = L->sig;

    }
}

void ListarHabilidadesEnUnaFechaDada(Lista L, Fecha f) {
    while (L != NULL) {
        if (compararFechas(DarFechaDeManifestacionHabilidad(L->info), f))
            MostrarHabilidad(L->info);
        L = L->sig;
    }
}


int ContarHabilidadesEntreDosFechasIngresadas(Lista L, Fecha primera, Fecha segunda) {
    int contarHabilidades = 0;
    while (L != NULL) {
        if (PrimeraFechaAnteriorOIgualALaSegunda(L->info.ManifestacionHabilidad, primera) &&
            PrimeraFechaAnteriorOIgualALaSegunda(segunda, L->info.ManifestacionHabilidad)) {
            contarHabilidades++;
            MostrarHabilidad(L->info);
        }
        L = L->sig;
    }

    return contarHabilidades;

}

int CantidadDeHabilidadesPorCedula(Lista L, long cedula) {
    int contarHabilidadesPorCedula = 0;
    while (L != NULL) {
        if (L->info.cedula == cedula)
            contarHabilidadesPorCedula++;
        L = L->sig;
    }
    return contarHabilidadesPorCedula;
}


void escribirListaHabilidad(Lista lista) {
    FILE *archivo = fopen("Habilidades.txt", "wb");
    while (lista != NULL) {
        escribirHabilidad(lista->info, archivo);
        lista = lista->sig;
    }
    fclose(archivo);
}

void leerListaHabilidad(Lista &lista) {
    Crear(lista);
    FILE *archivo = fopen("Habilidades.txt", "rb");
    if (archivo != NULL) {
        Habilidad habilidadAux;
        leerHabilidad(habilidadAux, archivo);
        while (!feof(archivo)) {
            IngresarPrimeraHabilidad(lista, habilidadAux);
            leerHabilidad(habilidadAux, archivo);
        }

        fclose(archivo); // cierra el archivo
    }
}
