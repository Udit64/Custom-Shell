#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

struct vargp{
    int argc;
    char **argv;
    int ret;
};


// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void* param)
{   struct vargp*arg = (struct vargp*)(param);
    int argc = (*arg).argc;
    char **argv = (*arg).argv;

	if (argc == 0) {
        return 0;
    }
    char cmd[255];
    int s = 0;
    for (int i = 1; i < argc; ++ i) {
        strcpy(cmd + s, argv[i]);        
        s += strlen(argv[i]);
        cmd[s ++] = ' ';
    }
    cmd[s] = '\0';
    printf("Running `%s` ...\n", cmd);
    int ret = system(cmd);
    printf("Return Code: %d\n", ret);
    
    (*arg).ret = ret;

    return NULL;
}



int main(int argc, char *argv[])
{   int ret;

    struct vargp param;

    param.argc = argc;
    param.argv = argv;
    while(1){
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, *myThreadFun, (void *)&param);
	pthread_join(thread_id, NULL);
	
    printf("After Thread\n");
    
    printf("%d",param.ret);
    return 0;
}
    
    exit(0);
}


// gcc shell.c -lpthread -o run
// ./run <any command with arguments>

// example ->./run ls -a
//         ->./run echo hitesh