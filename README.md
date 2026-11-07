# Artemis 3 — Simulador TLI (Inyección Translunar)


## Integrantes y comisión

- Cossani Leguizamon Maximiliano Alejandro
- Latorre Kanno Juan Pablo
- Trolson Foschiatti Joel Salvador

**Comisión:** K.1.3 
**Materia:** Algoritmos y Estructuras de Datos — Laboratorio de C  
**Escenario:** 3 — Inyección Translunar (TLI) e Inercia en Trayectoria Libre

---

## Descripción del escenario

El programa simula la misión Artemis 3 en su fase de **Inyección Translunar (TLI)**. La nave Orion parte de una órbita baja terrestre (LEO) y recibe un encendido que la impulsa hacia la Luna. Durante la simulación se modelan cuatro eventos:

1. Órbita LEO.
2. Encendido TLI.
3. Costeo translunar.
4. Ajuste final y reporte.

En cada turno el usuario puede:

- mantener rumbo;
- encender el propulsor auxiliar;
- abortar la misión.

El simulador calcula energía cinética, energía potencial, punto de equilibrio gravitatorio Tierra-Luna y trabajo externo por unidad de masa. Al finalizar genera un reporte paso a paso y muestra el historial de la misión.

Además, incluye una explicación física de:

- la 1.ª Ley de Newton aplicada a la trayectoria libre;
- la diferencia energética entre viajar Tierra → Luna y Luna → Tierra.

---

## Reglas del simulador

- La misión debe configurarse antes de simular.
- Rangos válidos:
  - Velocidad inicial TLI: 1.000 – 20.000 m/s.
  - Altitud LEO: 160.000 – 500.000 m.
  - Masa de la nave: 10.000 – 50.000 kg.
- Cada evento consume combustible.
- La misión termina si:
  - el usuario aborta;
  - el combustible llega a 0;
  - se completan los 4 eventos.
- El reporte final muestra el cálculo físico paso a paso.

---

## Funcionamiento breve

1. Ejecutar `./artemis`.
2. Elegir **1. Configurar misión** e ingresar velocidad, altitud y masa.
3. Elegir **2. Iniciar simulación TLI**.
4. En cada turno seleccionar una acción.
5. Al finalizar se muestra el reporte y el historial.
6. La opción **3. Ver explicación física** muestra el desarrollo conceptual del escenario 3.

---

## Compilación y ejecución

El proyecto incluye un `Makefile` con `-Wall -Wextra -std=c11 -g` y enlace con `-lm`.

```bash
make        # compila
./artemis   # ejecuta
make clean  # limpia objetos y ejecutable

También se puede compilar y ejecutar en un paso:

make run
```
## Arquitectura modular
```bash
          +----------------------+
          |        main.c        |
          | main() / menú        |
          +----------+-----------+
                     | llama
        +------------+------------+
        |            |            |
        v            v            v
+---------------+ +-----------+ +------------------+
|   artemis.c   | | artemis.h | | validaciones.c   |
| física +      | | structs + | | lectura          |
| estado +      | | prototipos| | segura           |
| reporte       | +-----------+ +---------+--------+
+-------+-------+                         |
        | usa                             | usa
        v                                 v
+--------------------------------------------------+
|                 validaciones.h                   |
+--------------------------------------------------+

EstadoMision  --> paso por puntero --> artemis.c
Evento[4]     --> arreglo fijo      --> precargarEventos()
```
## Responsabilidades

main.c: menú principal, opciones y flujo general.

artemis.h: constantes físicas, structs y prototipos.

artemis.c: estado de misión, cálculos físicos, eventos, historial y reporte.

validaciones.c/.h: lectura segura de enteros y flotantes, mensajes de error.

## Registro de uso de IA

| Herramienta | Tarea / consulta | Validación / adaptación |
|-------------|------------------|-------------------------|
| DeepSeek | Revisión del cumplimiento del TP y detección de casos borde (reconfiguración de misión, combustible agotado). | Se aplicaron las correcciones en `guardarConfiguracion()` (reinicio de estado) e `imprimirReporte()` (estado FALLIDA por combustible). Se probó reconfigurando después de abortar y simulando hasta combustible 0. |
| DeepSeek | Ayuda para redactar el README y el diagrama ASCII. | El diagrama se adaptó a la arquitectura real del proyecto y se verificó contra los archivos `.c/.h`. El texto se ajustó al escenario 3 y a las consignas de la cátedra. |
| DeepSeek | Consulta sobre buenas prácticas de modularización en C y paso de structs por puntero. | Se validó compilando con `-Wall -Wextra` y revisando que todas las funciones usen `EstadoMision *` o `Evento *` según corresponda. |
