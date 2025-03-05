//mesma funcao soma, mas agora usando ponteiro

#include <stdio.h>
#include <math.h>

void soma(int *a, int *b){
    int num = *a + *b;
    printf("%d + %d = %d\n\n", *a, *b, num);
}

int main(){
    int A = 69;
    int B = 24;

    soma(&A, &B);

    return 0;
}