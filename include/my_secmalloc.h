#ifndef MY_SECMALLOC_H
#define MY_SECMALLOC_H
#include <stdlib.h>
#include "my_memmap.h"
#include "cache.h"
#include <stdio.h>
#include <sys/mman.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

void    *my_malloc(size_t size);
void    my_free(void *ptr);
void    *my_calloc(size_t nmemb, size_t size);
void    *my_realloc(void *ptr, size_t size);

#endif