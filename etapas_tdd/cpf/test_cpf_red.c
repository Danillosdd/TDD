// Etapa RED do TDD para CPF
// Teste inicial: deve falhar pois a função ainda não existe
#include <stdio.h>
#include <assert.h>

// Não existe validate_cpf ainda

int main() {
    printf("[RED] Testando CPF inválido (deve falhar)...\n");
    // assert(validate_cpf("123") == 0); // Descomente quando implementar
    printf("[RED] Fim do teste (esperado: falha de compilação ou execução)\n");
    return 0;
}
