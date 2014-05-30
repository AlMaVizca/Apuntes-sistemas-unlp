build:
	gcc -o secuencial Secuencial.c
	mpicc -o mpi mpi.c

run:
	mpirun -np 4 mpi 1024
#mpirun –np cantidadDeProcesos –machinefile archivoMaquinas ejecutable
#El formato de archivo de máquinas es:
#maquina1 slot=cantidad de procesadores de la maquina1
#maquina2 slot=cantidad de procesadores de la maquina2
#.#..
#maquinaN slot=cantidad de procesadores de la maquinaN
