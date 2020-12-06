#include <stdio.h>
#include <stdlib.h>
#include "Huffman.h"
#include <string.h>

int main(){
    char s[10000];
    printf("enter the name of your file :");
    scanf("%s", s);
    compress_file(s);
    return 0;
}