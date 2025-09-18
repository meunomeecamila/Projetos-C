bool isAnagram(char* s, char* t) {
    //como tem 26 letras minúsculas, criar um vetor para contar a freq delas
    //zerar o vetor
    int c[26] = {0};
    
    //percorrer as strings porque se os tamanhos forem diferentes não são anagramas
    int i = 0;
    int j = 0;
    while (s[i] != '\0') i++;

    while (t[j] != '\0') j++;
    if (i != j) {
        return false;}

    //checar frequencia da primeira string
    //guarda a frequencia no valor anterior
    for (int a = 0; a < i; a++) {
        c[s[a] - 'a']++;
    }

    // segunda string
    for (int b = 0; b < j; b++) {
        c[t[b] - 'a']--;
        if (c[t[b] - 'a'] < 0) return false;
    }

    return true;
}
