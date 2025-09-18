/* 427A
Autor: Camila Cardoso de Menezes
O código a seguir calcula o número de crimes que não serão solucionados dado a falta de policiais. 
Caso o número seja -1, significa que será um crime. Caso seja outro número, significa que é a adição de um policial.
Os policiais que já foram designados para crimes serão removidos da contaem, porque 
cada um só pode resolver um crime. 
O primeiro if aumenta o número de policiais, o segundo aumenta o número de crimes e o terceiro remove 
os policiais já utilizados. 
*/

#include <stdio.h>
int main(void){
    //minhas variáveis
    // n -> número de eventos
    int n;
    int evento;
    int crimes;
    int policiaisdisp; 
    
    policiaisdisp = 0;
    crimes = 0;
    
    //meus inputs
    scanf("%d", &n);

    for(int i=0; i<n; ++i){
        scanf("%d", &evento);
        if(evento>0){
            //é um policial
            policiaisdisp = policiaisdisp + evento;
        }
        if(evento<0 && policiaisdisp==0){
            //é um crime
            crimes++;
        }
        else if(evento<0 && policiaisdisp>0){
            policiaisdisp--;
        }
    }

    printf("%d \n", crimes);
    return 0;

}