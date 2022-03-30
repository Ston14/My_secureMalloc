
#include "header/my_secmalloc.h"
#include "header/my_memmap.h"
//Contrainte lib statique dynamique & log

void* my_malloc(size_t size){
    //registre des adresses mmap
    if(size == 0 ){
        return NULL;
    }else{
        void* pointeur = my_memomap(size+1);
        pointeur[size + 1] = 0xC5;
        return insertCache(pointeur,size);
    }
}
void my_free(void *ptr){
    //creation d'un check pour eviter les erreur de free. unmap segfault si ptr==NULL
    size_t length_ptr = check_cache(ptr)
    if(length!=0){
        //enlever du registre ***
        my_unmap_mem(ptr,length_ptr);
    }else{
        return NULL;
    }
}
void* my_calloc(size_t nmemb, size_t size){
    /*nmemb * size
     * Set tout a 0 */
    return memset(my_malloc(nmemb*size),0,nmemb*size);
}
void* my_realloc(void *ptr, size_t size){
    if(ptr==NULL){
        return my_malloc(size);
    }
    if(taille == 0){
        my_free(ptr);
        return NULL;
    }

    size_t length = checkCache(ptr);
    if(length >= size){
        return ptr;
    }else{
        void *new_ptr = my_malloc(size);
        memcpy(new_ptr,ptr,length);
        my_free(ptr);
        return new_ptr;
    }
}
