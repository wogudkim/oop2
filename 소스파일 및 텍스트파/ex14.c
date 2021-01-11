#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int filedes;

	//open read and write file
	if ((filedes = open("rdwrFile.txt.", O_RDWR | O_CREAT)) == -1)
	{
		printf("Couldn't open read and write file\n");
		exit(1);
	}
	close(filedes);

	//open read file
	if ((filedes = open("readFile.txt.", O_RDONLY | O_CREAT)) == -1)
	{
		printf("Couldn't open read file\n");
		exit(1);
	}
	close(filedes);

	//open write file
	if ((filedes = open("writeFile.txt.", O_WRONLY | O_CREAT)) == -1)
	{
		printf("Couldn't open write file\n");
		exit(1);
	}
	close(filedes);

	//open append file
	if ((filedes = open("appendFile.txt.", O_APPEND | O_CREAT)) == -1)
	{
		printf("Couldn't open append file\n");
		exit(1);
	}
	close(filedes);
	
	exit(0);
}
