#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
void forkexample() 
{ 
	// child process because return value zero 
	if (fork() == 0) 
		printf("Hello from Child!\n"); 

	// parent process because return value non-zero. 
	else
		printf("Hello from Parent!\n"); 
} 
int main() 
{ 
	forkexample(); 
	return 0; 
} 

/*#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<math.h>
int main(){
    int pid ;
    printf("I am going to make child\n");
    pid=fork();
    if((pid)==0){
        printf("I am child\n");
    }
    else{
        printf("I am parent\n,%lf",pow(pid,1));
    }
}*/