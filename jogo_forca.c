#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "dados/forca_funcoes.h" // Corrigido caminho do arquivo de cabeçalho

char palavrasecreta[20];
char chutes[26]; 
int chutesdados = 0;

void banner(){
    printf("****************************\n");
    printf("*       JOGO DA FORCA      *\n");
    printf("****************************\n\n");
}

void capturarchute(){
    printf("\nInforme uma letra: ");
    char chute;
    scanf(" %c", &chute); 

    chutes[chutesdados] = chute;
    chutesdados++;
}

int jachutou(char letra){
    for (int j = 0; j < chutesdados; j++) {
        if (chutes[j] == letra) {
            return 1;
        }
    }
    return 0;
}

void desenhahangman(){
    int tamanho = strlen(palavrasecreta);

    for (int i = 0; i < tamanho; i++) {
        if (jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void adicionarpalavra(){
    char pergunta;
    printf("Deseja adicionar uma nova palavra ao jogo? (S/N) \n");
    scanf(" %c", &pergunta);

    if(pergunta == 'S' || pergunta == 's'){
        char novapalavra[20];
        printf("Informe a nova palavra a ser adicionada: ");
        scanf("%s", novapalavra); // Corrigido: removido o &

        FILE* f;
        f = fopen("C:\\Users\\Dell\\OneDrive\\Desktop\\Estudos\\jogo-forca-em-c\\dados\\palavras.txt", "r+");
        if (f == NULL){
            printf("Banco de dados nao disponivel.\n\n");
            exit(1);
        }
        
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}

void escolhepalavra(){
    FILE* f;
    f = fopen("C:\\Users\\Dell\\OneDrive\\Desktop\\Estudos\\jogo-forca-em-c\\dados\\palavras.txt", "r");

    if (f == NULL){
        printf("Banco de dados nao disponivel.\n\n");
        exit(1);
    }

    int qtdpalavras;
    fscanf(f, "%d", &qtdpalavras);

    srand(time(0));
    int randomico = rand() % qtdpalavras;

    for (int i = 0; i <= randomico; i++){
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

int acertou(){
    int tamanho = strlen(palavrasecreta);

    for(int i = 0; i < tamanho; i++){
        if (!jachutou(palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
}

int chuteserrados(){
    int tamanho = strlen(palavrasecreta);
    int erros = 0;

    for(int i = 0; i < chutesdados; i++){
        int existe = 0;
        for(int j = 0; j < tamanho; j++){
            if(chutes[i] == palavrasecreta[j]){
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros;
}

void hangman() {
    int erros = chuteserrados();

    printf("    +----+\n");
    printf("    |    |\n");
    printf("    %c   |\n", (erros >= 1 ? 'O' : ' '));  
    printf("   %c%c%c  |\n", (erros >= 3 ? '/' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '\\' : ' '));
    printf("   %c %c  |\n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf("         |\n");
    printf("  =========\n");
    printf("\n\n");
}

int enforcou(){
    return chuteserrados() >= 5;
}

int main() {
    escolhepalavra();
    banner();

    do {
        hangman(); // Atualiza o boneco conforme os erros aumentam
        desenhahangman();
        capturarchute();
    } while (!acertou() && !enforcou());

    if (acertou()){
        printf("\nParabens, voce ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } 
    else {
        printf("\nPuxa, voce foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
    adicionarpalavra();
    return 0;
}