#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "memory.h"

/// Represents the different opcodes
typedef enum {
    OP_RETURN,
    OP_CONSTANT,
} OpCode;

/// Represents a chunk of bytecode
typedef struct {
    // byte code
    uint8_t* code;
    // size of the code array
    int count;
    // capacity of the code array
    int capacity;
} Chunk;

/// Initialize a chunk
void initChunk(Chunk* chunk);

/// Free the memory allocated for the chunk
void freeChunk(Chunk* chunk);

/// Append a byte to the chunk
void writeChunk(Chunk* chunk, uint8_t byte);



#endif