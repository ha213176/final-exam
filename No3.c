#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define CAPACITY 32


typedef struct entry{
    char *key;
    int value;
    struct entry *next;
}Entry;

typedef struct {
    Entry *bucket;
    int capacity;
}hashMap;


int hashfunction(char *line);
int mapPut(hashMap *map, char *line);
void max(hashMap *map);



int main(int argc, char **argv){
    hashMap map;
//init map
    map.capacity = CAPACITY;
    map.bucket = calloc(map.capacity, sizeof(Entry));
    FILE *fp = fopen(argv[argc-1], "r");
    char buf[1024];
    while(fgets(buf, 1024, fp) != NULL){
        buf[strcspn(buf, "\n")] = '\0';
        mapPut(&map, buf);
    }
    max(&map);
    fclose(fp);
    
    return 0;
}

int hashfunction(char *line){
    int value = 0, i;
    int len = strlen(line);
    for(i = 0; i < len; i++){
        value += *line;
        value = value << 1;
    }
    return value %32;
}

int mapPut(hashMap *map, char *line){
    int idx = hashfunction(line);
    int len = strlen(line);
    if(map->bucket[idx].key == NULL){
        map->bucket[idx].key = (char *)malloc(len+1);
        strncpy(map->bucket[idx].key, line, len+1);
        map->bucket[idx].value = 1;
        map->bucket[idx].next = NULL;
    }
    else{
        Entry *ptr = &map->bucket[idx], *qtr = ptr;
        while(ptr != NULL){
            if(strcmp(ptr->key, line) == 0){
                ptr->value++;
                return 1;
            }
            qtr = ptr;
            ptr = ptr->next;
        }
        qtr->next = (Entry *)malloc(sizeof(Entry));
        ptr = qtr->next;
        strcpy(ptr->key, line);
        ptr->value = 1;
        ptr->next = NULL;
    }
    return 1;
}

void max(hashMap *map){
    int i, max = 0, f = 0;;
    char tmp[1024];
    Entry *ptr = NULL, *qtr = NULL;
    for(i = 0; i < CAPACITY; i++){
        ptr = &map->bucket[i];
        f = 0;
        while(ptr != NULL){
            if(ptr->value > max){
                max = ptr->value;
                strcpy(tmp, ptr->key); 
            }
            if(f != 0){
                qtr = ptr->next;
                free(ptr->key);
                free(ptr);
            }
            ptr = qtr;
        }
    }
    printf("%s  %d\n", tmp, max);
    return;
}
