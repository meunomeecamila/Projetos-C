#include <stdio.h>

int main(void) {
    //os colchetes fazem parte das strings. Eles podem armazenar no máximo 11 caracteres,
    //sendo 10 + o /n
    char passodm[11]; 
    char passodra[11]; 

    //contadordm = contador do Dreamoon
    int contadordm;
    contadordm = 0;
    //contadordra = contador do Drazil
    int contadordra;
    contadordra = 0;
    //desconhecido = número de ?
    int desconhecido;
    desconhecido = 0;
    //casos que queremos achar
    int possivel;
    //numero de + que precisamos para alcançar o objetivo
    int mais;

    
    scanf("%s", passodm);
    scanf("%s", passodra);

    int i = 0;
    //linha do Dreamoon
    while (passodm[i] != '\0') {
        if (passodm[i] == '+') {
            contadordm++;
        } else if (passodm[i] == '-') {
            contadordm--;
        }
        i++;
    }

    i = 0;
    // linha do Drazil
    //\0 é nulo no char
    while (passodra[i] != '\0') {
        if (passodra[i] == '+') {
            contadordra++;
        } else if (passodra[i] == '-') {
            contadordra--;
        } else if (passodra[i] == '?') {
            desconhecido++;
        }
        i++;
    }

    //verificar se é possivel alcançar
    //possivel = contadordra(alvo que queremos - drazil) - contadordm(o que ja fizemos - dreamoon)
    possivel = contadordm - contadordra;

    if (possivel > desconhecido || ((possivel + desconhecido) % 2 != 0)) {
        //não é possivel
        printf("0.000000000\n");
        return 0;
    }

    //Caso chegue até aqui, significa que é possivel
    //descobrir o valor de + que temos que alcançar
    mais = (possivel + desconhecido) / 2;

    //fazer uma combinação entre a quantidade que precisamos e o total de ?
    long long int casos_favoraveis = 1;
    for (int i = 0; i < mais; i++) {
        casos_favoraveis = casos_favoraveis * (desconhecido - i);
        casos_favoraveis = casos_favoraveis / (i + 1);
    }

    //o total de casos possíveis é dado por 2 elevado às interrogaões
    int total_casos = 1 << desconhecido;

    //calcular probabilidade -> pode ser decimal, então usamos float
    float probabilidade = (float) casos_favoraveis / total_casos;

    //.9f serve para colocar a quantidade de decimais pedida no codeforcs
    printf("%.9f\n", probabilidade);

    return 0;
}
