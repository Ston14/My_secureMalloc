#ifndef MY_CACHE_H
#define MY_CACHE_H
#include "my_secmalloc.h"
void* insertCache(void* ptr, size_t size);
size_t checkCache(void* ptr);
void deleteFromCache(void* ptr);
void memory_leak(void);

#endif