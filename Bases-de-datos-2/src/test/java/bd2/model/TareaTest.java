package bd2.model;

import java.util.Calendar;
import java.util.Date;

import junit.framework.TestCase;

public class TareaTest extends TestCase {

	private Date manhana, ayer;
	private Tarea tareaManhana, tareaAyer;
	private Pizarra hacer, haciendo, hecho;

	protected void setUp() throws Exception {
		super.setUp();

		Calendar cal = Calendar.getInstance();
		cal.add(Calendar.DATE, +1);
		manhana = cal.getTime();
		cal.add(Calendar.DATE, -2);
		ayer = cal.getTime();
		tareaManhana = new TareaConcreta("Hacer algo", manhana);
		tareaAyer = new TareaConcreta("Hacer algo", ayer);

		hacer = new Pizarra("Hacer");
		haciendo = new Pizarra("Haciendo");
		hecho = new Pizarra("Hecho");
	}
	
	public void testTarea(){
		Tarea nueva = new TareaConcreta("Hacer algo", manhana);
		assertFalse(nueva.completa());
		assertEquals(manhana, nueva.getFechaLimite());
		assertEquals("Hacer algo", nueva.getDescripcion());
		assertEquals(0, tareaManhana.getPasos().size());
	}
	
	public void testFechaLimite(){
		assertEquals(manhana, tareaManhana.getFechaLimite());
	}
	
	public void testVencida(){
		assertFalse(tareaManhana.vencida());
		assertTrue(tareaAyer.vencida());
	}
	
	public void testCompletar(){
		assertFalse(tareaAyer.completa());
		tareaAyer.completar();
		assertTrue(tareaAyer.completa());
	}
	public void testAgregarAPizarra(){
		assertEquals(0, tareaManhana.getPasos().size());
		tareaManhana.agregarAPizarra(hacer);
		assertEquals(1, tareaManhana.getPasos().size());
		tareaManhana.agregarAPizarra(haciendo);
		assertEquals(2, tareaManhana.getPasos().size());
		tareaManhana.agregarAPizarra(hecho);
		assertEquals(3, tareaManhana.getPasos().size());
	}

}
