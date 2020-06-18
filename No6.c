#include<stdio.h>
#include<string.h>


int main(){
    char buf[10][100];
    int idx = 0, k = 0;
    int len;
    FILE *fp = fopen("data", "r+");
    while(fgets(buf[idx], 100, fp) != NULL){
        len = strlen(buf[idx]);
        for(int i = 0; i < len; i++){
            if(buf[idx][i] >= 'A' && buf[idx][i] <= 'Z'){
                buf[idx][i] += ('a' - 'A');
            }
            if(buf[idx][i] != '\n' && buf[idx][i] != '\0'){
                k = 1;
            }
        }
        if(k == 1){
            idx++;
            k = 0;
        }
    }
    rewind(fp);
    for(int i = 0; i < idx; i++){
        fputs(buf[i], fp);
    }
    fclose(fp);
    return 0;
}
