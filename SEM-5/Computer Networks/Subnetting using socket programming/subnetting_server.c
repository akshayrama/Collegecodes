#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<math.h>
int* makeBinary ( int num ) {
	static int binary_rep[8];
	int j = 0;
	long int bin_num;
	int temp[8];
	int count = -1;
	int another = num;
	while( another != 0 ) {
		int f = another % 2;
		count++;
		temp[count] = f;
		another = another / 2;
	}
	while ( count >= 0 ) {
        	binary_rep[j] = temp[count--];
		j++;
	}
	//j is the number of bits in the binary representation but we need the representation in 8 bits
	//therefore we have to shift the contents of the array to 8 - number of bits places
	int places_to_shift = 8 - j;
	for ( int b = j ; b >= 0 ; b-- ) {
		binary_rep[b + places_to_shift] = binary_rep[b];
	}
	//now make the preeding bits in binary to 0
	for ( int s = 0 ; s < places_to_shift ; s++) {
		binary_rep[s] = 0;
	}
	//now we have the 8 bit binary representation of the number
	//return it
	return (binary_rep);
}	

char * convertFromBinary( int arr[] , int flag) {
	if(flag == 1) { 
		static char return_string1[100];
		int i = 0;
		int count = 0;
		for (i = 0 ; i < 4 ;i++) {
			int j;
			int sub_array[8];
			for(j = 0 ; j < 8; j++ ){
				sub_array[j] = 	arr[count++];
			}
			//we have our subarray of 8 bits
			int value = 0;
			for ( int k = 0 ; k < 8 ; k++ ) {
				if (sub_array[k] == 1 ) {
					value += pow(2, abs(k-7));
				}
			}
			char buff[10];
			sprintf(buff, "%d", value);
			strcat(return_string1,buff);
			if ( i <= 2 ) {
				strcat(return_string1,".");
			}
		}
		return return_string1;
	}
	else if (flag == 2) {
		static char return_string2[100];
		int i = 0;
		int count = 0;
		for (i = 0 ; i < 4 ;i++) {
			int j;
			int sub_array[8];
			for(j = 0 ; j < 8; j++ ){
				sub_array[j] = 	arr[count++];
			}
			//we have our subarray of 8 bits
			int value = 0;
			for ( int k = 0 ; k < 8 ; k++ ) {
				if (sub_array[k] == 1 ) {
					value += pow(2, abs(k-7));
				}
			}
			char buff[10];
			sprintf(buff, "%d", value);
			strcat(return_string2,buff);
			if ( i <= 2 ) {
				strcat(return_string2,".");
			}
		}
		return return_string2;
	}
}	 	
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
	//bind the socket
	int bind_status = bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	if ( bind_status < 0 ){
		printf("\n Bind failed! \n");
		return 0;
	}
	//listen for connection
	listen(sockfd, 5);
	//5 is the backlog
	//accept client
	int len = sizeof(cliaddr);
	newfd = accept( sockfd, (struct sockaddr *) &cliaddr, &len);
	//read using newfd
	int n;
	n = read(newfd, (char *) buffer, sizeof(buffer));
	buffer[n] = '\0';
	printf("\n IP Address received: %s \n" , buffer);
	//now get the number of prefix bits
	char temp[1024];
	strcpy(temp,buffer);
	char * token = strtok(temp, "/");
	int cnt = 0;
	char prefix_string[10];
	while(token != NULL) {
		cnt++;
		if (cnt == 2) {
			strcpy(prefix_string,token);
		}
		token = strtok(NULL, "/");	
	}
	//convert this to numerical
	int prefix_number = atoi(prefix_string);
	printf("\n Number of prefix bits: %d\n",prefix_number);
	//create and build the mask
	int mask[32];
	for ( int i = 0 ; i < prefix_number ; i++ ) {
		mask[i] = 1;
	}
	for( int j = prefix_number ; j < 32; j++ ){
		mask[j] = 0;
	}
	printf("\n MASK: ");
	for ( int y = 0 ; y < 32; y++ ){
		printf(" %d ", mask[y]);
	}
	//create and build the not mask
	int not_mask[32];
	for ( int i = 0 ; i < prefix_number ; i++ ) {
		not_mask[i] = 0;
	}
	for( int j = prefix_number ; j < 32; j++ ){
		not_mask[j] = 1;
	}
	printf("\n NOT MASK: ");
	for ( int y = 0 ; y < 32; y++ ){
		printf(" %d ", not_mask[y]);
	}
	//build binary representation of IP address
	//obtain token splits
	//obtain clean IP address without prefix representation
	char another_temp[1024];
	int v1 = 0;
	for (v1 = 0 ; temp[v1] != '\0' ; v1++ ) {
		if(temp[v1] == '/') {
			break;
		}
		another_temp[v1] = temp[v1];
	}
	another_temp[v1] = '\0';
	//another temp has the IP without prefix indication
	int complete_binary_representation[32];
	int cc = 0;
	char * tokens = strtok(another_temp, ".");
	while(tokens != NULL ) {
		int to_send = atoi(tokens);
		int * array_to_concat;
		array_to_concat = makeBinary(to_send);
		for ( int fg = 0 ; fg < 8 ;fg++ ) {
			complete_binary_representation[cc++] = array_to_concat[fg];
		}
		//concatenate with complete array
		tokens = strtok(NULL, ".");
	 
	}
	printf("\n IP ADDRESS IN 32 BIT FORMAT: ");
	for( int x = 0 ;x < cc ; x++ ) {
		printf(" %d " , complete_binary_representation[x]);
	}
	printf("\n");
	printf("\n Generating starting address and ending address of the subnet...  \n");
	//for starting address, IP Address AND mask
	int starting_address[32];
	for( int i = 0 ; i < 32 ; i++ ) {
		starting_address[i]  = complete_binary_representation[i] & mask[i];
	}
	int ending_address[32];
	for( int i = 0 ; i < 32 ; i++ ) {
		ending_address[i]  = complete_binary_representation[i] | not_mask[i];
	}
	char * start_addr;
	start_addr = convertFromBinary(starting_address,1);
	char * end_addr;
	end_addr = convertFromBinary(ending_address,2);
	char buff_to_send[1024];
	strcpy(buff_to_send," Starting Address: ");
	strcat(buff_to_send,start_addr);
	strcat(buff_to_send,"\n");
	strcat(buff_to_send, " Ending Address: ");
	strcat(buff_to_send,end_addr);
	strcat(buff_to_send,"\n");
	printf("\n Sending subnetted IPs to client... \n");
	write(newfd, (char *) buff_to_send, sizeof(buff_to_send));	
			
	close(newfd);
	close(sockfd);
	return 0;
}
	
	
