#include "Habilidad.h"

void CargarHabilidad(Habilidad &h)
{
    strcrear(h.nombreHabilidad);
    printf("\nIngrese el nombre de la habilidad: ");
    scan(h.nombreHabilidad);
    printf("\nIngrese fecha de manifestacion ");
    cargarFecha(h.ManifestacionHabilidad);
    printf("\nIngrese cedula de mago que tiene habilidad: ");
    scanf("%ld", &h.cedula);
    printf("\nIngrese tipo habilidad de mago: ");
    CargarTipoDeHabilidadMago(h.tipo);

}

void MostrarHabilidad(Habilidad h)
{
    printf("\nNombre de la habilidad: ");
    print(h.nombreHabilidad);
    printf(" | Fecha de manifestacion: ");
    mostrarFecha(h.ManifestacionHabilidad);
    printf(" | Cedula de mago que tiene habilidad: %ld | ", h.cedula);
    printf("Tipo habilidad de mago: ");
    MostrarTipoDeHabilidadMago(h.tipo);
}



string DarNombreHabilidad(Habilidad h)
{
    return h.nombreHabilidad;
}

Fecha DarFechaDeManifestacionHabilidad(Habilidad h)
{
    return h.ManifestacionHabilidad;
}

long DarCedulaHabilidad(Habilidad h)
{
    return h.cedula;
}

TipoHabilidad DarTipoDeHabilidad(Habilidad h)
{
    return h.tipo;
}
