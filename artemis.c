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
void generarReporte(EstadoMision *e)
{
    /* TODO(maxi) */
    (void)e;
}

double calcularEnergiaCinetica(double m, double v)
{
    /* TODO(maxi): 0.5*m*v*v */
    (void)m; (void)v;
    return 0.0;
}

double calcularEnergiaPotencial(double m, double r)
{
    /* TODO(maxi): -G*M_TIERRA*m/r */
    (void)m; (void)r;
    return 0.0;
}

double calcularPuntoEquilibrio(void)
{
    /* TODO(maxi): D/(1+sqrt(M_LUNA/M_TIERRA)) */
    return 0.0;
}

double calcularTrabajoRequerido(EstadoMision *e)
{
    /* TODO(maxi): (U_eq - (U_i + K)) / m */
    (void)e;
    return 0.0;
}

void imprimirHistorial(const EstadoMision *e)
{
    /* TODO(maxi) */
    (void)e;
}

void imprimirReporte(const EstadoMision *e)
{
    /* TODO(maxi) */
    (void)e;
}

/* Juampi  */
void simularTurno(EstadoMision *e, Evento *ev)
{
    /* Actualiza la fase actual según el evento */
    e->fase_actual = ev->id;

    printf("\n>>> TURNO %d: %s\n", ev->id, ev->nombre);
    mostrarEstado(e);

    int accion = pedirAccionTurno();

    switch (accion) {
        case 1: aplicarMantenerRumbo(e, ev);      break;
        case 2: aplicarPropulsorAuxiliar(e, ev);  break;
        case 3: aplicarAbortar(e);                break;
    }
}

void mostrarEstado(const EstadoMision *e)
{
    printf("    Combustible : %.2f kg\n", e->combustible);
    printf("    Velocidad   : %.2f m/s\n", e->velocidad);
    printf("    Altitud     : %.2f m\n", e->altura);
}

int pedirAccionTurno(void)
{
    printf("\n  Acciones disponibles:\n");
    printf("    1. Mantener rumbo\n");
    printf("    2. Encender propulsor auxiliar\n");
    printf("    3. Abortar mision\n");
    return leerEnteroValido("  Seleccione accion (1-3): ", 1, 3);
}

void aplicarMantenerRumbo(EstadoMision *e, Evento *ev)
{
    /* Consume solo el costo base del evento */
    e->combustible -= ev->costo_combustible;

    /* Simulación simplificada: la gravedad frena la nave */
    double r = R_TIERRA + e->altura;
    double gravedad = G * M_TIERRA / (r * r);
    e->velocidad -= gravedad * 10.0;  /* dt = 10s por turno */
    e->altura    += e->velocidad * 10.0;

    registrarHistorial(e, "Mantener rumbo: velocidad ajustada por gravedad.");
}

void aplicarPropulsorAuxiliar(EstadoMision *e, Evento *ev)
{
    /* Consume el costo del evento + un extra por el propulsor */
    e->combustible -= (ev->costo_combustible + 30.0);
    
    /* El propulsor da un empujón de velocidad */
    e->velocidad += 150.0;
    
    registrarHistorial(e, "Propulsor auxiliar: +150 m/s.");
}

void aplicarAbortar(EstadoMision *e)
{
    /* Marca la misión como abortada (fase 99) */
    e->fase_actual = 99;
    registrarHistorial(e, "MISION ABORTADA POR EL USUARIO.");
    printf("\n[AVISO] Mision abortada.\n");
}
