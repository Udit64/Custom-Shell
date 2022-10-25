#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
int main(int x,char  *argv[]){
    // printf("UDit");
    // printf("%d",x);
    // printf("%s",argv[0]);
    // printf("%s",argv[1]);
    // printf("idot");
    // return ;
    // return 0;
    char *pointer=argv[2];
    char pathOfwd[1000];
    // printf("%s",argv[2]);
    // return 0;
    //  strcpy(pathOfwd,argv[2]);
    // printf("%s",pointer);
    // printf("hitesh");
    if ((pointer==NULL)){
        // printf("uuuu");
        // return 0;
    //     if(x==1){
    //    strcpy(pathOfwd,argv[0]);}
    //    else{
        strcpy(pathOfwd,argv[1]);
    //    }
        struct dirent **d;
        int total =scandir(pathOfwd,&d,0,alphasort);
    
        for(int i=0;i<total;i++){
            char* filename;
            filename=d[i]->d_name;
            if(filename[0]!='.'){
            printf("%s  ",filename);
            free(d[i]);
            }
        }
        free(d);
        printf("\n"); 
    }

    else if(strcmp(pointer,"-A")==0){
    //   if(strcmp(pointer,"-A")==0)
      strcpy(pathOfwd,argv[1]);
    //   if(strcmp(argv[1],"-A")==0)
    //   strcpy(pathOfwd,argv[0]);
        // struct dirent *d;
        // DIR *directory=opendir(".");
        // if(directory==NULL){
        //     printf("Error");
        // }
        // else{
        //     while(d!=NULL){
        //         printf("%s",d->d_name);
        //         d=readdir(directory);
        //     }
        // }
        
        // printf("\n");
        // free(d);
        // free(directory);
        // printf("udpafg");
        struct dirent **d;
        int total =scandir(pathOfwd,&d,0,alphasort);
    
        for(int i=0;i<total;i++){
            char* filename;
            filename=d[i]->d_name;
            if(filename[0]!='.'){
                
                printf("%s  ",filename);
                free(d[i]);
            }
        }
        free(d);
        printf("\n");
    }
    else if(strcmp(pointer,"-a")==0 ){
        // if(strcmp(pointer,"-A")==0)
      strcpy(pathOfwd,argv[1]);
    //   if(strcmp(argv[1],"-A")==0)
    //   strcpy(pathOfwd,argv[0]);
        // strcpy(pathOfwd,argv[1]);
        struct dirent **d;
        int total =scandir(pathOfwd,&d,0,alphasort);
    
        for(int i=0;i<total;i++){
            char* filename;
            filename=d[i]->d_name;
            printf("%s  ",filename);
            free(d[i]);
        }
        free(d);
        printf("\n");
    }
    return 0;
    
}
