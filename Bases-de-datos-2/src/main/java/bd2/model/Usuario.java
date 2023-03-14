package bd2.model;

public class Usuario {
	
	/*
	 * Se modelan los datos del usuario
	 */
	
	private String email;
	private String nombre;
	private Long idUsuario;
	
	public Usuario(String e, String n){
		setEmail(e);
		setNombre(n);
	}
	
	public Usuario(){
		email="";
		nombre="";
	}
	
	public Long getIdUsuario(){
		return idUsuario;
	}
	
	public void setIdUsuario(Long id){
		idUsuario=id;
	}
	
	public String getEmail(){
		return email;
	}
	
	public void setEmail(String e){
		email=e;
	}
	
	public String getNombre(){
		return nombre;
	}
	
	public void setNombre(String nom){
		nombre=nom;
	}
	
}
