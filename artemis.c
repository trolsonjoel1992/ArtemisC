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