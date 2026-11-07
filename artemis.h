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
    int    cant_historial;
    char   historial[MAX_HISTORIAL][LARGO_MSG];
} EstadoMision;

typedef struct {
    int    id;
    char   nombre[40];
    double costo_combustible;
} Evento;

/* Joel */
void inicializarMision(EstadoMision *e);
void guardarConfiguracion(EstadoMision *e, double v, double h, double m);
void precargarEventos(Evento eventos[CANT_EVENTOS]);
void registrarHistorial(EstadoMision *e, const char *msg);
int misionSigueActiva(const EstadoMision *e);
void imprimirExplicacionFisica(void);

/* Maxi */
void generarReporte(EstadoMision *e);
double calcularEnergiaCinetica(double m, double v);
double calcularEnergiaPotencial(double m, double r);
double calcularPuntoEquilibrio(void);
double calcularTrabajoRequerido(EstadoMision *e);
void imprimirHistorial(const EstadoMision *e);
void imprimirReporte(const EstadoMision *e);

/* Juampi */
void simularTurno(EstadoMision *e, Evento *ev);
void mostrarEstado(const EstadoMision *e);
int pedirAccionTurno(void);
void aplicarMantenerRumbo(EstadoMision *e, Evento *ev);
void aplicarPropulsorAuxiliar(EstadoMision *e, Evento *ev);
void aplicarAbortar(EstadoMision *e);

/* main.c */
void mostrarMenuPrincipal(void);
int leerOpcionMenu(void);
void ejecutarConfiguracion(EstadoMision *e);
void ejecutarSimulacion(EstadoMision *e);
void mostrarExplicacionFisica(void);

#endif
