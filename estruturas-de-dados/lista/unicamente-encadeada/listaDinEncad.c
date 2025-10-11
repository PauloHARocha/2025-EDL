/*
    Implementação da lista simplesmente encadeada (dinâmica)

    Estrutura interna (oculta):
    - struct elemento (nó) contém:
        * struct aluno dados;
        * struct elemento *prox → ponteiro para o próximo nó.
    - O tipo Lista é definido como "struct elemento*".

    Observações:
    - Inserção no início: O(1)
    - Inserção no final ou ordenada: O(n) (precisa percorrer)
    - Busca: O(n)
    - Tamanho: O(n) (precisa percorrer para contar)
    - Não existe "cheia" (limitada apenas pela memória disponível).
*/

#include <stdio.h>
#include <stdlib.h>
#include "listaDinEncad.h" // inclui os prototipos
// Definicao do tipo lista

// Definição do nó (oculto ao usuário)
struct elemento {
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

// Cria uma nova lista (ponteiro para cabeça), inicialmente vazia
Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

// Libera todos os nós da lista e depois o ponteiro principal
void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

// Retorna a quantidade de nós (O(n))
int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

// Lista dinâmica nunca "enche"
int lista_cheia(Lista* li){
     return 0;
}

// Retorna 1 se a lista estiver vazia, 0 caso contrário
int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

// Insere um novo nó no início da lista
int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

// Insere um novo nó no final da lista
int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){ //lista vazia: insere inicio
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

// Insere ordenado pela matrícula
int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){ //lista vazia: insere inicio
        no->prox = NULL;
        *li = no;
        return 1;
    }else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){ //insere inicio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

// Remove o primeiro nó da lista
int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL) //lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

// Remove o último nó da lista
int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL) //lista vazia
        return 0;

    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li)) //remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

// Remove nó pela matrícula
int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL) //lista vazia
        return 0;
    Elem *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//nao encontrado
        return 0;
    if(no == *li)//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

// Busca elemento pela posição (1..n)
int busca_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

// Busca elemento pela matrícula
int busca_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}