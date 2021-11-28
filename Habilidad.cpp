#include "Habilidad.h"

void CargarHabilidad(Habilidad &h) {
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

void MostrarHabilidad(Habilidad h) {
    printf("\nNombre: ");
    print(h.nombreHabilidad);
    printf(" | Fecha de manifestacion: ");
    mostrarFecha(h.ManifestacionHabilidad);
    printf(" | Cedula: %ld | ", h.cedula);
    printf("Tipo habilidad: ");
    MostrarTipoDeHabilidadMago(h.tipo);
}

string DarNombreHabilidad(Habilidad h) {
    return h.nombreHabilidad;
}

Fecha DarFechaDeManifestacionHabilidad(Habilidad h) {
    return h.ManifestacionHabilidad;
}

long DarCedulaHabilidad(Habilidad h) {
    return h.cedula;
}

TipoHabilidad DarTipoDeHabilidad(Habilidad h) {
    return h.tipo;
}

void escribirHabilidad(Habilidad habilidad, FILE *archivo) {
    escribirString(habilidad.nombreHabilidad, archivo);
    fwrite(&habilidad.ManifestacionHabilidad, sizeof(Fecha), 1, archivo);
    fwrite(&habilidad.cedula, sizeof(long), 1, archivo);
    fwrite(&habilidad.tipo, sizeof(TipoHabilidad), 1, archivo);
}

void leerHabilidad(Habilidad &habilidad, FILE *archivo) {
    strcrear(habilidad.nombreHabilidad);
    leerString(habilidad.nombreHabilidad, archivo);
    fread(&habilidad.ManifestacionHabilidad, sizeof(Fecha), 1, archivo);
    fread(&habilidad.cedula, sizeof(long), 1, archivo);
    fread(&habilidad.tipo, sizeof(TipoHabilidad), 1, archivo);
}
