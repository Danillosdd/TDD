#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*
 * user.c
 * Implementação das funções do sistema de usuários.
 * Inclui validação de CPF (11 dígitos numéricos),
 * validação de cargo (professor, ceo, gerente),
 * validação de senha (mínimo 8 caracteres, maiúscula, minúscula, dígito, especial),
 * criação e remoção de usuário.
 */

#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Lista de cargos válidos
const char* cargos_validos[] = {"professor", "ceo", "gerente", NULL};

bool validate_cpf(const char *cpf) {
    // Implementação simplificada: verifica se tem 11 dígitos
    if (strlen(cpf) != 11) return false;
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) return false;
    }
    // Aqui poderia entrar a validação real do CPF
    return true;
}

bool validate_cargo(const char *cargo) {
    for (int i = 0; cargos_validos[i] != NULL; i++) {
        if (strcmp(cargo, cargos_validos[i]) == 0) return true;
    }
    return false;
}

bool validate_password(const char *senha) {
    int len = strlen(senha);
    if (len < 8) return false;
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    for (int i = 0; i < len; i++) {
        if (isupper(senha[i])) has_upper = 1;
        else if (islower(senha[i])) has_lower = 1;
        else if (isdigit(senha[i])) has_digit = 1;
        else has_special = 1;
    }
    return has_upper && has_lower && has_digit && has_special;
}

Usuario* create_user(const char *cpf, const char *senha, const char *cargo) {
    if (!validate_cpf(cpf) || !validate_password(senha) || !validate_cargo(cargo)) {
        return NULL;
    }
    Usuario *user = (Usuario*)malloc(sizeof(Usuario));
    if (!user) return NULL;
    strncpy(user->cpf, cpf, CPF_SIZE);
    strncpy(user->senha, senha, PASSWORD_SIZE);
    strncpy(user->cargo, cargo, CARGO_SIZE);
    return user;
}

void delete_user(Usuario *user) {
    if (user) free(user);
}
