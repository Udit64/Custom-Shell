#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
#include<wait.h>
struct vargp{
    int argc;
    char **argv;
    int ret;
};
int flag=0;
int flag2=0;
char currentDirectory[10000];
char previousDirectory[10000];
void run_cd(char* t){
	if(t==NULL){
		chdir(getenv("HOME"));
	}
	else if(strcmp(t,"-")==0 ){
		if(chdir(previousDirectory)==0){
			strcpy(previousDirectory,currentDirectory);
			// printf("%s",previousDirectory);
			strcpy(currentDirectory,previousDirectory);
			}
		else if(chdir(previousDirectory)==-1){
			printf("Unable to reach previous directory !! Error");			
			}
	}	
	else if(strcmp(t,"~")==0 ){
		chdir(getenv("HOME"));
	}
	else{
		if(chdir(t)==0){
		chdir(t);}
		else{
			printf("Error ! No such directory exist ");
		}
		}
}
void run_echo(char* t){
	if(t==NULL){
		// printf("xyz");
		printf("\n");
	}
	else if(strcmp(t,"-n")==0){
		// printf("ud");
		t=strtok(NULL," ");
		while(t!=NULL){
			
			printf("%s ",t);
			t=strtok(NULL," ");
		}
	}
	else if(strcmp(t,"-e")==0){
		// printf("ud");
		t=strtok(NULL," ");
		while(t!=NULL){
			if(strcmp(t,"\n")==0){
				printf("\n");
			}
			else{printf("%s ",t);
			t=strtok(NULL," ");}
		}
		printf("\n");
	}
	else{
		// printf("udite");
		while(t!=NULL){
			
			printf("%s ",t);
			t=strtok(NULL," ");
		}
		printf("\n");
	}
	
}
void run_pwd(char* t){
	if(t!=NULL){
		if(strcmp(t,"-L")==0){
			printf("%s\n",currentDirectory);
			}
}
	else{
		printf("%s\n",currentDirectory);
}
	// printf("udit");
	// printf("%s\n",currentDirectory);
}
void* myThreadFun(void* str){
	
	char* string=(char *)str;
	// printf("ud %s it",string);
	system(string);
}
int main(int arg,char const *argc[]){
	getcwd(currentDirectory,sizeof(currentDirectory));
	strcpy(previousDirectory,currentDirectory);
	struct vargp param;
	char **arr=malloc(sizeof(char)*100);
	char *x[10];
	char copyPath[1000]="";
	char tmp[1000]="";
	// getcwd(currentDirectory,sizeof(currentDirectory));
	strcpy(copyPath,currentDirectory);
	strcat(copyPath,"/");
	strcpy(tmp,currentDirectory);
	strcat(tmp,"/");
	while(1){
		getcwd(currentDirectory,sizeof(currentDirectory));
		printf("%s ~$ ",currentDirectory);
		strcpy(copyPath,tmp);
		
		// strcat(copyPath,"/");
		char line[200];
		char copy[200]="";
		char aasli[500];
		char cop_line[200]="";
		// scanf("%[^\n]%*c",line);
		gets(line);
		strcpy(cop_line,line);
		char copy2[200];
		strcpy(copy2,line);
		char* rajo=strtok(cop_line," ");
		char naru[100]="";
		while(rajo!=NULL){
			strcpy(naru,rajo);
			rajo=strtok(NULL," ");
			
		}
		// printf("%s",line);
		strcpy(aasli,line);
		char* t;
		t=strtok(line," ");
		x[5]=t;
		int flag_forThread=0;
		// int length=strlen(line);
		// printf("%s",line);
		// printf("%c",line[length-2]);
		// return 0;
		if(strcmp(naru,"&t")==0){
			// t=strtok(NULL," ");
			flag_forThread=1;
			
		}
		// printf("%d",flag_forThread);
		// return 0;
		t=strtok(NULL," ");
				// t=strtok(NULL," ");
		x[0]=t;
		
		t=strtok(NULL," ");
		x[1]=t;
		t=strtok(NULL," ");
		x[2]=t;
		// printf("xxx %s",x[5]);
		// return 0;
		// char ID[100];
		// strcpy(ID,t);
		// strcpy(copy,line);
		// strcat(copy," ");
		// printf("%s",x[5]);
		
		if(strcmp(x[5],"cd")==0 || strcmp(x[5],"pwd")==0 || strcmp(x[5],"echo")==0){
			if(strcmp(x[5],"cd")==0){
				// x[5]=strtok(NULL," ");
				run_cd(x[0]);			
				}
			else if(strcmp(x[5],"echo")==0){
				// x[5]=strtok(NULL," ");
		
				run_echo(x[0]);}
			else if(strcmp(x[5],"pwd")==0){
				// x[5]=strtok(NULL," ");	
						
				run_pwd(x[0]);
				}
				}
		if(flag_forThread==1){
			// printf("xxx %s",x[5]);
			// return 0;
			pthread_t thread_id;
			if(strcmp(x[5],"ls")==0){
				strcat(copyPath,"ls.out");
				strcat(copy,copyPath);
				strcat(copy," ");
				strcat(copy,currentDirectory);
				if(x[0] !=NULL){
				// printf("msd %s",x[0]);
				if(strcmp(x[0],"&t")!=0){
					strcat(copy," ");
					// printf("udit");
					strcat(copy,x[0]);
					strcat(copy," ");
					// return 0;
				}
				// return 0;
				}
			}
			if(strcmp(x[5],"rm")==0){
				strcat(copyPath,"rm.out");
				strcat(copy,copyPath);
				strcat(copy," ");
				// strcat(copy,line);
				char* uu=strtok(copy2," ");
				while(uu!=NULL){
					if(strcmp(uu,"&t")!=0){
						strcat(copy,uu);
						strcat(copy," ");
						}
					uu=strtok(NULL ," ");
				}
				// strcat(copy,"./rm.out");
			}
			if(strcmp(x[5],"mkdir")==0){
				strcat(copyPath,"Mkdir.out");
				strcat(copy,copyPath);
				strcat(copy," ");
				// strcat(copy,line);
				char* uu=strtok(copy2," ");
				while(uu!=NULL){
					if(strcmp(uu,"&t")!=0){
						strcat(copy,uu);
						strcat(copy," ");
						}
					uu=strtok(NULL ," ");
				}
				// strcat(copy,"./Mkdir.out");
			}
			if(strcmp(x[5],"cat")==0){
				strcat(copyPath,"cat.out");
				strcat(copy,copyPath);
				strcat(copy," ");
				// strcat(copy,line);
				char* uu=strtok(copy2," ");
				while(uu!=NULL){
					if(strcmp(uu,"&t")!=0){
						strcat(copy,uu);
						strcat(copy," ");
						}
					uu=strtok(NULL ," ");
				}
				// strcat(copy,"./cat.out");
			}
			if(strcmp(x[5],"date")==0){
				strcat(copyPath,"date.out");
				strcat(copy,copyPath);
				strcat(copy," ");
				if(x[0]!=NULL ){
					if(strcmp(x[0],"&t")!=0){
					strcat(copy,x[0]);
					strcat(copy," ");}}
					// strcat(copy,"./date.out");
				if(x[1]!=NULL ){
					if(strcmp(x[1],"&t")!=0){
					strcat(copy,x[1]);
					strcat(copy," ");}}
				if(x[2]!=NULL ){
					if(strcmp(x[2],"&t")!=0){
					strcat(copy,x[2]);
					strcat(copy," ");}}
				
				}
			// printf(" ud %s it",copy);
			
			
			
			// printf("udit2");
			// printf("%s",x[5]);
			// printf("%s",x[0]);
			// printf("%s",x[1]);
		
			// printf("%s",copy);

			
			// if(x[1]!=NULL ){
			// 	if(strcmp(x[1],"&t")!=0){
			// 	strcat(copy,x[1]);
			// 	strcat(copy," ");}}
			// if(x[2]!=NULL){
			// 	if(strcmp(x[2],"&t")!=0){
			// 	strcat(copy,x[2]);}}
		
			// printf("%s",copy);
			
			pthread_create(&thread_id, NULL, myThreadFun,&copy);
			pthread_join(thread_id, NULL);
		}
		else{
		if(strcmp(x[5],"ls")==0){ 
			strcat(copyPath,"ls.out");
			// printf("%s\n" ,copyPath);
			flag=1;
			x[1]=currentDirectory;
			//printf("%s\n",currentDirectory);
			// printf("HERE ");
			// return 0;
		}
		if(strcmp(x[5],"mkdir")==0){ 
			strcat(copyPath,"Mkdir.out");
			// printf("%s\n" ,copyPath);
			flag=1;
			// x[1]=currentDirectory;
			//printf("%s\n",currentDirectory);
			// printf("HERE ");
			// return 0;
		}
		if(strcmp(x[5],"cat")==0){ 
			strcat(copyPath,"cat.out");
			// printf("%s\n" ,copyPath);
			flag=1;
			// printf("helo this is %s",aasli);
			// x[1]=currentDirectory;
			//printf("%s\n",currentDirectory);
			// printf("HERE ");
			// return 0;
		}
		if(strcmp(x[5],"rm")==0){
			strcat(copyPath,"rm.out");
			flag=1;
		}
		if(strcmp(x[5],"date")==0){
			strcat(copyPath,"rm.out");
			flag=1;
		}
		
		// execl("./cat.out","./cat.out" ,x[0],x[1],x[2],NULL);
		if(strcmp(x[5],"ls")==0 || strcmp(x[5],"cat")==0 || strcmp(x[5],"date")==0 || strcmp(x[5],"rm")==0 || strcmp(x[5],"mkdir")==0){
			// printf("%s",t);
			// strcpy(arr[0],"/mnt/c/Users/HP/Desktop/OS/rm/a.out");
			// strcpy(arr[1],t);
			arr[2]=NULL;
			
			
			// char cat[]="cat";
			pid_t process_id;
			
			process_id=fork();

			if(process_id==0){
				
				if(strcmp(x[5],"ls")==0){
					
					execl(copyPath,copyPath,x[1],x[0],NULL);
					exit(0);
				}

				if(strcmp(x[5],"cat")==0){	
					execl(copyPath,copyPath,aasli,NULL);
					exit(0);
				}
				if(strcmp(x[5],"rm")==0){
					
					execl(copyPath,copyPath,aasli,NULL);
					exit(0);
				}
				if(strcmp(x[5],"date")==0){
					
					execl("./date.out","./date.out",x[0],x[1],x[2],NULL);
					exit(0);
				}
				if(strcmp(x[5],"mkdir")==0){
				
					execl(copyPath,copyPath,aasli,NULL);
					exit(0);
				}
				
				
			}
			else if(process_id>0){
				waitpid(0,NULL,0);
			}
		}
		}				

}

return 0;
}