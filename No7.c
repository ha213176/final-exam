#include<stdio.h>
#include<stdlib.h>
#include<string.h>




int main(int argc, char **argv){
    int i, p = 0;
    for(i = 2; i < argc-1; i++){
        if(strcmp(argv[i], "-p") == 0){
            p = atoi(argv[i+1]);
            break;
        }
    }
    FILE *fp = fopen(argv[argc-1], "r");
    fclose(fp);
    return 0;
}
