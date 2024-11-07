#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

/// Scales capacity by a factor of 2 based on current capacity
/// if capacity is zero jump to 8
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

/// Gets the size of the array's element type and casts the void pointer to the type
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
        sizeof(type) * (newCount))

/// Free memory for a pointer
#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

/// Reallocate memory for a pointer
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif