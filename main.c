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
    /* Reutiliza la función de validación segura para evitar letras o fuera de rango */
    return leerEnteroValido("Seleccione una opcion (1-4): ", 1, 4);
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

    /* Inicializa todos los campos del struct en 0 */
    inicializarMision(&mision);

    do {
        mostrarMenuPrincipal();
        opcion = leerOpcionMenu();

        switch (opcion) {
            case 1:
                ejecutarConfiguracion(&mision);
                break;
            case 2:
                ejecutarSimulacion(&mision);
                break;
            case 3:
                mostrarExplicacionFisica();
                break;
            case 4:
                printf("\nSaliendo del simulador...\n");
                break;
            default:
                /* Inalcanzable gracias a leerEnteroValido, pero se mantiene por buenas prácticas */
                printf("[ERROR] Opcion invalida.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}