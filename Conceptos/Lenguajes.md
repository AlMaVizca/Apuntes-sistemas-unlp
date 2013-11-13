Introducci�n
------------

  - Por qu� estudiar los lenguajes de programaci�n
    + razones de eficiencia: cu�nto cuesta cada caracter�stica de un lenguaje?
    + razones de vocabulario: las soluciones se expresan mejor o peor
      seg�n el lenguaje, por qu� restringirse a un solo lenguaje?
    + para saber elegir el lenguaje
    + para facilitar el aprendizaje de nuevos lenguajes
    + para dise�ar adecuadamente un lenguaje, i.e. una API

  - Para qu� sirve un lenguaje de programaci�n?
    + provee un lenguaje para expresar algoritmos, de manera independiente
      de la m�quina espec�fica
    + provee una abstracci�n de alto nivel de una m�quina compleja
      y dif�cil de programar

  - Caracter�sticas deseables
    + rapidez de aprendizaje: Scheme vs. Cobol, Pl1
      � integridad conceptual: pocos conceptos
      � ortogonalidad: composicion de las abstracciones, pocos casos especiales
    + expresividad: Smalltalk vs. Fortran
    + Costos
      � rapidez de programaci�n: Perl vs. Cobol, Java
      � legibilidad: Ml vs. Apl, perl write-only
      � mantenibilidad: Java vs. C
      � eficiencia: C vs. Basic
    + apoyo para la abstracci�n: tipos param�tricos
    + herramientas de verificaci�n: assert
    + ambientes de desarrollo: IDE, debugger
    + API est�ndar para desarrollar aplicaciones: Java vs. C

  - Dimensiones de los lenguajes de programaci�n
    + Sintaxis
    + Sem�ntica
    + Implementaci�n
    + Paradigmas

  - Paradigmas de programaci�n

    1.- imperativo
      � �nfasis en el estado: instrucciones y procedimientos modifican el estado
      � programaci�n estructurada: if-then-else, while, estructuras,
        procedimientos, no al goto
      ventajas
      � eficiencia
      desventajas
      � problema de complejidad: variables pueden ser modificadas en cualquier
        parte del programa

    2.- aplicativo o funcional

      � no hay asignacion: no hay estado
      � no hay ciclos
      � enfasis en funciones recursivas peque�as
      � relacionado con la inducci�n en matem�ticas
      ventajas
      � sencillez, mantenibilidad, demostrabilidad
      desventajes
      � dif�cil expresar un estado en problemas inherentemente basados en
        un estado, como la simulaci�n de eventos discretos
      � ineficiente para resolver algunos problemas
        (ej.: calculo de frecuencias)

    3.- orientado a objetos

      � enfasis en entidades que almacenan estado (los objetos) y peque�as
        unidades de c�digo que lo modifican (las clases) por medio de
        operaciones espec�ficas (m�todos)
      � cada clase se programa imperativamente
      . estado manejado por una clase es inaccesible a partir de otras
        clases (encapsulaci�n)
      � al invocar un m�todo sobre un objeto, el c�digo que lo ejecuta
        se determina din�micamente en funci�n de la clase del objeto
        (enlace din�mico)
      ventajas
      � complejidad controlada, mantenibilidad, eficiente
      desventajas
      � complejidad conceptual, ineficiente

    4.- l�gico
      � �nfasis en predicados l�gicos que expresan reglas
      � no hay estado, ni funciones
      ventajas
      � ideal para resolver aplicaciones espec�ficas (ej. an�lisis sint�ctico)
      desventajas
      � ineficiente, dificultad para expresar soluciones en problemas
        espec�ficos (ej. simulaci�n de eventos discretos)


Fases de la compilaci�n
-----------------------

1.- An�lisis l�xico

Descompone el programa fuente en una serie de tokens, i.e. las palabras
del lenguaje.

Ejemplo 1: calculadora

Entrada: 12 + 5 * -2 

Tokens: NUM(12), +, NUM(5), *, -, NUM(2)

Ejemplo 2: t�picos tokens encontrados en una lenguaje como Java

 NUM(1234), ID(count), true, while, STRING("hola"), COMMENT("/* ... */")

Todos los caracteres que se encuentran en el programa fuente deben formar
parte de un token, de otro modo se alerta la presencia de un error l�xico.

2.- An�lisis sint�ctico

Construye un �rbol sint�ctico del programa fuente en donde las hojas
corresponden a los tokens, los nodos internos a reducciones gramaticales
y la ra�z es el nodo inicial de la gram�tica.

Ejemplo: �rbol sint�ctico para 12 + 5 * -2

  +
    NUM(12)
    *
      5
      - (unario)
        2

La lectura secuencial de las hojas del �rbol corresponde a la secuencia
de tokens entregada por el an�lisis l�xico.  Si el analizador no es
capaz de atribuir un token a alguna regla de la gram�tica se alerta de
la presencia de un error sint�ctico.

