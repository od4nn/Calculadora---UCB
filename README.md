# Calculadora de Expressões Pós-Fixas em C

Projeto desenvolvido para a disciplina de **Estrutura de Dados**, com o objetivo de avaliar expressões matemáticas em notação pós-fixa e convertê-las para notação infixa.

O programa utiliza **pilhas** como estrutura principal para processar os operandos, operadores e funções matemáticas.

## Funcionalidades

* Avaliação de expressões em notação pós-fixa
* Conversão de notação pós-fixa para notação infixa
* Suporte aos operadores:

  * Soma: `+`
  * Subtração: `-`
  * Multiplicação: `*`
  * Divisão: `/`
  * Módulo: `%`
  * Potenciação: `^`
* Suporte às funções matemáticas:

  * `raiz`
  * `log`
  * `sen`
  * `cos`
  * `tg`
* Tratamento de expressões inválidas
* Tratamento de divisão por zero
* Tratamento de logaritmo inválido
* Tratamento de raiz de número negativo
* Uso de ângulos em graus para seno, cosseno e tangente

## Estrutura esperada

O arquivo principal enviado deve conter as funções:

```c
float getValor(char *Str);
char *getInFixa(char *Str);
```

Essas funções são chamadas por um arquivo `main.c` externo.

## Exemplo de expressão

Expressão pós-fixa:

```txt
3 4 + 5 *
```

Expressão infixa equivalente:

```txt
(3+4)*5
```

Valor calculado:

```txt
35
```

## Como compilar

Coloque o arquivo da calculadora e o arquivo `main.c` na mesma pasta.

Exemplo de arquivos:

```txt
25101474.c
main.c
```

Compile com GCC:

```bash
gcc 25101474.c main.c -o calculadora.exe -lm
```

Caso esteja no Windows e o `-lm` gere erro, tente:

```bash
gcc 25101474.c main.c -o calculadora.exe
```

## Como executar

No Windows PowerShell:

```bash
.\calculadora.exe
```

No Linux ou macOS:

```bash
./calculadora.exe
```

## Exemplo de `main.c` para teste

```c
#include <stdio.h>

float getValor(char *Str);
char *getInFixa(char *Str);

int main() {
    char expr[] = "3 4 + 5 *";

    printf("Expressao pos-fixa: %s\n", expr);
    printf("Expressao infixa: %s\n", getInFixa(expr));
    printf("Valor: %.2f\n", getValor(expr));

    return 0;
}
```

Saída esperada:

```txt
Expressao pos-fixa: 3 4 + 5 *
Expressao infixa: (3+4)*5
Valor: 35.00
```

## Observações

* A expressão pós-fixa deve ter os tokens separados por espaço.
* A função `getValor` retorna `NAN` em caso de erro.
* A função `getInFixa` retorna `NULL` em caso de erro.
* A conversão para infixa remove espaços e mantém apenas os parênteses necessários para preservar a ordem correta das operações.
