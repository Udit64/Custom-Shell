#include <stdio.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
int errorForDirec(char* f){
    struct stat p;
    stat(f, &p);
    return S_ISREG(p.st_mode);
    //equal to 1 if found a file and 0 if it is a directory
}
int main(int argc,char* argv[]){
    // printf("abc");
    // char* t=argv[0];
    // printf("%d",argc);
    char t[200];
    int index=2;
    char copy_rm[200]="";
    // strcat(copy_rm,argv[1]);
    // strcat(argv[1]," ");
    // printf("%s",argv[2]);
    // strcat(copy_rm,argv[2]);
    // strcat(" ",argv[2]);
    // strcat(argv[1],argv[2]);
    // while(argv[index]!=NULL){
    //     strcat(copy_rm,argv[index++]);
    //     strcat(copy_rm," ");

    // }
    
    strcat(copy_rm,"rm ");
    while(argv[index]!=NULL){
        strcat(copy_rm,argv[index++]);
        strcat(copy_rm," ");
    }
    // printf("%s",copy_rm);
    // printf("hitesh");
    // printf("%s",argv[0]);
    // printf("%s",argv[1]);
    // strcat(argv[1]," ");
    // int i=1;
    // // return 0;
    // if(argv[2]!=NULL){
    // while(argv[i]!=NULL){
    //     if(argv[++i]!=NULL){na
    //     strcat(argv[1],argv[i]);}
    //     strcat(argv[1]," ");
    // }}
    // printf("%s",argv[2]);
    // printf("%s",argv[3]);
    // printf("ud %s it",argv[1]);
    // return 0;
    if(argv[2]==NULL){
        strcpy(t,argv[1]);
        }
    else{
        strcpy(t,copy_rm);
    }
    // printf("%s",t);
    // return 0;
    char *token;
    token=strtok(t," ");
    token=strtok(NULL," ");

    if(token==NULL){
        printf("Error:please provide some file\n");
    }

    else if(strcmp(token,"-f")==0){
        while(token!=NULL){
            token=strtok(NULL ," ");
            unlink(token);
        }
//         if(argv[2]!=NULL){
//         remove(argv[2]);
// }       
//         if(argv[3]!=NULL){
//             remove(argv[3]);
// }       
    }
    else if(strcmp(token,"-i")==0){
        char x;
        token=strtok(NULL," ");
        printf("Are you sure that you want to delete this file if yes enter Y else enter N :");
        scanf("%c",&x);
        while(token!=NULL){
            if(x=='Y'){
                if(opendir(token)!=NULL){
                printf("Error! It is a directory not a file\n");
                }
            else if(unlink(token)!=0){
                printf("Error! File does not exist!!\n");  
                   }
                          
            else{
                unlink(token);
            }
            token=strtok(NULL," ");


                }
               }
               
               }
    
    else{
        while(token!=NULL){
            if(opendir(token)!=NULL){
                printf("Error! It is a directory not a file\n");
                }
            else if(unlink(token)!=0){
                printf("Error! File does not exist!!\n");  
                   }
                          
            else{
                unlink(token);
            }
            token=strtok(NULL," ");
            
        }
}
}