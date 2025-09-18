/* Autor: Camila Cardoso de Menezes
O código a seguir calcula o MDC de todos os números fornecidos na lista. Caso o MDC esteja na lista,
o imprime. Caso não esteja, imprime -1. 
Tentei fazer usando dois for e verificando um por um, mas com valores muito altos o tempo foi excedido. 
*/

#include <stdio.h>
//função que calcula o MDC de dois números
int mdc(int a, int b) {
    while (b != 0) {
        int var = b;
        b = a % b;
        a = var;
    }
    return a;
}

int main() {
    int n;
    //pegar a quantidade de itens
    scanf("%d", &n);
    int v[n];

    //pegar o valor de cada um
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    //pega o primeiro número do vetor e armazena
    int geral = v[0];
    //depois de pegar o primeiro, faz o mdc do geral com o segundo e pega o resultado
    //e aí faz o mdc do resultado com o terceiro e assim por diante
    for (int i = 1; i < n; i++) {
        geral = mdc(geral, v[i]);
    }

    int found = 0;
    for (int i = 0; i < n; i++) {
        //se encontrar o MDC na lista, temos a resposta
        if (v[i] == geral) {
            found = 1;
            break;
        }
    }

    if (found == 1) {
        printf("%d\n", geral);
    } else {
        printf("-1\n");
    }

    return 0;
}
