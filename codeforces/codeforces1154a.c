/*
*AED 115A
*Autor: Camila Cardoso de Menezes*/
/*Explicação: A conta em si é fácil: pegar o maior dos números (soma) e diminuir dos dois que 
não queremos descobrir. Ex: se quero descobrir a, pegar a+b+c e subtrair b+c. O problema
do código é que nem sempre eles virão na ordem certa. Por isso precisamos encontrar o maior
número para que assim subtraiamos ele dos demais (linhas 20 a 48) */

#include <stdio.h>
int main (void) {
    //x1 = a + b
    //x2 = a + c
    //x3 = b + c
    //x4 = a+b+c
    int x1, x2, x3, x4;
    int a, b, c;
    int maior, num1, num2, num3;
    scanf("%d %d %d %d", &x1, &x2, &x3, &x4);
    
    //Achar o maior e logo, a soma
     // Tentativa 1 -> x1
    if(x1>x4 && x1>x2 && x1>x3){
        maior = x1;
        num1 = x4;
        num2 = x2;
        num3 = x3;
    }
     // Tentativa 2 -> x2
    if(x2>x1 && x2>x4 && x2>x3){
        maior = x2;
        num1 = x1;
        num2 = x4;
        num3 = x3;
    }
     // Tentativa 3 -> x3
    if(x3>x1 && x3>x2 && x3>x4){
        maior = x3;
        num1 = x1;
        num2 = x2;
        num3 = x4;
    }
    // Tentativa 4 -> x4
    if(x4>x1 && x4>x2 && x4>x3){
        maior = x4;
        num1 = x1;
        num2 = x2;
        num3 = x3;
    }

    
    /* considerando que a variável maior é o maior número pois é a soma de todos os
    outros três, usamos ele para descobrir os valores de a,b e c*/
    a = maior - num1;
    b = maior - num2;
    c = maior - num3; 
    printf("%d \n", a);
    printf("%d \n", b);
    printf("%d \n", c);
}