# Integração - Sistema de Usuários (CPF, Senha, Cargo)

## Estrutura
- `main.c`: Exemplo de uso do sistema.
- `user.c`/`user.h`: Implementação das funções de usuário (validação de CPF, senha, cargo, criação e deleção).
- `test_user.c`: Testes integrados.

## Metodologia
- TDD aplicado em todas as etapas.
- Metodologia em espiral: cada ciclo incrementa uma funcionalidade (CPF, cargo, senha).

## Etapas
1. Validação de CPF
2. Validação de Cargo
3. Validação de Senha
4. Integração e testes finais

## Como compilar e rodar
```bash
gcc -o main main.c user.c
./main

gcc -o test_user test_user.c user.c
./test_user
```

## Observações
- O código demonstra a evolução e integração dos módulos.
- O README detalha as decisões e etapas do desenvolvimento.
