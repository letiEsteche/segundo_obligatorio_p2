#include "ListaHabilidadesDeSocio.h"

void Crear(Lista &L)
{
    L = NULL;
}


boolean TieneAlgunaHabilidad(Lista L, long cedula)
{
    boolean cedulaTieneHabilidad = FALSE;
    while(L != NULL)
        if(L->info.cedula == cedula)
            cedulaTieneHabilidad = TRUE;

    return cedulaTieneHabilidad;
}


Fecha FechaDeUltimaHabilidadRegistradaPorUnSocio(Lista L, long cedula)
{
    Fecha aux;
    boolean encontre = FALSE;
    while(L != NULL && !encontre){
        if(L->info.cedula == cedula){
             aux = L->info.ManifestacionHabilidad;
             encontre == TRUE;
        }
    }
    return aux;
}

/*int ContarHabilidadesEntreDosFechasIngresadas(Lista L, TipoHabilidad t)
{
    Fecha f, h;
    if(t == NULL)
        return 0;
    else{
        if(ValidarPrimeraFechaSeaMenorALaSegunda(f, h)){
            if(L->info.tipo == 'NATURAL' || L->info.tipo == 'POCONATURAL' || L->info.tipo == 'SOBRENATURAL')
                return 1 + ContarHabilidadesEntreDosFechasIngresadas(L->sig, t);

            }else
                return ContarHabilidadesEntreDosFechasIngresadas(L->sig, t);
    }
}
*/
boolean Vacio(Lista L)
{
    boolean es = FALSE;
    if(L == NULL)
        es = TRUE;
    return es;
}
void IngrearPrimeraHabilidad(Lista &L, Habilidad h)
{

}

void IngresarHabilidad(Lista &L ,Habilidad h)
{
        if(L == NULL){//no hay ninguna habilidad en la lista
            Lista aux= new NodoHabilidad;
            aux->info = h;
            aux->sig = NULL;
            L = aux;

        }else{
            while(L ->sig == NULL){//existe al menos una habilidad del socio
                    Lista aux = new NodoHabilidad;
                    aux->info = h;
                    aux->sig = L;
                    L = aux;

            L = L->sig;}
        }
}

void MostrarTodasLasHabilidades(Lista L)
{
    while(L!=NULL)
    {
        MostrarHabilidad(L->info);
        L = L->sig;
    }
}
