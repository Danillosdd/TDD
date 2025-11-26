// Etapa REFACTOR do TDD para Senha
// Função final, comentada linha a linha
#include <string.h>
#include <ctype.h>

// Valida se a senha atende todos os requisitos
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
