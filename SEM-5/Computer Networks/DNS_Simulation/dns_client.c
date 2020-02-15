#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define MAXLINE 1024
int main() {
	int sockfd;
	char buffer[MAXLINE];
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in servaddr, cliaddr;
	bzero(&servaddr, sizeof(servaddr));
	bzero(&cliaddr, sizeof(cliaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = 7223;
	

	printf("\n Enter the hostname to get IP address: ");
	scanf("%s",buffer);
	int len = sizeof(servaddr);
	
	sendto(sockfd, (char*) buffer, MAXLINE, MSG_CONFIRM, (struct sockaddr*) &servaddr, sizeof(servaddr));
	int n = recvfrom(sockfd, (char*) buffer, MAXLINE, MSG_WAITALL, (struct sockaddr*) &servaddr, &len);
	buffer[n] = '\0';
	printf("\n The IP Address of the host is: %s \n" , buffer);

	close(sockfd);
	return 0;
}
