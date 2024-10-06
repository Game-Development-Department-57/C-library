#include <stdio.h>
#include <stdlib.h>


FILE* WRAP_ALLOC_FILE_POINTER;

void wrap_alloc_init(const char* file_name)
{
  WRAP_ALLOC_FILE_POINTER = fopen(file_name, "w");
}

void wrap_alloc_fini(void)
{
  fclose(WRAP_ALLOC_FILE_POINTER);
}

void wrap_log_header(void)
{
  fprintf(WRAP_ALLOC_FILE_POINTER, "FUNC    out pointer      in pointer       alloc size       fill num        END\n");
}

void* wrap_malloc(size_t size) {
    void* ptr = malloc(size);
    fprintf(WRAP_ALLOC_FILE_POINTER, "MALLOC  %p %p %016llX %016llX\n", ptr, NULL, size, (size_t)0);
    return ptr;
}

void* wrap_calloc(size_t num, size_t size) {
    void* ptr = calloc(num, size);
    fprintf(WRAP_ALLOC_FILE_POINTER, "CALLOC  %p %p %016llX %016llX\n", ptr, NULL, size, num);
    return ptr;
}

void* wrap_realloc(void* ptr, size_t size) {
    void* new_ptr = realloc(ptr, size);
    fprintf(WRAP_ALLOC_FILE_POINTER, "REALLOC %p %p %016llX %016llX\n", new_ptr, ptr, size, (size_t)0);
    return new_ptr;
}

void wrap_free(void* ptr) {
    free(ptr);
    fprintf(WRAP_ALLOC_FILE_POINTER, "FREE    %p %p %016llX %016llX\n", NULL, ptr, (size_t)0, (size_t)0);
}