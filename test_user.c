#include <stdio.h>
#include <assert.h>
#include "user.h"

void test_validate_cpf() {
    assert(validate_cpf("12345678901") == true);
    assert(validate_cpf("1234567890") == false);
    assert(validate_cpf("abcdefghijk") == false);
}

void test_validate_cargo() {
    assert(validate_cargo("professor") == true);
    assert(validate_cargo("ceo") == true);
    assert(validate_cargo("gerente") == true);
    assert(validate_cargo("aluno") == false);
}

void test_validate_password() {
    assert(validate_password("Senha@123") == true);
    assert(validate_password("senha@123") == false); // falta maiúscula
    assert(validate_password("SENHA@123") == false); // falta minúscula
    assert(validate_password("Senha1234") == false); // falta especial
    assert(validate_password("Senha@abc") == false); // falta dígito
    assert(validate_password("S@1a") == false); // muito curta
}

void test_create_user() {
    Usuario *user = create_user("12345678901", "Senha@123", "professor");
    assert(user != NULL);
    delete_user(user);
    user = create_user("1234567890", "Senha@123", "professor");
    assert(user == NULL);
    user = create_user("12345678901", "senha@123", "professor");
    assert(user == NULL);
    user = create_user("12345678901", "Senha@123", "aluno");
    assert(user == NULL);
}

int main() {
    test_validate_cpf();
    test_validate_cargo();
    test_validate_password();
    test_create_user();
    printf("Todos os testes passaram!\n");
    return 0;
}
