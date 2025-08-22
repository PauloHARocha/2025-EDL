#include <stdio.h>

/*
 * PONTEIROS EM C
 * ------------------
 * - Um ponteiro é uma variável que armazena um ENDEREÇO de memória.
 * - Usamos o operador & ("endereço de") para obter o endereço de uma variável.
 * - Usamos o operador * ("conteúdo de") para acessar ou modificar o valor
 *   guardado nesse endereço.
 * - Com ponteiros, conseguimos manipular dados indiretamente.
 */

int main(void) {
    int x = 42;        // variável comum, armazenada na memória (stack)
    int *p = &x;       // ponteiro p recebe o endereço de x

    // Mostrando os valores:
    printf("x  = %d   (valor armazenado em x)\n", x);
    printf("&x = %p   (endereco de memoria de x)\n", (void*)&x);
    printf("p  = %p   (conteudo de p = endereco de x)\n", (void*)p);
    printf("*p = %d   (valor no endereco para onde p aponta)\n", *p);

    // Alterando x através do ponteiro:
    *p = 99;           // muda o valor de x indiretamente
    printf("Agora x = %d (alterado via ponteiro *p)\n", x);

    // (1) Um ponteiro pode apontar para OUTRA variável:
    int y = -7;
    p = &y;   // agora p não aponta mais para x, e sim para y
    printf("Agora p aponta para y: *p = %d\n", *p);

    // (2) Ponteiro nulo (NULL): usado quando não há destino válido
    //     Obs: em alocação dinâmica (malloc), NULL também pode aparecer
    //     quando o sistema não consegue reservar mais memória.
    int *q = NULL;   // ponteiro "sem apontar para nada"
    if (q == NULL) {
        printf("q nao aponta para lugar nenhum (NULL)\n");
    }

    return 0;
}