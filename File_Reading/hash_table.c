#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hash_table.h"


struct _node{
    key k;
    value v;
    struct _node* next;
};


struct _hashmap{
    struct _node** array;
    int m;
    int size;
    hash_function h;
};


//hash function
unsigned int hash_fun(key k){
    unsigned int hash = 5381;
    int i = 0;
    while (k[i] != '\0'){
        int c = (unsigned char) k[i];
        hash = hash * 33 + c;
        i++;
    }
    return hash;
}

hashmap hashmap_create(int m){
    hashmap map = (hashmap)malloc(sizeof(struct _hashmap));
    if (!map){
        printf("Error allocating memory.\n");
        exit(0);
    }

    if (m < 1){
        printf("Invalid inputs.\n");
        exit(0);
    }

    map->m = m;
    map->size = 0;
    map->h = hash_fun;
    map->array = (struct _node**)malloc(sizeof(struct _node*) * m);
    if (!map->array){
        printf("Error allocating memory. \n");
        exit(0);
    }

    //Memory initialization
    for (int j =0; j < m; j++){
        map->array[j] = NULL;
    }

    return map; 
}


void hashmap_destroy(hashmap map)
{
    assert(map);
    hashmap_clear(map);
    free(map->array);
    free(map);
}

int hashmap_contains(hashmap map, key k){
    assert(map && k);
    int pos = map->h(k) % map->m;
    struct _node* cur = map->array[pos];
    while (cur != NULL){
        if (strcmp(k, cur->k) == 0){
            return 1;
        }
        cur = cur->next;
    } 
    return 0;
}

value hashmap_get(hashmap map, key k){
    assert(map && k);
    int pos = map->h(k) % map->m;
    struct _node* cur = map->array[pos];
    if (cur == NULL){
        printf("Key not in map.\n");
        exit(0);
    }
    return cur->v;
}


void hashmap_put(hashmap map, key k, value v){
    assert(map && k);
    int pos = map->h(k) % map->m;
    struct _node* cur = map->array[pos];
    struct _node* prev = NULL;
    while (cur != NULL){
        if (strcmp(k, cur->k) == 0){
            cur->v = v;
            return;
        }
        prev = cur;
        cur = cur->next;
    } 

    // αν δεν βρω κατι, make new node
    struct _node* n = (struct _node*)malloc(sizeof(struct _node));
    if (!n){
        printf("Error allocating memory.\n");
        exit(0);
    }

    n->k = strdup(k);
    if (n->k == NULL){
        printf("Error allocating memory.\n");
        exit(0);
    }

    n->v = v;
    n->next = NULL;
    
    // add new node
    if (!prev){
        map->array[pos] = n;
    } else {
        prev->next = n;
    }
    map->size++;
}

void hashmap_remove(hashmap map, key k){
    assert(map && k);
    int pos = map->h(k) % map->m;
    struct _node* cur = map->array[pos];
    struct _node* prev = NULL;
    while (cur != NULL){
        if (strcmp(k, cur->k) == 0){
            if (prev == NULL){
                map->array[pos] = cur->next;
            } else {
                prev->next = cur->next;
            }
            free(cur->k);
            free(cur);
            map->size--;
            return;
        }
        prev = cur;
        cur = cur->next;
    } 
}

int hashmap_is_empty(hashmap map){
    assert(map);
    return map->size == 0;
}

int hashmap_size(hashmap map){
    assert(map);
    return map->size;
}


void hashmap_clear(hashmap map){
    assert(map);
    for (int i = 0; i < map->m ; i++){
        while (map->array[i] != NULL){
            struct _node* tmp = map->array[i];
            map->array[i] = map->array[i]->next;
            free(tmp->k);
            free(tmp);
        }
    }
    map->size = 0;
    return;

}





