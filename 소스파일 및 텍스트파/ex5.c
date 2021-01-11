#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 512

int main(int argc, char **argv)
{
	int fd;
	int len;
	int word_cnt = 0;
	int nline_cnt = 0;
	char buf;
	
	//open filedes
	fd = open(argv[1], O_RDONLY | O_CREAT, 0644);
	if(fd == -1)
		printf("open failed\n");

	//read filedes
	while(read(fd,&buf,sizeof(buf)) != 0)
	{
		if(nline_cnt == 0) nline_cnt++;
		printf("%c", buf);
		// if newline is in buffer, count the number of newlines
		if(buf == '\n'){
			len = read(fd, &buf, sizeof(buf));

			if(len == 0);
			else
			{
				nline_cnt++;
				lseek(fd, -1, SEEK_CUR);
			}
		}
	}
	
	//print out newline count
	printf("newline count: %d\n", nline_cnt);

	//initialize file pointer
	lseek(fd, 0, SEEK_SET);

	//read filedes
	while(read(fd,&buf,sizeof(buf)) != 0)
	{
		if(word_cnt == 0) word_cnt++;

		//if word is not in buffer, count the number of words
		if(buf == '\n' ||  buf == ' '){
			len = read(fd, &buf, sizeof(buf));

			if(len == 0);
			else
			{
				word_cnt++;
				lseek(fd, -1, SEEK_CUR);
			}
		}
	}

	//print out word count
	printf("word count: %d\n", word_cnt);
	close(fd);

	

	return 0;
}
