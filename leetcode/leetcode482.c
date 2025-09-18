char* licenseKeyFormatting(char* s, int k) {
    //primeiro pode ter menos de k
    /* depois do primeiro, cada grupo precisa ter 
    exatamente k caracteres */

    // !!! passo 1 - remover todos os hífens originais !!!
    //contar quantidade da s
    int tam=0;
    while(s[tam] != '\0') tam++;
    //criar uma string nova sem hifens
    char *n = malloc((tam+1)*sizeof(char));
    //colocar os itens na string
    int cont = 0;
    for(int j=0; j<tam; j++){
        if(s[j] != '-'){
            n[cont++] = s[j];
        }
    }
    n[cont] = '\0'; // garantir que a string nova termina corretamente

    //!!!passo 2 - converter todas as letras para maiúsculas!!!
    int h=0;
    while(n[h] != '\0'){
        if(n[h]>= 'a' && n[h] <= 'z'){//se for minúscula
            n[h] = n[h] - 32;
        }
        h++;
    }

    //!!!passo 3 - dividir em grupos
    //ver o tamanho da nova string
    int tamN = 0;
    while(n[tamN] != '\0') tamN++;
    // alocar memória suficiente para o resultado
    // máximo de hífens que podem ser inseridos: (tamN-1)/k
    int maxHifens = (tamN > 0) ? (tamN - 1) / k : 0;
    char *result = malloc((tamN + maxHifens + 1) * sizeof(char));

    //agrupar de trás para frente, inserindo um hifen de k em k
    int pos = 0; // posição em result
    int count = 0; //conta quantos caracteres já foram add no grupo

    for (int i = tamN - 1; i >= 0; i--) {
        result[pos++] = n[i];  // adiciona o caractere atual
        count++;

        if (count == k && i != 0) {
            result[pos++] = '-'; // adiciona hífen se ainda não for o fim
            count = 0; // zera o contador do grupo
        }
    }

    result[pos] = '\0'; // primeiro termina a string

    //agora a string está invertida, então temos que reverter
    char *resultado = malloc((pos + 1) * sizeof(char));
    //contar quantidade de result (pos já tem)
    int tamResult = pos;

    //começar do final
    int resultcont = 0;
    for (int i = tamResult - 1; i >= 0; i--) {
        resultado[resultcont++] = result[i];
    }
    resultado[resultcont] = '\0'; // finaliza corretamente

    free(n);
    free(result);

    return resultado;
}
