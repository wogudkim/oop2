#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 512

int main(int argc, char** argv)
{
	ssize_t nread;
	char buf[SIZE];
	int fd;

	//if command line arguments are existed
	if(argc > 1)
	{
		printf("command line arguments existed\n");
		for(int i = 1; i < argc; i++)
		{
			if((fd = open(argv[i], O_RDONLY)) == -1)
				exit(1);
			
			while((nread = read (fd, buf, SIZE)) > 0)
				write(1, buf, nread);

			close(fd);
		}
	}
	//are not existed
	else
	{
		printf("command line arguments not existed\n");
		while((nread = read (0, buf, SIZE)) > 0)
			write(1, buf, nread);
	}

	
	exit(0);
}
