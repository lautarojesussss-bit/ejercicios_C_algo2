#include "split.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX_ENTRADA 200
#define SALIDA "exit\n"
#define AVISO_INICIAL "Ingrese un string para dividr (%i caracteres como máximo), usando ; como separador, O escriba exit para salir\n"
#define separador_prueba ';'


void limpiar_entrada(char* entrada)
{
        size_t len = strlen(entrada);

        if (entrada[len-1]== '\n')
                entrada[len-1] = '\0';
}

int main()
{
        char leido[MAX_ENTRADA];
        printf(AVISO_INICIAL, MAX_ENTRADA-1);
    
        while(fgets(leido, MAX_ENTRADA, stdin) != NULL && strcmp(leido, SALIDA) != 0){
                limpiar_entrada(leido);

                struct vector *v = split(leido, separador_prueba);
                printf("Las palabras son:\n");

                for (size_t i = 0; i < v->cantidad; i++)
                        printf("%s\n",v->palabras[i]);

                vector_destruir(v);
                printf(AVISO_INICIAL, MAX_ENTRADA-1);        
        }

        return 0;
}