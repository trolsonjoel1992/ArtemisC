#ifndef VALIDACIONES_H
#define VALIDACIONES_H

void   limpiarBufferEntrada(void);                                  /* Juampi */
int    leerEnteroValido(const char *mensaje, int min, int max);     /* Joel   */
double leerFlotanteValido(const char *mensaje, double min, double max); /* Maxi */

#endif