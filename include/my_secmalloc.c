
#include "header/my_secmalloc.h"
#include "header/my_memmap.h"
//Contrainte lib statique dynamique & log



void* my_malloc(size_t size){
    //registre des adresses mmap
    return insertCache(my_memomap(size));
}
void my_free(void *ptr){
    remove_cache(ptr);
}
void* my_calloc(size_t nmemb, size_t size){
}
void* my_realloc(void *ptr, size_t size){
}
