#include "binary_search.h"





static long binary_search_recursive(void *ptr, size_t num, size_t size, void *data, int (*compare)(const void *, const void *), long low, long high)
{
    // item não está presente no vetor
    if (high < low)
        return -1;


    // calculamos o número médio entre low e high
    long middle = low + ((high - low) >> 1);



    // guardando o resultado
    int cmp = compare(ptr + middle * size, data);



    if (cmp > 0)
        // o valor procurado é menor que o meio então procura-se na esquerda
        return binary_search_recursive(ptr, num, size, data, compare, low, middle - 1);
    else if (cmp < 0)
        // o valor procurado é maior que o meio então procura-se na direita
        return binary_search_recursive(ptr, num, size, data, compare, middle + 1, high);
    else
        // um elemento igual foi encontrado, retorne-o
        return middle;
}





// está função utiliza a pesquisa binária para encontrar qualquer elemento igual dentro do vetor e depois realiza
// uma busca para a direita e esquerda para encontrar o início e o final dos elementos procurados
size_t *binary_search(void *ptr, size_t num, size_t size, void *data, int (*compare)(const void *, const void *))
{
    // vetor que guarda os resultados + a quantidade no índice 0
    size_t *result = calloc(num + 1, sizeof(size_t));



    // verificação de erro
    if (ptr == NULL || num <= 0 || size <= 0 || data == NULL || compare == NULL || result == NULL)
        return NULL;



    // verificamos se cada item é "melhor" ou igual ao item anterior (ordenado), caso contrário retorna NULL
    for (int i = 1; i < num; i++)
    {
        if (compare(ptr + i * size, ptr + (i - 1) * size) < 0)
            return NULL;
    }



    // esse indíce é apenas um dos itens que precisamos retornar
    long middle = binary_search_recursive(ptr, num, size, data, compare, 0, num - 1),
         low = middle,
         high = middle;



    // nenhum número foi encontrado
    if (middle == -1)
    {
        // realoca o vetor evitando erros
        size_t *temp = realloc(result, sizeof(size_t));

        if (temp != NULL)
        {
            result = temp;
        }
        else
        {
            free(result);
            return NULL;
        }



        // nenhum número foi encontrado
        result[0] = 0;



        return result;
    }



    // acha o menor indíce que contém um número ainda igual ao valor procurado
    while (compare(ptr + low * size, data) == 0)
    {
        low--;
        if (low <= 0)
            break;
    }
    low++;

    // acha o maior indíce que contém um número ainda igual ao valor procurado
    while (compare(ptr + high * size, data) == 0)
    {
        high++;
        if (high >= num)
            break;
    }
    high--;



    // realoca o vetor evitando erros
    size_t *temp = realloc(result, (high - low + 2) * sizeof(size_t));

    if (temp != NULL)
    {
        result = temp;
    }
    else
    {
        free(result);
        return NULL;
    }



    // quantidade de números encontrados
    result[0] = high - low + 1;



    // coloca os índices dos número encontrados no vetor de resultado
    for (size_t i = 0; i < high - low + 1; i++)
        result[i + 1] = low + i;



	// como o vetor está ordenado seria possível retornar apenas a primeira e última posições
	// mas isso não é feito para que o retorno esteja consistente com as outras funções
    return result;
}