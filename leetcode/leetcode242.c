/* LEETCODE 24
Autor: Camila Cardoso de Menezes
O código a seguir inicia criando um vetor de frequência, que guardará a quantidade de vezes que uma determinada letra aparece.
Depois, conta a quantidade de elementos em s e em t, porque se forem diferentes, não são anagramas.
Depois, checa a frequencia de cada letra em cada uma das strings, guardando-os em posições do alfabeto de 0 a 26
Ex: se a letra for a, que é 97 na tabela ASCII, guardará n posição zero, porque a-a é 97-97 = 0
Se for b, que é 98, guardará na posição 1, porque 98-97 = 1
Por fim, o código confere se a frequencia é igual. 
*/
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
