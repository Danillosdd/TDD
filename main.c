

/*
 * main.c
 * Exemplo de uso do sistema de usuários.
 * Tenta criar um usuário com dados válidos e exibe o resultado no terminal.
 */


#include <stdio.h>   // Para printf
#include "user.h"   // Para usar Usuario e funções

int main() {
    // Cria um usuário com dados válidos
    Usuario *user = create_user("12345678901", "Senha@123", "professor");
    if (user) { // Se criado com sucesso
        printf("Usuário criado com sucesso!\n"); // Mensagem de sucesso
        printf("CPF: %s\n", user->cpf);         // Mostra o CPF
        printf("Cargo: %s\n", user->cargo);     // Mostra o cargo
        delete_user(user);                       // Libera memória
    } else {
        printf("Falha ao criar usuário. Dados inválidos.\n"); // Mensagem de erro
    }
    return 0; // Fim do programa
}
