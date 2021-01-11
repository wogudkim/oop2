#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 512

//copy name1 to name2
int copyfile(const char* name1, const char* name2)
{
	int rd_fd;
	int wr_fd;
	int len;
	char buf[BUFSIZE];

	//open readfile, writefile
	rd_fd = open(name1, O_RDONLY | O_CREAT, 0644);
	wr_fd = open(name2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	
	//if readfile is not open
	if(rd_fd == -1)
		return -1;
	//if writefile is not open
	if(wr_fd == -1)
	{
		close (rd_fd);
		return -2;
	}
	

	while((len = read(rd_fd, buf, BUFSIZE)) > 0)
	{
		//write buffer in writefile
		if(write(wr_fd, buf, len) < len)
		{
			close(rd_fd);
			close(wr_fd);
			return -3; // writing error
		}
	}

	close(rd_fd);
	close(wr_fd);

	//reading error
	if(len == -1)
		return -4;
	else
		return 0;
}

int main(int argc, char **argv)
{
	int retcode;
	retcode = copyfile(argv[1], argv[2]);
	if(retcode != 0)
		printf("copy failed: %d\n", retcode);
	else
		printf("succeed in copying\n");

	return 0;
}
