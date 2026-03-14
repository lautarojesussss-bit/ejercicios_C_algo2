# Variables para hacernos la vida más fácil
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wtype-limits -Werror -I.
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

# Nombre del ejecutable
EJEC = pruebas

# La regla "all" es la que se corre por defecto al poner 'make'
all: clean $(EJEC)

# Compilación: unimos los dos archivos .c para crear el ejecutable
$(EJEC): split.c prueba.c
	$(CC) $(CFLAGS) split.c prueba.c -o $(EJEC)

# Regla para correr con Valgrind directamente
valgrind: $(EJEC)
	valgrind $(VFLAGS) ./$(EJEC)

# Regla para limpiar los archivos generados
clean:
	rm -f $(EJEC)