#include <stdio.h>
#include <math.h>

void potencia(double e, double b){
    double resultado = pow(b, e);
    printf("%.2lf^%.2lf = %.2lf\n", b, e, resultado);
}

int main(){
    double base, exp;

    printf("Digite a base e o expoente: ");
    scanf("%lf %lf", &base, &exp);

    potencia(exp, base);

    return 0;
}