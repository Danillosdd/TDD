// Etapa REFACTOR do TDD para Senha
// Teste completo e comentado
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

// Função final refatorada
int validate_password(const char *senha) {
    int len = strlen(senha); // Tamanho da senha
    if (len < 8) return 0; // Deve ter pelo menos 8 caracteres
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0; // Flags para requisitos
    for (int i = 0; i < len; i++) {
        if (senha[i] >= 'A' && senha[i] <= 'Z') has_upper = 1;      // Tem maiúscula
        else if (senha[i] >= 'a' && senha[i] <= 'z') has_lower = 1; // Tem minúscula
        else if (senha[i] >= '0' && senha[i] <= '9') has_digit = 1; // Tem dígito
        else has_special = 1;                                      // Tem especial
    }
    return has_upper && has_lower && has_digit && has_special;
}

int main() {
    printf("[REFACTOR] Testando senha válida...\n");
    assert(validate_password("Senha@123") == 1); // Válida
    printf("  ✓ Senha válida passou\n");
    assert(validate_password("senha@123") == 0); // Falta maiúscula
    printf("  ✓ Senha sem maiúscula rejeitada\n");
    assert(validate_password("SENHA@123") == 0); // Falta minúscula
    printf("  ✓ Senha sem minúscula rejeitada\n");
    assert(validate_password("Senha1234") == 0); // Falta especial
    printf("  ✓ Senha sem especial rejeitada\n");
    assert(validate_password("Senha@abc") == 0); // Falta dígito
    printf("  ✓ Senha sem dígito rejeitada\n");
    assert(validate_password("S@1a") == 0);      // Muito curta
    printf("  ✓ Senha curta rejeitada\n");
    printf("[REFACTOR] Todos os testes passaram!\n");
    return 0;
}
