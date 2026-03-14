#include "split.h"
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>

//"Hola;1;2;3;mundo"
// ["Hola", "1","2","3","mundo"]

//creo que a grandes rasgos ya está la función, me falta pensarla un toque más y escribir el error_memoria


/*
*PRE:
*POST:
*/
void vector_destruir(struct vector *v)
{
        for (size_t i = 0; i < v->cantidad; i++)
                free(v->palabras[i]);
        
        free(v);
}


//Debería armar una función que se crear vector y que directamente reserve la memoria y todo eso
/*
*PRE:
*POST:
*/
struct vector* vector_crear()
{
        struct vector *v = malloc(sizeof(struct vector));

        if (!v)
                return NULL;
        
        char *palabras = malloc(sizeof(char));
        if (!palabras) {
                free(v);
                return NULL;
        }

        v->palabras = palabras;
        return v;
};



//creo que lo que pasa es que no reserve un char* para tener como vector de strings, directamente intenté llenar un vector que todavía no está en ningún lado

/*
*PRE: texto debe ser un string
*POST: se devuelve un puntero al struct con el vector que tiene las palabras, ya separadas,
*y su tamaño en el campo cantidad, si falla algo se devuelve NULL 
*/ 
struct vector *split(char *texto, char separador)
{
        struct vector *resultado = malloc(sizeof(struct vector));

        if (!resultado){
                return avisar_error();
        }



        resultado->cantidad = 0;
        size_t cant_letras_aux = 0;
        bool error_memoria = false;

        for (size_t i = 0; i < strlen(texto) && !error_memoria; i++) {
                if (texto[i] == separador || i == 0) {
                        char* palabra_aux = malloc(sizeof(char));

                        if (palabra_aux != NULL) {
                                resultado->palabras[resultado->cantidad] = palabra_aux;
                                resultado->palabras[resultado->cantidad][0] = '\0';
                                cant_letras_aux = 1;
                                resultado->cantidad++;
                        } else {
                                error_memoria = true;    
                        }
                } else {
                        char* palabra_actualizada = realloc(
                                resultado->palabras[(resultado->cantidad) - 1], (cant_letras_aux + 1)*(sizeof(char)));

                        if (palabra_actualizada != NULL) {
                                resultado->palabras[resultado->cantidad - 1] = palabra_actualizada;
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
                return NULL;
        }

        return resultado;
        
}


// cómo puedo testeear esto ahora? sí o sí necesito valgrind gcc y gdb creo, o sea crear la maquina virtual y correrlo ahí



