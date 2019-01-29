# Introdução

Projeto que implementa dois TADS: pilha e fila.

Os TADs são implementados com vetor dinâmico e templates.

# Arquivos

* `stack.h`: classe template que implementa uma pilha.
* `parenteses.cpp`: aplicação teste que utiliza pilha para verificar fechamento de parênteses em expressões.
* `drive_stack.cpp`: arquivo de testes para a pilha.
* `queue.h`: implementação de uma fila com `std::vector`.

# TODO

1. Finalizar os testes unitários da pilha.
2. Ampliar a aplicação `parenteses` para tratar qualquer tipo de fechamento de escopo.
3. Implementar a classe Queue **com** vetor dinâmico (sem usar `std::vector`).


# Histórico

* **11-out**: Início do desenvolvimento da classe pilha, com ênfase no `push()` e método de duplicação da memória.
* **13-out**: Término da classe Stack. Início do desenvolvimento do programa `parenteses.cpp`.
* **18-out**:
    - Implementação da classe Queue utilizando o `std::vector`. O objetivo foi o de desmonstrar que uma fila é, na verdade, um subconjunto (**adapter**) do Vector (vetor dinâmico).


# Documentação

Depois de clonar este projeto, gere a documentação com `doxygen cfgDoxy`. Veja a documentação gerada ao abrir o arquivo [`index.html`](html\index.html).
