/*
    Implementação da fila sequencial estática

    Estrutura interna (oculta):
    - struct fila contém:
        * int inicio  → posição do primeiro elemento da fila;
        * int final   → posição da última inserção realizada;
        * int qtd     → quantidade de elementos atualmente armazenados;
        * struct aluno dados[MAX] → armazenamento contíguo dos elementos.
    - Esses campos NÃO são visíveis no main(); o usuário só manipula a fila
      por meio das funções declaradas no .h (tipo opaco).
*/

#include <stdio.h>
#include <stdlib.h>
#include "filaEstatica.h" //inclui os protótipos
//Definição do tipo Fila
struct fila{
    int inicio, final, qtd;
    struct aluno dados[MAX];
};

Fila* cria_Fila(){
    Fila* fi;
    fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    free(fi);
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    return fi->qtd;
}

int Fila_cheia(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    if(fi->qtd == MAX){
        return 1;
    }else{
        return 0;
    }
}

int Fila_vazia(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    if(fi->qtd == 0){
        return 1;
    }else{
        return 0;
    }
}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL){
        return 0;
    }
    if(fi->qtd == MAX){
        return 0;
    }
    fi->dados[fi->final] = al;
    fi->final = (fi->final+1) % MAX;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL || fi->qtd == 0){
        return 0;
    }
    fi->inicio = (fi->inicio+1) % MAX;
    fi->qtd--;
    return 1;
}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL || Fila_vazia(fi)){
        return 0;
    }
    *al = fi->dados[fi->inicio];
    return 1;
}