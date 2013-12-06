# Cuarto modulo

## M - Paradigma OO

- **Describa conceptualmente el POO y sus principales componentes.**

	Conjunto de objetos que interactuan entre si intercambiando
	mensajes para lograr un objetivo en comun.
	 - encapsulamiento
	 - abstraccion
	 - polimorfismo
	 - herencia


**Paradigma OO:**
El Paradigma OO es un paradigma de programación orientado a objetos que representa los conceptos como "objetos" que tienen 1- campos de datos (o sea, atributos que describen los objetos) y 2- prodecimientos relacionados conocidos como "métodos". Los objetos interactúan entre ellos para diseñar aplicaciones y programas de computación.

**Características principales de la programación OO:**

*Abstracción:*
Denota las características esenciales de un objeto, donde se capturan sus comportamientos. Cada objeto en el sistema sirve como modelo de un "agente" abstracto que puede realizar trabajo, informar y cambiar su estado, y "comunicarse" con otros objetos en el sistema sin revelar cómo se implementan estas características. Los procesos, las funciones o los métodos pueden también ser abstraídos, y, en ese caso, se requiere una variedad de técnicas para ampliar una abstracción. El proceso de abstracción permite seleccionar las características relevantes dentro de un conjunto e identificar comportamientos comunes para definir nuevos tipos de entidades en el mundo real. La abstracción es clave en el proceso de análisis y diseño orientado a objetos, ya que mediante ella podemos llegar a armar un conjunto de clases que permitan modelar la realidad o el problema que se quiere atacar.

*Encapsulamiento:*
Significa reunir todos los elementos que pueden considerarse pertenecientes a una misma entidad, al mismo nivel de abstracción. Esto permite aumentar la cohesión de los componentes del sistema. Algunos autores confunden este concepto con el principio de "ocultación", principalmente porque se suelen emplear conjuntamente.

*Polimorfismo:*
Comportamientos diferentes, asociados a objetos distintos, pueden compartir el mismo nombre; al llamarlos por ese nombre se utilizará el comportamiento correspondiente al objeto que se esté usando. O, dicho de otro modo, las referencias y las colecciones de objetos pueden contener objetos de diferentes tipos, y la invocación de un comportamiento en una referencia producirá el comportamiento correcto para el tipo real del objeto referenciado. Cuando esto ocurre en "tiempo de ejecución", esta última característica se llama asignación tardía o asignación dinámica. Algunos lenguajes proporcionan medios más estáticos (en "tiempo de compilación") de polimorfismo, tales como las plantillas y la sobrecarga de operadores de C++.

*Herencia:*
Las clases no están aisladas, sino que se relacionan entre sí, formando una jerarquía de clasificación. Los objetos heredan las propiedades y el comportamiento de todas las clases a las que pertenecen. La herencia organiza y facilita el polimorfismo y el encapsulamiento, permitiendo a los objetos ser definidos y creados como tipos especializados de objetos preexistentes. Estos pueden compartir (y extender) su comportamiento sin tener que volver a implementarlo. Esto suele hacerse habitualmente agrupando los objetos en clases y estas en árboles que reflejan un comportamiento común. Cuando un objeto hereda de más de una clase se dice que hay herencia múltiple.

*Modularidad:*
Se denomina modularidad a la propiedad que permite subdividir una aplicación en partes más pequeñas (llamadas módulos), cada una de las cuales debe ser tan independiente como sea posible de la aplicación en sí y de las restantes partes. Estos módulos se pueden compilar por separado, pero tienen conexiones con otros módulos. Al igual que la encapsulación, los lenguajes soportan la modularidad de diversas formas.

*Principio de ocultación:* 
Cada objeto está aislado del exterior, es un módulo natural, y cada tipo de objeto expone una interfaz a otros objetos que especifica cómo pueden interactuar con los objetos de la clase. El aislamiento protege a las propiedades de un objeto contra su modificación por quien no tenga derecho a acceder a ellas; solamente los propios métodos internos del objeto pueden acceder a su estado. Esto asegura que otros objetos no puedan cambiar el estado interno de un objeto de manera inesperada, eliminando efectos secundarios e interacciones inesperadas. Algunos lenguajes relajan esto, permitiendo un acceso directo a los datos internos del objeto de una manera controlada y limitando el grado de abstracción. La aplicación entera se reduce a un agregado o rompecabezas de objetos.

