#include <stdio.h>

#ifdef __linux__
#define linux_archi
#endif

int getback_key_metadata(void);
//Map la memoire
void *my_memomap(size_t size);
//memory map is fixed ?

//memory mapp is protected ?
bool my_mmap_fixed(void *ptr, size_t size);
bool my_map_is_protect_by_ro(void *ptr, size_t size);
bool my_map_is_protect_by_rw(void *ptr, size_t size);
bool my_map_is_protect_by_rw_on_metadata(void *ptr, size_t size);


//unmap memory
bool my_unmap_mem(void *ptr, size_t size);

//memory purge
bool my_purge_mem(void *ptr, size_t size);
bool name_my_memory(void *ptr, size_t size, const char* name);


/*LINUX mremap compatbile :D Permet de remapper une interval d'adresse */
#ifdef linux_archi
bool my_memraping();
bool my_memreaping_fixed();
#endif

