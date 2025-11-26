
#include <stdio.h>   // Para printf
#include <assert.h>  // Para assert
#include "user.h"   // Para funções e struct Usuario

/*
 * test_user.c
 * Arquivo de testes automatizados para o sistema de usuários.
 * Testa as funções de validação de CPF, cargo, senha e a criação de usuário.
 * Exibe logs detalhados no terminal mostrando o resultado de cada teste.
 * gcc -o test_user test_user.c user.c && ./test_user
 */


// Testa a função de validação de CPF
void test_validate_cpf() {
    printf("Testando validate_cpf...\n");
    assert(validate_cpf("12345678901") == true); // CPF válido
    printf("  ✓ CPF válido passou\n");
    assert(validate_cpf("1234567890") == false); // Tamanho inválido
    printf("  ✓ CPF com tamanho inválido falhou\n");
    assert(validate_cpf("abcdefghijk") == false); // Não numérico
    printf("  ✓ CPF com caracteres não numéricos falhou\n");
    printf("validate_cpf OK!\n\n");
}


// Testa a função de validação de cargo
void test_validate_cargo() {
    printf("Testando validate_cargo...\n");
    assert(validate_cargo("professor") == true); // Cargo válido
    printf("  ✓ Cargo professor aceito\n");
    assert(validate_cargo("ceo") == true);      // Cargo válido
    printf("  ✓ Cargo ceo aceito\n");
    assert(validate_cargo("gerente") == true);  // Cargo válido
    printf("  ✓ Cargo gerente aceito\n");
    assert(validate_cargo("aluno") == false);   // Cargo inválido
    printf("  ✓ Cargo aluno rejeitado\n");
    printf("validate_cargo OK!\n\n");
}


// Testa a função de validação de senha
void test_validate_password() {
    printf("Testando validate_password...\n");
    assert(validate_password("Senha@123") == true); // Senha válida
    printf("  ✓ Senha válida passou\n");
    assert(validate_password("senha@123") == false); // Falta maiúscula
    printf("  ✓ Senha sem maiúscula rejeitada\n");
    assert(validate_password("SENHA@123") == false); // Falta minúscula
    printf("  ✓ Senha sem minúscula rejeitada\n");
    assert(validate_password("Senha1234") == false); // Falta especial
    printf("  ✓ Senha sem especial rejeitada\n");
    assert(validate_password("Senha@abc") == false); // Falta dígito
    printf("  ✓ Senha sem dígito rejeitada\n");
    assert(validate_password("S@1a") == false);      // Muito curta
    printf("  ✓ Senha curta rejeitada\n");
    printf("validate_password OK!\n\n");
}


// Testa a função de criação de usuário
void test_create_user() {
    printf("Testando create_user...\n");
    Usuario *user = create_user("12345678901", "Senha@123", "professor"); // Válido
    assert(user != NULL); // Deve criar
    printf("  ✓ Usuário válido criado\n");
    delete_user(user);    // Libera
    user = create_user("1234567890", "Senha@123", "professor"); // CPF inválido
    assert(user == NULL);
    printf("  ✓ Usuário com CPF inválido rejeitado\n");
    user = create_user("12345678901", "senha@123", "professor"); // Senha inválida
    assert(user == NULL);
    printf("  ✓ Usuário com senha inválida rejeitado\n");
    user = create_user("12345678901", "Senha@123", "aluno");     // Cargo inválido
    assert(user == NULL);
    printf("  ✓ Usuário com cargo inválido rejeitado\n");
    printf("create_user OK!\n\n");
}


// Função principal que executa todos os testes
int main() {
    printf("==== INICIANDO TESTES INTEGRADOS DO SISTEMA DE USUÁRIO ====""\n\n");
    test_validate_cpf();
    test_validate_cargo();
    test_validate_password();
    test_create_user();
    printf("==== TODOS OS TESTES PASSARAM! ====\n");
    return 0;
}
