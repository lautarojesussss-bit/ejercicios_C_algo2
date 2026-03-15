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
        free(v->palabras);
        free(v);
}



void actualizar_palabra(struct vector *v, bool *error_memoria, size_t *cant_caracteres_aux, char nueva_letra)
{
        size_t pos_aux = (v->cantidad -1);

        char* palabra_actualizar_aux = realloc(
                v->palabras[pos_aux], (*cant_caracteres_aux + 1)*(sizeof(char)));

        if (palabra_actualizar_aux != NULL) {
                v->palabras[pos_aux] = palabra_actualizar_aux;
                v->palabras[pos_aux][*cant_caracteres_aux - 1] = nueva_letra;
                v->palabras[pos_aux][*cant_caracteres_aux] = '\0'; 
                (*cant_caracteres_aux)++;
        } else {
                *error_memoria = true;
        }
}

void agrandar_vector_palabras(struct vector *v, bool *error_memoria, size_t *cant_caracteres_aux)
{
        char** palabras_aux = realloc(v->palabras, (v->cantidad + 1)*sizeof(char*));

        if (palabras_aux != NULL) {
                v->palabras = palabras_aux;
                v->palabras[v->cantidad] = NULL;
                v->cantidad++;

                char* nueva_palabra_aux = malloc(sizeof(char));

                if (nueva_palabra_aux != NULL) {
                        v->palabras[v->cantidad -1] = nueva_palabra_aux;
                        v->palabras[v->cantidad -1][0] = '\0';
                        *cant_caracteres_aux = 1;
                }
                else {
                        *error_memoria = true;
                }
        } else {
                *error_memoria = true;    
        }
}


/*
*PRE: 
*POST: devuelve un puntero a una instancia de struct vector inicializado 
*con una sola palabra que es solo el caracter nulo
*/
struct vector* vector_inicializar()
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

        char *caracter_inicial = malloc(sizeof(char));
        if (!caracter_inicial)
        {
                free(v->palabras);
                free(v);
                return NULL;
        }

        *caracter_inicial = '\0';
        v->palabras[0] = caracter_inicial;
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
        struct vector *resultado = vector_inicializar();

        if (!resultado)
                return avisar_error();

        size_t cant_caracteres_aux = 1;
        size_t len = strlen(texto);
        bool error_memoria = false;

        for (int i = 0; !error_memoria && i < len ; i++) {
                if (texto[i] == separador)
                        agrandar_vector_palabras(resultado, &error_memoria, &cant_caracteres_aux);
                else
                        actualizar_palabra(resultado, &error_memoria, &cant_caracteres_aux, texto[i]);
        }

        if (error_memoria) {
                vector_destruir(resultado);
                return avisar_error();
        }

        return resultado;
}


