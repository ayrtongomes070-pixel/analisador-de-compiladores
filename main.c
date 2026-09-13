#include <stdio.h>
#include <string.h>
#include "analisador.h"
#include "testes.h"

int main(void) {
    Teste testes[] = {
        {"1. IDENT",                  "a",              1},
        {"2. IDENT + NUMERO",         "a + 1",          1},
        {"3. IDENT * NUMERO",         "a * 1",          1},
        {"4. IDENT ** NUMERO",        "a ** 1",         1},
        {"5. ( IDENT + NUMERO )",     "(a + 1)",        1},
        {"6. IDENT + NUMERO * IDENT", "a + 1 * b",      1},
        {"7. IDENT +",                "a +",            0},
        {"8. ( IDENT + NUMERO",       "(a + 1",         0},
        {"9. IDENT * + NUMERO",       "a * + 1",        0},
        {"10. + IDENT",               "+ a",            0},
        {"11. varX + 45",             "varX + 45",      1},
        {"12. A * (B + 2)",           "A * (B + 2)",    1},
        {"13. soma +",                "soma + ",        0},
        {"14. var1 $ 3",              "var1 $ 3",       0},
    };
    int total = sizeof(testes) / sizeof(testes[0]);
    int ok;
    char linha[MAX_ENTRADA];

    printf("== TESTES ==\n");
    rastreio = 0;
    ok = executa_testes(testes, total);
    printf("\n%d de %d passaram\n", ok, total);

    printf("\n== RASTREIO: a + 1 ==\n");
    rastreio = 1;
    analisa("a + 1");

    printf("\n== RASTREIO: (a + 1) ==\n");
    analisa("(a + 1)");

    rastreio = 0;
    printf("\nDigite uma expressao para analisar: ");
    if (fgets(linha, sizeof(linha), stdin) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
        printf("%s -> %s\n", linha, analisa(linha) ? "valida" : "invalida");
    }

    return 0;
}