#include <stdio.h>
#include <string.h>
#include <math.h>
#include "artemis.h"
#include "validaciones.h"

/* Joel  */
void inicializarMision(EstadoMision *e)
{
    /* Se inicializan todos los campos en 0 para evitar basura en memoria */
    e->velocidad = 0.0;
    e->altura = 0.0;
    e->masa = 0.0;
    e->combustible = 1000.0; /* Tanque lleno al inicio */
    e->energia_inicial = 0.0;
    e->trabajo_requerido = 0.0;
    e->fase_actual = 0;
    e->cant_historial = 0;
    
    /* Se limpia el arreglo de historial por seguridad */
    for (int i = 0; i < MAX_HISTORIAL; i++) {
        e->historial[i][0] = '\0';
    }
}

void guardarConfiguracion(EstadoMision *e, double v, double h, double m)
{
    /* Asigna los valores validados */
    e->velocidad = v;
    e->altura = h;
    e->masa = m;

    /* Calcula energía inicial usando funciones de Maxi */
    double k = calcularEnergiaCinetica(m, v);
    double u = calcularEnergiaPotencial(m, R_TIERRA + h);
    e->energia_inicial = k + u;

    /* Calcula trabajo requerido usando función de Maxi */
    e->trabajo_requerido = calcularTrabajoRequerido(e);

    /* Registrar el evento en el historial */
    registrarHistorial(e, "Mision configurada con exito.");
}

void precargarEventos(Evento eventos[CANT_EVENTOS])
{
    /* Definición de los 4 eventos del escenario Artemis 3 */
    Evento temp[CANT_EVENTOS] = {
        {1, "Orbita LEO",             0.0},
        {2, "Encendido TLI",        100.0},
        {3, "Costeo translunar",     10.0},
        {4, "Ajuste final y reporte", 50.0}
    };

    for (int i = 0; i < CANT_EVENTOS; i++) {
        eventos[i] = temp[i];
    }
}

void registrarHistorial(EstadoMision *e, const char *msg)
{
    /* Solo escribe si no superó el máximo del arreglo */
    if (e->cant_historial < MAX_HISTORIAL) {
        snprintf(e->historial[e->cant_historial], LARGO_MSG, "%s", msg);
        e->cant_historial++;
    }
}

int misionSigueActiva(const EstadoMision *e)
{
    /* Activa si no fue abortada (fase 99) y si aún queda combustible */
    if (e->fase_actual == 99 || e->combustible <= 0.0) {
        return 0;
    }
    return 1;
}

void imprimirExplicacionFisica(void)
{
    printf("\n==========================================\n");
    printf("      EXPLICACION FISICA - ESCENARIO 3    \n");
    printf("==========================================\n");

    printf("\n(a) 1ra Ley de Newton (Ley de Inercia):\n");
    printf("  Una vez apagados los propulsores, la nave mantiene su\n");
    printf("  estado de movimiento porque no hay fuerza neta externa\n");
    printf("  aplicada en la direccion de avance. La unica fuerza que\n");
    printf("  actua es la gravedad terrestre, que es central y decrece\n");
    printf("  con 1/r^2. Esta fuerza frena progresivamente el ascenso\n");
    printf("  porque la energia cinetica se convierte en energia\n");
    printf("  potencial gravitatoria. La componente tangencial de la\n");
    printf("  velocidad se conserva (momento angular).\n");

    printf("\n(d) Tierra -> Luna vs Luna -> Tierra:\n");
    printf("  En la IDA, la nave parte de un pozo gravitatorio profundo\n");
    printf("  (Tierra) y debe ganar energia mecanica para escapar.\n");
    printf("  Requiere W_ext > 0 significativo, por lo tanto mucho\n");
    printf("  combustible. En la VUELTA, la nave cae 'cuesta abajo'\n");
    printf("  del pozo gravitatorio terrestre. La gravedad hace trabajo\n");
    printf("  a favor, la nave gana energia cinetica sin necesidad de\n");
    printf("  propulsion sostenida. Solo se requiere un W_ext inicial\n");
    printf("  pequeno para escapar del pozo lunar (mucho menos masivo).\n");
    printf("==========================================\n\n");
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
