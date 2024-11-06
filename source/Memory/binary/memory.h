#ifndef BINARY_MEMORY_H
#define BINARY_MEMORY_H

#define BinaryDump(memory, length, line_length) memoryHexDump((void*)memory, length)

void memoryOctDump(void* memory, int length);
void memoryHexDump(void* memory, int length);

#endif