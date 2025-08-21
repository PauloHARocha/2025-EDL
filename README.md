# Atividade 1 – Estrutura de Dados Lineares

**Aluno:** `<SEU NOME COMPLETO AQUI>`
 
O objetivo é:
1. Revisar como funcionam o Git, o GitHub.  
2. Praticar conceitos básicos de programação em C.

---

## Parte 1 – Hello World com seu nome

1. Clone este repositório no seu computador.
2. Crie um programa em C chamado `hello_world.c`.
3. O programa deve imprimir exatamente a frase (substitua `<SEU NOME>` pelo seu nome):

```
Hello, my name is <SEU NOME>
```

4. Compile e execute para testar:

```
gcc hello_world.c -o hello_world
./hello_world
```

5. Atualize este arquivo (`README.md` / atividade) substituindo o placeholder do nome no topo.
6. Faça commit (pode ser 1 ou mais) contendo apenas:
   - `hello_world.c`
   - atualização deste README com seu nome

---

## Parte 2 – Calculadora de IMC

1. Crie um novo arquivo chamado `imc.c`.
2. O programa deve:
   - Solicitar ao usuário o **peso (kg)**.
   - Solicitar a **altura (m)**.
   - Calcular o IMC usando a fórmula:
     
     ```
     IMC = peso / (altura * altura)
     ```

3. Mostrar o IMC com **duas casas decimais**.

Exemplo de execução:

```
Digite seu peso (kg): 70
Digite sua altura (m): 1.75
Seu IMC é: 22.86
```

4. Compile e execute para validar:

```
gcc imc.c -o imc
./imc
```

5. Faça commit do `imc.c`.

---

## Parte 3 – Calculadora de IMC usando ponteiros

Refazer a calculadora de IMC, mas desta vez utilizando ponteiros.

1.	Crie um novo arquivo chamado imc_ponteiros.c.
2.	O programa deve:
  •	Declarar variáveis para peso e altura.
  •	Utilizar ponteiros para armazenar e manipular os valores lidos.
  •	Calcular o IMC.
3.	Mostrar o IMC com duas casas decimais.
4.	Compile e execute para validar


## Entregáveis

- `hello_world.c` com seu nome no output.
- `imc.c` com o cálculo do IMC formatado com duas casas decimais.
- `imc_ponteiros.c` com o cálculo do IMC usando ponteiros formatado com duas casas decimais.
- Este `README.md` atualizado com seu nome.

---
