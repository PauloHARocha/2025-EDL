#include<stdio.h>
#include<stdlib.h>

typedef struct elemento {
    int dado;
    struct elemento *prox;
} Elem;

typedef struct descritor{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
} Fila;


Fila* cria_Fila(){
    Fila *fi = malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->final = NULL;
        fi->qtd = 0;
    }
    return fi;
}

//enqueue
int insere_Fila(Fila *fi, int x){
    if(fi == NULL)
        return 0;
    Elem *no = malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dado = x;
    no->prox = NULL;
    if(fi->final == NULL) //fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

// dequeue
int remove_Fila(Fila *fi){
    if(fi == NULL || fi->inicio == NULL)
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    free(no);
    if(fi->inicio == NULL) //fila ficou vazia
        fi->final = NULL;
    fi->qtd--;
    return 1;
}

int consulta_Fila(Fila *fi, int *x){
    if(fi == NULL || fi->inicio == NULL)
        return 0;
    *x = fi->inicio->dado;
    return 1;
}

void libera_Fila(Fila *fi){
    if(fi != NULL){
        Elem *no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_Fila(Fila *fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila *fi){
    if(fi == NULL || fi->inicio == NULL)
        return 1;
    return 0;
}

int main(){
    Fila *fi = cria_Fila();
    insere_Fila(fi, 10);
    insere_Fila(fi, 20);
    insere_Fila(fi, 30);

    printf("tamanho = %d\n", tamanho_Fila(fi));  // 3
    int t;
    if(consulta_Fila(fi, &t)) 
        printf("primeiro = %d\n", t); // 10

    remove_Fila(fi);
    consulta_Fila(fi, &t);
    printf("primeiro = %d, tamanho = %d\n", t, tamanho_Fila(fi)); // 20, 2

    printf("vazia? %s\n", Fila_vazia(fi) ? "sim" : "nao");

    libera_Fila(fi);
    return 0;
}