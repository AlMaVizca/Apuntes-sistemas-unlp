Apref Conceptos:
================

# Primer modulo

## A- Criterios de evaluacion y evolucion de los lenguajes

- **Indique los criterios para evaluar un lenguaje de programacion.**

Facil de escribir -> Legible -> Confiable

Mantenible

Eficiente


*Facil de escribir*
-------------------

Es la medida de cuan facil resulta un lenguaje para contruir soluciones.

   1. Simplicidad -> facil de capturar: entender y recordar.
   2. Expresividad -> Concentrar la atencion en la resolucion del problema
   3. Ortogonalidad -> El usuario comprende mejor si tiene un pequeño
   número de primitivas y un conjunto consistente de reglas de combinación.
   4. Soporte  de Abstraccion -> Concepto clave para manejar la
   complejidad, abstracción de procesos y de datos.
 
*Legible*
---------

Facil de leer a las personas (equipo)

1. Semantica
   2. Sintaxis
   3. Definicion
   4. Estructuras de datos
   5. Estructuras de control

*Confiable*
-----------

Correcto: cumple con las especificaciones
Certificacion:
Verificacion de programas: probar su correción

Chequeo de tipos, Restricción de alias, Robusto

*Mantenibilidad*
----------------

Modificabilidad: Facil para introducir cambios
Factoreo: una sola vez y luego reusar
Localidad: El efecto de una caracteristica se restringe a una porción
local del programa

*Eficiencia*
------------

Tiempo y espacio
Esfuerzo humano
Optimizable

-------
ACA va ale



antes la eficiencia era solo tiempo de ejecucion y espacio de memoria utilizado.



- **En la actualidad como se mide la eficiencia del software?
    Evoluciono este concepto.** 
	
	Pag 13 libro ghezzi..
	
	antes se usaba solamente el tiempo de ejecucion y el espacio
	utilizado, aora tambien se tiene en cuenta el esfuerzo de
	mantenimiento y productividad
	
- **Que significa que un lenguaje sea ortogonal?**
- **Construya ejemplos de cada uno de los criterios** 	
- **Indique cuales fueron los motivos que a su juicio condujeron a
la evolucion historica de los lenguajes de programacion**
- **Describa la evolucion de los lenguajes de programacion en cuanto a su Sistema de Tipos.**
- **Describa la rama de la evolucion de los lenguajes que condujo al Paradigma de Objetos.**		
- **Desde el punto de vista de la evolucion de los lenguajes, defina los objetivos, caracteristicas y aportes de Ada**
- **Segun su criterio: Cuales fueron los lenguajes que mas
aportaron a la evolucion de los lenguajes. Por que?**

## B- Procesamiento de un lenguaje

- **Que son la compilacion y la interpretacion? Defina y describa ambos
procesos. Comparelos por distintos criterios.**
 - Compilador:
  - Analisis lexico
  - Analisis Sintactico
  - Analisis semantico(estatica)
  - Traduccion
  - Optimizacion
  - Codigo objeto
 - Interpretacion
  - Lectura de sentencia
  - Interpretacion
  - Ejecucion

## C- Sintaxis y semantica
- **Sintaxis y semantica de un lenguaje. Defina que es cada concepto
e indique cual es la manera formal o no formal que usan generalmente
los lenguajes de  programacion.**

*Syntax influences how programs are written by the programmer, read by
other programmers, and parsed by the computer. Semantics determines
how programs are composed by the programmer, understood by other
programmers, and interpreted by the computer. Pragmatics influences
how programmers are expected to design and implement programs in
practice. Syntax is important, but semantics and pragmatics are more
important still.*

## D- Sintaxis
- **Defina y describa la utilidad de la sintaxis de un lenguaje**
*utilidad de componer instrucciones*
Es un protocolo para poder escribir en un leguaje

- **Diferencie: Reglas lexicas y  reglas sintacticas.**

*Reglas lexicas:* componer las palabras del alfabeto
*Reglas sintacticas:* componer 

- **Sintaxis abstracta y sintaxis concreta. Ejemplifique.** 
Sintaxis abstracta: Estructura
Sintaxis concreta: forma de escribir en el lenguaje concreto

- **Que forma de definir la sintaxis conoce?, Comparelas.**
*Lenguaje natural*
*BNF y EBNF*
*Diagrama de conboy?...*

