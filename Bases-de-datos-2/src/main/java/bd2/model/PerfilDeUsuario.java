package bd2.model;

import java.util.Date;

public class PerfilDeUsuario {
	
	/*
	 * Esta clase representa los usuarios del sistema
	 */
	
	private Date fechaDeCreacion;
	private Usuario usuario;
	private Long idPerfilDeUsuario;
	
	
	public PerfilDeUsuario(Date fecha, Usuario usu){
		setFechaDeCreacion(fecha);
		setUsuario(usu);
	}
	
	public PerfilDeUsuario(){            //Constructor sin parámetros
		setFechaDeCreacion(new Date());
		setUsuario(null);
	}
	
	public Long getIdPerfilDeUsuario(){
		return idPerfilDeUsuario;
	}
	
	public void setIdPerfilDeUsuario(Long id){
		idPerfilDeUsuario=id;
	}
	public Date getFechaDeCreacion(){
		return fechaDeCreacion;
	}
	
	public void setFechaDeCreacion(Date fecha){
		fechaDeCreacion=fecha;
	}
	public Usuario getUsuario(){
		return usuario;
	}
	
	public void setUsuario(Usuario u){
		usuario=u;
	}
	
	public boolean esCreador(){
		return false;
	}
	
	public void eliminarDe(Proyecto proyecto) throws Exception{  
		proyecto.eliminarPerfil(this);
	}
	
}
