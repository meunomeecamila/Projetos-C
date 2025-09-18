/*CODEFORCES 1772B
Autor: Camila Cardoso de Menezes
O código a seguir aloca a matriz 2x2 e seus elementos. Depois, cria um for de rotação 
para poder testar as quatro possibilidades rotacionando e checar se a matriz é bonita.
Para descobrir se a matriz é bonita, o código utiliza a função mudar, que retorna
1 caso ela satisfaça as condições e 0 caso não satisfaça. 
Zero significa que ela ainda não rotacionou até a correta ou que 
não é bonita.
Caso o if acabe e a função retorne 0 sempre, ela é feia. 
*/
#include <stdio.h>
#include <stdlib.h>

//função verifica se a matriz está bonita
int mudar(int a, int b, int c, int d) {
    if(a < b && c < d && a < c && b < d){
        return 1;
    }
    else return 0;
}

int main() {
    //testes para o loop
    int a;
    scanf("%d", &a);
    int b = 0;

    while (b < a) {
        //alocar a matriz
        int **matriz;
        int n = 2;
        matriz = (int **)malloc(n * sizeof(int *)); // Criar o espaço
        for (int i = 0; i < n; i++) {
            matriz[i] = (int *)malloc(n * sizeof(int));
        }

        //ler os elementos da matriz
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        int num1, num2, num3, num4;
        int rotacao;
        int found = 0;  //found == 1, parar de rodar (flag)

        // Rodar as 4 vezes para testar todas as rotações da matriz 2x2
        for (rotacao = 0; rotacao < 4; rotacao++) {
            // Atualizar os números dependendo da rotação
            num1 = matriz[0][0];
            num2 = matriz[0][1];
            num3 = matriz[1][0];
            num4 = matriz[1][1];

            // Verificar se a matriz atual é bonita com a função mudar
            if (mudar(num1, num2, num3, num4)) {
                printf("YES\n");
                found = 1;
                break; // Se encontrar, não precisa mais rodar
            }

            // Rotacionar a matriz 90 graus no sentido horário
            int temp = matriz[0][0];
            matriz[0][0] = matriz[1][0];
            matriz[1][0] = matriz[1][1];
            matriz[1][1] = matriz[0][1];
            matriz[0][1] = temp;
        }

        if (found == 0) {
            printf("NO\n");
        }

        // Liberar memória
        for (int i = 0; i < n; i++) {
            free(matriz[i]);
        }
        free(matriz);
        b++;
    }

    return 0;
}
