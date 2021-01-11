#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define NAMELENGTH 41
#define NROOMS 10

char namebuf[NAMELENGTH];
int infile = -1;

char* getoccupier (int roomno)
{
	off_t offset;
	ssize_t nread;

	if(infile == -1 &&
		(infile = open("residents", O_RDWR | O_CREAT)) == -1)
	{
		return NULL;
	}
	offset = (roomno - 1) * NAMELENGTH;

	if(lseek(infile, offset, SEEK_SET) == -1)
		return NULL;

	if((nread = read (infile, namebuf, NAMELENGTH)) <= 0)
		return NULL;

	namebuf[nread - 1] = '\0';

	return namebuf;
}

int main()
{	
	int fnum = 11;
	char o;
	printf("command: ");
	scanf("%c", &o);

	if(o == 'g')
	{
		for (int j = 1; j <= NROOMS; j++)
		{
			if(getoccupier(j) == NULL)
			{
				printf("Room %d is free\n", j);
			}
			else
			printf("Room %d: %s\n", j, getoccupier(j));
		}
		
		lseek(infile, 0, SEEK_SET);
		close(infile);
	}

	//findfree
	else if(o == 'f')
	{
		if(fnum == 11)
		{
			for (int j = 1; j <= NROOMS; j++)
			{
				if(getoccupier(j) == NULL)
				{
					fnum = j;
					break;
				}
			}
		}
		printf("Free room is %d\n", fnum);
	}
				

	return 0;
}























