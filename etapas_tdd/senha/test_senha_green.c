// Etapa GREEN do TDD para Senha
// Teste: agora a função existe, mas retorna sempre falso
#include <stdio.h>
#include <assert.h>

int validate_password(const char *senha) {
    return 0; // Implementação mínima para passar a compilação
}

int main() {
    printf("[GREEN] Testando senha inválida (deve passar: retorna 0)...\n");
    assert(validate_password("abc") == 0);
    printf("[GREEN] Teste passou!\n");
    return 0;
}
