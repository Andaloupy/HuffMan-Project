#include <stdio.h>
#include <stdlib.h>
#include "Huffman.h"
#include <string.h>
#include <time.h>

int main(){
    clock_t t1, t2;
    char s[10000];
    printf("enter the name of your file :");
    scanf("%s", s);
    t1 = clock();

    compress_file(s);

    t2=clock();
    double temps = (t2-t1);
    printf("\nCompressed in %f seconds\n", temps/1000);
    //printf("%ld\n", t1);
    //printf("%ld", t2);
    return 0;
}

