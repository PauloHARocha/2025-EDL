#include <stdio.h>
#include <string.h>   // Biblioteca para manipulação de strings

int main() {
    char s1[50] = "Hello";
    char s2[50] = "World";
    char copia[50];

    // strlen -> retorna o tamanho da string (sem contar o '\0')
    printf("strlen(s1) = %d\n", (int) strlen(s1));

    // strcpy -> copia s1 em copia
    strcpy(copia, s1);
    printf("strcpy(copia, s1) -> copia = %s\n", copia);

    // strcat -> concatena s2 no final de s1
    strcat(s1, s2);
    printf("strcat(s1, s2) -> s1 = %s\n", s1);

    // strcmp -> compara duas strings (0 se forem iguais)
    if (strcmp(s1, copia) == 0) {
        printf("s1 e copia sao iguais\n");
    } else {
        printf("s1 e copia sao diferentes\n");
    }

    // strncpy -> copia no maximo n caracteres
    strncpy(copia, s2, 3);
    copia[3] = '\0';   // garantir que tenha terminador
    printf("strncpy(copia, s2, 3) -> copia = %s\n", copia);

    // strchr -> retorna ponteiro para a primeira ocorrência do caractere
    char *ptr = strchr(s2, 'o');
    if (ptr != NULL) {
        printf("strchr(s2, 'o') -> encontrou em: %s\n", ptr);
    }

    // strstr -> retorna ponteiro para a primeira ocorrência da substring
    ptr = strstr(s1, "World");
    if (ptr != NULL) {
        printf("strstr(s1, \"World\") -> encontrou em: %s\n", ptr);
    }

    return 0;
}