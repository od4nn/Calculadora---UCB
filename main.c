#include <stdio.h>
#include <math.h>

float getValor(char *Str);

int main() {
    printf("%.3f\n", getValor("2 3 + log 5 /"));
    printf("%.3f\n", getValor("10 log 3 ^ 2 +"));
    printf("%.3f\n", getValor("45 60 + 30 cos *"));
    printf("%.3f\n", getValor("0.5 45 sen 2 ^ +"));
    printf("%.3f\n", getValor("9 raiz"));

    return 0;
}