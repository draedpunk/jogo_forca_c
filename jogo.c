#include <stdio.h>
#include <string.h>

void banner(){
    printf("****************************\n");
    printf("*       JOGO DA FORCA      *\n");
    printf("****************************\n\n");
}

void capturarchute(char chutes[26], int *tentativas){
    printf("\nInforme uma letra: ");
    char chute;
    scanf(" %c", &chute); // Espaço antes do %c para evitar problemas com buffer

    // Armazena o chute no array de chutes
    chutes[(*tentativas)] = chute;
    (*tentativas)++;
}


int main() {
    char palavrasecreta[20] = "CEMITERIO"; // Definição direta sem sprintf

    int acertou = 0;
    int enforcou = 0; // Corrigido para iniciar como falso
    int tamanho = strlen(palavrasecreta);

    char chutes[26]; // Corrigido para armazenar caracteres
    int tentativas = 0;

    // chamada da funçao para o banner
    banner();

    do {
        // Exibir palavra com letras já acertadas
        for (int i = 0; i < tamanho; i++) {
            int achou = 0;
            // printf("Verificando a letra secreta %c na posicao %d...\n", palavrasecreta[i], i);
            for (int j = 0; j < tentativas; j++) {
                // printf("-> Chute %d = %c\n", j, chutes[j]);
                if (chutes[j] == palavrasecreta[i]) {
                    // printf("-----> Chute correto! A palavra secreta possui essa letra!\n\n");
                    achou = 1;
                    break;
                }
            }

            if (achou) {
                printf("%c ", palavrasecreta[i]);
            } else {
                printf("_ ");
            }
        }
        // capturar chute
        capturarchute(chutes, &tentativas);

    } while (!acertou && !enforcou);

    return 0;
}
