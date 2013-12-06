# Primer modulo

## A- Criterios de evaluacion y evolucion de los lenguajes

- **Indique los criterios para evaluar un lenguaje de programacion.**

Facil de escribir -> Legible -> Confiable

Mantenible

Eficiente


*Facil de escribir*
-------------------

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


Es la medida de cuan facil resulta un lenguaje para contruir soluciones.

   1. Simplicidad -> facil de capturar: entender y recordar.
   2. Expresividad -> Concentrar la atencion en la resolucion del problema
   3. Ortogonalidad -> El usuario comprende mejor si tiene un pequeño
   número de primitivas y un conjunto consistente de reglas de combinación.
   4. Soporte  de Abstraccion -> Concepto clave para manejar la
   complejidad, abstracción de procesos y de datos.

*Legible*
---------


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


- **En la actualidad como se mide la eficiencia del software?
    Evoluciono este concepto.** 
	
(Pag 13 Ghezzi)
	
La eficiencia del software según ghezzi se mide teniendo en cuenta la
velocidad de ejecucion, el tiempo utilizado y el esfuerzo utilizado (productividad).

Es decir que el concepto cambio, anteriormente solo era considerado el
espacio ocupado y la velocidad de ejecucion. Ahora no tien eque
dejarse de lado el esfuerzo requerido en la produccion de software y
en el mantenimiendo del mismo.


- **Que significa que un lenguaje sea ortogonal?**

Significa que un conjunto relativamente pequeño de constructores
primitivos pueden ser combinados para construir el flujo y las
estructuras de datos de todo el lenguaje.

- **Construya ejemplos de cada uno de los criterios** 	

PL/1 es un lenguaje confiable pero demasiado extenso(ni sencillo ni ortogonal)

- **Indique cuales fueron los motivos que a su juicio condujeron a
la evolucion historica de los lenguajes de programacion**
- **Describa la evolucion de los lenguajes de programacion en cuanto a su Sistema de Tipos.**
- **Describa la rama de la evolucion de los lenguajes que condujo al Paradigma de Objetos.**		
Miranda, ML

SIMULA 67, C++ CLU, SMALLTALK Java Eiffel

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
