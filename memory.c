#include <stdlib.h>

#include "memory.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    // allocate a new block of memory
    void* result = realloc(pointer, newSize);
    // handle the case where the allocation fails
    if (result == NULL) exit(1);
    return result;
}