/*
    Exemplos de uso de Lista Dinâmica (simplesmente encadeada)

    1. Cadastro de alunos
       - Podemos inserir alunos no início, no fim ou de forma ordenada.

    2. Busca
       - Recuperar aluno pela matrícula ou pela posição na lista.

    3. Remoção
       - Retirar do início, do fim ou por matrícula.

    Diferença para vetor/fila:
    - Não há limite fixo de tamanho.
    - Inserções e remoções não exigem deslocar elementos: apenas ajuste de ponteiros.
*/

#include <stdio.h>
#include "listaDinEncad.h"

int main(void){
    Lista *li = cria_lista();
    if (li == NULL){
        printf("Erro ao criar lista.\n");
        return 1;
    }

    printf("Lista criada.\n");
    printf("Tamanho inicial: %d\n", tamanho_lista(li));
    printf("Esta vazia? ");
    if (lista_vazia(li)){
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    /* alunos de exemplo */
    struct aluno a1 = {101, "Ana",   8.0f, 7.5f, 9.0f};
    struct aluno a2 = {202, "Bruno", 6.0f, 8.0f, 7.0f};
    struct aluno a3 = {303, "Clara", 9.0f, 9.5f, 8.5f};

    struct aluno achado;

    // Inserir no início
    printf("\nInserindo no inicio...\n");
    insere_lista_inicio(li, a1);
    printf("Tamanho: %d\n", tamanho_lista(li));

    // Inserir no final
    printf("\nInserindo no final...\n");
    insere_lista_final(li, a2);
    printf("Tamanho: %d\n", tamanho_lista(li));

    // Inserir ordenado (vai para depois de Ana e Bruno)
    printf("\nInserindo ordenado...\n");
    insere_lista_ordenada(li, a3);
    printf("Tamanho: %d\n", tamanho_lista(li));

    // Buscar por posição
    printf("\nBuscando posicao 2...\n");
    if (busca_lista_pos(li, 2, &achado)){
        printf("Achado: %d - %s\n", achado.matricula, achado.nome);
    }

    // Buscar por matrícula
    printf("\nBuscando matricula 303...\n");
    if (busca_lista_mat(li, 303, &achado)){
        printf("Achado: %d - %s\n", achado.matricula, achado.nome);
    }

    // Remover do início
    printf("\nRemovendo do inicio...\n");
    remove_lista_inicio(li);
    printf("Tamanho: %d\n", tamanho_lista(li));

    // Remover do final
    printf("\nRemovendo do final...\n");
    remove_lista_final(li);
    printf("Tamanho: %d\n", tamanho_lista(li));

    // Remover por matrícula
    printf("\nRemovendo matricula 303...\n");
    remove_lista(li, 303);
    printf("Tamanho: %d\n", tamanho_lista(li));

    printf("\nEsta vazia? ");
    if (lista_vazia(li)){
        printf("Sim\n");
    } else {
        printf("Nao | Tamanho: %d\n", tamanho_lista(li));
    }

    // Remover por matrícula
    printf("\nRemovendo matricula 202...\n");
    remove_lista(li, 202);
    printf("Tamanho: %d\n", tamanho_lista(li));

    libera_lista(li);
    printf("\nLista liberada.\n");
    return 0;
}