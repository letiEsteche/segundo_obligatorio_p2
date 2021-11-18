#include"ABBTodosLosSocios.h"

void Crear (ABB &a)
{
    a = NULL;
}

/* precondición: el la cedula no existía previamente en el ABB */
void InsertarSocio (ABB &a, Mago m)
{
    if (a == NULL)
    {
         a = new NodoSocio;
         a -> info = m;
         a -> hizq = NULL;
         a -> hder = NULL;
    }
    else{
     if (m.cedula < a->info.cedula)
        InsertarSocio (a -> hizq, m);
     else
        InsertarSocio (a -> hder, m);
     }
}

/* saber si un elemento pertenece al ABB, versión recursiva */
boolean ExisteSocio (ABB a, long cedula)
{
    if (a == NULL)
        return FALSE;
    else
        if (a ->info.cedula == cedula)
            return TRUE;
        else
            if (cedula < a ->info.cedula)
                return ExisteSocio (a -> hizq, cedula);
            else
                return ExisteSocio (a -> hder, cedula);
}

void Desplegar (ABB a)
{
    if(a!= NULL){
        Desplegar(a -> hizq);
        printf("%d  ", a -> info);
        Desplegar(a -> hder);
    }
}

int ContarCantidadDeBrujos(ABB a)
{
     if(a == NULL)
        return 0;
    else
        if(a->info.categoria == BRUJO)
            return 1 + ContarCantidadDeBrujos(a->hder) + ContarCantidadDeBrujos(a->hizq);
        else
            return ContarCantidadDeBrujos(a->hder) + ContarCantidadDeBrujos(a->hizq);
}


