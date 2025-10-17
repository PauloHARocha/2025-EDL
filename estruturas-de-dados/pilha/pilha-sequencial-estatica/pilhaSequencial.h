/*
    Pilha sequencial estática

    Definição / Intuição:
    - Pilha é uma estrutura linear de dados em que o último a entrar é o primeiro a sair (LIFO = Last in First Out).
    - Inserções e remoções acontecem sempre na mesma extremidade: o TOPO.
    - Para acessar um elemento específico, seria preciso remover todos acima dele.

    Tipos de implementação:
    - Alocação estática com acesso sequencial (esta biblioteca): usa um array e um contador de elementos.
      Vantagem: simplicidade e facilidade de criar/destruir;
      Desvantagem: é preciso definir previamente um tamanho máximo.
    - Alocação dinâmica com acesso encadeado: elementos podem estar
      em endereços não contíguos e cada nó aponta para o próximo.

    Operações básicas (independem do tipo):
    - criar a pilha;
    - inserir elemento no topo (push);
    - remover elemento do topo (pop);
    - acessar o elemento do topo (peek);
    - destruir a pilha;
    - consultar tamanho, vazio e cheio.

    Tipo opaco:
    - O usuário vê apenas um ponteiro para Pilha (typedef struct pilha Pilha;).
    - A estrutura real (campos) fica oculta no .c, limitando o acesso aos dados
      às funções da biblioteca.

    Dado armazenado:
    - Neste exemplo, cada item da pilha é um 'struct aluno' (matrícula, nome, n1,n2,n3).
*/

#define MAX 100
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

// Tipo opaco: a definição real está no .c
typedef struct pilha Pilha;

// Operações expostas ao usuário da biblioteca
Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int acessa_topo_Pilha(Pilha* pi, struct aluno *al);
int insere_Pilha(Pilha* pi, struct aluno al); // push
int remove_Pilha(Pilha* pi); // pop
int tamanho_Pilha(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int Pilha_cheia(Pilha* pi);