- **Diferencias entre una gramatica libre de contexto y una gramatica
sensible al contexto. Ejemplos**
evaluacion de tipos en un condicional

- **Cuando una gramatica es ambigua? Se puede solucionar?**
Cuando una gramatica puede generar dos arboles sintacticos

- **Que son BNF y EBNF? Definalas y comp?relas.**
Herramientas para escribir lenguajes
EBNF es la version extendida

# Segundo modulo

## E- Semantica
- **Que formas de definir la Semantica de un lenguaje conoce? 
Describalas brevemente.**
No existe una forma formal.
Gramatica con atributos (semantica estatica)
distintos tipos de semantica (estatica - dinamica - operacional)

- **Defina y diferencia la semantica estatica de la semantica dinamica. Ejemplifique.** 		

semantica estatica -> compilacion, comprobacion de tipo, operaciones 
semantica dinamica -> Describe el efecto de ejecutar las diferentes
construcciones en el lenguaje de programacion.


## F- Semantica Operacional
- **Enumere los  elementos principales de la semantica operacional y
    describa dos de ellos.**
	
- **Para que nos sirve el procesador abstracto?**	
- **Describa el  concepto de ligadura y su funcion.** 	

## G - Variables

- **Enumere los atributos de las variables y describalos en general.**
- **Clasifique las variables a acuerdo a cada uno de sus atributos y
    describa cada  una en forma general.**
	
- **Es lo mismo una variable global que una variable estatica? Que
    relacion tienen? Ejemplifique**
	
- **Variables automaticas, semidinamicas y dinamicas. Indique
    diferencias entre ellas. Ejemplifique**
	
- **Cuales son las diferencias semanticas entre variable estatica y
    variable semiestatica?. Ejemplifique.**
	
- **Cuales son las diferencias semanticas entre variable estatica y
    constante. Ejemplifique.**
	
- **Por que se recomienda el uso de constantes?** 		 
- **Describa la ligadura estatica y ligadura dinamica de dos atributos
    de las variables.** 	   
	
- **Defina, analice e indique ventajas y peligros de los
    alias. Ejemplos. Indique si se pueden evitar.**
	
- **Construya al menos dos ejemplos en los que no coincidan los
    atributos de alcance y tiempo de vida.**    
	

## H - Representacion en ejecucion

- **En general, indique las caracteristicas de un lenguaje con un
    esquema estaticas, uno basado en pila y uno con esquema
    dinamico.**
	
- **Los lenguajes actuales ?se encuadran en uno de estos esquemas?
    Justifique.**
	
- **Indique con que clase de variables se puede trabajar en cada
    esquema.**
- **Que informacion se guarda en el segmento de codigo de una
    unidad?**
	
- **Esquematice el registro de activacion de una unidad, indicando que
    informacion  contiene.**
- **Describa el ambiente de referencia de una unidad.**
- **Justifique la existencia de un link dinamico en la semantica
    operacional de un lenguaje. Si el lenguaje sigue la cadena
    estatica, para resolver las referencias no locales, ?es necesario
    el link dinamico? Justifique**
	
- **?Que es una variable sensible a la historia? ?Todos los lenguajes
    las proveen?.**
	
- **Marque diferencias semanticas y como se los implementa, a un
    arreglo seminidinamico y un arreglo dinamico. Que se hace en
    compilacion y que en ejecucion?**
	
- **Cuando es indispensable que un objeto de dato sea almacenado en el
    heap?  Ejemplos**

# Tercer modulo

## I- Parametros

- **Indique las maneras de compartir datos entre unidades, describa
    sus caracteristicas y plantee una comparacion entre ellas.**
	
- **A traves de ejemplos unidades demuestre la importancia de conocer
    el momento  de asignacion y orden de evaluacion de los parametros
    en el pasaje de parametros.**
	
- **En el metodo de pasaje de parametros, indique a traves de
    ejemplos, las distintas formas de pasaje de parametros dato.**
	
- **Describa el pasaje de parametro procedimiento, indique porque es
    necesaria mas informacion que en el parametro dato.**
	
- **Como pueden ligarse los parametros formales y los parametros
    reales?**
	
## J- Tipos de datos

- **Indique si los conceptos: Sistema de tipos y Tipos de datos son iguales.**
- **Tipo puntero: indique y ejemplifique dos casos en donde se
    demuestre la inseguridad de su uso.**
	
