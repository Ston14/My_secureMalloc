//
// Created by alexi on 22/03/2022.
//

#include "../header/cache.h"
//variable global pour le registre des pointeurs
void** secmalloc_cache =NULL;

//insertion dans le registre
void* insertCache(void* ptr,size_t size){
    if(ptr == NULL | size == 0){
        return NULL;
    }
    //Pourquoi 3 etoiles : 1 etoiles pour le types 1 parce que c'est un tableau et 1 pour pour agrandir la liste
    void*** cache = &secmalloc_cache;
    //on se balade dans le tableau de pointeur pour verifier que nous n'avons pas l'adresse
    while(*cache!=NULL){
        for (int i = 1; i < 4096 ; i+=2) {
            //(*cache) pour acceder simplement au tableau car ***
            if((*cache)[i] == NULL){
                (*cache)[i] = ptr;
                (*cache)[i+1] = (void***)size;
                return ptr;
            }
        }
        //& pour le debut des adresses
        /* on recupere une adresse dans celui ci on recupere le pointeur des pointeurs de mmap
         * */
        cache = (void***)&(*cache)[0];
    }
    //equivalent de secmalloc_cache = my_memomap(); liaison de la page a un nouvelle page
    *cache = my_memommap(size);
    /*Initialisation du cache : Parcourir le tableau et mettre a null
     * set Ptr a 1
     * return mon pointeur*/
    for(int t = 0; t<4096;t++){
        (*cache)[t] = NULL;
    }
    //set mon ptr
    (*cache)[1] = ptr;
    return ptr;
}
//
size_t checkCache(void *ptr){
    //renvoi null si mon ptr n'est pas initialisé
    if(ptr == NULL){
        return NULL;
    }
    //recuperer ma variable globale
    void** cache = &secmalloc_cache;
    //tant que mon cache n'est pas egale a la valeur de mon ptr
    while (*cache != ptr){
        for(int i = 1; i<4096;i+=2){
            if(cache[i] == ptr){
                cache[i] = NULL;
                return (size_t )cache[i+1];
            }
        }
        cache = (void**)cache[0];
    }
    return 0;
}