#!/bin/bash

mkdir -p Result
for each in 512 1024 2048; do 
       for x in $(seq 1  10); do 
         ./6-secuencial $each >> Result/secuencial-$each.txt; 
         ./6-secuencial-cache $each >> Result/secuencial-cache-$each.txt; 
         ./6-threads $each >> Result/threads-$each.txt; 
         ./6-threads-cache $each >> Result/threads-cache-$each.txt; 
       done; 
done

for eachFile in $(ls Result); do
    awk '{s+=$1}END{print s/NR}' RS=" " Result/$eachFile > Result/average-$eachFile
    sort -n Result/$eachFile > Result/sorted-$eachFile;
    echo $AVG, $eachFile > Result/$eachFile
    echo "mediana:" >> Result/$eachFile
    grep $(AVG=$(cat Result/average-$eachFile) && echo "${AVG%?}") Result/sorted-$eachFile >> Result/$eachFile
done
