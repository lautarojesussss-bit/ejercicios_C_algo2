#include "split.h"
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include<stdio.h>
#define ERROR_MENSAJE "Error al intentar reservar memoria.\n"

/*
*PRE: vector debe haber sido creado con vector_crear()
*POST: libera toda la memoria reservada vinculada a v
*/
void vector_destruir(struct vector *v)
{
        if(!v)
                return;

        for (size_t i = 0; i < v->cantidad; i++)
                free(v->palabras[i]);
        free(v->palabras); //este me falta tanto reservar como liberar
        free(v);
}

/*
*PRE: 
*POST: devuelve un puntero a una instancia de struct vector inicializado 
*con una sola palabra que es solo el caracter nulo
*/
struct vector* vector_crear()
{
        struct vector *v = malloc(sizeof(struct vector));

        if (!v)
                return NULL;
        
        char **palabras = malloc(sizeof(char*));
        if (!palabras) {
                free(v);
                return NULL;
        }

        v->palabras = palabras;

        char *letra = malloc(sizeof(char));
        if (!letra)
        {
                free(v->palabras);
                free(v);
                return NULL;
        }

        *letra = '\0';
        v->palabras[0] =letra;
        v->cantidad = 1;
        return v;
};

/*
*PRE: 
*POST: devuelve NULL e imprime un aviso de error 
*/
struct vector* avisar_error()
{
        printf(ERROR_MENSAJE);
        return NULL;
}

/*
*PRE: texto debe ser un string
*POST: se devuelve un puntero a una instancia de struct vector que tiene las palabras, ya separadas,
*y su tamaño en el campo cantidad, si falla algo se devuelve NULL y se imprime un aviso
*/ 
struct vector *split(char *texto, char separador)
{
        struct vector *resultado = vector_crear();

        if (!resultado)
                return NULL;
        
        size_t cant_letras_aux = 1;
        bool error_memoria = false;

        for (int i = 0; !error_memoria && i < strlen(texto) ; i++) {
                if (texto[i] == separador) {
                        char** palabras_aux = realloc(resultado->palabras, (resultado->cantidad + 1)*sizeof(char*));
                        char* nueva_palabra_aux = malloc(sizeof(char));

                        if (palabras_aux != NULL && nueva_palabra_aux != NULL ) {
                                resultado->palabras = palabras_aux;
                                resultado->palabras[resultado->cantidad] = nueva_palabra_aux;
                                resultado->palabras[resultado->cantidad][0] = '\0';
                                cant_letras_aux = 1;
                                resultado->cantidad++;
                        } else {
                                error_memoria = true;    
                        }
                } else {
                        char* palabra_actualizar_aux = realloc(
                                resultado->palabras[(resultado->cantidad) - 1], (cant_letras_aux + 1)*(sizeof(char)));

                        if (palabra_actualizar_aux != NULL) {
                                resultado->palabras[resultado->cantidad - 1] = palabra_actualizar_aux;
                                resultado->palabras[resultado->cantidad - 1][cant_letras_aux - 1] = texto[i];
                                resultado->palabras[resultado->cantidad - 1][cant_letras_aux] = '\0'; 
                                cant_letras_aux++;
                        } else {
                                error_memoria= true;
                        }
                }
        }

        if (error_memoria) {
                vector_destruir(resultado);
                return avisar_error();
        }

        return resultado;
}


