/* Autor: Camila Cardoso de Menezes
O código a seguir pega todos os elementos através de um vetor e os divide em três listas: a de positivos, negativos e zero.
O objetivo é dividir em tres conjuntos que o produto do primeiro dê positivo, do segundo negativo
e do terceiro zero. Para isso, ele confere o de positivos primeiro. Caso tenha algum número positivo, ele o coloca na lista
e joga os outros para a lista do zero. Caso não tenha, ele pega dois negativos e os coloca, pois a multiplicação
de dois negativos é positiva. 
Para os negativos, ele coloca um número ímpar de negativos e joga o resto no zero.
O produto da lista que tem que dar zero apenas necessita de um número 0, pois qualquer número x zero = 0
*/



#include <stdio.h>
int main(){
    //primeiro input -> número do vetor
    int n;
    scanf("%d",&n);
    //cria o vetor com n elementos
    int v[n];
    //fazer os vetores para dividir os números em listas
    int neg[n], pos[n], zero[n];
    //fazer contadores para saber quantos números tem em cada conjunto
    int cneg = 0;
    int cpos = 0;
    int czero = 0;

    //fazer um for pra pegar cada elemento e separar em listas de negativo, positivo e zero
    for(int i=0; i<n; i++){
        scanf("%d",&v[i]);
        //negativos
        if(v[i]<0){
            neg[cneg++] = v[i];
        }
        //positivos
        if(v[i]>0){
            pos[cpos++] = v[i];
        }
        //zeros
        if(v[i]==0){
            zero[czero++] = v[i];
        }
    }
    
    //agora já temos as listas com os números divididos, precisamos colocar em conjuntos
    //conjuntos
    int conjneg[n];
    int conjpos[n];
    int conjzero[n];
    //criar contadores 
    //c1 negativo, c2 positivo e c3 zero
    int c1 = 0, c2 = 0, c3 = 0;

    //negativo -> sempre colocar 1 negativo no conjunto 1
    conjneg[c1++] = neg[0];

    //positivos
    if(cpos == 0){
        conjpos[c2++] = neg[1];
        conjpos[c2++] = neg[2];
    } 
    else {
        for(int i=0; i<cpos; i++){
            conjpos[c2++] = pos[i];
        }
    }

    int start;
    if(cpos == 0){
        start = 3;
    } else {
        start = 1;
    }

    for(int i = start; i < cneg; i++){
        conjzero[c3++] = neg[i];
    }

    //zero
    for(int i=0; i<czero; i++){
        conjzero[c3++] = zero[i];
    }

    //printar o número de elementos + elementos
    //negativos -> conjunto 1
    printf("%d", c1);
    for (int i = 0; i < c1; i++) {
        printf(" %d", conjneg[i]);
    }
    printf("\n");

    //positivos -> conjunto 2
    printf("%d", c2);
    for (int i = 0; i < c2; i++) {
        printf(" %d", conjpos[i]);
    }
    printf("\n");

    //zero -> conjunto 3
    printf("%d", c3);
    for (int i = 0; i < c3; i++) {
        printf(" %d", conjzero[i]);
    }
    printf("\n");

    return 0;
}
