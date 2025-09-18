/*Autor: Camila Cardoso de Menezes
Exercício LeetCode 263
O código a seguir testa a divisão do número n por 2,3 e 5. 
Caso esse número seja divisivel por um deles até chegar em 1,
ele é considerado um ugly number, e aí retornamos verdadeiro. 
Caso ele não seja divisivel até chegar em um, retornamos falso.
*/



class Solution {
public:
    bool isUgly(int n) {
        if(n<=0){
            return false;
        }

        //dividir o numero por 2,3 e 5. 
        //Se o resultado final der 1, então ele é feio
        while(n%2==0){
            n = n/2;
        }
        while(n%3==0){
            n = n/3;
        }
        while(n%5==0){
            n = n/5;
        }

        //se as divisões foram feitas e o número chegar a 1,
        //ele é um ugly number
        if (n == 1) {
            return true;
        } else {
            return false;
        }
    }
};