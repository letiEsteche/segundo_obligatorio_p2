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

void DesplegarTodosLosSocios (ABB a)
{
    if(a!= NULL){
        DesplegarTodosLosSocios(a -> hizq);
        MostrarMago(a->info);
        DesplegarTodosLosSocios(a -> hder);
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

int ContarCantidadDeHadas(ABB a)
{
    if(a == NULL)
        return 0;
    else
        if(a->info.categoria == HADA)
            return 1 + ContarCantidadDeHadas(a->hder) + ContarCantidadDeHadas(a->hizq);
        else
            return ContarCantidadDeHadas(a->hder) + ContarCantidadDeHadas(a->hizq);
}

int ContarCantidadDeHechiceros(ABB a)
{
    if(a == NULL)
        return 0;
    else
        if(a->info.categoria == HECHICERO)
            return 1 + ContarCantidadDeHechiceros(a->hder) + ContarCantidadDeHechiceros(a->hizq);
        else
            return ContarCantidadDeHechiceros(a->hder) + ContarCantidadDeHechiceros(a->hizq);
}

void ContarSociosDeCadaCategoria(ABB a, int &countBrujos, int &countHadas, int &countHechiceros)
{
    if(a != NULL) {
        if (a->info.categoria == HECHICERO) {
            countHechiceros++;
        } else if (a->info.categoria == HADA) { // llamar al las selectora
            countHadas++;
        } else if (a->info.categoria == BRUJO) {
            countBrujos++;
        }

        ContarSociosDeCadaCategoria(a->hizq, countBrujos, countHadas, countHechiceros);
        ContarSociosDeCadaCategoria(a->hder, countBrujos, countHadas, countHechiceros);
    }
}

int ContarCuantosSociosNacieronAntesDeFechaDada(ABB a, Fecha f)
{
    if(a == NULL)
        return 0;
    else{
        if(a->info.nacimiento.anio <= f.anio && a->info.nacimiento.mes <= f.mes && a->info.nacimiento.dia <= f.dia)
            return 1 + ContarCuantosSociosNacieronAntesDeFechaDada(a->hder,f) + ContarCuantosSociosNacieronAntesDeFechaDada(a->hizq,f);
        else
            return ContarCuantosSociosNacieronAntesDeFechaDada(a->hder,f) + ContarCuantosSociosNacieronAntesDeFechaDada(a->hizq,f);
    }
}
