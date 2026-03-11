#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//"Hola;1;2;3;mundo"
// ["Hola", "1","2","3","mundo"]

//creo que a grandes rasgos ya está la función, me falta pensarla un toque más y escribir el error_memoria


struct vector {
        unsigned int cantidad;
        char **palabras;
};

//no puedo hacer strcpy así que tengo que copiar caracter por caracter básicamente
//tengo que usar memoria dinámica para esto, o sea tengo que reservar un bloque para cada palabra, y según si se agranda o no le tengo que hacer realloc
//PRE: texto debe ser un string
//POST: se devuelve un struct palabas que en su campo palabras tiene el vector con las palabras de texto, luego de separarlas considerando el caracter separador, el campo cantidad del struct palabras devuelto es la cantidad de strings del vector palabras, devuelve un struct palabras_separadas con NULL en el campo palabras y 0 en el campo cantidad si hubo un error en el proceso
struct vector *split(char *texto, char separador)
{
        struct vector *resultado = malloc(sizeof(struct vector));

        if (!resultado)
                return NULL;
        
        resultado->cantidad = 0;
        int cant_letras_aux = 1;

        for (int i = 0; i < strlen(texto); i++) {
                if (texto[i] == separador || i == 0) {
                        char* palabra_aux = malloc(sizeof(char));

                        if (palabra_aux != NULL) {
                                resultado->palabras[resultado->cantidad] = palabra_aux;
                                resultado->palabras[resultado->cantidad][0] = '\0';
                                cant_letras_aux = 1;
                                resultado->cantidad++;
                        } else {
                                goto error_memoria;    
                        }
                } else {
                        char* palabra_actualizada = realloc(
                            resultado->palabras[resultado->cantidad - 1], (cant_letras_aux + 1)*(sizeof(char)));

                        if (palabra_actualizada != NULL) {
                                resultado->palabras[resultado->cantidad - 1] = palabra_actualizada;
                                resultado->palabras[resultado->cantidad - 1][cant_letras_aux - 1] = texto[i];
                                resultado->palabras[resultado->cantidad - 1][cant_letras_aux] = '\0'; 
                                cant_letras_aux++;
                        } else {
                                goto error_memoria;
                        }
                }
        }

        return resultado;

error_memoria: 
        for (int j = 0; j < resultado->cantidad; j++) 
                free(resultado->palabras[j]);

        free(resultado);
        return NULL;
}


void vector_destruir(struct vector *v)
{
    
}

// cómo puedo testeear esto ahora? sí o sí necesito valgrind gcc y gdb creo











//hasta acá puede lleger mi función como máximo, 50 lineas