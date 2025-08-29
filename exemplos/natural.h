#define NATURAL_H

// Definição opaca do tipo Natural (usuário não sabe o que tem dentro)
typedef struct natural Natural;

// Cria um novo número natural
Natural* natural_criar(int valor);

// Retorna o valor inteiro armazenado
int natural_acessa(const Natural* n);

// Incrementa o número natural em 1
void natural_incrementar(Natural* n);

// Libera a memória
void natural_destruir(Natural* n);

// Atribui um valor natural
void natural_atribui(Natural* n, int valor);
