package bd2.model;

import java.util.Date;

import junit.framework.TestCase;

public class PizarraTest extends TestCase {

	Pizarra pizarra, backlog, hecho;
	Tarea requerimientos, diagramar, programar;
	
	protected void setUp() throws Exception {
		super.setUp();
		pizarra = new Pizarra("Tareas");
		backlog = new Pizarra("Backlog");
		hecho = new Pizarra("Tareas Hechas");
		
		requerimientos = new TareaDeDesarrollo("Tomar Requerimientos", new Date());
		diagramar = new TareaDeDesarrollo("Dibujar Diagrama", new Date());
		programar = new TareaDeDesarrollo("Programar Login", new Date());

		backlog.agregarTarea(requerimientos);
		backlog.agregarTarea(diagramar);
		backlog.agregarTarea(programar);
	}
	
	public void testPizarra(){
		Pizarra nueva = new Pizarra("Backlog");
		assertEquals("Backlog", nueva.getNombre());
		assertEquals(0, nueva.getTareas().size());
	}
	
	public void testAgregarTarea(){
		pizarra.agregarTarea(requerimientos);
		assertEquals(1, pizarra.getTareas().size());
		assertTrue(pizarra.getTareas().contains(requerimientos));
		pizarra.agregarTarea(diagramar);
		assertEquals(2, pizarra.getTareas().size());
		assertTrue(pizarra.getTareas().contains(requerimientos));
		assertTrue(pizarra.getTareas().contains(diagramar));
	}
	
	public void testMoverTareaAPizarra(){
		backlog.moverTareaAPizarra(requerimientos, hecho);
		assertEquals(2, backlog.getTareas().size());
		assertEquals(1, hecho.getTareas().size());
		assertFalse(backlog.getTareas().contains(requerimientos));
		assertTrue(backlog.getTareas().contains(diagramar));
		assertTrue(backlog.getTareas().contains(programar));
		assertTrue(hecho.getTareas().contains(requerimientos));
		assertFalse(hecho.getTareas().contains(diagramar));
		assertFalse(hecho.getTareas().contains(programar));
		backlog.moverTareaAPizarra(diagramar, hecho);
		assertEquals(1, backlog.getTareas().size());
		assertEquals(2, hecho.getTareas().size());
		assertFalse(backlog.getTareas().contains(requerimientos));
		assertFalse(backlog.getTareas().contains(diagramar));
		assertTrue(backlog.getTareas().contains(programar));
		assertTrue(hecho.getTareas().contains(requerimientos));
		assertTrue(hecho.getTareas().contains(diagramar));
		assertFalse(hecho.getTareas().contains(programar));
		hecho.moverTareaAPizarra(requerimientos, backlog);
		assertEquals(2, backlog.getTareas().size());
		assertEquals(1, hecho.getTareas().size());
		assertTrue(backlog.getTareas().contains(requerimientos));
		assertFalse(backlog.getTareas().contains(diagramar));
		assertTrue(backlog.getTareas().contains(programar));
		assertFalse(hecho.getTareas().contains(requerimientos));
		assertTrue(hecho.getTareas().contains(diagramar));
		assertFalse(hecho.getTareas().contains(programar));
		
	}

}
