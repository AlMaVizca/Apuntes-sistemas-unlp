package bd2.model;

import java.util.Collection;
import java.util.HashSet;

public class Pizarra {
	
	/*
	 * En esta clase representamos la pizzarra y el conjunto de tareas asociadas
	 */
	
	private String nombre;
	private Collection<Tarea> tareas;
	private Long idPizarra;
	
	public Long getIdPizarra(){
		return idPizarra;
	}
	public void setIdPizarra(Long id){
		idPizarra= id;
	}
	
	public void setTareas(Collection<Tarea> t){
		tareas= t;
	}
	
	
	public Pizarra(String nom){     
		setNombre(nom);
		tareas = new HashSet<Tarea>();
	}
	
	public Pizarra(){                    //Constructor sin parámetros
		setNombre("");
		tareas = new HashSet<Tarea>();
	}
	
	public String getNombre(){
		return nombre;
	}
	
	public void setNombre(String nom){
		nombre=nom;
	}
	
	public Collection<Tarea> getTareas(){
		return tareas;
	}
	
	
	public void agregarTarea(Tarea tarea){
		/*
		 * Agrega tarea a la pizarra receptora. 
		 * Notar además que la tarea tiene que registrar su incorporación a la pizarra.
		 */
		
		tareas.add(tarea);
		tarea.getPasos().add(new Paso(this));
	}
	
	
	public void eliminarTarea(Tarea tarea){
		if (tareas.contains(tarea)){          
			tareas.remove(tarea);
		}
	}

	
	public void moverTareaAPizarra(Tarea tarea, Pizarra destino){
		/*
		 * Mueve una tarea a la pizarra destino y se agrega el paso
		 */
		
		
		this.eliminarTarea(tarea);
		destino.agregarTarea(tarea);
	}
}
