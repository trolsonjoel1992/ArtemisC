#include <stdio.h>
#include <string.h>
#include <math.h>
#include "artemis.h"
#include "validaciones.h"

/* Joel  */
void inicializarMision(EstadoMision *e)
{
    /* TODO(joel): ceros + fase 0 */
    (void)e;
}

void guardarConfiguracion(EstadoMision *e, double v, double h, double m)
{
    /* TODO(joel): asignar y calcular energia_inicial / trabajo_requerido */
    (void)e; (void)v; (void)h; (void)m;
}

void precargarEventos(Evento eventos[CANT_EVENTOS])
{
    /* TODO(joel): 4 eventos con id, nombre y costo_combustible */
    (void)eventos;
}

void registrarHistorial(EstadoMision *e, const char *msg)
{
    /* TODO(joel): copiar msg respetando MAX_HISTORIAL y LARGO_MSG */
    (void)e; (void)msg;
}

int misionSigueActiva(const EstadoMision *e)
{
    /* TODO(joel) */
    (void)e;
    return 1; /* stub */
}

void imprimirExplicacionFisica(void)
{
    /* TODO(joel) */
}

/* Maxi  */

double calcularEnergiaCinetica(double m, double v)
{
    /* K = 0.5 * m * v^2 */
    return 0.5 * m * v * v;
}

double calcularEnergiaPotencial(double m, double r)
{
    /* U = -G * M_TIERRA * m / r */
    return -G * M_TIERRA * m / r;
}

double calcularPuntoEquilibrio(void)
{
    /* r_eq = D / (1 + sqrt(M_LUNA / M_TIERRA)) */
    return D_TIERRA_LUNA / (1.0 + sqrt(M_LUNA / M_TIERRA));
}

double calcularTrabajoRequerido(EstadoMision *e)
{
    double K    = calcularEnergiaCinetica(e->masa, e->velocidad);
    double r_i  = R_TIERRA + e->altura;
    double U_i  = calcularEnergiaPotencial(e->masa, r_i);
    double r_eq = calcularPuntoEquilibrio();
    
    /* Energía potencial en el punto de equilibrio (suma Tierra + Luna) */
    double U_eq = (-G * M_TIERRA * e->masa / r_eq) 
                - (G * M_LUNA   * e->masa / (D_TIERRA_LUNA - r_eq));

    /* W_ext por unidad de masa = (U_eq - (U_i + K)) / m */
    return (U_eq - (U_i + K)) / e->masa;
}

void generarReporte(EstadoMision *e)
{
    registrarHistorial(e, "Simulacion finalizada. Generando reporte.");
    imprimirReporte(e);
    imprimirHistorial(e);
}

void imprimirHistorial(const EstadoMision *e)
{
    printf("\n--- HISTORIAL DE LA MISION ---\n");
    if (e->cant_historial == 0) {
        printf("  (Sin eventos registrados)\n");
        return;
    }
    for (int i = 0; i < e->cant_historial; i++) {
        printf("  [%02d] %s\n", i + 1, e->historial[i]);
    }
}

void imprimirReporte(const EstadoMision *e)
{
    double K    = calcularEnergiaCinetica(e->masa, e->velocidad);
    double r_i  = R_TIERRA + e->altura;
    double U_i  = calcularEnergiaPotencial(e->masa, r_i);
    double r_eq = calcularPuntoEquilibrio();
    double U_eq = (-G * M_TIERRA * e->masa / r_eq) 
                - (G * M_LUNA   * e->masa / (D_TIERRA_LUNA - r_eq));
    double W_ext_total = U_eq - (U_i + K);
    double W_ext_por_masa = W_ext_total / e->masa;

    printf("\n==========================================\n");
    printf("      REPORTE FINAL DE DESEMPENO          \n");
    printf("==========================================\n");
    printf("  Masa de la nave        : %.2f kg\n", e->masa);
    printf("  Velocidad inicial TLI  : %.2f m/s\n", e->velocidad);
    printf("  Altitud inicial        : %.2f m\n", e->altura);
    printf("  Combustible restante   : %.2f kg\n", e->combustible);
    printf("  Estado de la mision    : %s\n", 
           (e->fase_actual == 99) ? "ABORTADA" : "COMPLETADA");

    printf("\n--- CALCULO PASO A PASO ---\n");
    printf("  1. K (E. Cinetica)     : %.6e J\n", K);
    printf("  2. U_i (E. Pot. LEO)   : %.6e J\n", U_i);
    printf("  3. r_eq (Punto equil.) : %.6e m\n", r_eq);
    printf("  4. U_eq (E. Pot. equil.): %.6e J\n", U_eq);
    printf("  5. W_ext total         : %.6e J\n", W_ext_total);
    printf("  6. W_ext / m           : %.6e J/kg\n", W_ext_por_masa);
    printf("==========================================\n\n");
}

/* Juampi  */
void simularTurno(EstadoMision *e, Evento *ev)
{
    /* TODO(juampi): mostrar estado, pedir acción, despachar, registrar */
    (void)e; (void)ev;
}

void mostrarEstado(const EstadoMision *e)
{
    /* TODO(juampi) */
    (void)e;
}

int pedirAccionTurno(void)
{
    /* TODO(juampi): 1 mantener rumbo / 2 propulsor / 3 abortar (usar validaciones) */
    return 1; /* stub */
}

void aplicarMantenerRumbo(EstadoMision *e, Evento *ev)
{
    /* TODO(juampi) */
    (void)e; (void)ev;
}

void aplicarPropulsorAuxiliar(EstadoMision *e, Evento *ev)
{
    /* TODO(juampi) */
    (void)e; (void)ev;
}

void aplicarAbortar(EstadoMision *e)
{
    /* TODO(juampi) */
    (void)e;
}