#include <stdio.h>

int len;
int year = 2023;
const int max = 100;


int main(int argc, char **argv){

    int local = 0x90;

    printf("argc: %p\n",&argc);
    printf("argv: %p\n",argv);
    
    printf("global no-init: %p\n",&len);
    printf("global initialized: %p\n",&year);
    printf("global const: %p\n",&max);

    printf("local: %p\n",&local);

    return 0;
    
}
