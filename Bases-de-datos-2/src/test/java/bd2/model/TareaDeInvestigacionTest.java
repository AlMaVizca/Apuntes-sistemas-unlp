package bd2.model;

import java.util.Date;
import junit.framework.TestCase;

public class TareaDeInvestigacionTest extends TestCase {
	
	private TareaDeInvestigacion pasarTests;

	protected void setUp() throws Exception {
		super.setUp();
		pasarTests = new TareaDeInvestigacion();
		pasarTests.setHipotesis("Hacer tests mejora los tiempos de desarrollo");
		pasarTests.setResultado("No hay evidencia suficiente");
	}
	
	public void testTareaDeInvestigacion(){
		TareaDeInvestigacion nueva = new TareaDeInvestigacion("Comprobar tests", new Date());
		assertEquals("", nueva.getHipotesis());
		assertEquals("", nueva.getResultado());
	}
	
	public void testSetHipotesis(){
		assertEquals("Hacer tests mejora los tiempos de desarrollo", pasarTests.getHipotesis());
		pasarTests.setHipotesis("Hacer tests mejora el desarrollo");
		assertEquals("Hacer tests mejora el desarrollo", pasarTests.getHipotesis());
	}
	
	public void testSetResultado(){
		assertEquals("No hay evidencia suficiente", pasarTests.getResultado());
		pasarTests.setResultado("Hipotesis rechazada - p<0,05");
		assertEquals("Hipotesis rechazada - p<0,05", pasarTests.getResultado());
	}

}
