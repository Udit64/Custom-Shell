#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
int main(int argc,char* argv[]){
    char* t=argv[1];
    int i=0;
    // while(argv[i]!=NULL){
    //     printf("%s",argv[i++]);
    // }
    // return 0;
    if(t==NULL){
		char d[100];
        time_t time_in_kernel;
        struct tm* info;
        
		time(&time_in_kernel);
        info=localtime(&time_in_kernel);
        strftime(d, 100, "%a %b %d %H:%M:%S %Z %Y", info);
		printf("%s\n",d);
		// if(time_in_kernel==-1){
		// 	printf("Time function not working\n");
		// }
		// printf("%s\n",ctime(&t));

	}
    else if(strcmp(t,"-u")==0){		
		time_t time_in_kernel;
        time(&time_in_kernel);
		struct tm *u=gmtime(&time_in_kernel);
		if(u==NULL){
			printf("GMtime functioning not working \n");
		}
		printf("UTC TIME FRAME: %s",asctime(u));
        printf("\n");
	}
    else if(strcmp(t,"-r")==0){
        struct stat properties;
        if(argv[2]==NULL){
            printf("File not found ! Error \n");
            return 0;
        }
        FILE* pointer=fopen(argv[2],"r");
        if(pointer==NULL){
            printf("File does not exist !! error\n");
            return 0;
        }
        char *t=strtok(argv[2],"/");
        char fn[100]="";
        while(t!=NULL){
            strcat(fn,t);
            strcat(fn,"/");
            t=strtok(NULL,"/");
        }
        fn[strlen(fn)-1]='\0';
        // printf("%s",fn);
        stat(fn,&properties);
        printf("%s " ,asctime(localtime(&(properties.st_mtime))));
        fclose(pointer);
    }
    else{
        printf("Error: Incorrect option\n");
    }

}