#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void whatable(char* filename)
{
	if(access(filename, R_OK) == -1)
		perror("failed to read\n");
	else
		printf("succeed in reading %s\n", filename);

	if(access(filename, W_OK) == -1)
		perror("failed to write\n");
	else
		printf("succeed in writing %s\n", filename);
	if(access(filename, X_OK) == -1)
		perror("failed to execute\n");
	else
		printf("succeed in executing %s\n", filename);
}

int main(int argc, char* argv[])
{
	if(argc == 2)
		whatable(argv[1]);
	else
	{
		printf("file error\n");
		return -1;
	}
	return 0;
}

