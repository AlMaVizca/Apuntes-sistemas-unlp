# Segundo módulo


## E- Semántica
### E-1. Que formas de definir la Semantica de un lenguaje conoce? 
Describalas brevemente.

Teniendo en cuenta que la semantica da significado a los programas
sintacticamente correctos, no existe una forma formal. 


Existen distintos momentos en los que se evalua la semantica:
- Semantica estática -> se verifica antes de que el programa se ejecute
- Semantica Dinámica -> se verifica durante su funcionamiento.

----

Gramática con atributos (semántica estática)
Distintos tipos de semantica (estatica - dinamica - operacional)

----

### E-2. Defina y diferencia la semántica estática de la semántica dinámica. Ejemplifique. 		

La **semántica estática** se encarga de realizar la comprobación de nombres y tipos
sobre las operaciones que se realizaran en el programa, mientras que

La **semántica dinámica** describe el efecto de ejecutar las diferentes
construcciones en el lenguaje

Es decir:

*La semantica estática va a evaluar que en una condicion de if el
valor de la condicion sea un valor de verdad (True or False).*

*La semantica dinamica verifica que por ejemplo en el recorrido de un
vector realizando la busqueda de un valor, no se excedan los limites
del mismo. (no pedir el dato 14 si el vector tiene 10 elementos)*


## F- Semantica Operacional
### F-1. Enumere los  elementos principales de la semantica operacional y describa dos de ellos.

- **Variables** *La noción de variable es una abstracción que permite
identificar celdas de memoria*

Una variable tiene los siguientes atributos <nombre, alcance, tipo, l-valor, r-valor>

   - **nombre:** Caracteres alfabeticos y numericos utilizados para identificar
      la variable
   - **alcance:** Rango de instrucciones en el que se conoce el nombre
   - **tipo:** valores y operaciones permitidas
   - **l-valor:** Lugar de memoria asociado con la variable(tiempo de
       vida)
   - **r-valor:** Valor codificado almacenado en la ubicacion de la
       variable
	   
- **Ligadura** *Especificacion exacta de la naturaleza de un atributo*

En criollo podemos decir que la ligadura tiene que ver con el lugar
donde se almacenan los atributos de una unidad.

   - **estática:** Si se establece antes de la ejecucion y no se puede cambiar
   - **dinamica:** Se establece durante la ejecución y puede
       cambiar de acuerdo a alguna regla especifica del lenguaje.
	   
- **Unidades** *Mecanismos que controlan el flujo de ejecución entre
  rutinas con todas las ligaduras involucradas.* 
- **Modúlos de ejecución** *Es la representación de una unidad en ejecución*
- **Parametros** 



### F-2. ¿Para que nos sirve el procesador abstracto?	

El procesador abstracto nos sirve para estudiar la estructura de un
lenguaje de programación por ejemplo para saber como las estructuras
de datos son ordenadas y accedidas en un conjunto de instrucciones de
maquinas.

Es un procesador que cuenta con una memoria de Código, otra de datos
y un puntero a la instrucción que se esta ejecutando(ip)


### F-3. Describa el  concepto de ligadura y su función. 	

**Ligadura** *Especificación exacta de la naturaleza de un atributo*

En criollo podemos decir que la ligadura tiene que ver con el lugar
donde se almacenan los atributos de una entidad.

   - **estática:** Si se establece antes de la ejecucion y no se puede cambiar
   - **dinámica:** Se establece en el momento de la ejecución y puede
       cambiarse de acuerdo a alguna regla especifica del lenguaje.


## G - Variables

### G-1. Enumere los atributos de las variables y describalos en general.

Una variable tiene los siguientes atributos <nombre, alcance, tipo, l-valor, r-valor>

   - **nombre:** string de caracteres que se utiliza para referenciar
      la variable
   - **alcance:** rango de instrucciones en el que se conoce el nombre
   - **tipo:** valores y operaciones permitidas
   - **l-valor:** lugar de memoria asociado con la variable(tiempo de
       vida)
   - **r-valor:** valor codificado almacenado en la ubicacion de la
       variable


### G-2. Clasifique las variables a acuerdo a cada uno de sus atributos y describa cada  una en forma general.**
	
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
	  - **TADs:** Tipo de dato abstracto asociado a un conjunto de operaciones
	  - El tipado estatico hace referencia a la asignacion de un tipo
        a la variable en momento de compilacion
	  - El tipado dinamico hace referencia a la asignacion de tipo
        durante la ejecucion de las insturcciones, esto hace que las
        variables puedan ser polimorficas, es decir cambiar de tipo
   - **l-value:** tiempo de vida
      - **alocacion estatica** Si se determina estáticamente, la
        variable se entiende como sensible a la historia
	  - **alocacion dinamica**
	     - **Automática** Cuando se alcanza el ámbito de la variable
		 - **Explícita o Semi-Automática** mediante una instrucción explicita (new)
	  - **alocacion persistente** su tiempo de vida no depende de la ejecución
	  
Este ultimo hay que completarlo
-------------------------------

### G-3. ¿Es lo mismo una variable global que una variable estática? Que relación tienen? Ejemplifique.

No son lo mismo, la relacion que tienen es en cuanto al tiempo de vida
de la variable, ambas estan en memoria durante toda la ejecución del
programa.

Una variable global puede ser accedida desde cualquier módulo o
archivo que involucre el programa, mientras que la estática tiene
alcance sólo durante la ejecución del módulo o archivo.

### G-4. Variables automaticas, semidinamicas y dinamicas. Indique diferencias entre ellas. (respecto a su l-valor)Ejemplifique

Las variables dinamicas son aquellas en donde la ligadura de su
l-valor se define durante la ejecución del programa.

Las variables automaticas son un tipo de variable dinamica que se
aloca y desaloca durante la ejecucion de alguna unidad.

Las variables semidinamicas son variables que se alocan o desalocan
por decision del programador.

### G-5. ¿Cuales son las diferencias semanticas entre variable estatica y variable semiestatica?. (respecto a su l-valor)Ejemplifique.

Para poder utilizar una variables estática se necesita reservar
espacio de memoria con anterioridad mientras que en la semiestatica el
espacio es reservado por el programador.

Por ejemplo los arreglos en Ada

### G-6. Cuales son las diferencias semanticas entre variable estatica y constante. Ejemplifique.

una variable estática puede cambiar su valor durante la ejecución del
programa, una contante no.

### G-7. ¿Por que se recomienda el uso de constantes?

Porque ayuda a la legibilidad del código y son un ayuda para utilizar
limites en bucles de control.
	
### G-8. Describa la ligadura estatica y ligadura dinamica de dos atributos de las variables.

La ligadura hace referencia al momento de asociación de un determinado
atributo de la variable. Si se realiza en la carga del programa, es
decir, antes de la ejecución se considera ligadura estática y si se
realiza durante la ejecución se considera ligadura dinámica.

Tipo, l-valor.
	
### G-9. Defina, analice e indique ventajas y peligros de los alias. Ejemplos. Indique si se pueden evitar.
	
Se llama alias cuando dos variables con el atributo nombre distinto
tienen el mismo l-value, eso provoca que cuando una variable cambia,
la otra también.
El alias es util ya que permite por ejemplo compartir un dato
identificando un nombre distinto segun el contexto de uso sin
tener que incremetar el uso de espacio de memoria, esto tambien
provoca que por ejemplo si se desaloca una variable, la otra queda
apuntando a datos no concretos.

Se puede evitar el uso de alias e incluso es una practica recomendada.
	
### G-10. Construya al menos dos ejemplos en los que no coincidan los atributos de alcance y tiempo de vida.    

- la variable estatica (respecto a su l-valor) el tiempo de vida es mayor que el alcance
porque el valor perdura en memoria durante y despues de finalizado el programa

- un puntero tiene menor tiempo de vida que el alcance 
- los procedimientos / funciones tienen mas alcance que tiempo de vida


## H - Representación en ejecución

### H-1. En general, indique las caracteristicas de un lenguaje con un esquema estáticas, uno basado en pila y uno con esquema dinámico.

**Estático**
C1 y C2 - Fortran

- El espacio necesario para la ejecucion se deduce del código
- La alocación puede hacerse estáticamente
- No puede haber recursión

**Basado en pila**
C3 y C4 Pascal

- El espacio se deduce del código
- El espacio es predecible

**Dinámico**
C5 y C6 APL, snobol/4

- El espacio es impredecible
- Los datos se alocan dinámicamente durante la ejecución

### H-2. Los lenguajes actuales ?se encuadran en uno de estos esquemas? Justifique.

Si

### H-3. Indique con que clase de variables se puede trabajar en cada esquema.

(????????)

**Esquema estático**

C1 y C2 : variables estáticas

**Esquema basado en pila**

C3 y C4: Variables automáticas

**Esquema dinámico**

C5 y C6: variables dinámicas y semi-dinamicas

### H-4. Que información se guarda en el segmento de código de una unidad?

En el segmento de código de una unidad se almacena el código fuente
que da significado semántico a la unidad

### H-5. Esquematice el registro de activación de una unidad, indicando que información contiene.

(????????????)
Cuando una unidad es llamada se genera un registro de activación que
contiene un punto de retorno y un link dinamico que informa a donde se
cargo el registro de activacion

### H-6. Describa el ambiente de referencia de una unidad.

- Local
Asociaciones creadas al activar la unidad (parámetros formales,
parámetros locales y subprogramas locales
- No local
Referencias creadas antes de activar la unidad (depende de la cadena
estática o dinámica)
- Global
Conjunto de referencias accesibles desde cualquier unidad (es incluido
en el no local)????????
- Predefinido
Identidicadores predefinidos por el lenguaje

### H-7. Justifique la existencia de un link dinámico en la semántica operacional de un lenguaje. Si el lenguaje sigue la cadena estatica, para resolver las referencias no locales, ?es necesario el link dinamico? Justifique

Link Dinámico: me sirve para saber quien invoco a la
funcion/procedimiento

Es necesario el link dinámico porque los registros de activación no
estan mapeados en memoria de forma homogenea, por lo que si no
tuvieramos la dirección del link dinamico, no podriamos determinar
donde esta el retorno. 

### H-8. ¿Que es una variable sensible a la historia? ?Todos los lenguajes las proveen?.

Una variable sensible a la historia es aquella que conserva su
L-valor. Las unicas variables que son sensibles a la historia son las
estáticas siempre y cuando el lenguaje asi lo defina.

### H-9. Marque diferencias semánticas y como se los implementa, a un arreglo seminidinámico y un arreglo dinámico. Que se hace en compilación y que en ejecución?

Arreglo semidinámico: en copilacion se determina que tipo va a ser
(descriptor) y en ejecución se determina cuanto va a ocupar

Arreglo dinámico: se tiene que alocar en forma explicita
la memoria.  En compilación se puede llegar a fijar el nombre..

### H-10. Cuando es indispensable que un objeto de dato sea almacenado en el heap?  Ejemplos

Es necesario almacenarlo en la heap cuando el dato es dinámico y
cuando no se cuanto va a ocupar.

Los arreglos dinámicos se almacenan en la heap y los semidinámicos en
la pila de ejecución
