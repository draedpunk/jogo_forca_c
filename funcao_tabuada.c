// Criação de uma tabuada por meio de uma função com paramêtro.

#include <stdio.h>

void aberturafuncao(int n){
    printf("****************************\n");
    printf("*     TABUADA DO %d      *\n", n);
    printf("****************************\n\n");
    // printf("Segue tabuada do numero %d:\n", n);
}

int main(){
    int num, produto;
    num = 6104;

    aberturafuncao(6104); // ou chamar por aberturafuncao(num)

    for(int i = 1; i <=10; i++){
        produto = num * i;
        printf("%d x %d = %d\n", i, num, produto);
    }

    return 0;
}