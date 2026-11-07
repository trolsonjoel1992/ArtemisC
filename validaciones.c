#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "validaciones.h"

#define MAX_BUFFER 100

/* Juampi */
void limpiarBufferEntrada(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* descarta */
    }
}

/* Helper interno: lee una línea y limpia el buffer si fue demasiado larga */
static int leerLinea(char *buffer, int tam)
{
    if (fgets(buffer, tam, stdin) == NULL) {
        return 0;
    }

    if (strchr(buffer, '\n') == NULL) {
        limpiarBufferEntrada();
    } else {
        buffer[strcspn(buffer, "\n")] = '\0';
    }

    return 1;
}

/* Joel */
int leerEnteroValido(const char *mensaje, int min, int max)
{
    char buffer[MAX_BUFFER];
    char *endptr;
    long valor;

    while (1) {
        printf("%s", mensaje);

        if (!leerLinea(buffer, sizeof(buffer))) {
            return min; /* EOF: evita bucle infinito */
        }

        if (strlen(buffer) == 0) {
            printf("[ERROR] El campo no puede estar vacio. Intente de nuevo.\n");
            continue;
        }

        errno = 0;
        valor = strtol(buffer, &endptr, 10);

        if (endptr == buffer || *endptr != '\0') {
            printf("[ERROR] Entrada invalida. Ingrese solo numeros enteros.\n");
            continue;
        }

        if (errno == ERANGE) {
            printf("[ERROR] El numero es demasiado grande.\n");
            continue;
        }

        if (valor < min || valor > max) {
            printf("[ERROR] Valor fuera de rango. Debe estar entre %d y %d.\n", min, max);
            continue;
        }

        return (int)valor;
    }
}

/* Maxi */
double leerFlotanteValido(const char *mensaje, double min, double max)
{
    char buffer[MAX_BUFFER];
    char *endptr;
    double valor;

    while (1) {
        printf("%s", mensaje);

        if (!leerLinea(buffer, sizeof(buffer))) {
            return min; /* EOF: evita bucle infinito */
        }

        if (strlen(buffer) == 0) {
            printf("[ERROR] El campo no puede estar vacio. Intente de nuevo.\n");
            continue;
        }

        errno = 0;
        valor = strtod(buffer, &endptr);

        if (endptr == buffer || *endptr != '\0') {
            printf("[ERROR] Entrada invalida. Ingrese solo numeros.\n");
            continue;
        }

        if (errno == ERANGE || !isfinite(valor)) {
            printf("[ERROR] Numero fuera del rango representable.\n");
            continue;
        }

        if (valor < min || valor > max) {
            printf("[ERROR] Valor fuera de rango. Debe estar entre %.2f y %.2f.\n", min, max);
            continue;
        }

        return valor;
    }
}