#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "validaciones.h"

#define MAX_BUFFER 100

/* Juampi */
void limpiarBufferEntrada(void)
{
<<<<<<< HEAD
    int c;
    /* Lee y descarta caracteres hasta encontrar un salto de línea o el final del archivo */
    while ((c = getchar()) != '\n' && c != EOF) {
        /* No hace nada, solo consume los caracteres */
    }
=======
    
>>>>>>> 195dc7485f90a0dcce101b3ff91c3a05f5fb3888
}

/* Joel */
int leerEnteroValido(const char *mensaje, int min, int max)
{
    char buffer[MAX_BUFFER];
    char *endptr;
    long valor;

    while (1) {
        printf("%s", mensaje);
        
        /* Leer usando fgets (seguro) */
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            /* Si hay un error de lectura (EOF), devolvemos el mínimo para no colgar el programa */
            return min; 
        }

        /* Limpiar el salto de línea que agrega fgets al final */
        buffer[strcspn(buffer, "\n")] = '\0';

        /* 1. Validar campo vacío (el usuario solo presionó Enter) */
        if (strlen(buffer) == 0) {
            printf("[ERROR] El campo no puede estar vacio. Intente de nuevo.\n");
            continue;
        }

        /* 2. Convertir a entero con strtol */
        errno = 0;
        valor = strtol(buffer, &endptr, 10);

        /* 3. Validar si hubo error en la conversión (letras mezcladas) */
        if (endptr == buffer || *endptr != '\0') {
            printf("[ERROR] Entrada invalida. Ingrese solo numeros enteros.\n");
            continue;
        }

        /* 4. Validar que no haya desbordado el rango de un int */
        if (errno == ERANGE) {
            printf("[ERROR] El numero es demasiado grande.\n");
            continue;
        }

        /* 5. Validar el rango permitido */
        if (valor < min || valor > max) {
            printf("[ERROR] Valor fuera de rango. Debe estar entre %d y %d.\n", min, max);
            continue;
        }

        return (int)valor; /* Entrada válida */
    }
}

/* Maxi */
double leerFlotanteValido(const char *mensaje, double min, double max)
{
    (void)mensaje; (void)min; (void)max;
    return min;   /* stub */
}
