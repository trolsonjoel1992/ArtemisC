#ifndef ARTEMIS_H
#define ARTEMIS_H

/* ===== Constantes físicas ===== */
#define G              6.674e-11
#define M_TIERRA       5.972e24
#define R_TIERRA       6.371e6
#define M_LUNA         7.348e22
#define D_TIERRA_LUNA  3.844e8
#define H_LEO          192000.0
#define V_TLI          10900.0

/* ===== Constantes del simulador ===== */
#define CANT_EVENTOS   4
#define MAX_HISTORIAL  10
#define LARGO_MSG      100

#define VEL_MIN   1000.0
#define VEL_MAX   20000.0
#define ALT_MIN   160000.0
#define ALT_MAX   500000.0
#define MASA_MIN  10000.0
#define MASA_MAX  50000.0

/* ===== Structs ===== */
typedef struct {
    double velocidad;
    double altura;
    double masa;
    double combustible;
    double energia_inicial;
    double trabajo_requerido;
    int    fase_actual;
    int    cant_historial;                    /* necesario para saber dónde escribir */
    char   historial[MAX_HISTORIAL][LARGO_MSG];
} EstadoMision;

typedef struct {
    int    id;
    char   nombre[40];
    double costo_combustible;
} Evento;

/* Maxi  */
/* ===== Prototipos de funciones - módulo artemis.c ===== */
/* (Cálculos físicos, reportes y matemática del escenario) */

// Genera el reporte final paso a paso (energías, trabajo, estado final).
void generarReporte(EstadoMision *e);

// Calcula la energía cinética: K = 0.5 * m * v^2
double calcularEnergiaCinetica(double m, double v);

// Calcula la energía potencial gravitatoria: U = -G * M * m / r
double calcularEnergiaPotencial(double m, double r);

// Calcula el punto de equilibrio gravitatorio Tierra-Luna (r_eq).
double calcularPuntoEquilibrio(void);

// Calcula el trabajo externo requerido por unidad de masa (W_ext/m).
double calcularTrabajoRequerido(EstadoMision *e);

// Imprime el historial de eventos de la misión.
void imprimirHistorial(const EstadoMision *e);

// Imprime el reporte en formato legible para el usuario.
void imprimirReporte(const EstadoMision *e);

/* ===== Prototipos de funciones - módulo main.c ===== */
/* (Wrappers de configuración y explicación) */

// Pide los datos de la misión al usuario y los guarda en el estado.
void ejecutarConfiguracion(EstadoMision *e);

// Wrapper que llama a la función de explicación física de artemis.c
void mostrarExplicacionFisica(void);

#endif