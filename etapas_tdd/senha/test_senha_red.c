// Etapa RED do TDD para Senha
// Teste inicial: deve falhar pois a função ainda não existe
#include <stdio.h>
#include <assert.h>

// Não existe validate_password ainda

int main() {
    printf("[RED] Testando senha inválida (deve falhar)...\n");
    // assert(validate_password("abc") == 0); // Descomente quando implementar
    printf("[RED] Fim do teste (esperado: falha de compilação ou execução)\n");
    return 0;
}
