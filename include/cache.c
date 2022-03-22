//
// Created by alexi on 22/03/2022.
//

#include "../header/cache.h"
//variable global pour le registre des pointeurs
void** secmalloc_cache =NULL;

//insertion dans le registre
void* insertCache(void* ptr){
    if(ptr == NULL){
        return NULL;
    }
    //Pourquoi 3etoiles 1 etoiles pour le types 1 parce que c'est un tableau et 1 pour pour agrandir la liste
    void*** cache = &secmalloc_cache;
    //on se balade dans le tableau de pointeur pour verifier que nous n'avons pas l'adresse
    while(*cache!=NULL){
        for (int i = 1; i < 4096 ; ++i) {
            //(*cache) pour acceder simplement au tableau car ***
            if((*cache)[i] == NULL){
                (*cache)[i] = ptr;
                return ptr;
            }
        }
        //& pour le debut des adresses
        /* on recupere une adresse dans celui ci on recupere le pointeur des pointeurs de mmap
         * */
        cache = &(*cache)[0];
    }
    //equivalent de secmalloc_cache = my_memomap(); liaison de la page a un nouvelle page
    *cache = my_memommap();
    /*Initialisation du cache : Parcourir le tableau et mettre a null
     * set Ptr a 1
     * return mon pointeur*/
    for(int t = 0; t<4096;t++){
        (*cache)[t] = NULL;
    }
    //set mon ptre
    (*cache)[1] = ptr;
    return ptr;
}

void setCache(void* cache){

}
void removeCache(void *ptr){

}