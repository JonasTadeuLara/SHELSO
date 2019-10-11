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

    token=strtok(linha," |=><=\n");
    int x=0;
    while(x==0){
        
        if(token != NULL){
                
            if((strcmp(token,"|"))==0){
                printf(" ++++++comando+++++++\n");
                token=strtok(NULL," \n");
                    
            }else if((strcmp(token,"<=")==0)){
                token=strtok(NULL," \n");
                printf("%s ",token);
                token=strtok(NULL," \n");
            }else if((strcmp(token,"=>")==0)){
                token=strtok(NULL," \n");
                printf("%s ",token);
                token=strtok(NULL," \n");
            }else{
                
                printf("%s ",token);
                token=strtok(NULL," \n");
            }
        }else{
            x++;
            printf(" ++++++comando+++++++\n");
        }
        
    }

    return 0;
}
