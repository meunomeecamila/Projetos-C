#include <stdio.h>
#include <string.h>

int compara(char *s1, char *s2){
    if(strlen(s1) != strlen(s2)){
        return 0;
    }

    else {
        int tam = strlen(s1);
        for(int i=0; i<tam; i++){
            char aa = s1[i];
            char bb = s2[i];
            if(aa != bb) return 0;
        }

        return 1;
    }
}

int main(){
    int qtd; //quantidade de pokemons
    scanf("%d", &qtd);
    int capturados = 0;
    int cont = 0; //quantidade de pokemons ja colocada

    //criar um vetor de strings
    char vetor[qtd][1000];

    /*for(int i=0; i<qtd; i++){
        scanf("%s", vetor[i]);
    }*/

    for(int i=0; i<qtd; i++){
        //percorrer todas as strings
        scanf("%s", vetor[i]);
        int achou = 0;

        //conferir se a string ja esta no vetor
        for(int j=0; j<cont; j++){
            if(compara(vetor[j], vetor[i])){
                achou = 1;
                break; //ja tem
            }
        }

        cont++; 

        if(achou == 0) {
            capturados++;
        }
    }

    int faltam = 151 - capturados;
    printf("Falta(m) %d pomekon(s).\n", faltam);


    return 0;
}