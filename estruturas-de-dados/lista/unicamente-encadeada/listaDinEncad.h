/*
    Lista simplesmente encadeada (implementação dinâmica)

    Definição / Intuição:
    - Estrutura linear de nós, onde cada nó aponta para o próximo.
    - Não possui limite fixo de tamanho; cresce conforme malloc/free.
    - Inserções e remoções são feitas ajustando ponteiros.

    Tipo opaco:
    - O usuário vê apenas "Lista" (typedef struct elemento* Lista).
    - A estrutura real do nó (struct elemento) é definida no .c e fica oculta.

    Operações básicas:
    - criar / liberar a lista;
    - inserir (início, final, ordenada);
    - remover (início, final, por matrícula);
    - buscar (por posição, por matrícula);
    - utilitárias: tamanho, vazia, cheia.
*/

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);

int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);

int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);

int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);

int busca_lista_mat(Lista* li, int mat, struct aluno *al);
int busca_lista_pos(Lista* li, int pos, struct aluno *al);