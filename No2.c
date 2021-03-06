#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){
    if(argc < 2){
        printf("error\n");
        return 0;
    }
    int i, j,I = 0, C = 0;
    int len = 0, cnt = 0;
    for(i = 1; i < argc-2; i++){
        if(strcmp(argv[i], "-i\0") == 0){
            I = 1;
            len = strlen(argv[argc-2]);
            for(j = 0; j < len; j++){
                if(argv[argc-2][j] >= 'A' && argv[argc-2][j] <= 'Z'){
                    argv[argc-2][j] += ('a' - 'A');
                }
            }
        }
        else if(strcmp(argv[i], "-c\0") == 0){
            C = 1;
        }
        else{
            printf("error1\n");
            return 0;
        }
    }
    FILE *fp = fopen(argv[argc-1], "r");
    if(fp == NULL){
        printf("No such file.\n");
    }
    char buf[100];
    while(fgets(buf, 100, fp) != NULL){
        buf[strcspn(buf, "\r\n")] = '\0';
        len = strlen(buf);
        if(I == 1){
            for(i = 0; i < len; i++){
                if(buf[i] >= 'A' && buf[i] <= 'Z'){
                    buf[i] += ('a' - 'A');
                }
            }
        }
        if(strstr(buf, argv[argc-2]) != NULL){
            if(C == 1){
                cnt++;
            }
            else{
                printf("%s\n", buf);
            }
        }
    }
    if(C == 1){
        printf("%d\n", cnt);
    }
    fclose(fp);
    return 0;
}
