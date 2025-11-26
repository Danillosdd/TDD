
#include "user.h"      // Header com definições e struct Usuario
#include <stdio.h>      // Para funções de entrada/saída (não usado aqui, mas útil para debug)
#include <stdlib.h>     // Para malloc e free
#include <string.h>     // Para manipulação de strings
#include <ctype.h>      // Para funções de verificação de caracteres

/*
 * user.c
 * Implementação das funções do sistema de usuários.
 * Inclui validação de CPF (11 dígitos numéricos),
 * validação de cargo (professor, ceo, gerente),
 * validação de senha (mínimo 8 caracteres, maiúscula, minúscula, dígito, especial),
 * criação e remoção de usuário.
 */


// Valida se o CPF tem 11 dígitos numéricos
bool validate_cpf(const char *cpf) {
    if (strlen(cpf) != 11) return false; // Verifica se o tamanho é 11
    for (int i = 0; i < 11; i++) {       // Para cada caractere
        if (!isdigit(cpf[i])) return false; // Se não for dígito, retorna falso
    }
    // Aqui poderia entrar a validação real do CPF
    return true; // Se passou por tudo, é válido
}


// Valida o campo cargo: obrigatório, tamanho máximo e caracteres válidos
bool validate_cargo(const char *cargo) {
    if (cargo == NULL) return false; // Campo obrigatório
    int len = strlen(cargo);
    if (len == 0 || len >= CARGO_SIZE) return false; // Não pode ser vazio nem ultrapassar o limite
    for (int i = 0; i < len; i++) {
        if (!(cargo[i] == ' ' || (cargo[i] >= 'A' && cargo[i] <= 'Z') || (cargo[i] >= 'a' && cargo[i] <= 'z') || (cargo[i] == '-'))) {
            return false; // Só aceita letras, espaço e hífen
        }
    }
    return true;
}


// Valida se a senha atende todos os requisitos
bool validate_password(const char *senha) {
    int len = strlen(senha); // Tamanho da senha
    if (len < 8) return false; // Deve ter pelo menos 8 caracteres
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0; // Flags para requisitos
    for (int i = 0; i < len; i++) {
        if (isupper(senha[i])) has_upper = 1;      // Tem maiúscula
        else if (islower(senha[i])) has_lower = 1; // Tem minúscula
        else if (isdigit(senha[i])) has_digit = 1; // Tem dígito
        else has_special = 1;                      // Tem especial
    }
    // Só retorna true se todos os requisitos forem atendidos
    return has_upper && has_lower && has_digit && has_special;
}


// Cria um usuário se todos os dados forem válidos
Usuario* create_user(const char *cpf, const char *senha, const char *cargo) {
    // Se qualquer dado for inválido, retorna NULL
    if (!validate_cpf(cpf) || !validate_password(senha) || !validate_cargo(cargo)) {
        return NULL;
    }
    // Aloca memória para o usuário
    Usuario *user = (Usuario*)malloc(sizeof(Usuario));
    if (!user) return NULL; // Falha na alocação
    // Copia os dados para a struct
    strncpy(user->cpf, cpf, CPF_SIZE);
    strncpy(user->senha, senha, PASSWORD_SIZE);
    strncpy(user->cargo, cargo, CARGO_SIZE);
    return user; // Retorna ponteiro para o usuário criado
}


// Libera a memória de um usuário criado
void delete_user(Usuario *user) {
    if (user) free(user); // Só libera se não for NULL
}
