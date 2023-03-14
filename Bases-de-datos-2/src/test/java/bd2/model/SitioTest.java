package bd2.model;

import junit.framework.TestCase;

public class SitioTest extends TestCase {

	private Sitio sitio;
	private Proyecto proyecto;
	private Usuario sven, kurt, franz;
	
	protected void setUp() throws Exception {
		super.setUp();
		sitio = new Sitio();
		sven = new Usuario("sven@pizarrello.net", "Sven");
		kurt = new Usuario("kurt@pizarrello.net", "Kurt");
		franz = new Usuario("franz@pizarrello.net", "Franz");
		proyecto = new Proyecto(sven);
		sitio.agregarProyecto(proyecto);
	}

	public void testSitio(){
		Sitio nuevo = new Sitio();
		assertNotNull(nuevo.getProyectos());
		assertNotNull(nuevo.getUsuarios());
		assertEquals(0, nuevo.getProyectos().size());
		assertEquals(0, nuevo.getUsuarios().size());
	}
	
	public void testRegistrarUsuario(){
		sitio.registrarUsuario(franz);
		assertEquals(1, sitio.getUsuarios().size());
		sitio.registrarUsuario(franz);
		assertEquals(1, sitio.getUsuarios().size());
		sitio.registrarUsuario(kurt);
		assertEquals(2, sitio.getUsuarios().size());
	}
	
}
