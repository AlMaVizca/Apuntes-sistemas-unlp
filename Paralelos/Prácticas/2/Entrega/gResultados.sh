#!/bin/bash

for each in 512 1024 2048; do 
       for x in $(seq 1  100); do 
         ./6-secuencial $each >> secuencial-$each.txt; 
         ./6-threads $each >> threads-$each.txt; 
       done; 
done
