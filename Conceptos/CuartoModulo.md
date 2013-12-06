# Cuarto modulo

## M - Paradigma OO

- **Describa conceptualmente el POO y sus principales componentes.**

	Conjunto de objetos que interactuan entre si intercambiando
	mensajes para lograr un objetivo en comun.
	 - encapsulamiento
	 - abstraccion
	 - polimorfismo
	 - herencia

	El Paradigma OO es un paradigma de programación orientado a objetos que representa los conceptos como "objetos" que tienen 1- campos de datos (o sea, atributos que describen los objetos) y 2- prodecimientos relacionados conocidos como "métodos". Los objetos interactúan entre ellos para diseñar aplicaciones y programas de computación.

	Características principales de la programación OO:

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

	Componentes principales de los lenguages de programación OO:
	

*Clase:*s, metodos, objetos, mensajes.
 
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
