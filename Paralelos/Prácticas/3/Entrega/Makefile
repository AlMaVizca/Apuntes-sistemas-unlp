ARCHIVO=traspuesta

build:
	gcc -o $(ARCHIVO)-secuencial $(ARCHIVO)-secuencial.c
	gcc -fopenmp -o $(ARCHIVO)-original $(ARCHIVO)-original.c
	gcc -fopenmp -o $(ARCHIVO)-corregido-estatico $(ARCHIVO)-corregido-estatico.c
	gcc -fopenmp -o $(ARCHIVO)-corregido-dinamico $(ARCHIVO)-corregido-dinamico.c
	gcc -fopenmp -o $(ARCHIVO)-corregido-guiado $(ARCHIVO)-corregido-guiado.c


