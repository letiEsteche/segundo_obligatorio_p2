#include "ABBTodosLosSocios.h"

void Crear(ABB &a) {
    a = NULL;
}

/* precondicion: el la cedula no existia previamente en el ABB */
void InsertarSocio(ABB &a, Mago m) {
    if (a == NULL) {
        a = new NodoSocio;
        a->info = m;
        a->hizq = NULL;
        a->hder = NULL;
    } else {
        if (DarCedula(m) < DarCedula(a->info))
            InsertarSocio(a->hizq, m);
        else
            InsertarSocio(a->hder, m);
    }
}

/* saber si un elemento pertenece al ABB, version recursiva */
boolean ExisteSocio(ABB a, long cedula) {
    if (a == NULL)
        return FALSE;
    else if (DarCedula(a->info) == cedula)
        return TRUE;
    else if (cedula < DarCedula(a->info))
        return ExisteSocio(a->hizq, cedula);
    else
        return ExisteSocio(a->hder, cedula);
}

void DesplegarTodosLosSocios(ABB a) {
    if (a != NULL) {
        DesplegarTodosLosSocios(a->hizq);
        MostrarMago(a->info);
        DesplegarTodosLosSocios(a->hder);
    }
}

void ContarSociosDeCadaCategoria(ABB a, int &countBrujos, int &countHadas, int &countHechiceros) {
    if (a != NULL) {
        if (DarCategroriaMago(a->info) == HECHICERO) {
            countHechiceros++;
        } else if (DarCategroriaMago(a->info) == HADA) {
            countHadas++;
        } else if (DarCategroriaMago(a->info) == BRUJO) {
            countBrujos++;
        }

        ContarSociosDeCadaCategoria(a->hizq, countBrujos, countHadas, countHechiceros);
        ContarSociosDeCadaCategoria(a->hder, countBrujos, countHadas, countHechiceros);
    }
}

int ContarCuantosSociosNacieronAntesDeFechaDada(ABB a, Fecha f)
{
    if (a == NULL)
        return 0;
    else {
        if (f.dia < a->info.nacimiento.dia && f.mes < a->info.nacimiento.mes &&
            f.anio < a->info.nacimiento.anio)
            return 1 + ContarCuantosSociosNacieronAntesDeFechaDada(a->hder, f) + ContarCuantosSociosNacieronAntesDeFechaDada(a->hizq, f);
        else
            return ContarCuantosSociosNacieronAntesDeFechaDada(a->hder, f) + ContarCuantosSociosNacieronAntesDeFechaDada(a->hizq, f);
    }
}


void ListarTodosLosSociosSinHabilidades(ABB a, Lista L)
{
    if(a != NULL){
            ListarTodosLosSociosSinHabilidades(a->hizq, L);
        if(TieneAlgunaHabilidad(L, DarCedula(a->info)== FALSE)){
            MostrarMago(a->info);
        }
        ListarTodosLosSociosSinHabilidades(a->hder, L);

    }
}

//precondicion cantMax inicia con la raiz del arbol
void ListarSocioConMasHabilidades(ABB a, Lista L, Mago &masPoderoso, int &cantMax)
{
    if(a !=NULL){
        int aux = CantidadDeHabilidadesPorCedula(L, a->info.cedula);
        if(aux > cantMax){
            cantMax = aux;
            masPoderoso = a->info;
        }
        ListarSocioConMasHabilidades(a->hizq,L,masPoderoso, cantMax);
        ListarSocioConMasHabilidades(a->hder,L,masPoderoso, cantMax);

    }
}

void escribirArbolSocios(ABB arbol, FILE *archivo) {
    if (arbol != NULL) {
        escribirMago(arbol->info, archivo);
        escribirArbolSocios(arbol->hizq, archivo);
        escribirArbolSocios(arbol->hder, archivo);
    }
}

void leerArbolSocios(ABB &arbol) {
    Crear(arbol);
    FILE * archivo = fopen("Socios.txt", "rb");
    if (archivo != NULL) {
        Mago magoAux;
        leerMago(magoAux, archivo);
        while (!feof(archivo)) {
            InsertarSocio(arbol, magoAux);
            leerMago(magoAux, archivo);
        }
        fclose(archivo);
    }
}


