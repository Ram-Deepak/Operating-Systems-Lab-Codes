#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	pid_t pid;
	switch(pid = fork()){
		case -1:
			perror("Process creation unsuccessful");
			exit(-1);
		case 0:
			printf("Child starts\n");
			execl("/bin/date", "date", 0);
			exit(0);
		default:
			wait(NULL);
			printf("Child terminated\n");
			exit(0);
	}
	return 0;
}
