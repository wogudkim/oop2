#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char *workfile = "junk.txt";

int main()
{
	int filedes;

	//file is not existed
	if ((filedes = open(workfile, O_RDWR)) == -1)
	{
		printf("Couldn't open %s\n", workfile);
		exit(1);
	}
	
	exit(0);
}

