#ifndef TESTES_H
#define TESTES_H

typedef struct {
    char *nome_teste;
    char *entrada;
    int esperado;
} Teste;

int executa_testes(Teste *testes, int total);

#endif