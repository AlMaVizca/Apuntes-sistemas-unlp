package bd2.model;

import java.util.Date;

public class TareaDeDesarrollo extends Tarea{

	private String requerimientos;
	private Long idTareaDeDesarrollo;
	
	public TareaDeDesarrollo(String desc,Date fecha){  
		super(desc,fecha);
		setRequerimientos("");
	}
	

	public TareaDeDesarrollo() {
		super("",new Date());
		setRequerimientos("");
	}


	public String getRequerimientos(){
		return requerimientos;
	}
	
	public void setRequerimientos(String req){
		requerimientos=req;
	}
	
	

}
