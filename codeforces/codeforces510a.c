/* 510A
Autor: Camila Cardoso de Menezes
O código a seguir cria o desenho de uma cobra, sendo que locais com # representam o corpo
da cobra e locais com ponto, representam o vazio. 
Nas linhas pares, o corpo da cobra segue completo. 
Nas linhas ímpares, temos duas divisões: corpo na primeira coluna a direita ou a esquerda. 
O código utiliza de ifs para descobrir qual das três ocasiões está acontecendo e completa de acordo, 
utilizando o comando de repetição for. 
*/

#include <stdio.h>
int main (void){
    // n = número de linhas
    int n;
    // m = número de colunas
    int m;
    //Meus inputs
    scanf("%d %d", &n, &m);

    //Criar um contador para cada linha
    for(int i=0; i<n; i++){
        //caso a linha seja par -> imprimir # em tudo
        if(i%2 == 0){
            for (int j = 0; j < m; j++) {
                printf("#");
            }
    } 
        //caso a linha seja ímpar tem duas situações
        //situação 1: linhas 2,6,10,14... -> corpinho da cobra na direita
        else if(i%4 == 1) {
            for (int j = 0; j < m - 1; j++) {
                    printf(".");
                }
            printf("#");
            }
        //situação 2: linhas 4, 8, 12, 16... -> corpinho da cobra na esquerda
        else {
            printf("#");
            for (int j = 1; j < m; j++) {
                    printf(".");
                }
            }
        //No final de todo for, fazer uma quebra de linha
        printf("\n");
            
    }   
    return 0; 
    }
    