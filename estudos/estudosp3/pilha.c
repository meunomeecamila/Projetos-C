#include <stdio.h>

int main() {
    int cartas;
    scanf("%d", &cartas);

    while (cartas != 0) {

        // pilhas
        int p1[cartas];
        int p2[cartas];
        int p3[cartas];

        // ler as cartas (do topo ao fundo)
        for (int i = 0; i < cartas; i++) {
            scanf("%d %d %d", &p1[i], &p2[i], &p3[i]);
        }

        // índices dos topos de cada pilha
        int t1 = 0, t2 = 0, t3 = 0;
        int possivel = 1;

        // enquanto restar alguma carta em qualquer pilha
        while ((t1 < cartas || t2 < cartas || t3 < cartas) && possivel) {

            int a = (t1 < cartas ? p1[t1] : -1);
            int b = (t2 < cartas ? p2[t2] : -1);
            int c = (t3 < cartas ? p3[t3] : -1);

            int jogou = 0;

            // Tentativas com 1 carta
            if (t1 < cartas && (a % 3 == 0)) {
                t1++;
                jogou = 1;
            }
            else if (t2 < cartas && (b % 3 == 0)) {
                t2++;
                jogou = 1;
            }
            else if (t3 < cartas && (c % 3 == 0)) {
                t3++;
                jogou = 1;
            }

            // Tentativas com 2 cartas
            else if (t1 < cartas && t2 < cartas && ((a + b) % 3 == 0)) {
                t1++; t2++;
                jogou = 1;
            }
            else if (t1 < cartas && t3 < cartas && ((a + c) % 3 == 0)) {
                t1++; t3++;
                jogou = 1;
            }
            else if (t2 < cartas && t3 < cartas && ((b + c) % 3 == 0)) {
                t2++; t3++;
                jogou = 1;
            }

            // Tentativa com 3 cartas
            else if (t1 < cartas && t2 < cartas && t3 < cartas &&
                     ((a + b + c) % 3 == 0)) {
                t1++; t2++; t3++;
                jogou = 1;
            }

            // Nenhuma jogada possível
            if (!jogou) {
                possivel = 0;
            }
        }

        printf("%d\n", possivel);

        // ler próxima instância
        scanf("%d", &cartas);
    }

    return 0;
}
