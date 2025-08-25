#include <stdio.h>

// ENUM:
// Um enum é um conjunto de constantes inteiras nomeadas.
// Serve para dar nomes legíveis a valores numéricos,
// melhorando a clareza do código.
// Por padrão, começa em 0, mas podemos atribuir valores
// iniciais diferentes.
// Exemplo: dias da semana.

enum DiaSemana { SEGUNDA=1, TERCA, QUARTA, QUINTA, SEXTA };

int main() {
    enum DiaSemana hoje = QUARTA;  // hoje recebe valor 3

    printf("Hoje é dia %d da semana\n", hoje);

    return 0;
}