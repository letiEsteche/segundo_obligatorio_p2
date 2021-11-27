#include "Mago.h"

void CargarMago(Mago &m)
{
    printf("\nIngrese cedula de Mago: ");
    scanf("%ld", &m.cedula);
    strcrear(m.nombre);
    printf("\nIngrese el nombre del Mago: ");
    scan(m.nombre);
    printf("\nIngrese la fecha de nacimiento del Mago ");
    cargarFecha(m.nacimiento);
    strcrear(m.DimensionOrigen);
    printf("\nIngrese la dimension de origen del Mago: ");
    scan(m.DimensionOrigen);
    printf("\nIngrese la categoria del Mago: ");
    CargarCategoriaMago(m.categoria);

}

void MostrarMago(Mago m)
{
    printf("\nCedula: %ld | ", m.cedula);
    printf("Nombre: ");
    print(m.nombre);
    printf("| Fecha de nacimiento: ");
    mostrarFecha(m.nacimiento);
    printf(" | Dimension de origen: ");
    print(m.DimensionOrigen);
    printf(" | Categoria: ");
    MostrarCategoriaMago(m.categoria);

}

string DarNombre(Mago m)
{
    return m.nombre;
}

long DarCedula(Mago m)
{
    return m.cedula;
}

Fecha DarFecha(Mago m)
{
    return m.nacimiento;
}

string DarDimensionOrigen(Mago m)
{
    return m.DimensionOrigen;
}

CategoriaMago DarCategroriaMago (Mago m)
{
    return m.categoria;
}

void escribirMago(Mago mago, FILE *archivo) {
    escribirString(mago.nombre, archivo);

    fwrite(&mago.cedula, sizeof(long), 1, archivo);

    fwrite(&mago.nacimiento, sizeof(Fecha), 1, archivo);

    escribirString(mago.DimensionOrigen, archivo);

    fwrite(&mago.categoria, sizeof(CategoriaMago), 1, archivo);
}

void leerMago(Mago &mago, FILE *archivo) {
    strcrear(mago.nombre);
    leerString(mago.nombre, archivo);

    fread(&mago.cedula, sizeof(long), 1, archivo);

    fread(&mago.nacimiento, sizeof(Fecha), 1, archivo);

    strcrear(mago.DimensionOrigen);
    leerString(mago.DimensionOrigen, archivo);

    fread(&mago.categoria, sizeof(CategoriaMago), 1, archivo);
}
