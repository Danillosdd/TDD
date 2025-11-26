// Etapa REFACTOR do TDD para Cargo
// Função final, comentada linha a linha
#include <string.h>

// Valida o campo cargo: obrigatório, tamanho máximo e caracteres válidos
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
