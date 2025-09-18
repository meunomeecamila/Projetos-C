bool isLongPressedName(char* name, char* typed) {
    int i=0;
    int j=0;

    //percorrer a string typed
    while (typed[j] != '\0') {
        //se forem iguais, tudo bem
        if (name[i] == typed[j]) {
            i++;
            j++;
        } 
        /*se forem diferentes, mas passou do índice 0 e typed
        é igual a última, tudo bem */
        else if (j > 0 && typed[j] == typed[j - 1]) {
            j++;
        } else {
            return false;
        }
    }
    return name[i] == '\0';
}