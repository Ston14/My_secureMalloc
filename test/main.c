#include <stdio.h>
#include "my_secmalloc.h"
#include <criterion/criterion.h>

Test(malloc_is_working,test_if_malloc_is_working){
    cr_assert_neq(my_malloc(sizeof(int)),NULL);
}
Test(free,test_if_free_is_working){
    int* ptr = my_malloc(sizeof(int));
    my_free(ptr);
    cr_assert_eq(checkCache(ptr),NULL);
    
}
Test(calloc_is_working,test_if_calloc_is_working){
    cr_assert_neq(my_calloc(sizeof(int),sizeof(int)),NULL);
}
Test(realloc_is_working,test_if_realloc_is_working){
    cr_assert_neq(my_realloc(my_malloc(sizeof(int)),sizeof(int)*2),NULL);
}
