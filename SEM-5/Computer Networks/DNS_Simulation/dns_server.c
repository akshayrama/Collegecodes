//server side
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#define MAXLINE 1024
int main() {
	int sockfd;
	char buffer[MAXLINE];
	char lookuptable[30][30][30];
	int number_of_entries = 0;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in servaddr, cliaddr;
	bzero(&servaddr, sizeof(servaddr));
	bzero(&cliaddr, sizeof(cliaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = 7223;
	
	int bind_status = bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	if (bind_status < 0) {
		printf("\n Bind failed! \n");
	}
	
	int n,len;
	len = sizeof(cliaddr);

	while(1) {
		n = recvfrom(sockfd, (char*) buffer, MAXLINE, MSG_WAITALL, (struct sockaddr*) &cliaddr, &len);
		buffer[n] = '\0';
		printf("\n Host name received is: %s \n", buffer);
		
		char temp[MAXLINE];
		strcpy(temp, buffer);
		
		int flag = 0;
		int i;
		for ( i = 0 ; i < number_of_entries; i++ ) {
			if (strcmp(lookuptable[i][0], temp) == 0) {
				flag = 1;
				strcpy(buffer,lookuptable[i][1]);
			}
		}
		if ( flag != 1 ) {
			struct hostent* host_addr;
			struct in_addr ip_address;
			host_addr = gethostbyname(temp);	
			ip_address = *(struct in_addr *) (host_addr -> h_addr);
			strcpy(buffer, inet_ntoa(ip_address));
			//now we add to the look up table
			strcpy(lookuptable[number_of_entries][0],temp);
			strcpy(lookuptable[number_of_entries][1], inet_ntoa(ip_address));	
			number_of_entries++;
		}
		printf("\n Sending IP Address.. ");
		sendto(sockfd, (char* ) buffer, MAXLINE, MSG_CONFIRM, (struct sockaddr*) &cliaddr, len);
		//printing look up table
		printf("\n \n\n Printing Look-up table... \n\n");
		for( i = 0 ; i < number_of_entries; i++ ) {	
			printf(" %s \t | ", lookuptable[i][0]);
			printf("%s",lookuptable[i][1]);		
			printf("\n");
		}
		printf("\n\n");
	}


	close(sockfd);
	return 0;
}
