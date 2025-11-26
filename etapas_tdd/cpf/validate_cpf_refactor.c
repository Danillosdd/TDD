// Etapa REFACTOR do TDD para CPF
// Função final, comentada linha a linha
#include <string.h>
#include <ctype.h>

// Valida se o CPF tem 11 dígitos numéricos
int validate_cpf(const char *cpf) {
    // Verifica se o tamanho é 11
    if (strlen(cpf) != 11) return 0;
    // Verifica se todos os caracteres são dígitos
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) return 0;
    }
    return 1;
}
