#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

static int verifica_Operador(char *token) {
    return strcmp(token, "+") == 0 ||
           strcmp(token, "-") == 0 ||
           strcmp(token, "*") == 0 ||
           strcmp(token, "/") == 0 ||
           strcmp(token, "%") == 0 ||
           strcmp(token, "^") == 0;
}

static int verifica_Funcao(char *token) {
    return strcmp(token, "log") == 0 ||
           strcmp(token, "raiz") == 0 ||
           strcmp(token, "sen") == 0 ||
           strcmp(token, "cos") == 0 ||
           strcmp(token, "tg") == 0;
}

static float grausParaRadianos(float graus) { //usar esse pq o math nao aceita graus literalmente
    return graus * PI / 180.0;
}

float getValor(char *Str) {
    float pilha[512];
    int topo = -1;

    char copia[512];

    /*evita overflow limitando o tamanho a ate 511*/
    strncpy(copia, Str, 511);
    copia[511] = '\0';

    char *token = strtok(copia, " ");

    while (token != NULL) {
        char *fim;
        float numero = strtof(token, &fim);

        if (*fim == '\0') {
            topo++;
            pilha[topo] = numero;
        }
        else if (verifica_Operador(token)) { //precisa de dois operandos
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
            else if (strcmp(token, "%") == 0) {
                if (b == 0) {
                    return NAN;
                }

                resultado = fmod(a, b);
            }
            else if (strcmp(token, "^") == 0) {
                resultado = pow(a, b);
            }

            topo++;
            pilha[topo] = resultado;
        }

        else if (verifica_Funcao(token)) { //precisa de um operando
            if (topo < 0) {
                return NAN;
            }

            float a = pilha[topo--];
            float resultado = 0;

            if (strcmp(token, "log") == 0) {
                if (a <= 0) {
                    return NAN;
                }

                resultado = log10(a);
            }
            else if (strcmp(token, "raiz") == 0) {
                if (a < 0) {
                    return NAN;
                }

                resultado = sqrt(a);
            }
            else if (strcmp(token, "sen") == 0) {
                resultado = sin(grausParaRadianos(a));
            }
            else if (strcmp(token, "cos") == 0) {
                resultado = cos(grausParaRadianos(a));
            }
            else if (strcmp(token, "tg") == 0) {
                resultado = tan(grausParaRadianos(a));
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

char *getInFixa(char *Str) {
    static char resultadoFinal[512];

    char pilha[512][512];
    int topo = -1;

    char copia[512];
    strncpy(copia, Str, 511);
    copia[511] = '\0';

    char *token = strtok(copia, " ");

    while (token != NULL) {
        char *fim;
        strtof(token, &fim);

        if (*fim == '\0') {
            topo++;
            strcpy(pilha[topo], token);
        }
        else if (verifica_Operador(token)) {
            if (topo < 1) {
                return NULL;
            }

            char b[512];
            char a[512];
            char resultado[512];

            strcpy(b, pilha[topo--]);
            strcpy(a, pilha[topo--]);

            snprintf(resultado, sizeof(resultado), "(%s%s%s)", a, token, b);

            topo++;
            strcpy(pilha[topo], resultado);
        }
        else if (verifica_Funcao(token)) {
            if (topo < 0) {
                return NULL;
            }

            char a[512];
            char resultado[512];

            strcpy(a, pilha[topo--]);

            snprintf(resultado, sizeof(resultado), "%s(%s)", token, a);

            topo++;
            strcpy(pilha[topo], resultado);
        }
        else {
            return NULL;
        }

        token = strtok(NULL, " ");
    }

    if (topo != 0) {
        return NULL;
    }

    strcpy(resultadoFinal, pilha[topo]);
    return resultadoFinal;
}