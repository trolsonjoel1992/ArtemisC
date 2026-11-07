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

/* Joel  */
/* ===== Prototipos de funciones - módulo artemis.c ===== */
/* (Gestión de estado, historial, inicialización y explicación teórica) */

// Inicializa todos los campos del estado en 0.
void inicializarMision(EstadoMision *e);

// Asigna los valores validados a la estructura y calcula las energías iniciales.
void guardarConfiguracion(EstadoMision *e, double v, double h, double m);

// Llena el arreglo de eventos con los 4 eventos predefinidos de la misión.
void precargarEventos(Evento eventos[CANT_EVENTOS]);

// Guarda un mensaje en el historial de la misión, respetando el límite.
void registrarHistorial(EstadoMision *e, const char *msg);

// Devuelve 1 si la misión sigue activa, 0 si fue abortada o terminó.
int misionSigueActiva(const EstadoMision *e);

// Imprime el texto de la explicación física (cubre las preguntas a y d del TFI).
void imprimirExplicacionFisica(void);

/* ===== Prototipos de funciones - módulo main.c ===== */
/* (Menú principal y navegación base) */

// Imprime en pantalla las opciones del menú principal.
void mostrarMenuPrincipal(void);

// Lee y valida la opción elegida del menú.
int leerOpcionMenu(void);

#endif