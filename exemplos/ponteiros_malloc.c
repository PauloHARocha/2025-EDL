/*
 * FUNÇÕES DE ALOCAÇÃO DINÂMICA DE MEMÓRIA EM C
 * ----------------------------------------------
 * malloc  -> aloca um bloco de memória no HEAP e retorna um ponteiro (void*).
 *            Se não houver memória disponível, retorna NULL.
 *
 * sizeof  -> operador que retorna o tamanho (em bytes) de um tipo ou variável.
 *            Usado para calcular quantos bytes precisamos alocar.
 *
 * realloc -> realoca um bloco já alocado com malloc/calloc.
 *            Pode aumentar ou diminuir o tamanho da memória.
 *            Se não conseguir realocar no mesmo lugar, copia os dados
 *            para outro espaço e devolve o novo endereço.
 *
 * free    -> libera a memória alocada dinamicamente, devolvendo ao sistema.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Alocando espaço para 1 inteiro no heap
    int *p = malloc(sizeof(int));

    if (p == NULL) {
        printf("Erro: sem memoria disponivel!\n");
        return 1;
    }

    *p = 42;  // acessa a memória e guarda um valor
    printf("Valor armazenado em *p = %d\n", *p);
    printf("Numero de bytes pra inteiro = %d\n", (int) sizeof(int));

    free(p);  // sempre liberar quando nao precisar mais
    return 0;
}