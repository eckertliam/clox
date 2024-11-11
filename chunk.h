#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "memory.h"
#include "value.h"

/// Represents the different opcodes
typedef enum {
    OP_CONSTANT,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NEGATE,
    OP_RETURN,
} OpCode;

/// Represents a chunk of bytecode
typedef struct {
    // byte code
    uint8_t* code;
    // size of the code array
    int count;
    // capacity of the code array
    int capacity;
    // array of constants
    ValueArray constants;
    // line number for debugging
    int* lines;
} Chunk;

/// Initialize a chunk
void initChunk(Chunk* chunk);

/// Free the memory allocated for the chunk
void freeChunk(Chunk* chunk);

/// Append a byte to the chunk
void writeChunk(Chunk* chunk, uint8_t byte, int line);


/// Add a constant to the chunk and return the index
int addConstant(Chunk* chunk, Value value);

#endif