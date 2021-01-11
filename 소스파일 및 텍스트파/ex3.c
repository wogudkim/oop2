#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int filedes;
	//if file is not existed, create the file
	filedes = creat("./file.txt", 0644);

	//open readFile
	if ((filedes = open("./file.txt", O_RDONLY, 0644)) == -1)
		printf("failed to open read file\n");
	else
		printf("succeeded in opening read file\n");

	//open writeFile with same file
	if ((filedes = open("./file.txt", O_WRONLY, 0644)) == -1)
		printf("failed to open write file\n");
	else
		printf("succeeded in opening write file\n");
	
	close(filedes);

	return 0;
}

