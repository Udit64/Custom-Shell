
#include<stdio.h>
#include <sys/types.h> 
#include<string.h>
#include <sys/stat.h> 
#include<dirent.h>
#include<stdlib.h>
#include<unistd.h>
char currentDirectory[1000];
int main(int argc, char* argv[]){
    char copy_mkdir[200];
    char t[200];
    strcat(copy_mkdir,"mkdir ");
    int index=2;
    while(argv[index]!=NULL){
        strcat(copy_mkdir,argv[index++]);
        strcat(copy_mkdir," ");
    }
    if(argv[2]==NULL){
        strcpy(t,argv[1]);
        }
    else{
        strcpy(t,copy_mkdir);
    }
    // printf("%d",argc);
    // return 0;
    char* token=strtok(t," ");
    token=strtok(NULL," ");
    if(token==NULL){
        printf("Error! You have not provided any directory as input\n");
    }
    else{
        if(strcmp(token,"-v")==0){
            token=strtok(NULL," ");
            while(token!=NULL){
            getcwd(currentDirectory,sizeof(currentDirectory));
                strcat(currentDirectory,"/");
                strcat(currentDirectory,token);

                // printf("%s\n",temp );
                if(mkdir(currentDirectory,0777)==0){
                    printf("Directory created successfully\n");
                }
                else{
                    printf("Unable to create directory !! Error\n");
                }
                token=strtok(NULL," ");
                }
           
        }
        else if(strcmp(token,"-p")==0){
            token=strtok(NULL," ");
            char* token2;
            while(token!=NULL){
            token2=strtok(token,"/");
            
            while(token2!=NULL){
                 getcwd(currentDirectory,sizeof(currentDirectory));
                strcat(currentDirectory,"/");
                strcat(currentDirectory,token2);
                // if(currentDirectory==NULL){
                mkdir(currentDirectory,0777);
                chdir(currentDirectory);
                token2=strtok(NULL,"/");
            }
            token=strtok(NULL," ");
        }
            
        }
        else{
            while(token!=NULL){
             getcwd(currentDirectory,sizeof(currentDirectory));
            strcat(currentDirectory,"/");
            strcat(currentDirectory,token);
            if(mkdir(currentDirectory,0777)!=0){
                printf("Unable to create directory !! Error\n");
            }
            token=strtok(NULL," ");
}            
        }
    }
}