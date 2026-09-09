#ifndef TESTES_H
#define TESTES_H

#define MAX_TOKENS_TESTE 16

typedef struct {
    char *nome_teste;
    int seq[MAX_TOKENS_TESTE];
    int esperado;
} Teste;

int executa_testes(Teste *testes, int total);

#endif