#ifndef WRAP_ALLOC_H
#define WRAP_ALLOC_H

#include <stddef.h>

#ifndef WRAP_ALLOC_LOG_OUT_FILE
#define WRAP_ALLOC_LOG_OUT_FILE "wrapAllocLogOutFile.txt"
#endif

void wrap_alloc_init(const char* file_name);
void wrap_alloc_fini(void);
void wrap_log_header(void);
void* wrap_malloc(size_t size);
void* wrap_calloc(size_t num, size_t size);
void* wrap_realloc(void* ptr, size_t size);
void wrap_free(void* ptr);

#define malloc(size)       wrap_malloc(size)
#define calloc(num, size)  wrap_calloc(num, size)
#define realloc(ptr, size) wrap_realloc(ptr, size)
#define free(ptr)          wrap_free(ptr)

#endif