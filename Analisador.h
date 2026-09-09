#ifndef ANALISADOR_H
#define ANALISADOR_H

#include "tokens.h"

extern int rastreio;

int analisa(int *entrada);

void expr(void);
void termo(void);
void fator(void);
void primario(void);

void obtenha_simbolo(void);
void erro(const char *msg);
void mostra(char *txt);
char *nome(int t);

#endif