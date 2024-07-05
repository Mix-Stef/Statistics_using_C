#ifndef _HASHMAP_H
#define _HASHMAP_H


typedef char* key;
typedef int value;
typedef struct _hashmap* hashmap;
typedef unsigned int (*hash_function)(key);


hashmap hashmap_create(int);
void hashmap_destroy(hashmap);
void hashmap_put(hashmap, key, value);
value hashmap_get(hashmap, key);
int hashmap_contains(hashmap, key);
void hashmap_remove(hashmap, key);
int hashmap_is_empty(hashmap);
int hashmap_size(hashmap);
void hashmap_clear(hashmap);


#endif