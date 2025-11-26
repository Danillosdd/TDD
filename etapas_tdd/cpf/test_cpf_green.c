// Etapa GREEN do TDD para CPF
// Teste: agora a função existe, mas retorna sempre falso
#include <stdio.h>
#include <assert.h>

int validate_cpf(const char *cpf) {
    return 0; // Implementação mínima para passar a compilação
}

int main() {
    printf("[GREEN] Testando CPF inválido (deve passar: retorna 0)...\n");
    assert(validate_cpf("123") == 0);
    printf("[GREEN] Teste passou!\n");
    return 0;
}
