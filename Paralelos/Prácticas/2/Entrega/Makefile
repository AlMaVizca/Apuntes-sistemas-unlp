#ARCHIVO=multiplicacionDeMatrices
ARCHIVO_S=6-secuencial
ARCHIVO_T=6-threads
build:
	gcc -pthread -o $(ARCHIVO_T) $(ARCHIVO_T).c 
	gcc -pthread -o $(ARCHIVO_T)-cache $(ARCHIVO_T)-cache.c 
	gcc -o $(ARCHIVO_S) $(ARCHIVO_S).c
	gcc -o $(ARCHIVO_S)-cache $(ARCHIVO_S)-cache.c
run:
	./$(ARCHIVO_S)
