void moveZeroes(int* nums, int numsSize) {
    int insertPos = 0; //cria uma posição pro prox zero

    //move todos os elementos que não são zero pra frente
    for (int i=0; i < numsSize; i++) {
        if (nums[i] != 0) { //se não for zero
            nums[insertPos++] = nums[i];
        }
    }

    //completa o resto com zeris
    while (insertPos < numsSize) {
        nums[insertPos++] = 0;
    }  
}