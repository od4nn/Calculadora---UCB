#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int verifica_Operador_Basico(char *token) {
    return strcmp(token, "+") == 0 ||
           strcmp(token, "-") == 0 ||
           strcmp(token, "*") == 0 ||
           strcmp(token, "/") == 0;
}

float getValor(char *Str) {
    float pilha[512];
    int topo = -1;

    char copia[512];
    strcpy(copia, Str);

    char *token = strtok(copia, " ");

    while (token != NULL) {
        char *fim;
        float numero = strtof(token, &fim);

        if (*fim == '\0') {
            topo++;
            pilha[topo] = numero;
        }
        else if (verifica_Operador_Basico(token)) {
            if (topo < 1) {
                return NAN;
            }

            float b = pilha[topo--];
            float a = pilha[topo--];
            float resultado = 0;

            if (strcmp(token, "+") == 0) {
                resultado = a + b;
            }
            else if (strcmp(token, "-") == 0) {
                resultado = a - b;
            }
            else if (strcmp(token, "*") == 0) {
                resultado = a * b;
            }
            else if (strcmp(token, "/") == 0) {
                if (b == 0) {
                    return NAN;
                }

                resultado = a / b;
            }

            topo++;
            pilha[topo] = resultado;
        }
        else {
            return NAN;
        }

        token = strtok(NULL, " ");
    }

    if (topo != 0) {
        return NAN;
    }

    return pilha[topo];
}