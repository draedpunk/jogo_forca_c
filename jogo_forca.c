#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "dados\forca_funcoes.h" // header file

char palavrasecreta[20];
char chutes[26]; // Corrigido para armazenar caracteres
int chutesdados = 0;

void banner(){
    printf("****************************\n");
    printf("*       JOGO DA FORCA      *\n");
    printf("****************************\n\n");
}

void capturarchute(){
    printf("\nInforme uma letra: ");
    char chute;
    scanf(" %c", &chute); // Espaço antes do %c para evitar problemas com buffer

    // Armazena o chute no array de chutes
    chutes[chutesdados] = chute;
    chutesdados++;
}

void hangman(){
    printf("    +----+\n");
    printf("    |    |\n");
    printf("    O    |\n");
    printf("   /|\\    |\n");
    printf("   / \\    |\n");
    printf("         |\n");
    printf("  =========\n");
    printf("\n\n");
  
}

int jachutou(char letra){
    int achou = 0; // setted as False :)

    for (int j = 0; j < chutesdados; j++) {
        if (chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhahangman(){
    int tamanho = strlen(palavrasecreta);

    for (int i = 0; i < tamanho; i++) {
        // aqui estava o for para saber se a letra dada pelo usurario
        // estava presente
        int achou = jachutou(palavrasecreta[i]);

        if (achou) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
}

void adicionarpalavra(){
    char pergunta;
    printf("Deseja adicionar uma nova palavra ao jogo? (S/N) \n");
    scanf(" %c", &pergunta);

    if(pergunta == 'S' || pergunta == 's'){
        char novapalavra[20];
        printf("Informe a nova palavra a ser adicionada: ");
        scanf("%s", &novapalavra);

        FILE* f;
        f = fopen("C:\\Users\\Dell\\OneDrive\\Desktop\\Estudos\\jogo-forca-em-c\\dados\\palavras.txt", "r+");
        if (f == 0){
            printf("Banco de dados nao disponivel.\n\n");
            exit(1);
        }
        
        // pega a qtd de palavras q ja tinha no arquivo
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        // posiciona o ponteiro do arquivo para o inicio
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        // posiciona a set ano fim
        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}

void escolhepalavra(){
    FILE* f;
    // abre o arquivo e lê
    // f = fopen("dados\\palavras.txt", "r");
    f = fopen("C:\\Users\\Dell\\OneDrive\\Desktop\\Estudos\\jogo-forca-em-c\\dados\\palavras.txt", "r");

    if (f == 0){
        printf("Banco de dados nao disponivel.\n\n");
        exit(1);
    }

    // descobre a quantidade de palavras no arquivo
    // (ta na primeira linha)
    int qtdpalavras;
    fscanf(f, "%d", &qtdpalavras);

    // calcula o numero randomico
    srand(time(0));
    int randomico = rand() % qtdpalavras;

    // for roda na qtd de palavras q o arquivo tem
    // e escolhe uma
    for (int i = 0; i <= randomico; i++){
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

int acertou(){
    int tamanho = strlen(palavrasecreta);

    for(int i = 0; i < tamanho; i++){
        if (!jachutou((char) palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
}

int enforcou(){
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

int main() {
    escolhepalavra();
    banner();
    hangman();

    do {
        // Exibir palavra com letras já acertadas
        desenhahangman();

        // capturar chute
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