- **Marque diferencia entre tipo Uni?n y Uni?n discriminada. Incluya
    la inseguridad que puede provocar su uso y como evitarla.**
	
- **Concepto de alias y sobrecarga. Definalos y de ejemplos.**
- **Indique que caracteristicas deberia tener un lenguaje, para que se
    diga que tiene un sistema de tipo fuerte.**
	
- **Lenguaje fuertemente y debilmente tipado. Defina que indican cada
    uno de esos conceptos. Estan relacionados con que el tipo se ligue
    a la variable en el momento de ejecucion o compilacion?**
	
- **Defina el concepto de "compatibilidad de tipos". Nombre un
    lenguaje e indique que tipo de compatibilidad de tipo utiliza.**
	
- **?Cual es la utilidad de un sistema de tipos?**

## K- Abstraccion de control a nivel de Sentencias

- **Sentencia de asignacion. Indique que caracteristica tiene la
    sentencia de asignacion del lenguaje C que la diferencia de los
    otros lenguajes, como Pascal, Ada, etc. Ejemplifique.**
	
- **Enumere las soluciones de los distintos lenguajes al problema  de
    los "else" colgados. Comparelas**
	

## L- Abstraccion de control a nivel de Unidad: Excepciones

- **Frente a un lenguaje de programacion que presenta mecanismos para
    manejo de   excepciones, que aspectos del mismo deberi conocer
    para hacer un buen uso de este mecanismo. Enumere los puntos a
    tener en cuenta y ejemplifique con uno de los lenguajes vistos.** 
	
- **Indique las diferencias entre el manejo que hace ADA, C+ + y Java
    respecto a los casos animalos.**
	
- **Indique en que casos se propaga una excepcion y elija dos
    lenguajes que tengan diferentes maneras de propagar las
    excepciones. Ejemplifique.**


# Cuarto modulo

## M - Paradigma OO

- **Describa conceptualmente el POO y sus principales componentes.**

	Conjunto de objetos que interactuan entre si intercambiando
	mensajes para lograr un objetivo en comun.
	 - encapsulamiento
	 - abstraccion
	 - polimorfismo
	 - herencia
 
*componentes* clases, metodos, objetos, mensajes.
 
*Objetos*:entidades con estado interno y comportamiento.

- **?Como evoluciona el concepto de tipos a lo largo de la historia de
    los lenguajes? Hasta llegar al Paradigma OO.**
	
	
	- Tipos predefinidos
	- Tipos definidos por el usuario
	- Tad's  ->encapsulamiento y Ocultamiento?
	- Clases
		
- **Compare el paradigma OO y el desarrollo a traves de TADs.**
 
	 - OO aporta herencia
	 
- **Dentro de la evolucion historica de los lenguajes de programacion,
    describa los antecedentes del Paradigma de Objetos.**
	
	algol 60
	simula
	smalltalk
	

# N - Paradigma Funcional

- **Describa conceptualmente el paradigma funcional y sus principales
    componentes.**
	
	- una entrada tiene siempre el mismo resultado
	- *componentes* Funciones, variables
	
- **Describa detalladamente que significan y como actuan la
    Currificacion y la transparencia referencial.**    
	
	
	*transparencia referencial* -> con los mismos valore de entradas
     las mismas salidas
	
- **Dentro de la evolucion historica de los lenguajes de programacion,
    describa los antecedentes del Paradigma Funcional.**
	

# O - Paradigma L?gico

- **Describa conceptualmente el paradigma logico y sus principales
    componentes.**
	
	un paradigma logico en el cual los programas se consideran como
	una serie de aserciones logicas
	
	Se compone de reglas y hechos.
	
	termino, variable constante
	
- **Indique la filosofia de este paradigma, como se compone un
    programa, como se inicia la ejecucion, etc.** 	
	
- **Dentro de la evolucion historica de los lenguajes de programacion,
    describa los antecedentes del Paradigma Logico.**
	

# P - Comparaciones

- **Compare los paradigmas Imperativo y OO.**
- **Compare los paradigmas Imperativo y Funcional.**
- **Compare los paradigmas Imperativo y Logico.**
- **Describa a que se llama un lenguaje hibrido.**  
- **Indique a forma de abordar la solucion de un problema en los
    diferentes paradigmas. Especifique cual es el rol del programador y cual es el de la
    computadora, en cada caso.**
	
