# Primer modulo

## A - Criterios de evaluacion y evolucion de los lenguajes

### A-1. Indique los criterios para evaluar un lenguaje de programacion.

**Criterios de evaluación:**
Fácil de escribir -> Legible -> Confiable 
Mantenible
Eficiente

**Fácil de escribir**
Es la medida de cuán fácil resulta un lenguaje para construir soluciones.

Dentro de este criterio encontramos 4 características:
- Simplicidad ->fácil de capturar: entender y recordar.
- Expresividad -> Concentrar la atención en la resolución del problema
- Ortogonalidad -> El usuario comprende mejor si tiene un pequeño número de primitivas y un conjunto consistente de reglas de combinación.
- Soporte de Abstraccion -> Concepto clave para manejar la complejidad, abstracción de procesos y de datos.
	
**Legible**
	Es la medida de cuan fácil de leer resulta para las personas.

Elementos que afectan a la legibilidad:
- Semántica: Los Alias, efectos laterales y estructuras de datos pueden afectar la legibilidad
- Sintaxis:  Debe permitir comentarios. No debe permitir ambigüedades entre semántica y sintaxis.
- Definición: precisión en la definición de la sintaxis y la semántica. (ambigüedad - portabilidad - Definiciones formales)
- Estructuras de datos: programación estructurada
- Estructuras de control:  Facilidades para expresar los datos del problema



**Confiable**
	Un lenguaje debe aportar mecanismos para comprobar que sus programas sean correcto. El objetivo es comprobar estáticamente la mayor cantidad de aspectos, ya que lo dinámico no certifica la correctitud del programa.
 
Aspectos que afectan la confiabilidad de un programa:
- Correcto: cumple con las especificaciones
- Robustez:  permite manejo de errores (excepciones)
- Chequeo de tipos: estáticos y dinámicos
- Restricción de alias

**Mantenibilidad**

Aspectos que afectan la mantenibilidad:
- Modificabilidad: Fácil para introducir cambios 
- Factoreo: poder reutilizar código
- Localidad: El efecto de una característica se restringe a una porción local del código

**Eficiencia**

Aspectos que afectan la eficiencia:
- Tiempo de ejecución
- Memoria utilizada
- Espacio en disco
- Esfuerzo humano
- Optimizable


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

SIMULA 67, C++ CLU, SMALLTALK Java Eiffel


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

*The syntax rules of the language state how to form expressions, statements, and programs that look right.*
*The semantic rules of the language tell us how to build meaningful expressions, statements and programs*


## D- Sintaxis
- **Defina y describa la utilidad de la sintaxis de un lenguaje**

**Definición:**: Conjuto de reglas que definen como componer letras, digitos y otros caracteres para formar los programas 


**utilidad:**  de componer instrucciones*
Es un protocolo para poder escribir en un leguaje

- **Diferencie: Reglas lexicas y  reglas sintacticas.**

*Reglas lexicas:* Definen el conjunto de caracteres que componen el alfabeto del lenguaje y la manera en la que los caracteres pueden ser combinados para formar palabras
*Reglas sintacticas:* Conjunto de reglas que define como formar expresiones y sentencias

- **Sintaxis abstracta y sintaxis concreta. Ejemplifique.** 
*Sintaxis abstracta:* Hace referencia a la forma en la que se compone una expresion
*Sintaxis concreta:* Especificamente como se escribe la expresion en un lenguaje concreto

   - **Abstracta**
      While <condicion> <sentenciase>
   - **Concreta**
      while (i<100) {i++; tot+=1}
	  while (i<100) do
	    begin
		i=i+1
		tot=tot+1
		end
	  
- **Que forma de definir la sintaxis conoce?, Comparelas.**
*Lenguaje natural*
*BNF y EBNF*

*Diagrama de conway*
Representacion sintactica a traves de graficos

- **Diferencias entre una gramatica libre de contexto y una gramatica
sensible al contexto. Ejemplos**
evaluacion de tipos en un condicional

- **Cuando una gramatica es ambigua? Se puede solucionar?**
Cuando una gramatica puede generar dos arboles sintacticos

- **Que son BNF y EBNF? Definalas y comp?relas.**
Herramientas para escribir lenguajes
EBNF es la version extendida
