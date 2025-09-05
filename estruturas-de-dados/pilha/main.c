/*
    Exemplos de uso de Pilhas (LIFO – Last In, First Out)

    1. Undo/Redo (Desfazer/Refazer)
       - Editores de texto e imagem usam pilhas para armazenar ações.
       - Ctrl+Z desempilha a última ação; Ctrl+Y/Redo empilha de volta.

    2. Histórico de Navegador
       - Cada página visitada vai para uma pilha.
       - "Voltar" desempilha a página atual e retorna à anterior.
       - "Avançar" usa outra pilha para refazer os passos.

    3. Chamadas de Funções (Call Stack)
       - O sistema empilha endereços de retorno e variáveis locais.
       - Ao terminar a função, desempilha e volta para o ponto correto.

    4. Expressões e Parênteses
       - Verificação de parênteses balanceados: "(" empilha, ")" desempilha.
       - Avaliação de expressões na forma pós-fixa (ex.: "3 4 + 5 *")
         também usa pilha para guardar operandos e aplicar operações.
*/

#include <stdio.h>
#include "pilhaSequencial.h"

int main(void){
    Pilha *p = cria_Pilha();
    if (p == NULL){
        printf("Erro ao criar pilha.\n");
        return 1;
    }

    printf("Pilha criada.\n");
    printf("Tamanho inicial: %d\n", tamanho_Pilha(p));
    printf("Esta vazia? ");
    if (Pilha_vazia(p)){
        printf("Sim\n"); 
    }        
    else{
        printf("Nao\n");
    } 
        

    /* alunos de exemplo */
    struct aluno a1 = {101, "Ana",   8.0f, 7.5f, 9.0f};
    struct aluno a2 = {202, "Bruno", 6.0f, 8.0f, 7.0f};
    struct aluno a3 = {303, "Clara", 9.0f, 9.5f, 8.5f};

    struct aluno topo;

    // Pilhar 1 a 1
    printf("\nInserindo Aluno...\n");
    insere_Pilha(p, a1);
    printf("Tamanho: %d\n", tamanho_Pilha(p));
    if (acessa_topo_Pilha(p, &topo)){
        printf("Topo: %d - %s\n", topo.matricula, topo.nome);
    }
        

    printf("\nInserindo Aluno...\n");
    insere_Pilha(p, a2);
    printf("Tamanho: %d\n", tamanho_Pilha(p));
    if (acessa_topo_Pilha(p, &topo)){
        printf("Topo: %d - %s\n", topo.matricula, topo.nome);
    }
        
    printf("\nInserindo Aluno...\n");
    insere_Pilha(p, a3);
    printf("Tamanho: %d\n", tamanho_Pilha(p));
    if (acessa_topo_Pilha(p, &topo)){
        printf("Topo: %d - %s\n", topo.matricula, topo.nome);
    }
        

    printf("\nEsta vazia? ");
    if (Pilha_vazia(p)){
        printf("Sim\n"); 
    }        
    else{
        printf("Nao | Tamanho: %d\n", tamanho_Pilha(p));
    }
        
        
    // Remover 1 a 1
    printf("\nRemovendo do topo...\n");
    if (acessa_topo_Pilha(p, &topo)){
        printf("Removendo: %d - %s\n", topo.matricula, topo.nome);
    }
    remove_Pilha(p);
    printf("Tamanho: %d\n", tamanho_Pilha(p));
    if (acessa_topo_Pilha(p, &topo)){
        printf("Novo topo: %d - %s\n", topo.matricula, topo.nome);
    }

    printf("\nRemovendo do topo...\n");
    if (acessa_topo_Pilha(p, &topo)){
        printf("Removendo: %d - %s\n", topo.matricula, topo.nome);
    }
    remove_Pilha(p);
    printf("Tamanho: %d\n", tamanho_Pilha(p));
    if (acessa_topo_Pilha(p, &topo)){
        printf("Novo topo: %d - %s\n", topo.matricula, topo.nome);
    }

    printf("\nRemovendo do topo...\n");
    if (acessa_topo_Pilha(p, &topo)){
        printf("Removendo: %d - %s\n", topo.matricula, topo.nome);
    }
    remove_Pilha(p);
    printf("Tamanho: %d\n", tamanho_Pilha(p));

    printf("\nEsta vazia? ");
    if (Pilha_vazia(p)){
        printf("Sim\n"); 
    }         
    else{
        printf("Nao | Tamanho: %d\n", tamanho_Pilha(p));
    } 

    libera_Pilha(p);
    printf("\nPilha liberada.\n");
    return 0;
}