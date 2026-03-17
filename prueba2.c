#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "split.h"
#include <stdbool.h>
#define prueba_1_texto "Hola;amigo"
#define prueba_1_separador ';'
#define prueba_1_cantidad 2

#define prueba_2_texto ";amigo"
#define prueba_2_separador ';'
#define prueba_2_cantidad 2


#define MENSAJE_EXITO "La prueba %i fue un éxito.\n"
#define MENSAJE_FRACASO "La prueba %i fue un fracaso.\n"



bool prueba(char *texto, char separador, struct vector *resultado_esperado)
{
        struct vector *v = split(texto, separador);

        if (!v)
                return false;
        
        bool funciona = true;
        

        if (v->cantidad != resultado_esperado->cantidad) {
                funciona = false;
        }else{
                size_t len = v->cantidad;

                for (size_t i = 0; funciona && i < len; i++)
                {
                    if (strcmp(resultado_esperado->palabras[i], v->palabras[i]) != 0)
                    {
                            funciona = false;
                    }
                }
        }
        vector_destruir(v);
        return funciona;
}

int main()
{
        struct vector prueba_1_resultado;
        char *palabras_esperadas_1[] = {"Hola", "amigo"};
        prueba_1_resultado.cantidad = prueba_1_cantidad;
        prueba_1_resultado.palabras = palabras_esperadas_1;

        bool prueba_1 = prueba(prueba_1_texto, prueba_1_separador, &prueba_1_resultado);
        
        if (prueba_1)
                printf(MENSAJE_EXITO, 1);
        else
                printf(MENSAJE_FRACASO,1);

        struct vector prueba_2_resultado;
        char *palabras_esperadas_2[] = {"","amigo"};
        prueba_2_resultado.cantidad = prueba_2_cantidad;
        prueba_2_resultado.palabras = palabras_esperadas_2;

        bool prueba_2 = prueba(prueba_2_texto, prueba_2_separador, &prueba_2_resultado);
        
        if (prueba_2)
                printf(MENSAJE_EXITO, 2);
        else
                printf(MENSAJE_FRACASO,2);

}