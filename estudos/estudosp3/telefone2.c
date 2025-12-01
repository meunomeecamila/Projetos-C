#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int modelo[100];
        int tam = 0;

        // consumir o espaço após o número
        getchar();

        // lê até o fim da linha
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            if (c >= '0' && c <= '9') {
                modelo[tam++] = c - '0';
            }
        }

        int vezes = 0;

        // agora compara com os próximos telefones
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < tam; j++) {
                int num;
                scanf("%d", &num);
                if (num == modelo[j]) vezes++;
            }
        }

        printf("%d\n", vezes);
    }
    return 0;
}
