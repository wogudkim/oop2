#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUF_SIZ 1000

struct stat sb;

void slowwatch(const char* name, time_t last)
{
	if(stat(name, &sb) == -1 || sb.st_mtime != last)
	{
		printf("%s changed\n", name);

		char buff[BUF_SIZ];
		int fd;
		ssize_t rd_size;

		if((fd = open(name, O_RDONLY)) > 0)
		{
			while((rd_size = read(fd,buff,BUF_SIZ - 1)) > 0)
			{
				buff[rd_size] = '\0';
				puts(buff);
			}
			close(fd);
		}
		else
			printf("file open failed\n");

		exit(1);
	}
}

int main(int argc, char* argv[])
{
	int fd;
	time_t last_time;

	if(argc != 2)
	{
		fprintf(stderr, "file can't specified\n");
		exit(1);
	}

	fd = open(argv[1], O_RDWR | O_CREAT, 0644);
	fd = close(fd);

	if(stat(argv[1], &sb) == -1)
	{
		perror("can't stat\n");
		exit(1);
	}
	last_time = sb.st_mtime;


	while(1)
	{
		slowwatch(argv[1], last_time);
		sleep(2);
	}
}






