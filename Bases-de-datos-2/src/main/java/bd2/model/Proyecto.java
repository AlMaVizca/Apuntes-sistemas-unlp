package bd2.model;

import java.util.Collection;
import java.util.Date;
import java.util.HashSet;

public class Proyecto {
	
	
	/*
	 * 	Cada proyecto tiene tareas organizadas en pizarras. Las pizzaras
	 * 	se pueden archivar y no se pueden borrar.
	 * 
	 * 	Los proyectos tienen usuarios comunes y administradores. En particular un
	 * 	administrador es el creador del proyecto y no puede ser eliminado del mismo.
	 * 	Los demas usuarios pueden ser eliminados del proyecto.
	 */
	

	private Collection<Pizarra> pizarras;
	private Collection<Pizarra> pizarrasArchivadas;
	private Collection<PerfilDeUsuario> perfiles;
	private Long idProyecto;
	
	
	public Proyecto(Usuario creador){  
		// Crea coleccion de pizarras
		pizarras=new HashSet<Pizarra>();
		// Crea coleccion de pizarras archivadas
		pizarrasArchivadas=new HashSet<Pizarra>();
		// Crea coleccion de perfiles
		perfiles=new HashSet<PerfilDeUsuario>();
		Date fecha=new Date();
		// Agrego a mi colección de perfiles un perfil de administrador con fecha de creación de 
		// la fecha actual (asignada a la variable de clase Date, fecha, en la linea anterior), 
		// el usuario pasado como parametro, y true como condición booleana indicando que es el creador
		// del proyecto. 
		perfiles.add(new PerfilDeAdministrador(fecha,creador,true));
	}
	
	
	public Proyecto(){                  //Constructor sin parámetros
		pizarras=new HashSet<Pizarra>();
		pizarrasArchivadas=new HashSet<Pizarra>();
		perfiles=new HashSet<PerfilDeUsuario>();
		Date fecha=new Date();
		perfiles.add(new PerfilDeAdministrador(fecha,null,true));
	}
	
	public Long getIdProyecto(){
		return idProyecto;
	}
	
	public void setIdProyecto(Long id){
		idProyecto=id;
	}
	
	public Collection<Pizarra> getPizarras(){
		return pizarras;
	}
	
	public void setPizarras(Collection<Pizarra> piz){
		pizarras=piz;
	}
	
	public Collection<Pizarra> getPizarrasArchivadas(){
		return pizarrasArchivadas;
	}
	
	public void setPizarrasArchivadas(Collection<Pizarra> piz){
		pizarrasArchivadas=piz;
	}
	
	public void agregarPizarra(Pizarra pizarra){
		pizarras.add(pizarra);
	}
	
	private void eliminarPizarra(Pizarra pizarra){

		if (pizarras.contains(pizarra)){          
			pizarras.remove(pizarra);
		}
	}
	
	public void archivarPizarra(Pizarra pizarra){
		
		/* 	
		 * Elimina de la colección de pizarras y pasa a 
		 * la colección de pizarras archivadas.
		 */
		
		
		eliminarPizarra(pizarra);
		pizarrasArchivadas.add(pizarra);
	}
	
	public Collection<PerfilDeUsuario> getPerfiles(){
		return perfiles;
	}
	
	public void setPerfiles(Collection<PerfilDeUsuario> p){
		perfiles=p;
	}
	
	
	
	
	public Collection<Usuario> getIntegrantes(){
		//creo una colección auxiliar u
		HashSet<Usuario> u = new HashSet<Usuario>();
		//recorro mi coleccion de perfiles, y agrego sólo cada usuario de la misma a mi coleccion auxiliar u
		for (PerfilDeUsuario p: perfiles){
			u.add(p.getUsuario());
		}
		//retorno u, la cuál ahora contiene cada usuario que tengo en mi colección de perfiles
		return u;
	}

	
	/*
	 * En los dos metodos siguientes se genera un perfil de usuario 
	 * y lo agrega a la colección de perfiles.
	 */

	
	public void agregarAdministrador(Usuario usuario){
		Date fecha=new Date();
		perfiles.add(new PerfilDeAdministrador(fecha,usuario,false)); 
	}
	
	public void agregarColaborador(Usuario usuario){
		Date fecha=new Date();
		perfiles.add(new PerfilDeUsuario(fecha,usuario));
	}
	
	
	public void eliminarUsuario(Usuario candidato) throws Exception{  
		
		/*
		 * Elimina al usuario enviado como parámetro. 
		 * Si coincide con el perfil de un usuario dentro del proyecto
		 * se elimina, en caso de que no exista se elimina el perfil null
		 */
		
		PerfilDeUsuario perfil= new PerfilDeUsuario(null, null);
		//recorro mi colección de perfiles y comparo cada elemento con el candidato a borrar que fue
		//enviado como parámetro buscando al mismo dentro de mi colección
		for (PerfilDeUsuario p: perfiles){
			if (p.getUsuario() == candidato){
				perfil=p;
				break;
			}
		}
		eliminarPerfil(perfil);
	}
	

	public void eliminarPerfil(PerfilDeUsuario perfil) throws Exception{
		//corroboro si el perfil que deseo eliminar es creador
		if (perfil.esCreador()){
			//Si es creador creo una excepcion
			throw new Exception("No se puede eliminar al creador del proyecto");
		}	
		else{
			//Si el perfil no es creador lo borro
			perfiles.remove(perfil);
		}
	}
	
	public void setCreador(Usuario usuario){  
		for (PerfilDeUsuario p: perfiles){
			if (p.esCreador()){
				((PerfilDeAdministrador) p).setCreador(false);
			}
		}
		Date fecha=new Date();
		perfiles.add(new PerfilDeAdministrador(fecha,usuario,true)); 
	}
	
	public Usuario getCreador(){
		Usuario u = new Usuario();
		for (PerfilDeUsuario p: perfiles){
			if (p.esCreador()){
				u= p.getUsuario();
			}
		}
		return u;
	}
	
}
