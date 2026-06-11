#include <stdio.h>
#include <math.h>
#include <string.h>

float getValor(char *Str);
char *getInFixa(char *Str);

void testarValor(char *expr, float esperado) {
    float valor = getValor(expr);

    printf("POSFIXA: %-25s | VALOR: %10.4f | ESPERADO: %10.4f | %s\n",
           expr,
           valor,
           esperado,
           fabs(valor - esperado) <= 0.001 ? "OK" : "ERRO");
}

void testarInfixa(char *expr, char *esperado) {
    char *infixa = getInFixa(expr);

    printf("POSFIXA: %-25s | INFIXA: %-30s | ESPERADO: %-30s | %s\n",
           expr,
           infixa != NULL ? infixa : "NULL",
           esperado,
           infixa != NULL && strcmp(infixa, esperado) == 0 ? "OK" : "VERIFICAR");
}

int main() {
    printf("\n==== TESTES DE POTENCIA ====\n");

    testarValor("2 3 ^ 2 ^", 64);
    testarInfixa("2 3 ^ 2 ^", "(2^3)^2");

    testarValor("2 3 2 ^ ^", 512);
    testarInfixa("2 3 2 ^ ^", "2^3^2");
    return 0;
}