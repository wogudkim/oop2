/*12171603 Jaehyeong Kim*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>


int main()
{
	// 1. CREATES A TCP SERVER SOCKET
	int server_socket = socket(PF_INET, SOCK_STREAM, 0);
	int option = 1;
	setsockopt(server_socket, SOL_SOCKET, 
		SO_REUSEADDR, &option, sizeof(option));
	if(server_socket == -1)
	{
		printf("create error\n");
		exit(1);
	}

	FILE* file = fopen("data.txt", "rb");
	const int BUFFER_SIZE = 20;
	char buffer[BUFFER_SIZE];
	
	struct sockaddr_in server_address;
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	
	// 2. BINDS THE SERVER SOCKET TO PORT 1234
	server_address.sin_port = htons(1234);
	if(bind(server_socket, (struct sockaddr*)&server_address,
		 sizeof(server_address)) == -1)
	{
		printf("bind error\n");
		exit(1);

	}

	// 2. LISTENS TO CONNECTION REQUESTS
	if(listen(server_socket, 2) == -1)
	{
		printf("listen error\n");
		exit(1);

	}
	
	// 3. ITERATIVE APPROACH
	int n;
	for(;!feof(file);)
	{
		struct sockaddr_in clnt_adr;
		socklen_t clnt_adr_sz = sizeof(clnt_adr);
		
		// 3. ACCEPTS A CONNECTION REQUEST FROM CLIENT
		int client_socket = accept(server_socket, 
			(struct sockaddr*)&clnt_adr, &clnt_adr_sz);
		if(client_socket == -1)
		{
			printf("accept failed");
			exit(1);
		}
		
		// 4.1. LOADS THE FILE CONTENT TO A BUFFER, AND NOTES THE LENGTH OF THE FILE
		rewind(file);
		char file_length = (char)fread((void*)buffer, sizeof(char), BUFFER_SIZE, file);
		
		// 4.2. SENDS THE LENGTH OF THE FILE (DATA) TO CLIENT
		write(client_socket, &file_length, BUFFER_SIZE);
		
		// 4.3. SENDS THE CONTENT OF THE FILE
		write(client_socket, buffer, file_length);
		
		// 4.4. TERMINATES ITS OUTPUT (TCP HALF-CLOSE)
		if(shutdown(client_socket, SHUT_WR) == -1)
		{
			printf("shutdown failed\n");
		}
		
		// 4.5. RECEIVES A NUMBER (A BYTE) FROM CLIENT
		read(client_socket, buffer, BUFFER_SIZE);
		
		// 4.5. PRINTS OUT THE RECEIVED NUMBER
		printf("Received: %s\n", buffer);
		
		// 4.6. CLOSES THE CLIENT SOCKET
		close(client_socket);
	}
	
	// 5. CLOSES THE FILE AND SERVER SOCKET
	fclose(file);
	close(server_socket);

	return 0;
}
