
#include "translate.h"

void output(char*file){

    int b,a,c;
    FILE *f,*t;
    f = fopen(file,"r+");
    t = fopen("Output.txt","w");
    while((c = fgetc(f)) != EOF ){

        if(c != 10){                 // doesn't count the end
            for(int i = 7; i>= 0;i--){
                a = c >> i;             //convert decimal into binary using bitwise operators
                if(a & 1){
                    b = 1;
                }
                else{
                    b = 0;
                }
                fprintf(t,"%d",b);
            }
        }
    }
    fclose(f);
    fclose(t);
}

int countchar(char*file){
    int cpt= 0,c;
    FILE *f;
    f = fopen(file,"r");
    while((c = fgetc(f)) != EOF ){
        if(c != 10){ // doesn't count the end
            cpt++;
        }
    }
    fclose(f);
    return cpt;
}

