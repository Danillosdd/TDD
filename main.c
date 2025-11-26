
/*
 * main.c
 * Exemplo de uso do sistema de usuários.
 * Tenta criar um usuário com dados válidos e exibe o resultado no terminal.
 */

#include <stdio.h>
#include "user.h"

int main() {
    Usuario *user = create_user("12345678901", "Senha@123", "professor");
    if (user) {
        printf("Usuário criado com sucesso!\n");
        printf("CPF: %s\n", user->cpf);
        printf("Cargo: %s\n", user->cargo);
        delete_user(user);
    } else {
        printf("Falha ao criar usuário. Dados inválidos.\n");
    }
    return 0;
}
