package bd2.model;

import java.util.Date;

/*
 * Clase concreta que extiende directamente la clase abstracta Tarea.
 * No es parte del modelo, sólo sirve para hacer posible el test de 
 * la lógica concreta implementada en la clase abstracta.
 * Estos tests están en la clase TareaTest.
 *  
 * */

public class TareaConcreta extends Tarea {

	public TareaConcreta(String descripcion, Date fechaLimite) {
		super(descripcion, fechaLimite);
	}

}
