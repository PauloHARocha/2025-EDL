#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct pilha Pilha;

struct pilha{
    int qtd;
    char dados[MAX];
};

Pilha* cria_Pilha(){
    Pilha *pi = (Pilha*) malloc(sizeof(struct pilha));
    if (pi != NULL) pi->qtd = 0;
    return pi;
}

void libera_Pilha(Pilha* pi){
    free(pi);
}

int tamanho_Pilha(Pilha* pi){
    if (pi == NULL) return -1;
    return pi->qtd;
}

int Pilha_cheia(Pilha* pi){
    if (pi == NULL) return -1;
    return (pi->qtd == MAX);
}

int Pilha_vazia(Pilha* pi){
    if (pi == NULL) return -1;
    return (pi->qtd == 0);
}

int insere_Pilha(Pilha* pi, char c){
    if (pi == NULL) return 0;
    if (pi->qtd == MAX) return 0; /* cheia */
    pi->dados[pi->qtd] = c;
    pi->qtd++;
    return 1;
}

int remove_Pilha(Pilha* pi){
    if (pi == NULL || pi->qtd == 0) return 0;
    pi->qtd--;
    return 1;
}

int acessa_topo_Pilha(Pilha* pi, char *c){
    if (pi == NULL || pi->qtd == 0) return 0;
    *c = pi->dados[pi->qtd - 1];
    return 1;
}

int palindromo(char s[]){
    Pilha *p = cria_Pilha();

    // Empilhar todos os caracteres até encontrar '\0'
    int n = 0;
    while (s[n] != '\0'){
        insere_Pilha(p, s[n]);
        n++;
    }

    // Comparar desempilhando
    for (int i = 0; i < n; i++){
        char topo;
        acessa_topo_Pilha(p, &topo);
        remove_Pilha(p);
        if (s[i] != topo){
            libera_Pilha(p);
            return 0; // não é palíndromo
        }
    }

    libera_Pilha(p);
    return 1; // é palíndromo
}


int main(){
    char palavra[MAX];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    if (palindromo(palavra))
        printf("\"%s\" é palindromo.\n", palavra);
    else
        printf("\"%s\" NAO é palindromo.\n", palavra);

    // Pilha *p = cria_Pilha();
    // insere_Pilha(p, 'A');
    // insere_Pilha(p, 'B');
    // insere_Pilha(p, 'C');
    // printf("Tamanho da pilha: %d\n", tamanho_Pilha(p));

    // char topo;
    // acessa_topo_Pilha(p, &topo);
    // printf("Topo da pilha: %c\n", topo);

    // remove_Pilha(p);
    // acessa_topo_Pilha(p, &topo);
    // printf("Topo após remover: %c\n", topo);

    // printf("Pilha tamanho %d\n", tamanho_Pilha(p));
    // printf("Pilha vazia? %d\n", Pilha_vazia(p));
    // printf("Pilha cheia? %d\n", Pilha_cheia(p));
    // libera_Pilha(p);

    return 0;
}