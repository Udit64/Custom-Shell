#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
char currentDirectory[200];
int main(int argc,char* argv[]){
    
    // char here[100];
    // for (int i=0;i<argc;i++){
    //     printf("%s\n",argv[i]);
    // }
    char t[200];
    // strcpy(t,argv[1]);
    char copy_cat[200];
    
    strcat(copy_cat,"cat ");
    int index=2;
    while(argv[index]!=NULL){
        strcat(copy_cat,argv[index++]);
        strcat(copy_cat," ");
    }
    if(argv[2]==NULL){
        strcpy(t,argv[1]);
        }
    else{
        strcpy(t,copy_cat);
    }
    // printf("%s",t);
    
    char* token=strtok(t," ");
    // return 0;
    //here[0]='q';

    // char* c=pointer[1];
    // printf("%s",t);
    // printf("%s",c);
    // strcpy(c,pointer[1]);s
    char temp[]="-n";
    // printf("%s\n",here);
    char tmp2[]="-E";
    // return 0;
    token=strtok(NULL," ");
    // printf("%s",token);
    //  return 0;
    // printf("udit");
    //     return 0;
    if(!(strcmp(token,temp))){
        int idx=1;
        while(token!=NULL){
        // return 0;
       
        
        struct stat show={0};
        token=strtok(NULL," ");
        getcwd(currentDirectory,sizeof(currentDirectory));
        strcat(currentDirectory,"/");
        if(token!=NULL){
        strcat(currentDirectory,token);
        }
        if(token!=NULL){
        if(opendir(currentDirectory)!=NULL){
            printf("Error !It is a directory\n");
            return 0;
        }}
        // printf("%s",currentDirectory);
        if(stat(currentDirectory,&show)==-1){
            printf("Error !! file not found\n");
        }
        FILE *f=fopen(currentDirectory,"r");
        char ans[1000];
        if(f!=NULL){
            while((fgets(ans,sizeof(ans),f))!=NULL){
            printf("%d ",idx);
            idx++;
            fputs(ans,stdout);
        }}}
        
    }
    else if(!(strcmp(token,tmp2))){
     
        
        while(token!=NULL){
        // return 0;
       
        
        struct stat show={0};
        token=strtok(NULL," ");
        getcwd(currentDirectory,sizeof(currentDirectory));
        strcat(currentDirectory,"/");
        if(token!=NULL){
        strcat(currentDirectory,token);}
        if(token!=NULL){
        if(opendir(currentDirectory)!=NULL){
            printf("Error !It is a directory\n");
            return 0;
        }}
        // printf("%s",token);
        // printf("%s",currentDirectory);
        if(stat(currentDirectory,&show)==-1){
            printf("Error !! file not found\n");
        }
        FILE *f=fopen(currentDirectory,"r");
        char ans[1000];
        char x='$';
        char xx='d';
        
        if(f!=NULL){
            while(fgets(ans,sizeof(ans),f)!=NULL){
            // int index=0;
            // // // printf("%d ",idx);
            // // // idx++;
            // while(x!='\n'){
                
            //     x=ans[index++];
            //     // printf("%c",x);
            // }
            int len=strlen(ans);
            // printf("%d",len);
            // ans[len-2]='$';
            ans[len-1]='$';
            ans[len]='\n';
            ans[len+1]='\0';
            // strcat(ans,"$");
            // strncat(ans,&x,1);
            // strncat(ans,&xx,1);
            fputs(ans,stdout);
            // printf("\n");
        }}}
    }
    else{
       
        while(token!=NULL){
        // return 0;
       
        
        struct stat show={0};
        
        getcwd(currentDirectory,sizeof(currentDirectory));
        strcat(currentDirectory,"/");
        if(token!=NULL){
        strcat(currentDirectory,token);
        if(opendir(currentDirectory)!=NULL){
            printf("Error !It is a directory\n");
            return 0;
        }}
        token=strtok(NULL," ");
        // printf("%s",currentDirectory);
        if(stat(currentDirectory,&show)==-1){
            printf("Error !! file not found\n");
        }
        FILE *f=fopen(currentDirectory,"r");
        char ans[1000];
        char x;
        
        if(f!=NULL){
            while((fgets(ans,sizeof(ans),f))!=NULL){
           
            fputs(ans,stdout);
            
        }}}
    }
    
    return 0;
}