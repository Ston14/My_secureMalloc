#ifndef _SECMALLOC_H
#define _SECMALLOC_H
#include <stdlib.h>
//

//utilisable pour calloc
/*
typedef struct chunck{
    size_t size;
    size_t previous_size;
}my_chunck;

typedef struct head_chunk{
    struct head_chunk *last;
    struct  head_chunk *next;
}my_head_chunk;

typedef enum zone {
        TINY,
        SMALL,
        LARGE,
        MAX_ZONE
} my_zone;*/


//cache head cache


void    *my_malloc(size_t size);
void    my_free(void *ptr);
void    *my_calloc(size_t nmemb, size_t size);
void    *my_realloc(void *ptr, size_t size);
#endif
