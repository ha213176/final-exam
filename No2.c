#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){
    if(argc < 2){
        printf("error\n");
        return 0;
    }
    int i, j,I = 0, C = 0;
    int len, cnt = 0;
    for(i = 1; i < argc-2; i++){
        //printf("i = %d\n", i);
        //printf("%s\n", argv[i]);
        //printf("argc = %d\n", argc);
        if(strcmp(argv[i], "-i\0") == 0){
            I = 1;
            len = strlen(argv[argc-1]);
            //printf("%s\n", argv[argc-2]);
            //printf("len = %d\n", len);
            for(j = 0; j < len; j++){
                if(argv[argc-2][j] >= 'A' && argv[argc-2][j] <= 'Z')
                    argv[argc-2][j] += ("a" - "A" +1);
            }
            printf("%s\n", argv[argc-2]);
        }
        else if(strcmp(argv[i], "-c\0") == 0){
            C = 1;
        }
        else{
            printf("error1\n");
            return 0;
        }
    }
    //printf("%s\n", argv[argc-1]);
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
                    buf[i] += ("a" - "A" +1);
                }
            }
            //printf("     %s\n", buf);
        }
        if(strstr(buf, argv[argc-2]) != NULL){
            if(C == 1){
                cnt++;
            }
            else{
                printf("%s\n", buf);
            }
            printf("ii\n");
        }
    }
    if(C == 1){
        printf("%d\n", cnt);
    }
    fclose(fp);
    return 0;
}
