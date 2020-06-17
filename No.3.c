#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BUF_SIZE 1024
#define MAP_CAT 32

typedef struct entry{
    char *key;
    int value
    struct entry *next;
}Entry;

typedef struct {
    Entry *bucket;
    int capacity;
}hashMap;





int main(int argc, char **argv){


//init map
    map->capacity = capacity;
    map->buckets = calloc(capacity, sizeof(Entry));



}
