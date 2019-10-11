#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define TOTAL_LINHA 512

int main() {

    FILE *arq = fopen("comandos.txt","r");
    char linha[TOTAL_LINHA];
    char *token;
    fgets(linha,TOTAL_LINHA,arq);
    fclose(arq);
    char **argv;
    argv = malloc(64*sizeof(char*));
    int i=0;
    token=strtok(linha," |=><=\n");
    argv[i++]=token;

    int x=0;
    while(x==0){
        
        if(token != NULL){
                
            if((strcmp(token,"|"))==0) {
                //printf(" ++++++comando+++++++\n");
                token=strtok(NULL," \n");
                argv[i++]=token;


                    
            } 
            else if((strcmp(token,"<=")==0)) {
                token=strtok(NULL," \n");
                argv[i++]=token;

                // printf("%s ",token);
                token=strtok(NULL," \n");
                argv[i++]=token;
                

            } else if((strcmp(token,"=>")==0)) {
                token=strtok(NULL," \n");
                argv[i++]=token;


                // printf("%s ",token);
                token=strtok(NULL," \n");
                argv[i++]=token;

            } else {
                
                // printf("%s ",token);
                token=strtok(NULL," \n");
                argv[i++]=token;

            }
        }else{
            x++;
            // printf(" ++++++comando+++++++\n");
        }
        
    }
    for(int j=0;argv[j];j++){
        printf("%s \n ",argv[j]);
    }
    return 0;
}
