/* 1692A
Autor: Camila Cardoso de Menezes
O código a seguir calcula quantas pessoas estão na frente de Timur dadas 
as distâncias. 
Ele utiliza um while para executar várias situações ao mesmo tempo. 
Para calcular as distâncias, utiliza uma variável contador, adicionando
um ponto a cada distância que for maior que a dele. 
*/


#include <stdio.h>
int main() {
    //contador para o while
    int n;
    scanf("%d", &n); 
    
    while (n > 0) { 
        //distância de timur
        int a;
        //distância dos outros
        int b, c, d;
        int contador = 0;

        scanf("%d %d %d %d", &a, &b, &c, &d);

        // Verifica quantos corredores estão na frente de timur
        if (b > a) {
            contador++;
        }
        if (c > a) {
            contador++;
        }
        if (d > a) {
            contador++;
        }

        printf("%d\n", contador); 
        n--;  // Decrementa o número de casos de teste
    }

    return 0;
}
