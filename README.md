# Searches

**Coleção de algoritmos de pesquisa.**

Algumas observações:
- A função `compare` de comparação deve decidir se dois itens são e iguais e retornar 0 nesse caso e qualquer outro número nos demais casos. No entanto, o ideal é que ela retorne um número positivo (1) caso o primeiro número seja *melhor* do que o segundo e um número negativo (-1) caso contrário. Isso permite verificar se o vetor está ordenado nos casos em que isso é um pré-requisito para a pesquisa.
- O retorno de todas as funções é um ponteiro `size_t` em que o primeiro item indica a quantidade de instâncias em que o valor de busca foi encontrado dentro da busca, seguido dos índices (origem 0) das posições na ordem em que em que o valor procurado for encontrado, na mesma quantidade que o primeiro número. (Ex: `{0}`, `{4, 0, 2, 3, 7}`)
- Em caso de erro ou se o vetor não estiver ordenado quando a ordenação é obrigatória é retornado um ponteiro `NULL`. Além disso como o ponteiro é dinamicamente alocado é preciso desalocar ele manualmente.