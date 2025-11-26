#ifndef USER_H
#define USER_H

#include <stdbool.h>

#define CPF_SIZE 12
#define PASSWORD_SIZE 100
#define CARGO_SIZE 20

// Estrutura do usuário
typedef struct {
    char cpf[CPF_SIZE];
    char senha[PASSWORD_SIZE];
    char cargo[CARGO_SIZE];
} Usuario;

// Funções de validação
bool validate_cpf(const char *cpf);
bool validate_password(const char *senha);
bool validate_cargo(const char *cargo);

// Funções de usuário
Usuario* create_user(const char *cpf, const char *senha, const char *cargo);
void delete_user(Usuario *user);

#endif // USER_H