*Recolección de basura:*
La recolección de basura es la técnica por la cual el entorno de objetos se encarga de destruir automáticamente, y por tanto desvincular la memoria asociada, los objetos que hayan quedado sin ninguna referencia a ellos. Esto significa que el programador no debe preocuparse por la asignación o liberación de memoria, ya que el entorno la asignará al crear un nuevo objeto y la liberará cuando nadie lo esté usando. En la mayoría de los lenguajes híbridos que se extendieron para soportar el Paradigma de Programación Orientada a Objetos como C++ u Object Pascal, esta característica no existe y la memoria debe desasignarse expresamente.

**Componentes principales de los lenguages de programación OO:**
	
*Objetos:*
Un objeto tiene una o más variables y cuenta con métodos que trabajan en él. Por lo general, las variables son privadas, y solo se puede acceder a ellas a través de los métodos de ese objeto. Los objetos proporcionan una manera natural de modelar entidades del mundo real y entidades sibernéticas como archivos, bases de datos, páginas web, componentes de la interfaz de usuarios, etc.

*Clases:*
Una clase es una familia de objetos con variables y métodos similares. Una *subclase* entiende una clase dada con más componentes y métodos. Cada subclase puede tener sus propias subclases y así formar una jerarquía de clases.

 
 
- **?Como evoluciona el concepto de tipos a lo largo de la historia de
    los lenguajes? Hasta llegar al Paradigma OO.**

Los distintos valores que manipulan los programas de computación se agrupan en *tipos*. Por ejemplo, casi todos los lenguages disntinguen entre números enteros y reales, y entre booleanos y enteros. Un *tipo* es un conjunto de valores, pero no todos los conjuntos de valores forman necesariamente un tipo. Para que un conjunto de valores sea considerado un tipo, todas las operaciones relacionadas con ese tipo se deben comportar de la misma forma cuando se aplican a todos los valores del tipo. Es decir, que un tipo se caracteriza no solo por el conjunto de valores sino también por las operaciones que se aplican a esos valores.
	
Todos los lenguages de programación soportan *tipos primitivos* y *tipos compuestos*. Algunos también soportan *tipos recursivos*.
	
*Tipo primitivo:*
No se puede descomponer en valores más sencillos. Los valores ya son primitivos. Pueden ser incorporados (built-in), ya incluidos en el lenguage; definidos, se definen de cero, nuevos; o discretos, que tienen una relación directa con un rango de números enteros.

*Tipo compuesto:*
Está compuesto por valores más simples. Los valores son compuestos. Pueden ser estructuras, registros, arreglos, tipos algebráicos, registros discriminados, objetos, uniones, cadenas, listas, árboles, relaciones, etc.

*Tipo recursivo:*
Se define según él mismo, como las listas y las cadenas. Una *lista* es una secuencia de valores, que puede tener cualquier cantidad de componentes, incluso cero (*lista vacía*). Las listas pueden ser homogéneas o heterogéneas en cuanto al tipo de sus componentes. Una *cadena* es una secuencia de caracteres, que al igual que las listas puede tener cualquier cantidad de componentes, incluso cero (*cadena vacía*).

**Conceptos relacionados:**
	
*Sistemas de tipos:*
Un sistema de tipos agrupa los valores en tipos. Esto permite que los programadores describan los datos con mayor eficacia y evita que los programas realicen operaciones sin sentido, un *error de tipo*. Los sistemas de tipos distinguen los lenguages de alto nivel de los lenguages de bajo nivel. En los de bajo nivel, los únicos tipos que hay son bytes y palabras, por lo cual no se pueden evitar las operaciones sin sentido.

En los lenguages de *tipos estáticos*, las variables y las expresiones son fijas, ya sea expllícitamente definidas por el programador o inferidas por el compilador. En los lenguages de *tipos dinámicos*, los valores son fijos, pero las variables y las expresiones, no. Cada vez que se computa un operando, puede dar un valor de un tipo diferente. La mayoría de los lenguages de alto nivel son de tipos estáticos. En cambio, SMALLTALK, LISP, PROLOG, PERL y PYTHON) son de tipos dinámicos.

