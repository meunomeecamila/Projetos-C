/* Autor: Camila Cardoso de Menezes
O código a seguir faz um for para escanear e obter os valores, e aproveita e os classifica em dois vetores separados: 
o de negativos, compostos por -1 e o de positivos, contendo 1.
Depois, faz um outro for para calcular a soma e o produto. 
Por fim, o código confere se a soma e o produto cumprem o desejado: soma positiva e produto = 1.
Caso não cumpram, o código calcula o número de operações necessárias para que esses pedidos sejam cumpridos, seguindo essa lógica: 
Primeiro, calcula quantas trocas são necessárias para que a soma seja ≥ 0, através da fórmula: 
(−soma + 1) / 2 (arredondando para cima).
Depois de aumentar a soma, verifica se o número de -1 restantes é par. 
Se for ímpar, mais uma troca é feita para tornar o produto igual a 1.
*/

#include <stdio.h>
int main(){
    //fazer o loop
    int loop;
    scanf("%d",&loop);
    int w;
    w = 0;
    while(w < loop){
        //pegar o valor do vetor
        int n;
        scanf("%d",&n);
        //criar o vetor com esse tamanho
        int v[n];
        int contadormenos = 0;

        //fazer um for para colocar os valores dentro do vetor
        //classificá-los em -1 e 1
        for(int i=0; i<n; i++){
            scanf("%d",&v[i]);
            if(v[i] == -1){ //se for -1
                contadormenos++;
            }
        }

        int op = 0;
        while ((n - 2 * contadormenos + 2 * op) < 0 || ((contadormenos - op) % 2 != 0)) {
            op++;
        }

        printf("%d\n", op);
        w++;
    }
    return 0;
}
