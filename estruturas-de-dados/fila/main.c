/*
    Exemplos de uso de Filas (FIFO – First In, First Out)

    1. Atendimento/Impressão
       - Requisições entram no final; a primeira a chegar é a primeira a ser atendida.

    2. Sistemas de simulação
       - Eventos aguardam em fila até que um servidor esteja disponível.

    3. Buffers
       - Produtor/Consumidor: dados entram no final e são lidos pelo início.
*/

#include <stdio.h>
#include "filaEstatica.h"

int main(void){
    Fila *f = cria_Fila();
    if (f == NULL){
        printf("Erro ao criar fila.\n");
        return 1;
    }

    printf("Fila criada.\n");
    printf("Tamanho inicial: %d\n", tamanho_Fila(f));
    printf("Esta vazia? ");
    if (Fila_vazia(f)){
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    /* alunos de exemplo */
    struct aluno a1 = {101, "Ana",   8.0f, 7.5f, 9.0f};
    struct aluno a2 = {202, "Bruno", 6.0f, 8.0f, 7.0f};
    struct aluno a3 = {303, "Clara", 9.0f, 9.5f, 8.5f};

    struct aluno frente;

    // Enfileirar 1 a 1
    printf("\nInserindo Aluno...\n");
    insere_Fila(f, a1);
    printf("Tamanho: %d\n", tamanho_Fila(f));
    if (consulta_Fila(f, &frente)){
        printf("Frente: %d - %s\n", frente.matricula, frente.nome);
    }

    printf("\nInserindo Aluno...\n");
    insere_Fila(f, a2);
    printf("Tamanho: %d\n", tamanho_Fila(f));
    if (consulta_Fila(f, &frente)){
        printf("Frente: %d - %s\n", frente.matricula, frente.nome);
    }

    printf("\nInserindo Aluno...\n");
    insere_Fila(f, a3);
    printf("Tamanho: %d\n", tamanho_Fila(f));
    if (consulta_Fila(f, &frente)){
        printf("Frente: %d - %s\n", frente.matricula, frente.nome);
    }

    printf("\nEsta vazia? ");
    if (Fila_vazia(f)){
        printf("Sim\n");
    } else {
        printf("Nao | Tamanho: %d\n", tamanho_Fila(f));
    }

    // Remover 1 a 1 (sempre remove do INICIO)
    printf("\nRemovendo do inicio...\n");
    if (consulta_Fila(f, &frente)){
        printf("Removendo: %d - %s\n", frente.matricula, frente.nome);
    }
    remove_Fila(f);
    printf("Tamanho: %d\n", tamanho_Fila(f));
    if (consulta_Fila(f, &frente)){
        printf("Novo frente: %d - %s\n", frente.matricula, frente.nome);
    }

    printf("\nRemovendo do inicio...\n");
    if (consulta_Fila(f, &frente)){
        printf("Removendo: %d - %s\n", frente.matricula, frente.nome);
    }
    remove_Fila(f);
    printf("Tamanho: %d\n", tamanho_Fila(f));
    if (consulta_Fila(f, &frente)){
        printf("Novo frente: %d - %s\n", frente.matricula, frente.nome);
    }

    printf("\nRemovendo do inicio...\n");
    if (consulta_Fila(f, &frente)){
        printf("Removendo: %d - %s\n", frente.matricula, frente.nome);
    }
    remove_Fila(f);
    printf("Tamanho: %d\n", tamanho_Fila(f));

    printf("\nEsta vazia? ");
    if (Fila_vazia(f)){
        printf("Sim\n");
    } else {
        printf("Nao | Tamanho: %d\n", tamanho_Fila(f));
    }

    libera_Fila(f);
    printf("\nFila liberada.\n");
    return 0;
}