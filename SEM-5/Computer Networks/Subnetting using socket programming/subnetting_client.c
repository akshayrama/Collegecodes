#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
#include<stdlib.h>
int main() {
	int sockfd, newfd;
	char buffer[1024];
	//create the socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in servaddr, cliaddr;
	bzero(&servaddr, sizeof(servaddr));
	//initialize sockadd_in structure
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = 7223;
	//read IP from user
	printf("\n Enter the IP Address to subnet: ");
	scanf("%s",buffer);
	//connect to server
	connect(sockfd, (struct sockaddr* )&servaddr, sizeof(servaddr));
	//write IP
	write(sockfd, (char*)buffer, sizeof(buffer));

	//reading the subnetted IPs from server
	int n = read(sockfd, (char *) buffer, sizeof(buffer));
	buffer[n] = '\0';
	printf("\n Received from server: \n");
	printf("%s",buffer);
	close(sockfd);
	return 0;
}
