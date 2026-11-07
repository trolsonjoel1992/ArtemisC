#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "validaciones.h"

#define MAX_BUFFER 100

/* Juampi */
void limpiarBufferEntrada(void)
{
    int c;
    /* Lee y descarta caracteres hasta encontrar un salto de línea o el final del archivo */
    while ((c = getchar()) != '\n' && c != EOF) {
        /* No hace nada, solo consume los caracteres */
    }
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