#include "linear_search.h"





// verifica cada item individualmente, um por um
size_t *linear_search(void *ptr, size_t num, size_t size, void *data, int (*compare)(const void *, const void *))
{
    size_t *result = calloc(num + 1, sizeof(size_t)); // vetor que guarda os resultados + a quantidade no índice 0
    size_t index = 0;                                 // indíce do vetor de retorno



    // verificação de erro
    if (ptr == NULL || num <= 0 || size <= 0 || data == NULL || compare == NULL || result == NULL)
        return NULL;



    // loop para cada item, quando for igual adicionar no próximo local do vetor e aumentar index
    for (size_t i = 0; i < num; i++)
    {
        if (compare(ptr + i * size, data) == 0)
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



    return result;
}