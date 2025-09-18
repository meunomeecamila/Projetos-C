#include <stdio.h>
#include <stdlib.h>

char* intToRoman(int num) {
    //são números de até 4000

    //fazer uma string de letras e uma de valores
    //ex: M = 1000
    int valores[] =  {1000, 900, 500, 400, 100, 90,  
    50, 40,  10, 9,   5, 4,  1};
    char *letras[] = {"M", "CM", "D", "CD", "C","XC",
    "L","XL","X","IX","V","IV","I"};

    //criar a string resultado
    char *resultado = malloc(20 *sizeof(char));

    int position = 0;

    //percorrer os números romanos
    for(int i=0; i<13; i++){
        while(num>= valores[i]){
            int j=0;
            while(letras[i][j] != '\0'){
                resultado[position++] = letras[i][j++];
            }
            num = num - valores[i];
        }
    }

    // finaliza string com caractere nulo
    resultado[position] = '\0'; 
    return resultado;

}