// Etapa REFACTOR do TDD para Cargo
// Teste completo e comentado
#include <stdio.h>
#include <assert.h>
#include <string.h>

// Função final refatorada
int validate_cargo(const char *cargo) {
    if (cargo == NULL) return 0; // Campo obrigatório
    int len = strlen(cargo);
    if (len == 0 || len >= 24) return 0; // Não pode ser vazio nem ultrapassar o limite
    for (int i = 0; i < len; i++) {
        if (!(cargo[i] == ' ' || (cargo[i] >= 'A' && cargo[i] <= 'Z') || (cargo[i] >= 'a' && cargo[i] <= 'z') || (cargo[i] == '-')))
            return 0; // Só aceita letras, espaço e hífen
    }
    return 1;
}

int main() {
    printf("[REFACTOR] Testando cargos válidos...\n");
    assert(validate_cargo("professor") == 1);
    printf("  ✓ Cargo 'professor' aceito\n");
    assert(validate_cargo("CEO") == 1);
    printf("  ✓ Cargo 'CEO' aceito\n");
    assert(validate_cargo("Gerente de Projetos") == 1);
    printf("  ✓ Cargo com espaço aceito\n");
    assert(validate_cargo("Gerente-Adjunto") == 1);
    printf("  ✓ Cargo com hífen aceito\n");
    assert(validate_cargo("") == 0);
    printf("  ✓ Cargo vazio rejeitado\n");
    assert(validate_cargo(NULL) == 0);
    printf("  ✓ Cargo nulo rejeitado\n");
    char grande[25] = "xxxxxxxxxxxxxxxxxxxxxxxxx";
    assert(validate_cargo(grande) == 0);
    printf("  ✓ Cargo muito grande rejeitado\n");
    assert(validate_cargo("Gerente123") == 0);
    printf("  ✓ Cargo com número rejeitado\n");
    assert(validate_cargo("Gerente!") == 0);
    printf("  ✓ Cargo com especial rejeitado\n");
    printf("[REFACTOR] Todos os testes passaram!\n");
    return 0;
}
