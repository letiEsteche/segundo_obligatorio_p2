#include "ABBTodosLosSocios.h"

void Crear(ABB &a) {
    a = NULL;
}

/* precondici�n: el la cedula no exist�a previamente en el ABB */
void InsertarSocio(ABB &a, Mago m) {
    if (a == NULL) {
        a = new NodoSocio;
        a->info = m;
        a->hizq = NULL;
        a->hder = NULL;
    } else {
        if (m.cedula < a->info.cedula)
            InsertarSocio(a->hizq, m);
        else
            InsertarSocio(a->hder, m);
    }
}

/* saber si un elemento pertenece al ABB, versi�n recursiva */
boolean ExisteSocio(ABB a, long cedula) {
    if (a == NULL)
        return FALSE;
    else if (a->info.cedula == cedula)
        return TRUE;
    else if (cedula < a->info.cedula)
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
        if (validarFecha(f))
            return 1 + ContarCuantosSociosNacieronAntesDeFechaDada(a->hder, f) + ContarCuantosSociosNacieronAntesDeFechaDada(a->hizq, f);
        else
            return ContarCuantosSociosNacieronAntesDeFechaDada(a->hder, f) + ContarCuantosSociosNacieronAntesDeFechaDada(a->hizq, f);
    }
}


void ListarTodosLosSociosSinHabilidades(ABB a, Lista L)
{
    if(a != NULL)
        if(TieneAlgunaHabilidad( L, a->info.cedula)==FALSE){
            MostrarMago(a->info);
            ListarTodosLosSociosSinHabilidades(a->hder, L);
            ListarTodosLosSociosSinHabilidades(a->hizq, L);
    }else{
        ListarTodosLosSociosSinHabilidades(a->hder, L);
        ListarTodosLosSociosSinHabilidades(a->hizq, L);
    }
}

void ListarSocioConMasHabilidades(ABB a)
{



}

