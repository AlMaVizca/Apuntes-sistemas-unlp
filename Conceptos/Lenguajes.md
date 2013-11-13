Introducción
------------

  - Por qué estudiar los lenguajes de programación
    + razones de eficiencia: cuánto cuesta cada característica de un lenguaje?
    + razones de vocabulario: las soluciones se expresan mejor o peor
      según el lenguaje, por qué restringirse a un solo lenguaje?
    + para saber elegir el lenguaje
    + para facilitar el aprendizaje de nuevos lenguajes
    + para diseñar adecuadamente un lenguaje, i.e. una API

  - Para qué sirve un lenguaje de programación?
    + provee un lenguaje para expresar algoritmos, de manera independiente
      de la máquina específica
    + provee una abstracción de alto nivel de una máquina compleja
      y difícil de programar

  - Características deseables
    + rapidez de aprendizaje: Scheme vs. Cobol, Pl1
      · integridad conceptual: pocos conceptos
      · ortogonalidad: composicion de las abstracciones, pocos casos especiales
    + expresividad: Smalltalk vs. Fortran
    + Costos
      · rapidez de programación: Perl vs. Cobol, Java
      · legibilidad: Ml vs. Apl, perl write-only
      · mantenibilidad: Java vs. C
      · eficiencia: C vs. Basic
    + apoyo para la abstracción: tipos paramétricos
    + herramientas de verificación: assert
    + ambientes de desarrollo: IDE, debugger
    + API estándar para desarrollar aplicaciones: Java vs. C

  - Dimensiones de los lenguajes de programación
    + Sintaxis
    + Semántica
    + Implementación
    + Paradigmas

  - Paradigmas de programación

    1.- imperativo
      · énfasis en el estado: instrucciones y procedimientos modifican el estado
      · programación estructurada: if-then-else, while, estructuras,
        procedimientos, no al goto
      ventajas
      · eficiencia
      desventajas
      · problema de complejidad: variables pueden ser modificadas en cualquier
        parte del programa

    2.- aplicativo o funcional

      · no hay asignacion: no hay estado
      · no hay ciclos
      · enfasis en funciones recursivas pequeñas
      · relacionado con la inducción en matemáticas
      ventajas
      · sencillez, mantenibilidad, demostrabilidad
      desventajes
      · difícil expresar un estado en problemas inherentemente basados en
        un estado, como la simulación de eventos discretos
      · ineficiente para resolver algunos problemas
        (ej.: calculo de frecuencias)

    3.- orientado a objetos

      · enfasis en entidades que almacenan estado (los objetos) y pequeñas
        unidades de código que lo modifican (las clases) por medio de
        operaciones específicas (métodos)
      · cada clase se programa imperativamente
      . estado manejado por una clase es inaccesible a partir de otras
        clases (encapsulación)
      · al invocar un método sobre un objeto, el código que lo ejecuta
        se determina dinámicamente en función de la clase del objeto
        (enlace dinámico)
      ventajas
      · complejidad controlada, mantenibilidad, eficiente
      desventajas
      · complejidad conceptual, ineficiente

    4.- lógico
      · énfasis en predicados lógicos que expresan reglas
      · no hay estado, ni funciones
      ventajas
      · ideal para resolver aplicaciones específicas (ej. análisis sintáctico)
      desventajas
      · ineficiente, dificultad para expresar soluciones en problemas
        específicos (ej. simulación de eventos discretos)


Fases de la compilación
-----------------------

1.- Análisis léxico

Descompone el programa fuente en una serie de tokens, i.e. las palabras
del lenguaje.

Ejemplo 1: calculadora

Entrada: 12 + 5 * -2 

Tokens: NUM(12), +, NUM(5), *, -, NUM(2)

Ejemplo 2: típicos tokens encontrados en una lenguaje como Java

 NUM(1234), ID(count), true, while, STRING("hola"), COMMENT("/* ... */")

Todos los caracteres que se encuentran en el programa fuente deben formar
parte de un token, de otro modo se alerta la presencia de un error léxico.

2.- Análisis sintáctico

Construye un árbol sintáctico del programa fuente en donde las hojas
corresponden a los tokens, los nodos internos a reducciones gramaticales
y la raíz es el nodo inicial de la gramática.

Ejemplo: árbol sintáctico para 12 + 5 * -2

  +
    NUM(12)
    *
      5
      - (unario)
        2

La lectura secuencial de las hojas del árbol corresponde a la secuencia
de tokens entregada por el análisis léxico.  Si el analizador no es
capaz de atribuir un token a alguna regla de la gramática se alerta de
la presencia de un error sintáctico.

