#include <stdio.h>
#include "analisador.h"
#include "testes.h"

int executa_testes(Teste *testes, int total) {
    int ok = 0;
    int i;

    for (i = 0; i < total; i++) {
        int r;
        printf("\n%s -> ", testes[i].nome_teste);
        r = analisa(testes[i].seq);
        printf("%s", r ? "valida" : "invalida");
        if (r == testes[i].esperado) {
            printf(" [ok]\n");
            ok++;
        } else {
            printf(" [falhou]\n");
        }
    }
    return ok;
}