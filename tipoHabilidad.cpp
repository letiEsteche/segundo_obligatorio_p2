#include"tipoHabilidad.h"

void CargarTipoDeHabilidadMago(TipoHabilidad &c) {
    int opcion;
    do {
        printf("\nA continuacion se selecciona la habilidad del Mago...");
        printf("\n1- NATURAL");
        printf("\n2- POCONATURAL");
        printf("\n3- SOBRENATURAL");
        printf("\nElija una opcion:");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                c = NATURAL;
                break;
            case 2:
                c = POCONATURAL;
                break;
            case 3:
                c = SOBRENATURAL;
                break;
            default:
                printf("\nLa opcion seleccionada es incorrecta, vuelva a intentarlo...");

        }
    } while (!(opcion >= 1 && opcion <= 3));
}

void MostrarTipoDeHabilidadMago(TipoHabilidad c) {
    switch (c) {
        case NATURAL:
            printf("Habilidad natural");
            break;
        case POCONATURAL:
            printf("Habilidad poconatural");
            break;
        case SOBRENATURAL:
            printf("Habilidad sobrenatural");
            break;
    }
}

int ContarTipoDeHabilidades(TipoHabilidad c, int contarNatural, int contarSobrenatural, int contarPoconatural) {
    contarNatural = 0, contarSobrenatural = 0, contarPoconatural = 0;
    if (c == 'NATURAL')
        contarNatural++;
    else if (c == 'SOBRENATURAL')
        contarSobrenatural++;
    else if (c == 'POCONATURAL')
        contarPoconatural++;
}
