// Etapa RED do TDD para Cargo
// Teste inicial: deve falhar pois a função ainda não existe
#include <stdio.h>
#include <assert.h>

// Não existe validate_cargo ainda

int main() {
    printf("[RED] Testando cargo inválido (deve falhar)...\n");
    // assert(validate_cargo("") == 0); // Descomente quando implementar
    printf("[RED] Fim do teste (esperado: falha de compilação ou execução)\n");
    return 0;
}
