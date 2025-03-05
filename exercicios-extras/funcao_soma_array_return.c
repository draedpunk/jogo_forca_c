// Escreva uma função soma que recebe um array de inteiros 
// e o tamanho do array, e retorna a soma dos números desse array.

#include <stdio.h>
#include <math.h>

int soma(int nums[3], int tamanho){
    int somatorio = 0;
    
    for (int i = 0; i < tamanho; i++){
        somatorio += nums[i];
    }

    return somatorio;
}

int main(){
    int listanumeros[3];
    listanumeros[0] = 69;
    listanumeros[1] = 4;
    listanumeros[2] = 61;

    int r = soma(listanumeros, 3);

    printf("O somatorio do array fornecido eh: %d", r);

    return 0;
}