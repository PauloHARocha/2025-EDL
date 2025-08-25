#include <stdio.h>

int main() {
    FILE *f;

    // abrir arquivo para escrita
    f = fopen("teste.txt", "w");
    if (f == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    // escrever caractere
    fputc('A', f);

    // fechar
    fclose(f);

    // abrir para leitura
    f = fopen("teste.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    // ler caractere
    int c = fgetc(f);
    printf("Caractere lido: %c\n", c);

    // verificar fim de arquivo
    if (feof(f)) {
        printf("Fim do arquivo.\n");
    }

    fclose(f);
    return 0;
}