*Equivalencia de tipos:*
Por un lado, la *equivalencia de nombres* hace que cada tipo diferente se defina en un único lugar, lo cual puede resultar un inconveniente, pero ayuda a que el programa se pueda mantener con mayor facilidad (mayoría de los lenguajes). Por el otro, la *equivalencia estructural* hace que se puedan confundir los tipos que solo por casualidad son similares (ALGOL68).

*Principio de compleción de tipos:*
Establece que ninguna operación se debe restringir arbitrariamente en cuanto a los tipos de sus operandos. Decir que los operandos de la operación *and* son booleanos no es una restricción "arbitratia", porque es algo propio e inherente de esta operación. Pero sí es "arbitrario" decir que solo se pueden asignar los valores de cierto tipo, o que solo se pueden pasar como argumentos o devolver como resultados de una función los valores de cierto tipo.

El diseño de software depende de la descomposición de programas grandes en unidades de programas. Y las unidades de programas más importantes son los paquetes, los tipos abstractos (TAD) y las clases.

Los *paquetes* agrupan declaraciones de varios componentes.
Los *TAD* tienen representaciones privadas, pero operaciones públicas.
Las *clases* definen la estructura de familias de objetos, donde cada objeto es un grupo de variables privadas con operaciones públicas.

Para que la interfaz del programa (API) sea sencinlla, un paquete suele deja visibles solamente algunos de sus componentes al código de la aplicación que lo utiliza. Estos componentes son *públicos*. Los demás componentes solo se ven dentro del paquete. Son *privados* y sirven para implementar los componentes públicos. Un paquete con componentes privados oculta información que es irrelevante para el código de la aplicación. Esta técnica que simplifica las API se denomina *encapsulación*.

Una *clase* es un conjunto de objetos similares. Todos los objetos de una misma clase tienen los mismos componentes y las mismas operaciones. Los componentes se denominan *variables* de instancia o miembro, y las operaciones se denominan *constructores* y *métodos*. Un constructor es una operación que crea, y generalmente inicializa, un objeto nuevo en la clase. Un método es una operación que inspecciona o actualiza un objeto ya existente en la clase..


- **Compare el paradigma OO y el desarrollo a traves de TADs.**
 
**Paradigma OO:**
El Paradigma OO es un paradigma de programación orientado a objetos que representa los conceptos como "objetos" que tienen 1- campos de datos (o sea, atributos que describen los objetos) y 2- prodecimientos relacionados conocidos como "métodos". Los objetos interactúan entre ellos para diseñar aplicaciones y programas de computación. (ver características y componentes arriba).

Desarrollo a través de los datos abstractos (TAD): NO LO SÉ

	 - OO aporta herencia
	 
- **Dentro de la evolucion historica de los lenguajes de programacion,
    describa los antecedentes del Paradigma de Objetos.**
	
	ALGOL 60: (1963) Lenguaje imperativo. Fue el primero que se diseñó para comunicar algoritmos y no solo para programar una computadora. Introdujo el concepto de estructura de bloques, mediante el cual se podían declarar variables y procedimientos donde fuera que se necesitaran en el programa (los bloques se pueden anidar). También fue el primero en soportar procedimientos recursivos. Considera las etiquetas como valores y las pasa como argumentos...
	
	SIMULA: (1979) Lenguaje orientado a objetos. Introdujo los conceptos de *objeto* y *clase*. Otro lenguaje de los ALGOL.
	
	SMALLTALK: (1989) Primer lenguaje puramente orientado a objetos, en el que programas enteros se desarrollaban a partir de clases. Tan puro que todos los valores son objetos. Incluso las órdenes se cuentan como objetos de la clase Bloque, y las estructuras de control como "si" (*if*) y "mientras" (*while*) son operaciones de esa clase. Muy económico en cuanto a conceptos, pero tiene una sintaxis extraña, tipos dinámicos y alcance dinámico (ver arriba).
	

# N - Paradigma Funcional

