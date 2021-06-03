#ifndef QUICK_SEARCH_H
#define QUICK_SEARCH_H

#include <stdlib.h>

size_t *quick_search(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif /* QUICK_SEARCH_H */