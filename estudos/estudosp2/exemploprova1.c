/*
============================================================
Exercício: Controle de Tráfego na Ponte
============================================================

Uma ponte suporta no máximo L toneladas por vez.
Durante o dia, N caminhões tentam atravessar a ponte.

Cada caminhão possui:
 - peso (em toneladas)
 - duração da travessia (em unidades de tempo)

A regra é:
1. A soma dos pesos dos caminhões que estão na ponte
   nunca pode ultrapassar o limite L.
2. Quando o tempo de travessia de um caminhão termina,
   ele sai da ponte e libera o peso.
3. Os caminhões chegam na ordem informada.
4. Se um novo caminhão não puder entrar (pois excederia
   o limite de peso), ele desiste (não espera).

O programa deve calcular quantos caminhões conseguiram
atravessar a ponte com sucesso.

------------------------------------------------------------
ENTRADA:
L N
<peso1> <duracao1>
<peso2> <duracao2>
...

------------------------------------------------------------
SAÍDA:
Um número inteiro representando quantos caminhões
conseguiram atravessar a ponte.

------------------------------------------------------------
EXEMPLO:
Entrada:
10 5
3 5
4 3
5 4
2 6
7 2

Saída:
4
============================================================
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Caminhao {
    int peso; //peso do caminhao
    int duracao; //duração da travessia
} Caminhao;

int main(){
    int l; //peso máximo da ponte
    scanf("%d", &l);

    int n; //quantidade de caminhões
    scanf("%d",&n);

    //criar um vetor de Caminhões
    Caminhao *vetor = (Caminhao*)malloc(n * sizeof(Caminhao));

    for(int i=0; i<n; i++){
        int pes, tmp;
        scanf("%d %d", &pes, &tmp);

        vetor[i].peso = pes;
        vetor[i].duracao = tmp;
    }

    int atravessou = 0; //quantos conseguiram atravessar
    int pesototal = 0; //peso total da ponte
    int i = 0; //começa do primeiro caminhao

    while(i < n){ //percorrer todos os caminhões

        //remover um minuto de cada um dos anteriores 
        for(int j=0; j<i; j++){
            //só mexe em quem está na ponte
            if(vetor[j].duracao > 0){
                vetor[j].duracao--;
                if(vetor[j].duracao == 0){
                    //se após decrementar acabou, o caminhão atravessou
                    pesototal -= vetor[j].peso;
                }
            }
        }

        if(vetor[i].peso + pesototal <= l){
            atravessou++;
            pesototal += vetor[i].peso;
        }

        else {
            vetor[i].duracao = 0; //nao entra
        }

        i++;
    }

    printf("%d\n", atravessou);
    free(vetor);
    return 0;
}
