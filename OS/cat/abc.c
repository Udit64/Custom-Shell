#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *f=fopen("/mnt/c/Users/HP/Desktop/tmp.txt","r");
    // while()
    char ch;
   while((ch=fgetc(f))!=EOF){
    printf("%c",ch);
    if(ch=="\n"){
        printf("\n");
    }
    // ch=fgetc(f);
   }
   return 0;
}