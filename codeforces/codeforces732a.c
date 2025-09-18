/* 732A
O código abaixo calcula o número mínimo de pás necessárias para que, dada uma quantidade
infinita de 10 burles e um outro valor, Policarpo consiga pagar sem precisar receber troco. 
Para isso, o número de pás multiplicado pela quantidade de pás x tem que ser divisível
por 0 ou o resto da sua divisão deve ser igual a r, que é o outro valor que Policarpo tem. 
O while testa até que uma dessas condições seja verdadeira, para assim determinar
a quantidade mínima de pás. 
*/

#include <stdio.h> 
int main(void){
    //preço de uma pá
    int k;
    int r;
    //valor mínimo de pás que ele tem que comprar
    int x;

    x = 1;

    //Meus inputs
    scanf("%d", &k);
    scanf("%d", &r);

    while(((x*k) % 10 != 0) && ((x*k)%10 != r)){
        x++;
    }

    printf("%d \n", x);
    return 0;
    
}