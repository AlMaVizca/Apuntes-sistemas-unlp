package bd2.model;

import java.util.Date;
import junit.framework.TestCase;

public class TareaDeDesarrolloTest extends TestCase {
	
	private TareaDeDesarrollo pasarTests;

	protected void setUp() throws Exception {
		super.setUp();
		pasarTests = new TareaDeDesarrollo();
		pasarTests.setRequerimientos("Pasar los tests");
	}
	
	public void testTareaDeDesarrollo(){
		TareaDeDesarrollo nueva = new TareaDeDesarrollo("Programar algo", new Date());
		assertEquals("", nueva.getRequerimientos());
	}
	
	public void testSetRequerimientos(){
		assertEquals("Pasar los tests", pasarTests.getRequerimientos());
		pasarTests.setRequerimientos("Pasar TODOS los tests");
		assertEquals("Pasar TODOS los tests", pasarTests.getRequerimientos());
	}

}
