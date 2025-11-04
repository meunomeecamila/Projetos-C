/*
    Problema: Teclado Quebrado (variação do Beiju Text)

    Enunciado:
    Um teclado defeituoso possui duas teclas especiais:
    - A tecla '[' move o cursor para o início do texto (Home).
    - A tecla ']' move o cursor para o final do texto (End).

    Todas as demais teclas inserem o caractere digitado na posição atual do cursor.
    O texto começa vazio e o cursor inicia no final (como em um editor normal).

    Sua tarefa é simular o funcionamento desse teclado, 
    reconstruindo o texto final digitado após a leitura de todos os caracteres.

    Entrada:
    - Várias linhas contendo uma sequência de caracteres (sem espaços).
    - A leitura deve continuar até o fim do arquivo (EOF).

    Saída:
    - Para cada linha de entrada, imprimir o texto resultante após a simulação.

    Exemplo de entrada:
    ThisIs[aTest]
    [abc]xyz

    Saída correspondente:
    aTestThisIs
    abcxyz

    Restrições:
    - O programa não pode usar funções prontas de manipulação de strings (como strcat, strlen, etc.).
    - Deve-se controlar manualmente o cursor e o deslocamento dos caracteres.
    - Tamanho máximo aproximado: 10^5 caracteres por linha.
*/


#include <stdio.h>

int main(){
    char texto[100000]; //texto completo

    while(scanf("%s", texto) != EOF){
        //fazer um vetor de caracteres
        //quando pressionar home, ir para o início e adicionar de lá
        //quando pressionar end, ir para o fim e adicionar de lá
        //e continuar normalmente

        char novo[100000]; //aumentei o tamanho para não limitar
        int i = 0; //contador de caracteres da entrada
        int tam = 0; //contador do tamanho atual do texto final
        int j = 0; //onde vamos inserir -> início ou fim

        while(texto[i] != '\0'){
            char c = texto[i];

            if(c != '[' && c != ']'){
                //inserir caractere normal na posição pedida
                //deslocar o resto do vetor para a direita
                for(int a = tam; a > j; a--){
                    novo[a] = novo[a-1];
                }

                novo[j] = c; 
                j++;
                tam++;
            }

            else if(c == '['){
                //apertou o botão de home -> inserir no início
                j = 0;
            }

            else if(c == ']'){
                //apertou o botão de end -> inserir no fim
                j = tam;
            }

            i++;
        }

        //termina a string
        novo[tam] = '\0';

        //no final, printar o vetor novo
        printf("%s\n", novo);
    }

    return 0;
}
