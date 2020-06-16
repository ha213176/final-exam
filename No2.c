#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
    int i, I == 0, C == 0;
    for(i = 1; i < argc-1; i++){
        if(strcmp(argv[i], "-i") == 0){
            I = 1;
        }
        else if(strcmp(argv[i], "-c") == 0){
            C = 1;
        }
        else{
            printf("error\n");
            return 0;
        }
    }
    FILE *fp = fopen(argv[argc-1], "r");
    char buf[100];
    while(scanf("%s", buf) != EOF){
        if(I == 1){
            for(i = 0; i < strlen(buf); i++){
                if(buf[i] > "a")
            }
        }
        if(strstr(buf, argv[argc-2]) != NULL){
            if(C == 0);
        }
    }
}
