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

/* ===== artemis.c ===== */
void   inicializarMision(EstadoMision *e);                               /* Joel   */
void   guardarConfiguracion(EstadoMision *e, double v, double h, double m); /* Joel */
void   precargarEventos(Evento eventos[CANT_EVENTOS]);                   /* Joel   */
void   simularTurno(EstadoMision *e, Evento *ev);                        /* Juampi */
void   mostrarEstado(const EstadoMision *e);                             /* Juampi */
int    pedirAccionTurno(void);                                           /* Juampi */
void   aplicarMantenerRumbo(EstadoMision *e, Evento *ev);                /* Juampi */
void   aplicarPropulsorAuxiliar(EstadoMision *e, Evento *ev);            /* Juampi */
void   aplicarAbortar(EstadoMision *e);                                  /* Juampi */
void   registrarHistorial(EstadoMision *e, const char *msg);             /* Joel   */
int    misionSigueActiva(const EstadoMision *e);                         /* Joel   */
void   generarReporte(EstadoMision *e);                                  /* Maxi   */
double calcularEnergiaCinetica(double m, double v);                      /* Maxi   */
double calcularEnergiaPotencial(double m, double r);                     /* Maxi   */
double calcularPuntoEquilibrio(void);                                    /* Maxi   */
double calcularTrabajoRequerido(EstadoMision *e);                        /* Maxi   */
void   imprimirHistorial(const EstadoMision *e);                         /* Maxi   */
void   imprimirReporte(const EstadoMision *e);                           /* Maxi   */
void   imprimirExplicacionFisica(void);                                  /* Joel   */

#endif