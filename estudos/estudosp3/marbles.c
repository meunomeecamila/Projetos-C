//Passo a passo
//ler a quantidade de numeros e de consultas
//ler os numeros
//ordenar os numeros 
//ler as consultas
//procurar as consultas -> imprimir no primeiro q encontrar
//se não encontrar, imprime not found

#include <stdio.h>
int main(){
    int qtd; //quantidade de numeros na lista
    int consultas; //quantidade de consultas

    scanf("%d", &qtd);
    scanf("%d", &consultas);

    int caso=0;

    while(!(qtd == 0 && consultas == 0)){
        printf("CASE# %d:\n",(caso+1));
        int vetor[qtd]; //vetor que guarda a lista
        for(int i=0; i<qtd; i++) scanf("%d", &vetor[i]);

        //agora, ordenar
        for(int i=0; i<qtd-1; i++){
            for(int j=0; j<qtd-1-i; j++){
                if(vetor[j] > vetor[j+1]){
                    int tmp = vetor[j];
                    vetor[j] = vetor[j+1];
                    vetor[j+1] = tmp;
                }
            }
        }

        //for(int i=0; i<qtd; i++) printf("%d", vetor[i]);

        //depois que ordenar, consultar
        for(int i=0; i<consultas; i++){
            int consultaatual;
            scanf("%d", &consultaatual);
            
            //percorrer o vetor e procurar a consulta
            int achou = 0;
            for(int j=0; j<qtd; j++){
                if(achou == 1) break;
                if(vetor[j] == consultaatual){
                    printf("%d found at %d\n", consultaatual, j+1);
                    achou = 1;
                    break;
                }
            }

            if(achou == 0) printf("%d not found\n", consultaatual);
        }

        scanf("%d", &qtd);
        scanf("%d", &consultas);
        caso++;
    }
    return 0;
}