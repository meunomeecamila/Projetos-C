#include <stdio.h>
//oi

//a função contarNumeros serve para aumentar o contador, fazendo com que os números binários sejam descobertos
void contarNumeros(int num, int n, int *contador) {
    if (num > n) return;  // Se o número for maior que n, paramos a recursão
    (*contador)++;  // Contamos o número atual

    // Chamamos a função recursivamente para gerar os próximos números
    contarNumeros(num * 10, n, contador);     // Adiciona um 0 no final
    contarNumeros(num * 10 + 1, n, contador); // Adiciona um 1 no final
}

int main(void) {
    int n;
    scanf("%d", &n);

    int contador = 0;
    contarNumeros(1, n, &contador);  // Iniciamos a contagem com o número 1

    printf("%d\n", contador);
    return 0;
}
