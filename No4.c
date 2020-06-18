#include<unistd.h>
#include<stdio.h>
#include <fcntl.h>
#include<string.h>



int main(int argc, char **argv){
    int a, b, total;
    char buf[1024*32];
    int len = strlen(argv[argc-1]);
    if(argv[argc-1][len-1] == '/'){

    }
    else{
        a = open(argv[argc-2], O_RDONLY);
        b = open(argv[argc-1], O_WRONLY, 777);
        //printf("%d\n", b);
        total = read(a, buf, 1024*32);
        perror("error: ");
        c = write(b, buf, total);
        perror("error: ");
        printf("%d\n", c);
    }
    close(a);
    close(b);
    return 0;
}
