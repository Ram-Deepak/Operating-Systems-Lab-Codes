#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	int i, status;
	pid_t pid;
	pid = fork();
	if(pid < 0){
		printf("Process creation error");
		exit(-1);
	}
	else if(pid>0){
		wait(NULL);
		printf("Parent starts\n");
		printf("Even numbers from 0-10\n");
		for(int i=0; i<=10; i+=2){
			printf("%3d", i);
		}
		printf("\nParent ends\n");
	}
	else{
		printf("Child starts\n");
		printf("Odd numbers from 0-10\n");
		for(int i=1; i<10; i+=2){
			printf("%3d", i);
		}
		printf("\nChild ends\n");
	}
	return 0;
}