- **Describa conceptualmente el paradigma funcional y sus principales
    componentes.**
	
	- una entrada tiene siempre el mismo resultado
	- *componentes* Funciones, variables

**Paradigma funcional:**
Se basa en funciones sobre tipos, como listas y árboles. LISP fue el primer lenguaje funcional, que demostró que se pueden escribir programas sin recurrir a variables ni hacer uso de asignaciones. ML y HASKELL son lenguajes funcionales modernos. Tratan las funciones como valores comunes, que se pueden pasar como parámetros y devolver como resultados desde otras funciones. Además, incorporan sistemas de tipos avanzados, que nos permiten escribir funciones polimórficas, es decir, funciones que operan en datos de diferentes tipos. ML, al igual que LISP, es impuro, porque soporta variables y asignaciones. HASKELL, es un lenguaje funcional puro.
	
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
	
**Paradigma lógico:**
Se basa en un subconjunto de lógica de predicados. Los programas lógicos, en lugar de calcular valores de salida a partir de valores de entrada, infieren las relaciones entre los valores. PROLOG fue el primer lenguaje lógico, y sigue siendo el más popular. En su forma lógica pura es bastante ineficiente, por lo cual se lo ha ampliado con características lógicas adicionales para que resulte más usable.

Los programas lógicos implementan relaciones (ya sean binarias, unitarias, terciarias, etc.), y por este motivo son de más alto nivel que los lenguajes imperativos o funcionales. Permiten aprovechar los beneficios de *backtracking* (intento fallido de comprobar una solicitud con respecto a una cláusula en particular, en el que la solicitud se comprueba, en cambio, con respecto a otra cláusula diferente), pero en la práctica también necesitan características impuras (cortar y entrada/salida).

Los conceptos fundamentales de los programas lógicos son: afirmaciones, cláusulas de Horn y relaciones.


- **Indique la filosofia de este paradigma, como se compone un
    programa, como se inicia la ejecucion, etc.** 	
	
- **Dentro de la evolucion historica de los lenguajes de programacion,
    describa los antecedentes del Paradigma Logico.**
	

# P - Comparaciones

Los lenguajes funcionales y lógicos tienen la contra de su incapacidad para modelar estados de manera natural, excepto por las extensiones más o menos ad hoc, que destruyen la claridad conceptual de estos lenguajes.

- **Compare los paradigmas Imperativo y OO.**
- **Compare los paradigmas Imperativo y Funcional.**

**Paradigma imperativo:**
Paradigma dominante desde los comienzos y hasta 1990. Se caracteriza por el uso de variables, órdenes y procedimientos. Luego fue reemplazado por los lenguajes OO.

Se basa en órdenes que actualizan las variables que están almacenadas. La relación cercaba con la arquitectura de la computadora permite que los programas imperativos se implementen en forma eficiente.

Con el paso del tiempo se agregó un concepto más a este tipo de paradigma: la abstracción de datos.

Las *variables* y las *órdenes* son fundamentales porque permiten modelar entidades del mundo real con naturalidad a través de las variables, y procesos del mundo real a través de las órdenes que inspeccionan y actualizan las variables. Este paradigma incluye un amplio repertorio de expresiones: de bloques, condicionales, itertativas y recursivas. Sin embargo, los lenguajes imperativos más importantes (C y ADA) no son lo suficientemente buenos en este aspecto.

Los *procedimientos* permiten generar abstracciones a partir de las órdenes. Se puede diferenciar entre el comportamiento observable de un procedimiento y el algoritmo (las órdenes) mediante el cual este procedimiento alcanza su comportamiento.

La *abstracción de datos* no es compatible con lenguajes imperativos clásicos como C y PASCAL, pero resulta esencial en otros más modernos como ADA. Se puede diferenciar en las propiedades de un tipo abstracto y su representación; entre el comportamiento observable de las operaciones del tipo abstracto y los algoritmos mediante los cuales estas operaciones alcanzan su comportamiento.

- **Compare los paradigmas Imperativo y Logico.**
- **Describa a que se llama un lenguaje hibrido.**  
- **Indique a forma de abordar la solucion de un problema en los
    diferentes paradigmas. Especifique cual es el rol del programador y cual es el de la
    computadora, en cada caso.**
