#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "too many files\n");
		exit(1);
	}
	if(access(argv[1], W_OK) == -1)
	{
		perror("Don't have writing authority\n");
	}

	printf("Have authority of writing\n");

	if(unlink(argv[1]) == -1)
	{
		perror("failed to unlink\n");
		exit(1);
	}
	else
	{
	printf("unlink succeeded\n");
	exit(0);
	}
}
