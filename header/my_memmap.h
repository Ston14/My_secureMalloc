#include <stdio.h>

//Map la memoire
void *my_memomap(size_t size);

//unmap memory
//segfault si pas bon
bool my_unmap_mem(void *ptr, size_t size);

//memory purge
bool my_purge_mem(void *ptr, size_t size);




