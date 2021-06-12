#ifndef QUICK_SEARCH_NTH_H
#define QUICK_SEARCH_NTH_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

long quick_search_nth(void *ptr, size_t num, size_t size, size_t n, int (*compare)(const void *, const void *));

#endif /* QUICK_SEARCH_NTH_H */