#include <stdio.h>
#include <math.h>

float getValor(char *Str);

int main() {
    printf("%.2f\n", getValor("3 4 +"));
    printf("%.2f\n", getValor("3 4 + 5 *"));
    printf("%.2f\n", getValor("7 2 * 4 +"));
    printf("%.2f\n", getValor("6 2 / 3 + 4 *"));

    return 0;
}