3.- Análisis semántico

  - Análisis de tipos: se anota el árbol sintáctico con el tipo
    de cada una de la expresiones y subexpresiones.
    Ej. en Java:    3 / 2 + 3 * 0.5 / 2
      +       : double
        /     : int
        3     : int
        2     : int
        /     : double
          *   : double
          3   : int
          0.5 : double
        2     : int
 
    Las reglas de inferencia de tipos gobiernan el tipo de
    una expresión en función del operador y el tipo de sus operandos.

  - Consistencia semántica del árbol sintáctico:
    Por ejemplo, no tiene sentido restar dos strings.

4.- Generación de código intermedio

Traduce el programa a une lenguaje de máquina abstracto (independiente
de la arquitectura del procesador de destino).

  - Resolución de formas equivalentes
    Por ejemplo:

      for (decl; exp; exp) inst

    se puede transformar en: decl; while (exp) { inst exp; }

    De esta forma, se simplifica la siguiente fase, reduciendo el
    número de construcciones que aparecen en el árbol sintáctico.

  - Transforma el árbol sintáctico en un programa de bajo nivel.
    Este último se puede expresar en la forma de:

    · un árbol de operaciones: similar al árbol sintáctico pero más
      cercano a una máquina abstracta

    . assembler abstracto basado en cuádruplas:
      op v1, v2, res
      ...

    · máquina de stack: como el bytecode de java (compando javap)

5.- Generación de código de máquina

  Enfoques:
  + generación de archivos binarios: C, Fortran, Cobol, Pascal, Ada
  + interpretación: Basic, Prolog
  + compilación Just-in-time (JIT): Java



Generación de archivos binarios:

  + El compilador genera a partir del código intermedio un programa
    en assembler
                                              /lib/libc.a ----+
                                                              V
    progr. -> COMPILADOR -> prog. -> ENSAMBLADOR -> prog. -> LINKER -> binario
    fuente     (gcc -S)    assembler    (as)       objeto     (ld)    ejecutable
    x.c, y.c               x.s, y.s                x.o, y.o            a.out

    El archivo a.out contiene una imagen binaria del programa, que es
    directamente ejecutable.  El núcleo del sistema operativo
    ejecuta este binario creando un proceso, con su espacio de direcciones,
    y copiando el binario en las direcciones baja de la memoria:

     +-----------------------------+-------+                 +---------+ 
     |     imagen binaria          |       |                 |         |
     +--------+--------------------+       |                 |         |
     | código | variables globales | heap  | -->         <-- | pila    |
     |        | inicializada       |       |                 |         |
     +--------+--------------------+-------+                 +---------+ 

  + Ventajas: Eficiente en tiempo de carga y ejecución.

  + Desventajas: El binario es dependiente de la plataforma

Interpretación

  Interpretación directa del programa fuente

  + Cada vez que se ejecuta el programa, el intérprete realiza todas
    las fases presentadas más arriba (análisis léxico ... generación
    de código intermedio).

  + El intérprete luego decodifica y ejecuta directamente el
    código intermedio.

  + Ventajas: cómodo, interacción rápida

  + Desventajas: lento para ejecutar y cargar, se distribuyen programas
    fuentes

  + Ejemplos: Perl, Scheme

  Interpretación de código intermedio

  + El código intermedio se guarda en un archivo.  Para ejecutar el
    programa existe un interprete que lee el archivo y lo ejecuta
    decodificando el mismo las instrucciones intermedias.

  + Ventajas: Archivo resultante es independiente de la plataforma y se puede
    distribuir sin entregar el código fuente.

  + Desventajas: Muy ineficiente en tiempo de ejecucion (24x)

  + Ejemplos: Emacs Lisp (archivos .elc), java 1.0

Compilacion JIT

  + El código intermedio se guarda en un archivo.  Para ejecutar el
    programa existe un compilador JIT que lee el archivo y lo traduce
    a instrucciones de máquina, típicamente sobre la marcha a medida
    que se va ejecutando, y en el mismo proceso en donde se ejecuta el JIT

  + Ventajas:
    · Archivo resultante es independiente de la plataforma y se puede
      distribuir sin entregar el código fuente
    · El JIT puede hacer un perfil del tiempo de ejecución para
      determinar que código necesita más optimización
    · Para programas que toman horas en ejecutarse, el JIT
      puede generar un código muy eficiente gracias al perfil
      del tiempo de ejecución

  + Desventajas: 
    · Tiempo de carga ineficiente, porque hay que compilar sobre la marcha
    · En programas de corta duración (menos de un minuto), el JIT
      no alcanza a hacer optimizaciones y el código es lento.
      Esto es especialmente molesto con programas que se ejecutan
      muchas veces.

