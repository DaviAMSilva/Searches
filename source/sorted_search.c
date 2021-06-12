#include "sorted_search.h"





// verifica cada item individualmente, um por um, entretanto é preciso que o vetor esteja ordenado e a pesquisa é
// finalizada quando achamos um item que é "melhor" que o item que se procura
size_t *sorted_search(void *ptr, size_t num, size_t size, void *data, int (*compare)(const void *, const void *))
{
    size_t *result = calloc(num + 1, sizeof(size_t)); // vetor que guarda os resultados + a quantidade no índice 0
    size_t index = 0;                                 // indíce do vetor de retorno



    // verificação de erro
    if (ptr == NULL || num <= 0 || size <= 0 || data == NULL || compare == NULL || result == NULL)
        return NULL;



    // verificamos se cada item é "melhor" ou igual ao item anterior (ordenado), caso contrário retorna NULL
    for (size_t i = 1; i < num; i++)
    {
        if (compare(ptr + i * size, ptr + (i - 1) * size) < 0)
            return NULL;
    }



    // loop para cada item, quando for igual adicionar no próximo local do vetor e aumentar index
    for (size_t i = 0; i < num; i++)
    {
        // guardando o resultado
        int cmp = compare(ptr + i * size, data);

        if (cmp > 0)
        {
            // o valor procurado é menor que o valor atual, parar a busca
            break;
        }
        else if (cmp == 0)
        {
            result[++index] = i;
        }
    }



    // index agora guarda a quantidade de itens encontrados então colocamos no índice 0 do resultado
    result[0] = index;



    // realoca o vetor evitando erros
    size_t *temp = realloc(result, (index + 1) * sizeof(size_t));

    if (temp != NULL)
    {
        result = temp;
    }
    else
    {
        free(result);
        return NULL;
    }



	// como o vetor está ordenado seria possível retornar apenas a primeira e última posições
	// mas isso não é feito para que o retorno esteja consistente com as outras funções
    return result;
}