3.- An�lisis sem�ntico

  - An�lisis de tipos: se anota el �rbol sint�ctico con el tipo
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
    una expresi�n en funci�n del operador y el tipo de sus operandos.

  - Consistencia sem�ntica del �rbol sint�ctico:
    Por ejemplo, no tiene sentido restar dos strings.

4.- Generaci�n de c�digo intermedio

Traduce el programa a une lenguaje de m�quina abstracto (independiente
de la arquitectura del procesador de destino).

  - Resoluci�n de formas equivalentes
    Por ejemplo:

      for (decl; exp; exp) inst

    se puede transformar en: decl; while (exp) { inst exp; }

    De esta forma, se simplifica la siguiente fase, reduciendo el
    n�mero de construcciones que aparecen en el �rbol sint�ctico.

  - Transforma el �rbol sint�ctico en un programa de bajo nivel.
    Este �ltimo se puede expresar en la forma de:

    � un �rbol de operaciones: similar al �rbol sint�ctico pero m�s
      cercano a una m�quina abstracta

    . assembler abstracto basado en cu�druplas:
      op v1, v2, res
      ...

    � m�quina de stack: como el bytecode de java (compando javap)

5.- Generaci�n de c�digo de m�quina

  Enfoques:
  + generaci�n de archivos binarios: C, Fortran, Cobol, Pascal, Ada
  + interpretaci�n: Basic, Prolog
  + compilaci�n Just-in-time (JIT): Java



Generaci�n de archivos binarios:

  + El compilador genera a partir del c�digo intermedio un programa
    en assembler
                                              /lib/libc.a ----+
                                                              V
    progr. -> COMPILADOR -> prog. -> ENSAMBLADOR -> prog. -> LINKER -> binario
    fuente     (gcc -S)    assembler    (as)       objeto     (ld)    ejecutable
    x.c, y.c               x.s, y.s                x.o, y.o            a.out

    El archivo a.out contiene una imagen binaria del programa, que es
    directamente ejecutable.  El n�cleo del sistema operativo
    ejecuta este binario creando un proceso, con su espacio de direcciones,
    y copiando el binario en las direcciones baja de la memoria:

     +-----------------------------+-------+                 +---------+ 
     |     imagen binaria          |       |                 |         |
     +--------+--------------------+       |                 |         |
     | c�digo | variables globales | heap  | -->         <-- | pila    |
     |        | inicializada       |       |                 |         |
     +--------+--------------------+-------+                 +---------+ 

  + Ventajas: Eficiente en tiempo de carga y ejecuci�n.

  + Desventajas: El binario es dependiente de la plataforma

Interpretaci�n

  Interpretaci�n directa del programa fuente

  + Cada vez que se ejecuta el programa, el int�rprete realiza todas
    las fases presentadas m�s arriba (an�lisis l�xico ... generaci�n
    de c�digo intermedio).

  + El int�rprete luego decodifica y ejecuta directamente el
    c�digo intermedio.

  + Ventajas: c�modo, interacci�n r�pida

  + Desventajas: lento para ejecutar y cargar, se distribuyen programas
    fuentes

  + Ejemplos: Perl, Scheme

  Interpretaci�n de c�digo intermedio

  + El c�digo intermedio se guarda en un archivo.  Para ejecutar el
    programa existe un interprete que lee el archivo y lo ejecuta
    decodificando el mismo las instrucciones intermedias.

  + Ventajas: Archivo resultante es independiente de la plataforma y se puede
    distribuir sin entregar el c�digo fuente.

  + Desventajas: Muy ineficiente en tiempo de ejecucion (24x)

  + Ejemplos: Emacs Lisp (archivos .elc), java 1.0

Compilacion JIT

  + El c�digo intermedio se guarda en un archivo.  Para ejecutar el
    programa existe un compilador JIT que lee el archivo y lo traduce
    a instrucciones de m�quina, t�picamente sobre la marcha a medida
    que se va ejecutando, y en el mismo proceso en donde se ejecuta el JIT

  + Ventajas:
    � Archivo resultante es independiente de la plataforma y se puede
      distribuir sin entregar el c�digo fuente
    � El JIT puede hacer un perfil del tiempo de ejecuci�n para
      determinar que c�digo necesita m�s optimizaci�n
    � Para programas que toman horas en ejecutarse, el JIT
      puede generar un c�digo muy eficiente gracias al perfil
      del tiempo de ejecuci�n

  + Desventajas: 
    � Tiempo de carga ineficiente, porque hay que compilar sobre la marcha
    � En programas de corta duraci�n (menos de un minuto), el JIT
      no alcanza a hacer optimizaciones y el c�digo es lento.
      Esto es especialmente molesto con programas que se ejecutan
      muchas veces.

