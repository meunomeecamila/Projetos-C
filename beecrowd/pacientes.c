#include <stdio.h>
#include <stdlib.h>

typedef struct Paciente {
    int hora; //hora que chegou
    int min; //minuto que chegou
    int morte; //horário da morte

} Paciente;

int main(){
    int n; //pacientes
    int mortos = 0; //pessoas que não foram atendidas a tempo
    scanf("%d",&n);

    int h; //hora q chegou
    int m; //minuto q chegou
    int c; //minutos até morte

    //criar um vetor de pacientes
    Paciente *paci = (Paciente*)malloc(n * sizeof(Paciente));

    for(int i=0; i<n; i++){
        scanf("%d %d %d",&h, &m, &c);

        //criar um objeto paciente
        paci[i].hora = h;
        paci[i].min = m;
        paci[i].morte = c;
    }

    //agora que ja lemos que hora cada paciente chegou, colocar todo mundo na fila
    //hora de inicio do atendimento
    int horatual = 7; //07
    int minatual = 0; //00
    
    //primeiro paciente sempre será atendido de primeira
    //começar do segundo paciente
    horatual = paci[0].hora;
    minatual = paci[0].min;

    //depois do primeiro atendimento, o médico leva 30 minutos
    minatual += 30;
    if (minatual >= 60) {
        minatual -= 60;
        horatual += 1;
    }

    int espera = 0;

    //fazer pro resto dos pacientes
    for(int i=1; i<n; i++){
        //converter horários para minutos totais
        int chegada = paci[i].hora * 60 + paci[i].min; //chegada do paciente em minutos
        int atual   = horatual * 60 + minatual; //hora atual em minutos

        //Calcular tempo de espera e, se o médico estiver livre, começar na chegada
        if (atual <= chegada) {
            espera = 0;
            // médico livre: atender na chegada
            horatual = paci[i].hora;
            minatual = paci[i].min;
        } else {
            espera = atual - chegada;
        }

        //Empate não conta: só morre se esperar MAIS que C
        if (espera > paci[i].morte) mortos++;

        //chegar no proximo horario de atendimento
        minatual += 30;
        if(minatual >= 60){
            minatual -= 60;
            horatual += 1;
        }
    }

    printf("%d\n",mortos);
    free(paci);
    return 0;
}
