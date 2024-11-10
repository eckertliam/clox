#include <stdlib.h>

#include "chunk.h"

void initChunk(Chunk* chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
    chunk->lines = NULL;
    initValueArray(&chunk->constants);
}

void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}

void writeChunk(Chunk* chunk, uint8_t byte, int line) {
    if (chunk->capacity < chunk->count + 1) {
        // if the capacity of the chunk is grow capacity
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code,
            oldCapacity, chunk->capacity);
        chunk->lines = GROW_ARRAY(int, chunk->lines,
            oldCapacity, chunk->capacity);
    }

    // assign the byte to the end of the chunk
    chunk->code[chunk->count] = byte;
    // assign the line number to the end of the chunk
    chunk->lines[chunk->count] = line;
    // increment the end of the chunk 
    chunk->count += 1;
}

int addConstant(Chunk* chunk, Value value) {
    // write the value to the value array
    writeValueArray(&chunk->constants, value);
    // return the index of the value
    return chunk->constants.count - 1;
}