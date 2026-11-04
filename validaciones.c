#include <stdio.h>
#include "validaciones.h"

/* Juampi — base para los otros dos lectores, mergear PRIMERO */
void limpiarBufferEntrada(void)
{
    /* TODO(juampi): descartar hasta '\n' o EOF */
}

/* Joel */
int leerEnteroValido(const char *mensaje, int min, int max)
{
    (void)mensaje; (void)min; (void)max;
    return min;   /* stub */
}

/* Maxi */
double leerFlotanteValido(const char *mensaje, double min, double max)
{
    (void)mensaje; (void)min; (void)max;
    return min;   /* stub */
}