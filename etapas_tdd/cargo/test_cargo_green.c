// Etapa GREEN do TDD para Cargo
// Teste: agora a função existe, mas retorna sempre falso
#include <stdio.h>
#include <assert.h>

int validate_cargo(const char *cargo) {
    return 0; // Implementação mínima para passar a compilação
}

int main() {
    printf("[GREEN] Testando cargo inválido (deve passar: retorna 0)...\n");
    assert(validate_cargo("") == 0);
    printf("[GREEN] Teste passou!\n");
    return 0;
}
