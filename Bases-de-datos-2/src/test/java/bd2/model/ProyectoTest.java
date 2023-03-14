package bd2.model;

import junit.framework.TestCase;

public class ProyectoTest extends TestCase {

	private Proyecto proyectoNuevo, proyecto;
	private Usuario sven, kurt, franz;
	private Pizarra backlog, completado;
	
	protected void setUp() throws Exception {
		super.setUp();
		sven = new Usuario("sven@pizarrello.net", "Sven");
		kurt = new Usuario("kurt@pizarrello.net", "Kurt");
		franz = new Usuario("franz@pizarrello.net", "Franz");
		backlog = new Pizarra("Backlog");
		completado = new Pizarra("Completado");
		proyectoNuevo = new Proyecto(sven);
		proyecto = new Proyecto(sven);
		proyecto.agregarColaborador(kurt);
		proyecto.agregarAdministrador(franz);
		proyecto.agregarPizarra(backlog);
		proyecto.agregarPizarra(completado);
	}

	public void testProyecto(){
		Usuario sven = new Usuario("sven@pizarrello.net", "Sven");
		Proyecto nuevo = new Proyecto(sven);
		assertNotNull(nuevo.getPizarras());
		assertNotNull(nuevo.getPizarrasArchivadas());
		assertNotNull(nuevo.getCreador());
		assertEquals(nuevo.getPizarras().size(), 0);
		assertEquals(nuevo.getPizarrasArchivadas().size(), 0);
		assertEquals(nuevo.getCreador(), sven);
	}
	public void testAgregarPizarra(){
		proyectoNuevo.agregarPizarra(backlog);
		assertEquals(proyectoNuevo.getPizarras().size(), 1);
		proyectoNuevo.agregarPizarra(completado);
		assertEquals(proyectoNuevo.getPizarras().size(), 2);
	}
	public void testArchivarPizarra(){
		proyecto.archivarPizarra(backlog);
		assertEquals(1, proyecto.getPizarras().size());
		assertEquals(1, proyecto.getPizarrasArchivadas().size());
		assertTrue(proyecto.getPizarrasArchivadas().contains(backlog));
		proyecto.archivarPizarra(completado);
		assertEquals(0, proyecto.getPizarras().size());
		assertEquals(2, proyecto.getPizarrasArchivadas().size());
		assertTrue(proyecto.getPizarrasArchivadas().contains(backlog));
		assertTrue(proyecto.getPizarrasArchivadas().contains(completado));
	}
	public void testAgregarColaborador(){
		proyectoNuevo.agregarColaborador(kurt);
		assertEquals(2, proyectoNuevo.getIntegrantes().size());
		assertTrue(proyectoNuevo.getIntegrantes().contains(kurt));
	}
	public void testAgregarAdministrador(){
		proyectoNuevo.agregarAdministrador(franz);
		assertEquals(proyectoNuevo.getIntegrantes().size(), 2);
		assertTrue(proyectoNuevo.getIntegrantes().contains(franz));
	}
	public void testEliminarUsuario(){
		try{
			proyecto.eliminarUsuario(kurt);
			assertEquals(proyecto.getIntegrantes().size(), 2);
			proyecto.eliminarUsuario(franz);
			assertEquals(proyecto.getIntegrantes().size(), 1);
		} catch(Exception e) {
			fail( "Eliminar al integrantes normales no debería fallar" );
		}
		try {
			 proyecto.eliminarUsuario(sven);
		     fail( "Eliminar al creador debería fallar" );
		} catch( Exception e ) {
		    assertEquals( "No se puede eliminar al creador del proyecto", e.getMessage() );
			assertEquals(proyecto.getIntegrantes().size(), 1);
		}
		
	}
}
