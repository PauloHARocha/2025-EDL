#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct fila{
    int inicio, final, qtd;
    int dados[MAX];
};

typedef struct fila Fila;

Fila* cria_fila(){
    Fila *fi = malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->qtd=0;
        fi->inicio=0;
        fi->final=0;
    }
    return fi;
}

void libera_fila(Fila *fi){
    free(fi);
}

// enqueue
int insere_fila(Fila *fi, int dado){ 
    if(fi == NULL || fi->qtd == MAX)
        return 0;
    fi->dados[fi->final] = dado;
    fi->final = (fi->final + 1) % MAX; 
    fi->qtd++;
    return 1;
}

// dequeue 
int remove_fila(Fila *fi){
    if(fi == NULL || fi->qtd == 0){
        return 0;
    }
    fi->inicio = (fi->inicio + 1) % MAX;
    fi->qtd--;
    return 1;
}

int tamanho_fila(Fila *fi){
    if(fi == NULL)
        return -1;
    return fi->qtd;
}

int fila_vazia(Fila *fi){
    if(fi == NULL)
        return -1;
    return (fi->qtd == 0);
}

int fila_cheia(Fila *fi){
    if(fi == NULL)
        return -1;
    return (fi->qtd == MAX);
}

int consulta_fila(Fila *fi, int *dado){
    if(fi == NULL || fi->qtd == 0)
        return 0;
    *dado = fi->dados[fi->inicio];
    return 1;
}

void remove_pares(Fila *fi) {
    Fila *aux = cria_fila();
    int dado;

    // percorre a fila original
    while (!fila_vazia(fi)) {
        consulta_fila(fi, &dado);
        if (dado % 2 != 0) {
            insere_fila(aux, dado);
        }
        remove_fila(fi);
    }

    // devolve ímpares para fi
    while (!fila_vazia(aux)) {
        consulta_fila(aux, &dado);
        insere_fila(fi, dado);
        remove_fila(aux);
    }

    libera_fila(aux);
}


int main(){

    Fila* fi = cria_fila();

    insere_fila(fi, 4);
    printf("Inseriu na fila: %d\n", 4);
    insere_fila(fi, 7);
    printf("Inseriu na fila: %d\n", 7);
    insere_fila(fi, 10);
    printf("Inseriu na fila: %d\n", 10);
    insere_fila(fi, 5);
    printf("Inseriu na fila: %d\n", 5);
    insere_fila(fi, 6);
    printf("Inseriu na fila: %d\n", 6);

    int primeiro_fila;
    consulta_fila(fi, &primeiro_fila);
    printf("Primeiro da fila: %d\n", primeiro_fila);
    printf("Tamanho fila: %d\n", tamanho_fila(fi));

    remove_pares(fi);

    consulta_fila(fi, &primeiro_fila);
    printf("Primeiro da fila: %d\n", primeiro_fila);
    printf("Tamanho fila: %d\n", tamanho_fila(fi));

    libera_fila(fi);
    return 0;
}
