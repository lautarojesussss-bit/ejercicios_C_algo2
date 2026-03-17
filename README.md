<div align="right">
    <img width="32px" src="img/algo2.svg">
</div>

# TP

## Información del estudiante

* Lautaro Jesús Duarte Vera
* 114088
* lautarojesussss@gmail.com o lduartev@fi.uba.com (uso más el @gmail)

---

## Índice
* [1. Instrucciones](#1-Instrucciones)
  * [1.1. Compilar el proyecto](#11-Compilar-el-proyecto)
  * [1.2. Ejecutar las pruebas](#12-Ejecutar-las-pruebas)
  * [1.3. Ejecutar el programa con Valgrind](#13-Ejecutar-el-programa-con-Valgrind)
* [2. Funcionamiento](#2-Funcionamiento)
* [3. Estructura](#3-Estructura)
  * [3.1. Diagrama de memoria](#31-Diagrama-de-memoria)
* [4. Decisiones de diseño y/o complejidades de implementación](#4-Decisiones-de-diseño-yo-complejidades-de-implementación)
* [5. Respuestas a las preguntas teóricas](#5-Respuestas-a-las-preguntas-teóricas)

## 1. Instrucciones

### 1.1. Compilar el proyecto
```bash
make
```

### 1.2. Ejecutar las pruebas
```bash
make run
```

### 1.3. Ejecutar el programa con Valgrind
```bash
make valgrind
```

## 2. Funcionamiento
La función split toma un string cualquiera y un char, y se encarga de separar el texto 
original en strings más pequeños usando el char que recibió como punto de separación, los nuevos strings se colocan en un vector de strings dentro de un struct vector, en el orden que estaban escritos originalmente en el string más grande. 

<div align="center">
  <img src="diagramas_de_flujo/diagrama_split_v7.svg" width="70%">
  <p>Diagrama de flujo de struct vector *split(char *texto, char separador).</p>
</div>


La función vector_destruir recibe un puntero a una instancia del struct vector y se encarga de liberar toda la memoria relacionada a esa instancia
<div align="center">
  <img src="diagramas_de_flujo/vector_destruir_3.svg" width="70%">
  <p>Diagrama de flujo de void vector_destruir(struct vector *v).</p>
</div>

La función actualizar_palabra se encarga de agrandar la última palabra del vector palabras de v, colocarle la nueva letra a esa palabra y colocarle también el carácter nulo al final, además de actualizar un contador auxiliar de caracteres
<div align="center">
  <img src="diagramas_de_flujo/diagrama_actualizar_palabra_3.svg" width="70%">
  <p>Diagrama de flujo de bool actualizar_palabra(struct vector *v, size_t *cant_caracteres_aux, char nueva_letra).</p>
</div>

La función agrandar_vector_palabras se encarga de reservar nueva memoria para agregar un char* al vector de palabras, y además reservar memoria para un carácter nulo que le cargamos automáticamente a esa nueva palabra, además incrementa el campo cantidad de v y vuelve a poner en 1 el contador de carácteres
<div align="center">
  <img src="diagramas_de_flujo/agrandar_vector_palabras_v2.svg" width="70%">
  <p>Diagrama de flujo de bool agrandar_vector_palabras(struct vector *v, size_t *cant_caracteres_aux).</p>
</div>


## 3. Estructura

No armé nuevas estructuras para el tp.

### 3.1. Diagrama de memoria
Realizar un diagrama de memoria de la estructura de memoria durante la ejecución del programa, esto debe incluir el stack y el heap con las estructuras contenidas en ellos.

<div align="center">
  <img src="diagramas_de_flujo/memoria_diagrama_4 (1).svg" width="70%">
  <p>Diagrama de memoria de la estructura.</p>
</div>

## 4. Decisiones de diseño y/o complejidades de implementación
Explicar las decisiones de diseño y/o las complejidades de implementación que hubo durante la resolución del TP.


La mayor complejidad en el tp creo que fue controlar los errores de memoria de manera que si algo fallaba pudiese terminar liberando todo sin dejar algún bloque reservado suelto porque me olvidé de actualizar un contador o de cargar un puntero al struct vector etc, además fue complicado pensar el primer string que se carga al vector palabras porque si no lo hacía como lo hice, o sea, inicializando primero el struct vector con 1 string al menos al ser creado, tenía que hacer las funciones auxiliares adaptables a ese caso en el que es el primer string el que tiene que ser creado desde cero etc, y se volvía menos entendible el código

## 5. Respuestas a las preguntas teóricas


### 5.1. ¿Cómo funcionan los strings en C?
Los strings en C son simplemente vectores de char (un char* que apunta al primer char del string) que terminan con caracter nulo (\0)
todas las operaciones que se hacen con string.h funcionan copiando/comparando/moviendo/contando caracter a caracter teniendo el caracter nulo como tope para el vector.

### 5.2 ¿Cómo funcionan las primitivas malloc y free?
dsfdsf
