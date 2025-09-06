/*
    Fila sequencial estática

    Definição / Intuição:
    - Fila é uma estrutura linear de dados em que o primeiro a entrar é o primeiro a sair (FIFO = First In First Out).
    - Inserções acontecem no FINAL da fila e remoções no INÍCIO.
    - Representa bem situações do mundo real como filas de banco, impressoras ou atendimento.

    Tipos de implementação:
    - Alocação estática com acesso sequencial (esta biblioteca): usa um array e variáveis de controle
      (início, final, quantidade).
      Vantagem: simplicidade e rapidez de acesso por índice;
      Desvantagem: precisa definir previamente um tamanho máximo.
    - Alocação dinâmica com acesso encadeado: cada nó aponta para o próximo, sem limite fixo de tamanho.

    Operações básicas (independem do tipo):
    - criar a fila;
    - inserir elemento no final (enqueue);
    - remover elemento do início (dequeue);
    - acessar o primeiro elemento (peek/front);
    - destruir a fila;
    - consultar tamanho, vazio e cheio.

    Tipo opaco:
    - O usuário vê apenas um ponteiro para Fila (typedef struct fila Fila;).
    - A estrutura real (campos) fica oculta no .c, limitando o acesso aos dados
      às funções da biblioteca.

    Dado armazenado:
    - Neste exemplo, cada item da fila é um 'struct aluno' (matrícula, nome, n1,n2,n3).
*/

#define MAX 100
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct aluno *al);
int insere_Fila(Fila* fi, struct aluno al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);