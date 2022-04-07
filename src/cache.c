#include "my_secmalloc.h"
#define MAXI 100

struct my_cache {
    void* my_address;
    size_t size;
};

struct my_cache cache [MAXI]; //Tableau pour stocker les appels à mysecmalloc
// Ne pas oublier de set a NULL au debut
//faire attention a Buffer overflow to segfault 
// OR ret2libc
//voir msm_output

void memory_leak(void)
{
    FILE* file = fopen("memory_use.txt","w");
    int i = 0;
    for (i = 0; i<MAXI;i++)
    {
        if (cache[i].my_address != NULL)
        {
            fprintf(file,"Address : %p - Size : %ld",cache[i].my_address,cache[i].size);
            my_unmap_mem(cache[i].my_address,cache[i].size);
        }
    }
    fclose(file);
}


int initialize = 0;

void* insertCache(void* ptr,size_t size){
    if(ptr == NULL || size == 0){
        return NULL;
    }

    //initialise tout le cache une seule fois via la variable globale
    if (initialize == 0)
    {
        int i = 0;
        for ( i = 0; i < MAXI; ++i) {
            cache[i].my_address = NULL;
            cache[i].size = 0;
        }
        initialize = 1;
    }
    int i = 0;
    for ( i = 0; i < MAXI; ++i) {
        if (cache[i].my_address == NULL) {
            cache[i].my_address = ptr;
            cache[i].size = size;
            return ptr;
        }
    }

    printf("No more memory space in the cache\n");
    return NULL;

}

size_t checkCache(void *ptr){
    if(ptr == NULL){
        return 0;
    }
    int i = 0;
    for (i = 0; i < MAXI; ++i) {
        if (cache[i].my_address == ptr) {
            return cache[i].size;
        }
    }
    return 0;
}

void deleteFromCache(void* ptr)
{
     int i = 0;
    for (i = 0; i < MAXI; ++i) {
        if (cache[i].my_address == ptr) {
            cache[i].my_address = NULL;
            cache[i].size = 0;
            return;
        }
    }
}
