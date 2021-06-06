#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stdlib.h>

size_t *binary_search(void *ptr, size_t num, size_t size, void *data, int (*compare)(const void *, const void *));

#endif /* BINARY_SEARCH_H */