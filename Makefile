CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wtype-limits -Werror -I.
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes
EJEC = pruebas

# 1.1. Compilar: 'make' o 'make all' solo construye el ejecutable
all: $(EJEC)

$(EJEC): split.c prueba2.c
	$(CC) $(CFLAGS) split.c prueba2.c -o $(EJEC)

# 1.2. Ejecutar pruebas: solo corre el binario
run: $(EJEC)
	./$(EJEC)

# 1.3. Ejecutar con Valgrind
valgrind: $(EJEC)
	valgrind $(VFLAGS) ./$(EJEC)

clean:
	rm -f $(EJEC)