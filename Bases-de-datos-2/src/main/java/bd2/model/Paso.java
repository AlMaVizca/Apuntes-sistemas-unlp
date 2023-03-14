package bd2.model;

import java.util.Date;

public class Paso {
	
	
	/*
	 * Esta clase sirve para determinar el Paso de una tarea por una pizzarra
	 */
	private Date fechaDeIngreso;
	private Pizarra pizarra;
	private Long idPaso;
	
	public Paso(Pizarra piz){
		//asigna la pizarra pasada como parametro y la fecha actual
		setPizarra(piz);
		setFechaDeIngreso(new Date());
	}
	
	public Paso(){                      // Constructor sin parámetros
		setPizarra(null);
		setFechaDeIngreso(new Date());
	}

	public Long getIdPaso(){
		return idPaso;
	}
	
	public void setIdPaso(Long id){
		idPaso=id;
	}
	public Pizarra getPizarra(){    
		return pizarra;
	}
	
	public void setPizarra(Pizarra piz){
		pizarra=piz;
	}
	
	public Date getFechaDeIngreso(){
		return fechaDeIngreso;
	}
	
	public void setFechaDeIngreso(Date fecha){
		fechaDeIngreso = fecha;
	}
	
	
	
}
