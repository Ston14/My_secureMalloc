#include <stdio.h>

//Map la memoire
void *my_memomap(size_t size);

//unmap memory
//segfault si pas bon
int my_unmap_mem(void *ptr);

//memory purge
bool my_purge_mem(void *ptr);




