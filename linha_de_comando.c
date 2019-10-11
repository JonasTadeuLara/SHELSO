#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TOTAL_LINHA 512

int main() {

    FILE *arq = fopen("comandos.txt","r");
    char linha[TOTAL_LINHA];
    char *token;
    fgets(linha,TOTAL_LINHA,arq);
    fclose(arq);
    char ***argv;
    argv = malloc(5*sizeof(char**));
    for(int x=0;x<5;x++){
        argv[x]=malloc(10 * sizeof(char*));
        for(int w=0;w<10;w++){
            argv[x][w]=malloc(64* sizeof(char));
        }
    }
    int i=0;
    int k=0;
    token=strtok(linha," |=><=\n");
    
    int x=0;
    while(x==0){
        
        if(token != NULL){
            if((strcmp(token,"|"))==0 || (strcmp(token,"\n"))==0){
                argv[i][k++]=NULL;
                i++;
                k=0;
                token=strtok(NULL," \n");

            } 
            else{
                argv[i][k++]=token;
                token=strtok(NULL," \n");
            }

        }else{
            if(argv[i][k][strlen(argv[i][k])-1] == '\n'){
    	        argv[i][k][strlen(argv[i][k])-1] = '\0';
                argv[i][++k]=NULL;
   	        }
            argv[++i]=NULL;
            x++;
            // printf(" ++++++comando+++++++\n");
        }
        
    }
    int numero_de_processos=i;
    for(int m=0;argv[m];m++){
        for(int n=0;argv[m][n];n++){
            printf("%s ",argv[m][n]);
        }
        printf("\n");
    }
    pid_t pid;

    if(numero_de_processos==1){

        printf("Vou criar meu filho\n");
        // cria processo filho e verifica a ocorrência de erro
		if((pid = fork()) < 0){
			printf("erro ao criar o processo\n");
			exit(1);
		}
   
		
		// processo filho: altera a imagem do processo filho (executa o programa )
		if(pid == 0){

            // char *argv[3];
            // argv[0] = "ls";
            // argv[1] = "-la";
            // argv[2] = NULL;
            argv[0][0]= "ls";
            argv[0][1]= "-la";
            argv[0][2]= NULL;
            argv[1] = NULL;
            printf("Sou filho, meu pid é %d\n", pid);
			if(execvp(argv[0][0],argv[0]) == -1){
				perror("execvp");
			}
			exit(EXIT_SUCCESS);
		}

		// processo pai: espera o filho terminar
		else{
            printf("Sou pai, meu pid é o id do meu filho, %d", pid);
            // printf("%s",argv[0][0]);
			wait(NULL);
		}
    }
    else{//pipeline. pra criar pipe, usar dup2.
        
        if(numero_de_processos == 2){

        }
        else{//mais de 2 processos, precisará de 2 ou mais pipes.

        }

    }
    return 0;
}
