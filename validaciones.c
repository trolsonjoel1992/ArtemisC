#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "validaciones.h"

#define MAX_BUFFER 100


/* Juampi */
void limpiarBufferEntrada(void)
{
    
}

/* Joel */
int leerEnteroValido(const char *mensaje, int min, int max)
{
    (void)mensaje; (void)min; (void)max;
    return min;   
}

/* Maxi */
double leerFlotanteValido(const char *mensaje, double min, double max)
{
    (void)mensaje; (void)min; (void)max;
    return min;  
}