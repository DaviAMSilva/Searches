#ifndef SORTED_SEARCH_H
#define SORTED_SEARCH_H

#include <stdlib.h>

size_t *sorted_search(void *ptr, size_t num, size_t size, void *data, int (*compare)(const void *, const void *));

#endif /* SORTED_SEARCH_H */