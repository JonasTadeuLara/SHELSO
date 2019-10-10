#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define TOTAL_LINHA 512

//kjhasdjkasdkjhasdkj
////asdasdasdasdasd

int main()
{

    FILE *arq = fopen("comandos.txt","r");
    char linha[TOTAL_LINHA];
    fgets(linha,TOTAL_LINHA,arq);
    fclose(arq);

    int x=0;

    for(int i=0; i<strlen(linha);i++ ){
        if(linha[i]== '|'){
            x++;
        }
    }

    x=(x*2);
    x++;
    //asdakbasdnbasdyasd basdibasdpklas askdjglkasdgljkadgjk fasdfsdfsdfsdf
    //char *comandos = (char*)malloc(sizeof(x)*sizeof(linha)*sizeof(char));
    char *strings[12];



















    return 0;
}
