#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
typedef int bool;
#define true 1
#define false 0

void callKill(){
	
}

void promptUser(){
	char prompt[] = "shredder";
	write(1,prompt,0);
}


void setTimer(int seconds){
	alarm(seconds);
}
void handler(int signum){
	printf("exiting shredder\n");
	exit(0);
}

int main(int argc, char *argv[] )
{
  bool tflag = false;
  bool loop = true;
	int timeout=0;
	int readReturn;
	int userInput = 0;
	char *command;
	char buffer[1024];
	
	signal(SIGALRM, handler);

	if(argc > 0){
		if(argv[1]){
			timeout = atoi(argv[1]);
		}
			if(timeout == 0){
				command = argv[1];
			}
			else{	
				tflag = true;
			}
	} 
		while(1){
			promptUser();
	 	  readReturn = read(0,buffer,1024);
			if(readReturn == -1){
				perror("reading line did not work");
			}
			if(tflag==true){
				setTimer(timeout);
			}

			char c;
		/*	while(c != '\n'){}
			pid = fork(); 
			if(!pid){
			//	execve(command,);
			 }else{
				wait();
		 }*/
	}
	return 0;
	exit(0);
}
