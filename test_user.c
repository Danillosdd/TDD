
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
    assert(validate_cargo("") == false); // Vazio
    printf("  ✓ Cargo vazio rejeitado\n");
    assert(validate_cargo(NULL) == false); // Nulo
    printf("  ✓ Cargo nulo rejeitado\n");
    char grande[25] = "xxxxxxxxxxxxxxxxxxxxxxxxx"; // 25 caracteres
    assert(validate_cargo(grande) == false); // Muito grande
    printf("  ✓ Cargo muito grande rejeitado\n");
    assert(validate_cargo("Gerente123") == false); // Números não aceitos
    printf("  ✓ Cargo com número rejeitado\n");
    assert(validate_cargo("Gerente!") == false); // Caracteres especiais não aceitos
    printf("  ✓ Cargo com especial rejeitado\n");
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
    Usuario *user = create_user("12345678901", "Senha@123", "professor");
    assert(user != NULL);
    printf("  ✓ Usuário com cargo 'professor' criado\n");
    delete_user(user);
    user = create_user("12345678901", "Senha@123", "Supervisor de Area");
    assert(user != NULL);
    printf("  ✓ Usuário com cargo 'Supervisor de Area' criado\n");
    delete_user(user);
    user = create_user("12345678901", "Senha@123", "Gerente-Adjunto");
    assert(user != NULL);
    printf("  ✓ Usuário com cargo 'Gerente-Adjunto' criado\n");
    delete_user(user);
    user = create_user("1234567890", "Senha@123", "professor"); // CPF inválido
    assert(user == NULL);
    printf("  ✓ Usuário com CPF inválido rejeitado\n");
    user = create_user("12345678901", "senha@123", "professor"); // Senha inválida
    assert(user == NULL);
    printf("  ✓ Usuário com senha inválida rejeitado\n");
    user = create_user("12345678901", "Senha@123", "aluno"); // Cargo válido (qualquer texto permitido)
    assert(user != NULL);
    printf("  ✓ Usuário com cargo 'aluno' criado\n");
    delete_user(user);
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
