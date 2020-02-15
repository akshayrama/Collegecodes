#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
void main() {
	pid_t pid;
	pid = fork();
	int id;
	//creating the shared memory space
	//returning the id for shared memory through shmget
	id = shmget(111,50,IPC_CREAT | 0666); //111 is key, 50 is shared memory allocation , 0666 is permission 
	char* a; // shared memory spaces
	char* b;
	if(pid > 0 ) {
		//shmat is to attach to shared memory 
		//shmat returns the address of the shared memory
		a = shmat(id,NULL,0);
		//accepting data in the shared memory space
		printf("\n Enter the string to convert to uppercase: ");
		scanf("%s",a); //where a is the address of shared memory	
		wait(NULL);
		shmdt(a); //detaching from the shared memory segment
		
	}
	else {
		sleep(3);
		b = shmat(id,NULL,0); //b contains the address of the shared memory and hence is able to access the data in the shared memory
		int i;
		for(i = 0; b[i]!='\0'; i++) {
			b[i] = toupper(b[i]); 
		}
		printf("\n %s \n", b);
		shmdt(b);
	}
	shmctl(id,IPC_RMID,NULL); //removing from shared memory 
}
