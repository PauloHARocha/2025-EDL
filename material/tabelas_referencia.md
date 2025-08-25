# Tabelas de Referência 

Essas tabelas ajudam a lembrar os principais códigos usados nas funções **printf** e **scanf**.

---

### Códigos Especiais (printf)

| Código especiais | Significado                                    |
|------------------|-----------------------------------------------|
| \n               | Nova linha                                    |
| \t               | Tabulação                                     |
| \b               | Retrocesso (usado para impressora)            |
| \f               | Salto de página de formulário                 |
| \a               | Beep – Toque do auto-falante                  |
| \r               | CR – Retorno do cursor para o início da linha |
| \\\               | \\- Barra invertida                            |
| \0               | Zero                                          |
| \\'               | Aspas simples (apóstrofo)                     |
| \\"               | Aspas dupla                                   |
| \xdd             | Representação hexadecimal                     |
| \ddd             | Representação octal                           |


### Códigos de Formatação (printf/scanf)

| Código de Formatação          | Significado                                  |
|-------------------------------|----------------------------------------------|
| %c                            | Caractere simples                            |
| %d                            | Inteiro decimal com sinal                    |
| %i                            | Inteiro decimal com sinal                    |
| %e                            | Notação científica (e minúsculo)             |
| %E                            | Notação científica (E maiúsculo)             |
| %f                            | Ponto flutuante em decimal                   |
| %g                            | Usa %e ou %f, o que for menor                |
| %G                            | Usa %E ou %f, o que for menor                |
| %o                            | Inteiro octal sem sinal                      |
| %s                            | String de caracteres                         |
| %u                            | Inteiro decimal sem sinal                    |
| %x                            | Inteiro hexadecimal sem sinal (letras min.)  |
| %X                            | Inteiro hexadecimal sem sinal (letras maiús.)|
| %p                            | Ponteiro (endereço)                          |
| %n                            | Ponteiro inteiro                             |
| %%                            | Imprime um caractere %                       |