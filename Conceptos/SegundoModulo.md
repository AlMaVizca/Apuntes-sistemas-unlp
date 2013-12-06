# Segundo modulo

## E- Semantica
- **Que formas de definir la Semantica de un lenguaje conoce? 
Describalas brevemente.**

Teniendo en cuenta que la semantica da significado a los programas
sintacticamente correctos, no existe una forma formal. 
Existen distintos momentos en los que se evalua la semantica, la que
se verifica antes de que el programa se ejecute, semantica estatica, y
si se verifica durante su funcionamiento se llama dinamica.

----
Gramatica con atributos (semantica estatica)
distintos tipos de semantica (estatica - dinamica - operacional)

- **Defina y diferencia la semantica estatica de la semantica dinamica. Ejemplifique.** 		

La semantica estatica se encarga de realizar la comprobacion de tipos
sobre las operaciones que se realizaran en el programa, mientras que
la semantica dinamica describe el efecto de ejecutar las diferentes
construcciones en el lenguaje

Es decir:

La semantica estática va a evaluar que en una condicion de if el valor
de la condicion sea un valor de verdad (True or False).
La semantica dinamica verifica que por ejemplo en el recorrido de un
vector realizando la busqueda de un valor, no se excedan los limites
del mismo. (no pedir el dato 14 si el vector tiene 10 elementos)


## F- Semantica Operacional
- **Enumere los  elementos principales de la semantica operacional y
    describa dos de ellos.**

- **Variables** *La nocion de variable es una abstraccion que permite
identificar celdas de memoria*

Una variable tiene los siguientes atributos <nombre, alcance, tipo, l-valor, r-valor>

   - **nombre:** string de caracteres que se utiliza para referenciar
      la variable
   - **alcance:** rango de instrucciones en el que se conoce el nombre
   - **tipo:** valores y operaciones permitidas
   - **l-valor:** lugar de memoria asociado con la variable(tiempo de
       vida)
   - **r-valor:** valor codificado almacenado en la ubicacion de la
       variable
	   
- **Ligadura** *Especificacion exacta de la naturaleza de un atributo*

En criollo podemos decir que la ligadura tiene que ver con el lugar
donde se almacenan los atributos de una entidad.

   - **estatica:** Si se establece antes de la ejecucion y no se puede cambiar
   - **dinamica:** Se establece en el momento de la ejecución y puede
       cambiarse de acuerdo a alguna regla especifica del lenguaje.
	   
- **Unidades** *Mecanismos que controlan el flujo de ejecución entre
-rutinas con todas las ligaduras involucradas.*
- **Modulos de ejecucion** *Es la representacion de una unidad en ejecucion*
- **Parametros** 



- **Para que nos sirve el procesador abstracto?**	

El procesador abstracto nos sirve para estudiar la estructura de un
lenguaje de programacionm por ejemplo para saber como las estructuras
de datos son ordenadas y accedidas en un conjunto de instrucciones de
maquinas.

Es un procesador que cuenta con una memoriad de Código, otra de datos
y un puntero a la instruccion que se esta ejecutando(ip)


- **Describa el  concepto de ligadura y su funcion.** 	

**Ligadura** *Especificacion exacta de la naturaleza de un atributo*

En criollo podemos decir que la ligadura tiene que ver con el lugar
donde se almacenan los atributos de una entidad.

   - **estatica:** Si se establece antes de la ejecucion y no se puede cambiar
   - **dinamica:** Se establece en el momento de la ejecución y puede
       cambiarse de acuerdo a alguna regla especifica del lenguaje.


## G - Variables

- **Enumere los atributos de las variables y describalos en general.**

Una variable tiene los siguientes atributos <nombre, alcance, tipo, l-valor, r-valor>

   - **nombre:** string de caracteres que se utiliza para referenciar
      la variable
   - **alcance:** rango de instrucciones en el que se conoce el nombre
   - **tipo:** valores y operaciones permitidas
   - **l-valor:** lugar de memoria asociado con la variable(tiempo de
       vida)
   - **r-valor:** valor codificado almacenado en la ubicacion de la
       variable


- **Clasifique las variables a acuerdo a cada uno de sus atributos y
    describa cada  una en forma general.**
	
   - **alcance:**
      - **estaticas** la ligadura se realiza segun el orden del código
          fuente,este tipo de alcance es el utilizado por ejemplo por C
      - **dinamicas** la ligadura se realiza según el orden de
          instrucciones que sigue el programa, este tipo de alcance es
          el utilizado por APL, LISP (como los primeros que lo
          definen) y snobol4
   - **tipo:**
      - **predefinidos:** son los tipos de datos que vienen definidos
          en el lenguaje en uso
	  - **definidos por el usuario:** son tipos de datos que define el usuario
	  - **TADs:**
	  - El tipado estatico hace referencia a la asignacion de un tipo
        a la variable en momento de compilacion
	  - El tipado dinamico hace referencia a la asignacion de tipo
        durante la ejecucion de las insturcciones, esto hace que las
        variables puedan ser polimorficas, es decir cambiar de tipo
   - **l-value:** tiempo de vida
      - **alocacion estatica**
	  - **alocacion dinamica**
	  - **alocacion automatica**
	  
Este ultimo hay que completarlo
-------------------------------

- **Es lo mismo una variable global que una variable estatica? Que
    relacion tienen? Ejemplifique**

No son lo mismo, 
	
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
	
Se llama alias cuando dos variables con el atributo nombre distinto
tienen el mismo l-value, eso provoca que cuando una variable cambia,
la otra también.
El alias es util ya que permite por ejemplo compartir un dato
identificando un nombre distinto segun el contexto de uso sin
tener que incremetar el uso de espacio de memoria, esto tambien
provoca que por ejemplo si se desaloca una variable, la otra queda
apuntando a datos no concretos.

Se puede evitar el uso de alias e incluso es una practica recomendada.
	
- **Construya al menos dos ejemplos en los que no coincidan los
    atributos de alcance y tiempo de vida.**    
	
- la variable estatica (respecto a su l-valor) el tiempo de vida es mayor que el alcance
porque el valor perdura en memoria durante y despues de finalizado el programa

- un puntero tiene menor tiempo de vida que el alcance 
- los procedimientos / funciones tienen mas alcance que tiempo de vida


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
