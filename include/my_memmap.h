#ifndef MY_MEMMAP_H
#define MY_MEMMAP_H
#include "my_secmalloc.h"

//Map la memoire
void *my_memomap(size_t size);

//unmap memory
//segfault si pas bon
int my_unmap_mem(void *ptr,size_t size);
#endif




