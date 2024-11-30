#!/bin/bash
clear
for file in maps/maps/invalid/*; do
    echo "Parsing map: $file..."
    echo "---------------------------"
    
    # Executa o Valgrind e captura a saída
    valgrind_output=$(valgrind --leak-check=full ./cub "$file" 2>&1)
    
    # Filtra e imprime as mensagens de erro do programa que começam com "Error:"
    echo "$valgrind_output" | grep "^Error:"
    echo "---------------------------"
    # Filtra e imprime a partir de "HEAP SUMMARY:" até o final usando awk
    echo "$valgrind_output" | awk '/ERROR SUMMARY:/,0'

    echo "---------------------------"
    sleep 1
    #clear
done
