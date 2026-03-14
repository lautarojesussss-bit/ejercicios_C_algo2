#include "split.h"
#include<stdlib.h>
#include<stdio.h>

#define texto_prueba "Hola;1;2;3;mundo"
#define separador_prueba ';'

//"Hola;1;2;3;mundo"
// ["Hola", "1","2","3","mundo"]

int main()
{
        struct vector *v= split(texto_prueba, separador_prueba);

        for (int i = 0; i < v->cantidad; i++)
            printf("%s\n",v->palabras[i]);
        
        return 0;
}