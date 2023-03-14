package bd2.model;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Collection;
import java.util.Date;
import java.util.GregorianCalendar;

public abstract class Tarea {

	
	/*
	 * Las tareas se pueden ir moviendo de una pizarra a la otra 
	 * (por ejemplo “Hacer” a “Hecho”), y en ese caso la tarea 
	 * se guarda en un pequeño historial (Paso) que indica
	 * que se movió a una pizarra en una fecha dada.
	*/

	
	private boolean completa=false;
	private Date fechaLimite;
	private String descripcion;
	private Collection<Paso> pasos;
	private Long idTarea;
	
	public Tarea(String desc,Date fecha){
		
		/* En particular, en la clase Tarea instanciar la colección de pasos 
		 * con la clase ArrayList.
		 */
		
		
		pasos = new ArrayList<Paso>();
		setFechaLimite(fecha);
		setDescripcion(desc);
	}
	
	public Tarea(){
		pasos = new ArrayList<Paso>();
		setFechaLimite(new Date());
		setDescripcion("");
	}
	
	public boolean completa(){
		return completa;
	}
	
	public void setCompleta(boolean c){
		completa= c;
	}
	
	public boolean getCompleta(){
		return completa;
	}
	
	public void completar(){
		completa=true;
	}
	
	public Date getFechaLimite(){
		return fechaLimite;
	}
	
	public void setFechaLimite(Date fecha){
		fechaLimite=fecha;
	}
	
	public String getDescripcion(){
		return descripcion;
	}
	
	public void setDescripcion(String descr){
		descripcion=descr;
	}
	
	public Collection<Paso> getPasos(){
		return pasos;
	}
	
	public void setPasos(Collection<Paso> p){
		pasos=p;
	}
	
	public boolean vencida(){
		
		/* 
		 * Se crean 2 objetos calendario para poder evaluar fechas
		 * En uno de ellos se mantiene la fecha actual y en el otro 
		 * se asigna la fecha limite. Luego se comparan.
		 */
			
		Calendar fechaActual=new GregorianCalendar();  
		Calendar fechaL=new GregorianCalendar();      
		fechaL.setTime(fechaLimite);      			 
		if (fechaActual.after(fechaL)){
			return true;
		}
		else{
			return false;
		}
	}
	
	
	public void agregarAPizarra(Pizarra pizarra){
		
		/* 
		 * Se agrega a la pizarra enviada como parámetro. 
		 * Debe registrar este movimiendo generando un nuevo Paso y 
		 * agregándolo a su colección de pasos, con la fecha actual y
		 * la pizarra en cuestión.
		 */
		
		pizarra.agregarTarea(this);
	}
	
	public Long getIdTarea(){
		return idTarea;
	}
	public void setIdTarea(Long id){
		idTarea= id;
	}
	
}
