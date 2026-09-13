#ifndef ANALISADOR_H
#define ANALISADOR_H

#include "tokens.h"

#define MAX_ENTRADA 256

extern int rastreio;
extern char entrada[MAX_ENTRADA];
extern int simbolo;

int analisa(char *linha);

void expr(void);
void termo(void);
void fator(void);
void primario(void);

void proximo_token(void);
void obtenha_simbolo(void);
void erro(const char *msg);
void mostra(char *txt);
char *nome(int t);

#endif