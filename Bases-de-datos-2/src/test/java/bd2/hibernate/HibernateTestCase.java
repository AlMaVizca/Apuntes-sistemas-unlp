package bd2.hibernate;

import java.util.Calendar;
import java.util.Date;

import junit.framework.TestCase;
import bd2.model.*;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.cfg.Configuration;
import org.hibernate.service.ServiceRegistry;
import org.hibernate.service.ServiceRegistryBuilder;

@SuppressWarnings("deprecation")
public class HibernateTestCase extends TestCase {

	private static SessionFactory factory;

	private void crearSessionFactory(String pathConfig) {
		Configuration configuration = new Configuration();
	    configuration.configure(pathConfig);
	    ServiceRegistry serviceRegistry = new ServiceRegistryBuilder().applySettings(
	            configuration.getProperties()).buildServiceRegistry();
	    factory = configuration.buildSessionFactory(serviceRegistry);
	}
	
	public void testGuardarYLeer() {
		this.crearSessionFactory("hibernate/hibernate.cfg.xml");
		this.guardarYLeerBasico();
		factory.close();
	}

	public void guardarYLeerBasico() {
		Usuario sven = new Usuario("sven@pizarrello.net", "Sven");
		Usuario kurt = new Usuario("kurt@pizarrello.net", "Kurt");
		Usuario franz = new Usuario("franz@pizarrello.net", "Franz");
		this.guardarYLeer(Usuario.class, sven);
		this.guardarYLeer(Usuario.class, kurt);
		this.guardarYLeer(Usuario.class, franz);
		

		Calendar cal = Calendar.getInstance();
		cal.add(Calendar.DATE, +1);
		Date manhana = cal.getTime();
		cal.add(Calendar.DATE, -2);
		Date ayer = cal.getTime();

		Pizarra backlog = new Pizarra("Backlog");
		Pizarra hecho = new Pizarra("Tareas Hechas");
		
		TareaDeInvestigacion investigarTests = new TareaDeInvestigacion();
		investigarTests.setHipotesis("Hacer tests mejora los tiempos de desarrollo");
		investigarTests.setResultado("No hay evidencia suficiente");

		TareaDeDesarrollo requerimientos = new TareaDeDesarrollo("Tomar Requerimientos", ayer);
		requerimientos.setRequerimientos("Reunirse.");
		TareaDeDesarrollo diagramar = new TareaDeDesarrollo("Dibujar Diagrama", manhana);
		diagramar.setRequerimientos("Usar Creately.");
		TareaDeDesarrollo programar = new TareaDeDesarrollo("Programar Login", manhana);
		programar.setRequerimientos("Tiene que tener recuperación de password.");
		this.guardarYLeer(TareaDeDesarrollo.class, requerimientos);
		this.guardarYLeer(TareaDeDesarrollo.class, diagramar);
		this.guardarYLeer(TareaDeDesarrollo.class, programar);

		backlog.agregarTarea(investigarTests);
		backlog.agregarTarea(requerimientos);
		backlog.agregarTarea(diagramar);
		backlog.agregarTarea(programar);
		
		this.guardarYLeer(Pizarra.class, backlog);
		
		backlog.moverTareaAPizarra(requerimientos, hecho);
		this.guardarYLeer(Pizarra.class, backlog);
		this.guardarYLeer(Pizarra.class, hecho);
			
		Proyecto proyecto = new Proyecto(sven);
		proyecto.agregarColaborador(kurt);
		proyecto.agregarAdministrador(franz);
		proyecto.agregarPizarra(backlog);
		proyecto.agregarPizarra(hecho);
		this.guardarYLeer(Proyecto.class, proyecto);
		
		Sitio sitio = new Sitio();
		sitio.agregarProyecto(proyecto);
		sitio.registrarUsuario(franz);
		sitio.registrarUsuario(kurt);
		sitio.registrarUsuario(sven);
		this.guardarYLeer(Sitio.class, sitio);
	}

	public void guardarYLeer(Class clazz, Object o) {
		Session session = factory.openSession();
		Transaction tx = null;
		Long id = null;
		tx = session.beginTransaction();
		id = (Long) session.save(o);
		assertNotNull(session.get(clazz, id));
		tx.commit();
		session.close();
	}
}
