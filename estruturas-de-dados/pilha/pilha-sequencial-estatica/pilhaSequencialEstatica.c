#include<stdio.h>
#include<stdlib.h>


#define MAX 10

struct pilha{
    int qtd;
    int dados[MAX];
};

typedef struct pilha Pilha;

Pilha* cria_pilha(){
    Pilha *pi = malloc(sizeof(struct pilha));
    if(pi != NULL)
        pi->qtd = 0;
    return pi;
}

int insere_pilha(Pilha *pi, int dado){ // push
    if(pi == NULL || pi->qtd == MAX)
        return 0;
    pi->dados[pi->qtd] = dado;
    pi->qtd++;
    return 1;
}


int remove_pilha(Pilha *pi){
    if(pi == NULL || pi->qtd == 0)
        return 0;
    pi->qtd--;
    return 1;    
}

int tamanho_pilha(Pilha *pi){
    if(pi == NULL)
        return -1;
    return pi->qtd;
}

int pilha_cheia(Pilha *pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == MAX);
}

int pilha_vazia(Pilha *pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == 0);
}

int topo_pilha(Pilha *pi, int *topo){
    if(pi == NULL || pi->qtd == 0)
        return 0;
    *topo = pi->dados[pi->qtd-1];
    return 1;
}

void libera_pilha(Pilha *pi){
    free(pi);
}

void copia_pilha(Pilha *pi_1, Pilha *pi_2){
    Pilha *pi_aux = cria_pilha();
    int topo;
    while(topo_pilha(pi_1, &topo)){
        insere_pilha(pi_aux, topo);
        remove_pilha(pi_1);
    }

    while(topo_pilha(pi_aux, &topo)){
        insere_pilha(pi_2, topo);
        insere_pilha(pi_1, topo);
        remove_pilha(pi_aux);
    }

    libera_pilha(pi_aux);
}

int pilhas_iguais(Pilha *pi_1, Pilha *pi_2){
    int topo_1, topo_2;

    while(!pilha_vazia(pi_1) && !pilha_vazia(pi_2)){
        topo_pilha(pi_1, &topo_1);
        topo_pilha(pi_2, &topo_2);
        remove_pilha(pi_1);
        remove_pilha(pi_2);
        if (topo_1 != topo_2)
            return 0;
    }

    return (pilha_vazia(pi_1) && pilha_vazia(pi_2));
}

int main(){

    Pilha *pi_1 = cria_pilha();

    insere_pilha(pi_1, 10);
    insere_pilha(pi_1, 5);
    insere_pilha(pi_1, 17);
    insere_pilha(pi_1, 13);

    Pilha *pi_2 = cria_pilha();

    copia_pilha(pi_1, pi_2);

    if(pilhas_iguais(pi_1, pi_2))
        printf("Pilhas iguais\n");
    else
        printf("Pilhas diferentes\n");

    libera_pilha(pi_1);
    libera_pilha(pi_2);

    return 0;
}
