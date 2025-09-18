/* 151a
Autor: Camila Cardoso de Menezes
O código a seguir calcula a quantidade máxima de brindes que n amigos podem fazer
seguindo suas próprias regras, que são: nl de bebida, uma fatia de limão e np de sal
Ele calcula a quantidade total que se tem de cada um dos recursos e após isso, 
compara os três para saber qual deles é o menor, que é o que definirá a quantidade máxima. 
*/

#include <stdio.h>
int main (void){
    // número de amigos
    int n;
    // número de garrafas
    int k;
    // mililitros de cada garrafa
    int l;
    // quantidade de limões
    int c;
    // fatias de cada limão
    int d;
    // gramas de sal
    int p;
    // quantidade necessária de ml de bebida
    int nl;
    // quantidade necessária de gramas de sal
    int np;

    int ml_total;
    int fat_total;
    int sal_total;
    int brindes_bebida;
    int brindes_fatia;
    int brindes_sal;
    int brindes_totais;

    ml_total = 0;
    fat_total = 0;
    sal_total = 0;

    brindes_bebida = 0;
    brindes_fatia = 0;
    brindes_sal = 0;
    brindes_totais = 0;

    //Meus inputs
    scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);

    //Objetivo -> printar o número máximo de brindes que cada amigo pode fazer, com todos bebendo a mesma quantidade
    ml_total = l*k;
    fat_total = c*d;
    sal_total = p;

    /*Temos três recursos: bebida, fatia de limão e sal 
    Devemos calcular quantos brindes podem ser feitos com esses três separados. 
    Para calcular a quantidade máxima de brindes, devemos saber o menor valor entre os três
    */

    //Brindes bebida
    brindes_bebida = ml_total / nl;

    //Quantidade de fatias
    brindes_fatia = fat_total; 

    //Brindes sal
    brindes_sal = sal_total / np; 

    //Descobrir qual destes valores é o menor 
   if (brindes_bebida <= brindes_fatia && brindes_bebida <= brindes_sal) {
        brindes_totais = brindes_bebida;
    } else if (brindes_fatia <= brindes_bebida && brindes_fatia <= brindes_sal) {
        brindes_totais = brindes_fatia;
    } else {
        brindes_totais = brindes_sal;
    }

    printf("%d\n", brindes_totais / n);
    }