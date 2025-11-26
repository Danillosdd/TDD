#ifndef USER_H // Evita inclusão múltipla deste header
#define USER_H

#include <stdbool.h> // Para usar o tipo bool

/*
 * user.h
 * Arquivo de cabeçalho do sistema de usuários.
 * Define a estrutura Usuario e declara as funções de validação (CPF, senha, cargo),
 * além das funções de criação e remoção de usuário.
 */

#define CPF_SIZE 12         // Tamanho máximo do CPF (11 dígitos + '\0')
#define PASSWORD_SIZE 100   // Tamanho máximo da senha
#define CARGO_SIZE 20       // Tamanho máximo do cargo

// Estrutura que representa um usuário
typedef struct {
    char cpf[CPF_SIZE];         // Armazena o CPF do usuário
    char senha[PASSWORD_SIZE];  // Armazena a senha do usuário
    char cargo[CARGO_SIZE];     // Armazena o cargo do usuário
} Usuario;

// Função que valida o CPF (retorna true se válido)
bool validate_cpf(const char *cpf);
// Função que valida a senha (retorna true se válida)
bool validate_password(const char *senha);
// Função que valida o cargo (retorna true se válido)
bool validate_cargo(const char *cargo);

// Cria um usuário se todos os dados forem válidos, retorna ponteiro para Usuario ou NULL
Usuario* create_user(const char *cpf, const char *senha, const char *cargo);
// Libera a memória de um usuário criado
void delete_user(Usuario *user);

#endif // USER_H
