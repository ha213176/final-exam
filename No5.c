#include<stdio.h>
#include<string.h>


char *getWord(char *line, char *maxWord, int *max);
int dig(char c);

int main(int argc, char **argv){
    FILE *fp;
    if(strcmp(argv[1], "longestword") == 0){
        fp = fopen(argv[2], "r");
    }
    else{
        printf("error: 1\n");
        return 0;
    }
    char buf[1024], maxWord[200], term[200];
    int max = 0;
    while(fgets(buf, 1024, fp) != NULL){

    }
    fclose(fp);
    return 0;
}



char *getWord(char *line, char *maxWord, int *max){
    int len, i, l = 0, idx = 0;
    char *ptr = line, tmp[200];
    len = strlen(line);
    for(i = 0; i < len; i++){
        if(dig(line[i])){
            l++;
            tmp[idx++] = line[i];
        }
        else{
            if(l > *max){
                *max = l;
                strncpy(maxWord, line, l);
                maxWord[l] = '\0';
            }
            return line+l;
        }
    }
    return NULL;
}


int dig(char c){
    if(c == ' ' || c == '\t' || c == '\n' || c == '\0'){
        return 1;
    }
    return 0;
}
