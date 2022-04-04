#include "../header/cache.h"
#include "../header/memmap.h"

struct my_cache {
    void* my_address;
    size_t size;
};
struct my_cache* cache = NULL;
int taille_index = 32;

void* insertCache(void* ptr,size_t size){
    if(ptr == NULL || size == 0){
        return NULL;
    }
    for (int i = 0; i < taille_index; ++i) {
        if (my_cache[i].my_address == NULL) {
            my_cache[i].address = ptr;
            my_cache[i].size = size;
            return ptr;
        }
    }
    //remapp tableau si il n'y a plus de place
    my_cache = mremap(ptr, sizeof(struct my_cache) * taille_index, sizeof(struct my_cache)taille_index * 2, MREMAP_MAYMOVE);
    for (int i = taille_index + 1; i < taille_index * 2; i++) {
        my_cache[i].address = NULL;
        my_cache[i].size = -1;
    }
    my_cache[taille_index].my_address = ptr;
    my_cache[taille_index].size = size;
    taille_index = taille_index * 2;

}

size_t checkCache(void *ptr){
    if(ptr == NULL){
        return NULL;
    }
    for (int i = 0; i < taille_index; ++i) {
        if (my_cache[i].address == ptr) {
            my_cache[i].address = NULL;
            my_cache[i].size = -1;
            return 0;
        }
    }
    return -1;
}