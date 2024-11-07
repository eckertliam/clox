#ifndef CLOX_DEBUG_H
#define CLOX_DEBUG_H

#include "chunk.h"

/// Disassemble the chunk
void disassembleChunk(Chunk* chunk, const char* name);

/// Disassemble a single instruction
int disassembleInstruction(Chunk* chunk, int offset);

#endif //CLOX_DEBUG_H
