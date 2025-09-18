/*
*AED 818A
*Autor: Camila Cardoso de Menezes*/
/*Explicação: Para resolver o seguinte código, foi necessária uma conta matemática.
Se o número de diplomas é igual ao número de certificados multiplicado por k, podemos pensar que:
diplomas + diplomas*k é igual a quantidade de vencedores, que é n/2
Com isso descobrimos que o valor máximo para diplomas é (n/2) / 1 + k, porque: 
d + d*k <= n/2
d(1+k) <= n/2
Assim, utilizamos o maior valor possível de d para descobrir assim a quantidade de 
certificados e de diplomas. Os vencedores serão a soma dos dois e assim, os não vencedores
serão o total - vencedores
*/

#include <stdio.h>
int main (void){
    // Declarar as nossas variáveis
    long long int vencedores;
    long long int nvencedores;
    long long int certificados; 
    long long int diplomas;
    // número de alunos
    long long int n;
    // certificados / diplomas  
    long long int k;

    //Meus inputs
    scanf("%lld %lld", &n, &k);

    //certificados = k * diplomas;
    diplomas = (n/2) / (1 + k);
    certificados = k * diplomas;
    vencedores = diplomas + certificados;
    nvencedores = n - vencedores;

    //Meus outputs 
    //numero de alunos com diplomas 
    printf("%lld \n", diplomas);
    //numero de alunos com certificados 
    printf("%lld \n", certificados);
    //numero de alunos que não são vencedores 
    printf("%lld \n", nvencedores);
    
}