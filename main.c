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
    Evento eventos[CANT_EVENTOS];
    int i;

    /* Verificación de seguridad: si la masa es 0, no se configuró nada */
    if (e->masa == 0.0) {
        printf("[ERROR] Debe configurar la mision antes de simular.\n");
        return;
    }

    printf("\n--- INICIANDO SIMULACION TLI ---\n");
    
    /* Precarga los 4 eventos (Funcion de Joel) */
    precargarEventos(eventos);

    /* Bucle de simulación por turnos */
    for (i = 0; i < CANT_EVENTOS; i++) {
        /* Si la mision se abortó en el turno anterior, corta el bucle */
        if (!misionSigueActiva(e)) {
            break;
        }
        
        /* Ejecuta el turno actual */
        simularTurno(e, &eventos[i]);
    }

    /* Al finalizar (por éxito o aborto), genera el reporte (Funcion de Maxi) */
    generarReporte(e);
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