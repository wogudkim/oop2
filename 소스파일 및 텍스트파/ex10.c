#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define NAMELENGTH 41
#define NROOMS 10

char namebuf[NAMELENGTH] = {0x00};
int infile = -1;

char* getoccupier (int roomno)
{
	off_t offset;
	ssize_t nread;

	if(infile == -1 &&
		(infile = open("residents.txt", O_RDWR | O_CREAT)) == -1)
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

char* freeroom (int roomno)
{
	off_t offset;
	ssize_t nread;

	if(infile == -1 &&
		(infile = open("residents.txt", O_RDWR | O_CREAT)) == -1)
	{
		return NULL;
	}
	offset = (roomno - 1) * NAMELENGTH;

	if(lseek(infile, offset, SEEK_SET) == -1)
		return NULL;
	
	//erase guest's name in Room (roomno)
	for(int i = 0; i < NAMELENGTH; i++)
		namebuf[i] = ' ';
	write(infile, namebuf, NAMELENGTH);

	namebuf[nread - 1] = '\0';

	return namebuf;
}

char* addguest (int roomno, char* guest)
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

	//write guest name on (Room (roomno))'s offset
	for(int i = 0; i < NAMELENGTH; i++)
		namebuf[i] = ' ';
	for(int i = 0; guest[i] != '\0'; i++)
		namebuf[i] = guest[i];
	write(infile, namebuf, NAMELENGTH);

	namebuf[nread - 1] = '\0';

	return namebuf;
}


int main()
{	
	int fnum = 11;
	char o = 'g';

	while(o != 'q')
	{
		printf("command: ");
		scanf(" %c", &o);

		if(o == 'g')
		{
			for (int j = 1; j <= NROOMS; j++)
			{
				if(getoccupier(j) == NULL || 
					getoccupier(j)[0] == ' ')
				{
					printf("Room %d is free\n", j);
				}
				else
					printf("Room %d: %s\n", 
						j, getoccupier(j));
			}
			

		}

		//freeroom
		else if(o == 'r')
		{
			int rnum;
			scanf("%d", &rnum);

			if(getoccupier(rnum) == NULL || 
					getoccupier(rnum)[0] == ' ')
			{
				printf("Room %d is already free\n", rnum);
			}
			else
			{
				freeroom(rnum);
				printf("Now, Room %d is free\n", rnum);
			}


		
		}
		//addguest
		else if(o == 'a')
		{
			int rnum;
			char guest[NAMELENGTH] = {0x00};
			scanf("%s", guest);
			scanf("%d", &rnum);
			printf("%s wants Room %d\n", guest, rnum);

			if(getoccupier(rnum) == NULL || 
					getoccupier(rnum)[0] == ' ')
			{
			
				printf("Room %d: %s\n",
					rnum, addguest(rnum, guest));
			}
			else
			{
				printf("Room %d is not free\n", rnum);
			}	


		}
	}			

	close(infile);
	return 0;
}























