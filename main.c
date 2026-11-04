#include <stdio.h>
#include "artemis.h"
#include "validaciones.h"

void mostrarMenuPrincipal(void)                  /* Joel  */
{
    printf("\n===== SIMULADOR ARTEMIS 3 =====\n");
    printf("1. Configurar mision\n");
    printf("2. Iniciar simulacion TLI\n");
    printf("3. Ver explicacion fisica\n");
    printf("4. Salir\n");
}

int leerOpcionMenu(void)                         /* Joel  */
{
    /* TODO(joel): leerEnteroValido("Opcion", 1, 4) */
    return 4;  /* stub: permite salir del esqueleto */
}

void ejecutarConfiguracion(EstadoMision *e)      /* Maxi  */
{
    /* TODO(maxi): pedir v, h, m con validaciones y llamar a guardarConfiguracion */
    (void)e;
}

void ejecutarSimulacion(EstadoMision *e)         /* Juampi */
{
    /* TODO(juampi): precargarEventos + recorrer 4 turnos con simularTurno */
    (void)e;
}

void mostrarExplicacionFisica(void)              /* Maxi  */
{
    imprimirExplicacionFisica();  /* wrapper delgado */
}

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