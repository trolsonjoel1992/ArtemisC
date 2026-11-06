#include <stdio.h>
#include <stdlib.h>
#include "artemis.h"
#include "validaciones.h"

/* Joel  */
void mostrarMenuPrincipal(void)                  
{
    printf("\n===== SIMULADOR ARTEMIS 3 =====\n");
    printf("1. Configurar mision\n");
    printf("2. Iniciar simulacion TLI\n");
    printf("3. Ver explicacion fisica\n");
    printf("4. Salir\n");
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
    /* TODO(maxi): pedir v, h, m con validaciones y llamar a guardarConfiguracion */
    (void)e;
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
      /* wrapper delgado */
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