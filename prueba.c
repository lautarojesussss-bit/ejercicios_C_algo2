#include "split.h"
#include<stdlib.h>
#include<stdio.h>

#define TEXTO_PRUEBA "Hola;1;2;3;mundo"
#define separador_prueba ';'

//"Hola;1;2;3;mundo"
// ["Hola", "1","2","3","mundo"]
//la H no me la devolvió parece

int main()
{
        char *texto = TEXTO_PRUEBA;
        struct vector *v = split(texto, separador_prueba);

        for (int i = 0; i < v->cantidad; i++)
            printf("%s\n",v->palabras[i]);
        
        vector_destruir(v);

        return 0;
}