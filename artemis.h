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

/* Juampi  */
/* ===== Prototipos de funciones - módulo artemis.c ===== */
/* (Lógica de simulación por turnos, acciones del jugador y estado actual) */

// Orquesta un turno completo: muestra estado, pide acción y la aplica.
void simularTurno(EstadoMision *e, Evento *ev);

// Muestra por pantalla los datos actuales de la nave y el evento actual.
void mostrarEstado(const EstadoMision *e);

// Solicita al usuario la acción a tomar (1 mantener rumbo, 2 propulsor, 3 abortar).
int pedirAccionTurno(void);

// Aplica la acción de mantener rumbo.
void aplicarMantenerRumbo(EstadoMision *e, Evento *ev);

// Aplica la acción de encender el propulsor auxiliar.
void aplicarPropulsorAuxiliar(EstadoMision *e, Evento *ev);

// Aplica la acción de abortar la misión.
void aplicarAbortar(EstadoMision *e);                               

/* ===== Prototipos de funciones - módulo main.c ===== */
/* (Wrapper de simulación) */

// Bucle principal que recorre los eventos y llama a simularTurno.
void ejecutarSimulacion(EstadoMision *e);


#endif