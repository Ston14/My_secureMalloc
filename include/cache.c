#include "../header/cache.h"

typedef struct my_metadata {
    void* ptr = NULL;
    size_t length_data = 0;
    char canarii = 0xC5;
    struct my_metadata *next;
};

void* insertCache(void* ptr,size_t size){
    struct set_malloc_metadata = my_metadata;
    if(ptr == NULL || size == 0){
        return NULL;
    }
    while (set_malloc_metadata->next != NULL) {
        set_malloc_metadata = set_malloc_metadata->next;
    }
    set_malloc_metadata->ptr = ptr;
    set_malloc_metadata->length_data = size;
    return ptr;
}

size_t checkCache(void *ptr){
    size_t not_found = 0;
    if(ptr == NULL){
        return NULL;
    }
    struct check_malloc_metadata = my_me;
    while (check_malloc_metadata->next != NULL){
        if (check_malloc_metadata->ptr == ptr) {
            return check_malloc_metadata->length_data;
        }
    }
    return not_found;
}