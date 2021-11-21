#include "ListaHabilidadesDeSocio.h"

void Crear(Lista &L)
{
    L = NULL;
}

/*void IngresarHabilidadA(Lista &l, )
{
    if(ExisteSocio(a, DarCedulaHabilidad(h))){


    }else{
        printf("La cedula ingresada en la habilidad no se encuentra en el sistema");
    }


}

*/
boolean TieneAlgunaHabilidad(Lista L, TipoHabilidad t)
{
    boolean cedulaTieneHabilidad = FALSE;
    if((L->info.tipo == 'NATURAL') || (L->info.tipo == 'POCONATURAL') || (L->info.tipo == 'SOBRENATURAL')){
        cedulaTieneHabilidad = TRUE;
    }
    return cedulaTieneHabilidad;
}


Fecha FechaDeUltimaHabilidadRegistradaPorUnSocio(Lista L)
{
    while(L->sig != NULL){
        L = L->sig;
    }

    return L->info.ManifestacionHabilidad;
}

int ContarHabilidadesEntreDosFechasIngresadas(Lista L, TipoHabilidad t)
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

boolean Vacio(Lista L)
{
    boolean es = FALSE;
    if(L == NULL)
        es = TRUE;
    return es;
}




