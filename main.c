#include <stdio.h>
#include "analisador.h"
#include "testes.h"

int main(void) {
    Teste testes[] = {
        {"1. IDENT",                  {IDENT, FIM}, 1},
        {"2. IDENT + NUMERO",         {IDENT, MAIS, NUMERO, FIM}, 1},
        {"3. IDENT * NUMERO",         {IDENT, MULT, NUMERO, FIM}, 1},
        {"4. IDENT ** NUMERO",        {IDENT, POTENCIA, NUMERO, FIM}, 1},
        {"5. ( IDENT + NUMERO )",     {ABRE_PAR, IDENT, MAIS, NUMERO, FECHA_PAR, FIM}, 1},
        {"6. IDENT + NUMERO * IDENT", {IDENT, MAIS, NUMERO, MULT, IDENT, FIM}, 1},
        {"7. IDENT +",                {IDENT, MAIS, FIM}, 0},
        {"8. ( IDENT + NUMERO",       {ABRE_PAR, IDENT, MAIS, NUMERO, FIM}, 0},
        {"9. IDENT * + NUMERO",       {IDENT, MULT, MAIS, NUMERO, FIM}, 0},
        {"10. + IDENT",               {MAIS, IDENT, FIM}, 0},
    };
    int total = sizeof(testes) / sizeof(testes[0]);
    int ok;

    printf("== TESTES ==\n");
    rastreio = 0;
    ok = executa_testes(testes, total);
    printf("\n%d de %d passaram\n", ok, total);

    printf("\n== RASTREIO: IDENT + NUMERO ==\n");
    rastreio = 1;
    {
        int t1[] = {IDENT, MAIS, NUMERO, FIM};
        analisa(t1);
    }

    printf("\n== RASTREIO: ( IDENT + NUMERO ) ==\n");
    {
        int t2[] = {ABRE_PAR, IDENT, MAIS, NUMERO, FECHA_PAR, FIM};
        analisa(t2);
    }

    return 0;
}