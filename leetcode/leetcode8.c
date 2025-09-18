int myAtoi(char* s) {
    //pular os espaços em branco
    int i=0;
    while(s[i] == ' ')i++; //para saber quantos pular

    //variáveis
    long int result = 0; //resultados
    int negativo = 0; //negativo
    int temdigit = 0; //se não tiver digitos retorna 0

    //tratar os sinais
    if (s[i] == '-') {
        negativo = 1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    /*ler a string e ignorar "", caracteres e 
    o que vem depois de não dígitos*/
     for (int j = i; s[j] != '\0'; j++) {
        if (s[j] < '0' || s[j] > '9') break;

        temdigit++;
        result = result * 10 + (s[j] - '0');

        if (!negativo && result > 2147483647L) return 2147483647;
        if (negativo && result > 2147483648L) return -2147483648;
    }

    //se não tiver nenhum número, retornar zero
    if(temdigit == 0) return 0;

    //tratar os negativos
    if(negativo == 1){ result = -result;}
    return (int)result;
}