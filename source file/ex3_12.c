#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

struct stat sb;

int lsoct(char* perm)
{
	int i, j, k, oct = 0;

	if(perm[0] == 'r') oct += 400;
	if(perm[1] == 'w') oct += 200;
	if(perm[2] == 'x') oct += 100;
	if(perm[3] == 'r') oct += 40;
	if(perm[4] == 'w') oct += 20;
	if(perm[5] == 'x') oct += 10;
	if(perm[6] == 'r') oct += 4;
	if(perm[7] == 'w') oct += 2;
	if(perm[8] == 'x') oct += 1;

	i = oct % 10;
	oct /= 10;
	j = oct % 10;
	oct /= 10;
	k = oct % 10;

	return (k*8*8 + j*8 + i);
}

int main(int argc, char* argv[])
{
	mode_t i, j, k, temp, perm;
	struct stat satbuf;
	int p;

	static short octarray[9] = {0400, 0200, 0100, 0040, 0020, 0010,
					0004, 0002, 0001};

	if(argc != 3)
	{
		perror("cannot specified argumnets\n");
		exit(1);
	}
	if(open(argv[1], O_RDONLY) == -1)
	{
		perror("file don't exist\n");
		exit(1);
	}
	if(argv[2][0] >= '0' && argv[2][0] < '9')
	{
		temp = atoi(argv[2]);
		i = temp % 10;
		temp /= 10;
		j = temp % 10;
		temp /= 10;
		k = temp % 10;

		perm = k*8*8 + j*8 + i;
	}
	else if(argv[2][1] == '+' || argv[2][1] == '-')
	{
		if(stat(argv[1], &sb) == -1)
		{
			fprintf(stderr, "couldn't stat %s\n", argv[2]);
			exit(1);
		}
		switch(argv[2][0])
		{
			case 'u': 
				p = 0;
				break;
			case 'g': 
				p = 3;
				break;
			case 'o': 
				p = 6;
				break;
			default: 
				fprintf(stderr, "wrong argument\n");
				exit(1);
		}
		switch(argv[2][2])
		{
			case 'r': 
				p += 0;
				break;
			case 'w': 
				p += 1;
				break;
			case 'x': 
				p += 2;
				break;
			default: 
				fprintf(stderr, "wrong argument\n");
				exit(1);
		}
		if(argv[2][1] == '+')
			sb.st_mode |= octarray[p];
		else if(argv[2][1] == '-')
			sb.st_mode ^= octarray[p];
		else
		{
			fprintf(stderr, "wrong argument\n");
			exit(1);
		}
		if(chmod (argv[1], sb.st_mode) == -1)
			fprintf(stderr, 
				"couldn't change mode for %s\n", argv[1]);
		exit(1);
	}
	else
		perm = lsoct(argv[2]);
	
	if(chmod(argv[1], perm) == -1)
	{
		perror("call to chmod failed\n");
		exit(1);
	}

	printf("jh's chmod ver 1.0\n");
		
}














