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
    return min;   /* stub */
}

/* Maxi */
double leerFlotanteValido(const char *mensaje, double min, double max)
{
    char buffer[MAX_BUFFER];
    char *endptr;
    double valor;

    while (1) {
        printf("%s", mensaje);
        
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            return min; /* Fallback en caso de EOF */
        }

        /* Limpiar el salto de línea */
        buffer[strcspn(buffer, "\n")] = '\0';

        /* 1. Validar campo vacío */
        if (strlen(buffer) == 0) {
            printf("[ERROR] El campo no puede estar vacio. Intente de nuevo.\n");
            continue;
        }

        /* 2. Convertir a double con strtod */
        errno = 0;
        valor = strtod(buffer, &endptr);

        /* 3. Validar letras mezcladas o falta de números */
        if (endptr == buffer || *endptr != '\0') {
            printf("[ERROR] Entrada invalida. Ingrese solo numeros.\n");
            continue;
        }

        /* 4. Validar el rango permitido */
        if (valor < min || valor > max) {
            printf("[ERROR] Valor fuera de rango. Debe estar entre %.2f y %.2f.\n", min, max);
            continue;
        }

        return valor; /* Entrada válida */
    }
}