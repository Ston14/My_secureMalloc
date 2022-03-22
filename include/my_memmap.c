//TBD
#include <sys/mman.h>
//NULL adresse la plus approprié
void *my_memomap(size_t size){
    void *return_pointer = mmap(NULL, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS|MAP_PRIVATE, 0, 0);
    if(return_pointer == MAP_FAILED){
        return NULL;
    }
    return return_pointer;
}

//unmap memory
//segfault si pas bon
int my_unmap_mem(void *ptr,size_t size){
    return unmap(ptr,size);

}

//memory purge
bool my_purge_mem(void *ptr){

}