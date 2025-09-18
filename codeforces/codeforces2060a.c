/*
*AED 2060A
*Autor: Camila Cardoso de Menezes*/
/*Explicação: o código a seguir conta com duas hipóteses para garantir que o máximo de
equações sejam satisfeitas. O teste 1 testa o valor de a3 para a1+a2. Enquanto o teste 2 
testa o valor de a3 para a5-a4. 
A cada equação satisfeita, é somado 1 ponto. 
O teste que tiver mais pontos no final é o printado. 
*/
#include <stdio.h>
int main (void) {
    int ntestes;
    scanf("%d", &ntestes);
    while(ntestes>0){
    
    //Inicialização
    int a1, a2, a3, a4, a5;
    int pontos1, pontos2;
    scanf("%d %d %d %d", &a1, &a2, &a4, &a5);
    pontos1 = 0;
    pontos2 = 0;

    //Testar quantidade de satisfações dado a3 = a1 + a2
    a3 = (a1 + a2);
    pontos1++;
    if(a4 == a2 + a3){
        pontos1++;
    }
    if(a5 == a3 + a4){
        pontos1++;
    }

    //Testar a quantidade de satisfações dado a3 = a5 - a4
    a3 = (a5 - a4);
    if(a3 == (a1 + a2)){
        pontos2++;
    }
    if(a4 == (a2 + a3)){
        pontos2++;
    }
    if(a5 == (a3 + a4)){
        pontos2++;
    }
    
    //Printar o teste que obteve mais pontos 
    if(pontos1>pontos2){
        printf("%d \n",pontos1);
    }
    else printf("%d \n",pontos2);
    ntestes--;
    }
    return 0;
}