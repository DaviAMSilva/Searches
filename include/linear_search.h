#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <stdlib.h>

size_t *linear_search(void *ptr, size_t num, size_t size, void *data, int (*compare)(const void *, const void *));

#endif /* LINEAR_SEARCH_H */