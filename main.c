#include <stdio.h>
#include <stdlib.h>
#include "artemis.h"
#include "validaciones.h"

/* Joel  */
void mostrarMenuPrincipal(void)
{
    printf("\n==========================================\n");
    printf("      SIMULADOR ARTEMIS 3 - TLI          \n");
    printf("==========================================\n");
    printf("1. Configurar mision\n");
    printf("2. Iniciar simulacion TLI\n");
    printf("3. Ver explicacion fisica\n");
    printf("4. Salir\n");
    printf("==========================================\n");
}

/* Joel  */
int leerOpcionMenu(void)                         
{
    /* TODO(joel): leerEnteroValido("Opcion", 1, 4) */
    return 4;  /* stub: permite salir del esqueleto */
}
/* Maxi  */
void ejecutarConfiguracion(EstadoMision *e)
{
    double v, h, m;

    printf("\n--- CONFIGURACION DE MISION ---\n");
    
    /* Usa las constantes definidas en artemis.h para los rangos */
    v = leerFlotanteValido("Ingrese Velocidad inicial TLI (1000 a 20000 m/s): ", VEL_MIN, VEL_MAX);
    h = leerFlotanteValido("Ingrese Altitud de orbita baja (160000 a 500000 m): ", ALT_MIN, ALT_MAX);
    m = leerFlotanteValido("Ingrese Masa de la nave (10000 a 50000 kg): ", MASA_MIN, MASA_MAX);

    /* Llama a la función de Joel que guarda los datos y calcula energías iniciales */
    guardarConfiguracion(e, v, h, m);
    
    printf("[OK] Mision configurada correctamente.\n");
}

/* Juampi */
void ejecutarSimulacion(EstadoMision *e)         
{
    /* TODO(juampi): precargarEventos + recorrer 4 turnos con simularTurno */
    (void)e;
}


/* Maxi  */
void mostrarExplicacionFisica(void)
{
    /* Wrapper delgado que llama a la lógica pesada implementada por Joel */
    imprimirExplicacionFisica();
}

/* Joel  */
int main(void)
{
    EstadoMision mision;
    int opcion;

    inicializarMision(&mision);

    do {
        mostrarMenuPrincipal();
        opcion = leerOpcionMenu();

        switch (opcion) {
            case 1: ejecutarConfiguracion(&mision); break;
            case 2: ejecutarSimulacion(&mision);    break;
            case 3: mostrarExplicacionFisica();     break;
            case 4: printf("Saliendo...\n");        break;
            default: printf("[ERROR] Opcion invalida.\n"); break;
        }
    } while (opcion != 4);

    return 0;
}