// Etapa REFACTOR do TDD para CPF
// Teste completo e comentado
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

// Função final refatorada
int validate_cpf(const char *cpf) {
    // Verifica se o tamanho é 11
    if (strlen(cpf) != 11) return 0;
    // Verifica se todos os caracteres são dígitos
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) return 0;
    }
    return 1;
}

int main() {
    printf("[REFACTOR] Testando CPF válido...\n");
    assert(validate_cpf("12345678901") == 1); // Válido
    printf("  ✓ CPF válido passou\n");
    assert(validate_cpf("123") == 0); // Inválido
    printf("  ✓ CPF inválido rejeitado\n");
    assert(validate_cpf("abcdefghijk") == 0); // Inválido
    printf("  ✓ CPF não numérico rejeitado\n");
    printf("[REFACTOR] Todos os testes passaram!\n");
    return 0;
}
