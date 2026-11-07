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