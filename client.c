/* PLEASE WRITE YOUR STUDENT ID AND NAME(ENGLISH) HERE */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>


int main()
{
	// 1. CREATES A TCP SOCKET
	int client_socket = socket(PF_INET, SOCK_STREAM, 0);
	if(client_socket == -1)
	{
		printf("create error\n");
		exit(1);
	}

	const int BUFFER_SIZE = 20;
	char buffer[BUFFER_SIZE];
	
	struct sockaddr_in server_address;
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;

	// 2. CONNECTS TO TCP LOCAL SERVER (BY ADDRESS: ip=127.0.0.1, port=1234)
	server_address.sin_port = htons(1234);
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	if(connect(client_socket, (struct sockaddr*)&server_address,
		sizeof(server_address)) == -1)
	{
		printf("connect error\n");
		exit(1);
	}
	
	// 3. RECEIVES (A BYTE) A LENGTH OF THE INCOMING DATA
	char expected_data_length;
	read(client_socket, buffer, BUFFER_SIZE);
	expected_data_length = buffer[0];
	/* YOUR CODE HERE (RECEIVE A BYTE AND ASSIGN IT TO THE VARIABLE ABOVE) */
	// 4. RECEIVES THE INCOMING DATA
	
	char received_length = (char)read(client_socket, buffer, BUFFER_SIZE);
	
	/* YOUR CODE HERE (RECEIVE THE DATA AND ASSIGN IT'S LENGTH TO THE VARIABLE ABOVE) */

	if(received_length != expected_data_length)
	{
		printf("Mismatch in data length! Expected data length: %d, received data length: %d\n", expected_data_length, received_length);
	}

	// 5. PRINTS OUT THE RECEIVED DATA
	printf("%s", buffer);
	
	// SEND A NUMBER (A BYTE) VALUE 0 TO SERVER
	write(client_socket, "0", BUFFER_SIZE);
	
	// CLOSES THE SOCKET
	close(client_socket);

	return 0;
}
