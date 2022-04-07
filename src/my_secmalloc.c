#include "my_secmalloc.h"
int memory_leak_canarii = 0;



void* my_malloc(size_t size){
if(memory_leak_canarii == 0)
{
    atexit(memory_leak);
    memory_leak_canarii = 1;
}

    //registre des adresses mmap
    if(size == 0 ){
        return NULL;
    }else{
        void* pointeur = my_memomap(size);
        pointeur= insertCache(pointeur,size);
        if(pointeur !=NULL)
        {
            FILE* file = fopen("memory_use.txt","a+");
            fprintf(file,"Malloc - address : %p, size : %ld",pointeur,size);
            fclose(file);
        }
        return pointeur;
    }
}

void my_free(void *ptr){
    if(memory_leak_canarii == 0){
        atexit(memory_leak);
        memory_leak_canarii = 1;
    }
    //creation d'un check pour eviter les erreur de free. unmap segfault si ptr==NULL
    size_t length_ptr = checkCache(ptr);
    if(length_ptr!=0){
        //enlever du registre ***
        //memset(ptr,0,//a checker dans le cache)
        size_t size_of_ptr= checkCache(ptr);
        memset(ptr,0,size_of_ptr);//protection contre les use after free
        my_unmap_mem(ptr,length_ptr);
        FILE* file = fopen("memory_use.txt","a+");
        fprintf(file,"Free - address : %p",ptr);
        fclose(file);
        deleteFromCache(ptr);
    }
    else{
        printf("This pointer doesn't exist\n");
    }
}

void* my_calloc(size_t nmemb, size_t size){
    if(memory_leak_canarii == 0)
{
    atexit(memory_leak);
    memory_leak_canarii = 1;
}
    /*nmemb * size
     * Set tout a 0 */

    void* pointeur = memset(my_malloc(nmemb*size),0,nmemb*size);
    if(pointeur !=NULL)
        {
            FILE* file = fopen("memory_use.txt","a+");
            fprintf(file,"Calloc - address : %p, size : %ld",pointeur,nmemb*size);
            fclose(file);
        }
    return pointeur;
}

void* my_realloc(void *ptr, size_t size){
    if(memory_leak_canarii == 0)
{
    atexit(memory_leak);
    memory_leak_canarii = 1;
}
    if(ptr==NULL){
        return NULL;
    }

    if(size == 0){
        my_free(ptr);
        FILE* file = fopen("memory_use.txt","a+");
        fprintf(file,"Realloc - address : %p, size : 0 => return NULL",ptr);
        fclose(file);
        return NULL;
    }

    size_t length = checkCache(ptr);
    if (length==0)
    {
        printf("This pointer doesn't exist\n");
        return ptr;
    }

    void *new_ptr = my_malloc(size);
    memcpy(new_ptr,ptr,length);
    my_free(ptr);
    FILE* file = fopen("memory_use.txt","a+");
    fprintf(file,"Realloc - old_address : %p, new_adress : %p, new_size : %ld",ptr, new_ptr,size);
    fclose(file);
    return new_ptr;  
}
