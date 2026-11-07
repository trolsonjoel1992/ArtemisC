# ==========================================================================
# MAKEFILE - ARTEMIS 3
# ==========================================================================
# Compila los 3 módulos del proyecto cumpliendo con el estándar C11
# y las banderas de advertencia estrictas exigidas por la cátedra.

CC     = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
LDLIBS = -lm
OBJS   = main.o artemis.o validaciones.o
TARGET = artemis

# Regla principal: compila el ejecutable final
all: $(TARGET)

# Enlaza los archivos objeto con la librería matemática (-lm)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

# Regla genérica para compilar archivos .c a .o
# Depende de ambos headers para recompilar si hay cambios en las firmas
%.o: %.c artemis.h validaciones.h
	$(CC) $(CFLAGS) -c $< -o $@

# Regla de conveniencia para compilar y ejecutar en un solo paso
run: $(TARGET)
	./$(TARGET)

# Limpieza del directorio de trabajo
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean run