# Primer modulo

## A - Criterios de evaluacion y evolucion de los lenguajes

### A-1. Indique los criterios para evaluar un lenguaje de programacion.

Criterios de evaluación:

 - Fácil de escribir -> Legible -> Confiable
 - Mantenible
 - Eficiente

**Facil de escribir**
	
        Es la medida de cuán fácil resulta un lenguaje para construir soluciones.

En la decada del '70 se focalizaba en escribir código, y del '70 en
adelante el mantenimiento del software fue reconocido como una parte
importante del ciclo de vida, particularmente en terminos de costo.

Cuan facil es mantener un programa es determinado por la facilidad de
lectura y esto refleja una caracteristica de calidad en los programas
y en los lenguajes de programacion.

- Simplicidad 
   - muchas componentes de construcción
   - muchas formas de hacer lo mismo
   - polimorfismo
- Ortgonalidad
   - Algol'68 extremadamente ortogonal

Dentro de este criterio encontramos 4 características:

   1. Simplicidad -> facil de capturar: entender y recordar.
   2. Expresividad -> Concentrar la atencion en la resolucion del problema
   3. Ortogonalidad -> El usuario comprende mejor si tiene un pequeño
   número de primitivas y un conjunto consistente de reglas de combinación.
   4. Soporte  de Abstraccion -> Concepto clave para manejar la
   complejidad, abstracción de procesos y de datos.


**Legible**

        Es la medida de cuan fácil de leer resulta para las personas.

Elementos que afectan a la legibilidad:

 1. Semántica: Los Alias, efectos laterales y estructuras de datos pueden afectar la legibilidad
 2. Sintaxis:  Debe permitir comentarios. No debe permitir ambigüedades entre semántica y sintaxis.
 3. Definición: precisión en la definición de la sintaxis y la semántica. (ambigüedad - portabilidad - Definiciones formales)
 4. Estructuras de datos: programación estructurada
 5. Estructuras de control:  Facilidades para expresar los datos del problema


**Confiable**
     
        Un lenguaje debe aportar mecanismos para comprobar que sus programas sean correcto. 
        El objetivo es comprobar estáticamente la mayor cantidad de aspectos, 
        ya que lo dinámico no certifica la correctitud del programa.
 
Aspectos que afectan la confiabilidad de un programa:
 
 1. Correcto: cumple con las especificaciones
 2. Robustez:  permite manejo de errores (excepciones)
 3. Chequeo de tipos: estáticos y dinámicos
 4. Restricción de alias

**Mantenibilidad**

Aspectos que afectan la mantenibilidad:

 1. Modificabilidad: Fácil para introducir cambios 
 2. Factoreo: poder reutilizar código
 3. Localidad: El efecto de una característica se restringe a una porción local del código


**Eficiencia**

Aspectos que afectan la eficiencia:

 1. Tiempo de ejecución
 2. Memoria utilizada
 3. Espacio en disco
 4. Esfuerzo humano
 5. Optimizable



###A-2. ¿En la actualidad como se mide la eficiencia del software? Evoluciono este concepto.

La eficiencia del software se mide:

- Originalmente por: 
    - Memoria que ocupa 
    - Tiempo de ejecución
- Ahora se le agrego tambien:
    - Esfuerzo humano
    - La portabilidad
    - La calidad (si no tiene errores)
    - El reuso
    - Interface
    - Optimizable

	

	
La eficiencia del software se mide teniendo en cuenta:(Pag 13 Ghezzi)

- La velocidad de ejecución
- El tiempo utilizado
- el esfuerzo utilizado (productividad).

Es decir que el concepto cambio, anteriormente sólo era considerado el espacio ocupado y la velocidad de ejecución. Ahora no tiene que dejarse de lado el esfuerzo requerido en la producción de software y en el mantenimiento del mismo.




### A-3. ¿Que significa que un lenguaje sea ortogonal?

Significa que un conjunto relativamente pequeño de constructores
primitivos pueden ser combinados para construir el flujo y las
estructuras de datos de todo el lenguaje.

### A-4. Construya ejemplos de cada uno de los criterios 


 - PL/1 es un lenguaje confiable pero demasiado extenso(ni sencillo ni ortogonal)
 - Ejem de escritura: Que los nombres de las variables pueden ser escritos como una letra y números (A1, A2, A3...). Es facil de escribir pero difícil de leer.
 - Ada no es un lenguaje simple: es robusto pero complejo. Abuso de operadores sobrecargados.
 - Ada es un lenguaje expresivo.
 - Ada no es un lenguaje ortogonal.
 - Ada es un lenguaje legible: permite documentar  - brinda estructuras de control y de datos.
 - Ada es un lenguaje confiable: brinda mecanismos de chequeo y manejo de excepciones.


### A-5. Indique cuáles fueron los motivos que a su juicio condujeron a la evolución histórica de los lenguajes de programación

Motivos que provocan la evolución de los lenguajes:

 - Mantenibilidad: hacer lenguajes en los que cueste menos mantener los programas
 - Eficiencia: hacer programas más eficientes
 - Estandarización
 - Abstracción: generar lenguajes de alto nivel para que sea más fácil programar.
 - Complejidad de los problemas: obligó a que los lenguajes deban incorporar herramientas que permitan modelar problemas más complejos.
 - Evolución de la tecnologia / necesidades



### A-6. Describa la evolucion de los lenguajes de programacion en cuanto a su Sistema de Tipos.

Evolución de tipos en orden de aparición:

 - Tipos predefinidos: Fortran
 - Tipos definidos por el usuario: Algol
 - Tipos estructurados: Cobol
 - TAD: Modula, ADA, C++
 - Objetos / Clases: C++, Java, Smaltalk



### A-7. Describa la rama de la evolucion de los lenguajes que condujo al Paradigma de Objetos.

Miranda, ML

  1. SIMULA 67: 
    - Padre del paradigma OO. Lenguaje de simulacion de eventos. 
    - Aporta concepto de Clase, objeto, jerarquia, herencia, binding dinamico.
  2. SMALLTALK:
    - Lenguaje puro Orientado a Objetos
    - Aporta: encapsulamiento y abstracción. Polimorfismo y binding dinámico
  3. C++:
    - Aporte: manejo de clases y objetos al lenguaje C.
  4. Java:
    - Aporta: portabilidad e independencia de hardware.
  
   CLU,  Java Eiffel


### A-8.Desde el punto de vista de la evolucion de los lenguajes, defina los objetivos, caracteristicas y aportes de Ada

Ada incorporó:
 
 - Excepciones: mejoró lo que hizo PL1 (ada termina la ejecución después de una excepción mientras que PL1 retorna al punto siguiente:, siendo mas inseguro)
 - Multitarea
 - Concepto Tarea
 - Abstracción de datos
 - Unidades genéricas: packaging


### A-9. ¿Segun su criterio: Cuales fueron los lenguajes que mas aportaron a la evolucion de los lenguajes. Por que?

Simula -> dio origen a las clases / objetos

PL1 -> dio origen a las excepciones.


## B - Procesamiento de un lenguaje

### B-1. Que son la compilacion y la interpretacion? Defina y describa ambos procesos. Comparelos por distintos criterios.

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

 - Intérprete vs Compilador
	- El interprete lee e interpreta línea a línea <> El compilador lee un programa entero y lo convierte en código objeto
	- El intérprete ejecuta siguiendo un orden lógico de ejecución <> El compilador sigue el 
orden físico de las sentencias.
	- Los programas compilados se ejecutan mucho mas rápidamente que los interpretados desde el 
punto de vista del hardware aunque el proceso de compilación en si mismo lleva mas tiempo.
	- En cuanto al espacio ocupado el intérprete ocupa menos espacio. Cada sentencia se deja en la 
forma original; el compilador una sentencia ocupa cientos de sentencias de maquina.
	- La detección de errores es más difícil para el intérprete que para el compilador.

## C- Sintaxis y semantica

### C-1. Sintaxis y semantica de un lenguaje. Defina que es cada concepto e indique cual es la manera formal o no formal que usan generalmente los lenguajes de  programacion.

 **Sintaxis**: conjunto de reglas que definen como componer letras, dígitos y otros 
caracteres para formar los programas. 

**Semantica**: conjunto de reglas para dar significado a los programas sintácticamente válidos.

Formas de definir la sintaxis:

 - Lenguaje natural (Ej.: Fortran)
 - Utilizando la gramática libre de contexto
 - Backus y Naun: BNF(Ej: Algol) 
 - Diagramas Sintacticos: equivalentes a BNF pero mucho mas intuitivos.

La utilidad de definir la sintaxis y la semántica de un lenguaje es determinar si un programa es válido y si lo es que significa.



*Syntax influences how programs are written by the programmer, read by
other programmers, and parsed by the computer. Semantics determines
how programs are composed by the programmer, understood by other
programmers, and interpreted by the computer. Pragmatics influences
how programmers are expected to design and implement programs in
practice. Syntax is important, but semantics and pragmatics are more
important still.*

*The syntax rules of the language state how to form expressions, statements, and programs that look right.*
*The semantic rules of the language tell us how to build meaningful expressions, statements and programs*


## D- Sintaxis

### D-1. Defina y describa la utilidad de la sintaxis de un lenguaje

**Definición:**: Conjuto de reglas que definen como componer letras, digitos y otros caracteres para formar los programas 

**Utilidad:**  de componer instrucciones*
Es un protocolo para poder escribir en un leguaje

Favorece:

     - Legibilidad
     - Verficabilidad
     - Facil abstracción
     - Auscencia de ambiguedad 

Elementos de la sintaxis:
 
 1. Alfabeto / Conjunto de caracteres
 2. Identificadores: cadena de caracteres
 3. Operadores
 4. Palabra clave y palabra reservada
 5. Comentarios


### D-2. Diferencie: Reglas lexicas y  reglas sintacticas.

**Reglas lexicas:** Definen el conjunto de caracteres que componen el alfabeto del lenguaje y la manera en la que los caracteres pueden ser combinados para formar palabras

**Reglas sintacticas:** Conjunto de reglas que define como formar expresiones y sentencias

### D-3. Sintaxis abstracta y sintaxis concreta. Ejemplifique.

**Sintaxis abstracta:** Hace referencia a la forma en la que se compone una expresion

**Sintaxis concreta:** Especificamente como se escribe la expresion en un lenguaje concreto

   - **Abstracta**
      While <condicion> <sentenciase>
   - **Concreta**

         while (i<100) {i++; tot+=1}

	     while (i<100) do
	     begin
	      i=i+1
		  tot=tot+1
		 end
	  
### D-4. Que forma de definir la sintaxis conoce?, Comparelas.

Formas de definir la sintaxis:

 - Lenguaje natural (Ej.: Fortran)
 - Utilizando la gramática libre de contexto
 - Backus y Naun: BNF(Ej: Algol) 
 - Diagramas Sintacticos: equivalentes a BNF pero mucho mas intuitivos (Diagrama de conway)



### D-5. Diferencias entre una gramatica libre de contexto y una gramatica sensible al contexto. Ejemplos

**Gramatica**: forma de definir la sintaxis de un lenguaje G = (N,T,S,P)

Ejemplo: int a; int a;

Una gramatica libre de contexto no analiza si un a se definio mas de una vez, en cambio una sensible al contexto si lo analiza.
 
evaluacion de tipos en un condicional

### D-6. Cuando una gramatica es ambigua? Se puede solucionar?
Cuando una gramatica puede generar dos arboles sintacticos

### D-7. Que son BNF y EBNF? Definalas y comparelas.
Herramientas para escribir gramaticas
EBNF es la version extendida

Consta basicamente de 4 elementos G= (N,T,S,P)
