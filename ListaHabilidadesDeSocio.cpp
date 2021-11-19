#include "ListaHabilidadesDeSocio.h"

void Crear(Lista &L)
{
    L = NULL;
}

void IngresarHabilidad(Lista &L, Habilidad h)
{
    if(ExisteSocio){
        if(TieneAlgunaHabilidad(h.tipo)){
                CargarHabilidad(h);
            }
        }else{
            CargarHabilidad(h);
        }
}

boolean TieneAlgunaHabilidad(Lista L, TipoHabilidad t)
{
    boolean cedulaTieneHabilidad = FALSE;
    if(L->info.tipo == 'NATURAL' || L->info.tipo == 'POCONATURAL' || L->info.tipo == 'SOBRENATURAL')
        cedulaTieneHabilidad = TRUE;
    return cedulaTieneHabilidad;

}

void FechaDeUltimaHabilidadRegistradaPorUnSocio(long cedula)
{

}

int ContarHabilidadesEntreDosFechasIngresadas(Lista L, TipoHabilidad t)
{
    if(t == NULL)
        return 0;
    else{
        if(L->info.tipo == 'NATURAL' || L->info.tipo == 'POCONATURAL' || L->info.tipo == 'SOBRENATURAL')
            return 1 + ContarHabilidadesEntreDosFechasIngresadas(L->sig, t);
        else
            return ContarHabilidadesEntreDosFechasIngresadas(L->sig, t);
            }
}

boolean Vacio(Lista L)
{
    boolean es = FALSE;
    if(L == NULL)
        es = TRUE;
    return es;
}




