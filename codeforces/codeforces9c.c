/* Codeforces 9c
Autor: Camila Cardoso de Menezes
O código a seguir cria uma função recursiva chamada binários. Ela não retorna nada caso
o número ultrapasse o valor pedido. Se não ultrapassar, ela aumenta
o contador e multiplica o número por 10 para gerar os números escritos com final 0 
e aumenta 1 pra gerar os números escritos com final 1
*/
// objetivo: criar um código que fale quantos números escritos com 0 e/ou 1 temos de 1 a n
// como fazer: numeros de 1 a n tem que começar com 1. Depois disso, eles apenas são 1 x 10 ou 1 x 10 + 1.

#include <stdio.h>
void binario(int num, int n, int *contador){
    //se o num atual for maior que n, saia da função
    if(num > n) return;
    
    (*contador)++;
    //numeros com 0 no final
    binario(num * 10, n, contador);
    //numeros com 1 no final
    binario(num * 10 + 1, n, contador);
}

int main(void){
    int n;
    scanf("%d",&n);
    int contador = 0;

    binario(1,n,&contador);
    
    printf("%d\n",contador);
    return 0;
} 