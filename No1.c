#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int cmp(const void *a, const void *b);
int dcmp(const void *a, const void *b);

int main(int argc, char **argv){
    int i,  d = 0, u = 0;
    for(i = 1; i < argc-1; i++){
        if(strcmp(argv[i], "-d") == 0){
            d = 1;
        }
        else if(strcmp(argv[i], "-u") == 0){
            u = 1;
        }
        else{
            printf("error\n");
            return 0;
        }
    }
    int data[1024], idx = 0;
    char buf[100];
    FILE *fp = fopen(argv[argc-1], "r");
    while(fgets(buf, 1024, fp) != NULL){
        data[idx++] = atoi(buf);
    }
    idx--;
    if(d == 0)
        qsort(data, idx, sizeof(int), cmp);
    else
        qsort(data, idx, sizeof(int), dcmp);
    if(u == 1){
    int tmp = data[0];
        printf("%d\n", data[0]);
        for(i = 1; i < idx; i++){
            if(tmp != data[i]){
                printf("%d\n", data[i]);
                tmp = data[i];
            }
        }
    }
    else{
        for(i = 0; i < idx; i++){
            printf("%d\n", data[i]);
        }
    }
    fclose(fp);
}




int cmp(const void *a, const void *b){
    return *((int *)a)-*((int *)b);
}

int dcmp(const void *a, const void *b){
    return *((int *)b)-*((int *)a);
}
