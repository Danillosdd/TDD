#include <stdio.h>
#include <assert.h>
#include "user.h"

void test_validate_cpf() {
    printf("Testando validate_cpf...\n");
    assert(validate_cpf("12345678901") == true);
    printf("  ✓ CPF válido passou\n");
    assert(validate_cpf("1234567890") == false);
    printf("  ✓ CPF com tamanho inválido falhou\n");
    assert(validate_cpf("abcdefghijk") == false);
    printf("  ✓ CPF com caracteres não numéricos falhou\n");
    printf("validate_cpf OK!\n\n");
}

void test_validate_cargo() {
    printf("Testando validate_cargo...\n");
    assert(validate_cargo("professor") == true);
    printf("  ✓ Cargo professor aceito\n");
    assert(validate_cargo("ceo") == true);
    printf("  ✓ Cargo ceo aceito\n");
    assert(validate_cargo("gerente") == true);
    printf("  ✓ Cargo gerente aceito\n");
    assert(validate_cargo("aluno") == false);
    printf("  ✓ Cargo aluno rejeitado\n");
    printf("validate_cargo OK!\n\n");
}

void test_validate_password() {
    printf("Testando validate_password...\n");
    assert(validate_password("Senha@123") == true);
    printf("  ✓ Senha válida passou\n");
    assert(validate_password("senha@123") == false); // falta maiúscula
    printf("  ✓ Senha sem maiúscula rejeitada\n");
    assert(validate_password("SENHA@123") == false); // falta minúscula
    printf("  ✓ Senha sem minúscula rejeitada\n");
    assert(validate_password("Senha1234") == false); // falta especial
    printf("  ✓ Senha sem especial rejeitada\n");
    assert(validate_password("Senha@abc") == false); // falta dígito
    printf("  ✓ Senha sem dígito rejeitada\n");
    assert(validate_password("S@1a") == false); // muito curta
    printf("  ✓ Senha curta rejeitada\n");
    printf("validate_password OK!\n\n");
}

void test_create_user() {
    printf("Testando create_user...\n");
    Usuario *user = create_user("12345678901", "Senha@123", "professor");
    assert(user != NULL);
    printf("  ✓ Usuário válido criado\n");
    delete_user(user);
    user = create_user("1234567890", "Senha@123", "professor");
    assert(user == NULL);
    printf("  ✓ Usuário com CPF inválido rejeitado\n");
    user = create_user("12345678901", "senha@123", "professor");
    assert(user == NULL);
    printf("  ✓ Usuário com senha inválida rejeitado\n");
    user = create_user("12345678901", "Senha@123", "aluno");
    assert(user == NULL);
    printf("  ✓ Usuário com cargo inválido rejeitado\n");
    printf("create_user OK!\n\n");
}

int main() {
    printf("==== INICIANDO TESTES INTEGRADOS DO SISTEMA DE USUÁRIO ====""\n\n");
    test_validate_cpf();
    test_validate_cargo();
    test_validate_password();
    test_create_user();
    printf("==== TODOS OS TESTES PASSARAM! ====\n");
    return 0;
}
