int missingNumber(int* nums, int numsSize) {
    //retornar o número que falta
    //colocar eles em ordem
    int *ordem = malloc((numsSize + 1) * sizeof(int));  // corrigido: ponteiro e tamanho

    //inicializar todos com 0 pra contar a frequência
    for (int i = 0; i <= numsSize; i++) {  // corrigido: 'n' virou 'numsSize'
        ordem[i] = 0;
    }

    // Conta quantas vezes cada número aparece
    for (int i = 0; i < numsSize; i++) {
        ordem[nums[i]]++;
    }

    // Reconstrói o vetor em ordem
    int indice = 0;
    for (int i = 0; i <= numsSize; i++) {  // corrigido: 'n' virou 'numsSize'
        while (ordem[i] > 0) {
            nums[indice++] = i;
            ordem[i]--;
        }
    }

    //percorrer os números -> ex: numSize = 3 significa que vai de 0 a 3
    int i;
    for (i = 0; i < numsSize; i++) {
        if (i != nums[i]) break;
    }

    free(ordem); // boa prática: liberar memória alocada
    return i;
}
