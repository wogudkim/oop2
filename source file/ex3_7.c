#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

char oc[4] = "";

//ex3_3.c's lsoct function
int lsoct(char* ls)
{
	int oc[4] = {0};
	int check = 0;
	for(int i=0; i<=8; i++)
	{
		if(ls[i] == 'r')
			check += 4;
		else if(ls[i] == 'w')
			check += 2;
		else if(ls[i] == 'x')
			check += 1;
		else if(ls[i] == '-');
		else
		{
			printf("inapposite singnal");
			return -1;
		}

		if(i%3 == 2)
		{
			oc[i/3+1] = check;
			check = 0;
		}
	}
	return 0;
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("can't specified arguments\n");
		return -1;
	}
	else if(strlen(argv[2]) == 9)
		lsoct(argv[2]);
	else if(strlen(argv[2]) != 4)
	{
		printf("file permission\n");
		return -1;
	}
	else
		strcpy(oc, argv[2]);

	long i = strtol(oc, 0, 8);

	if(chmod(argv[1], i) == -1)
		perror("call to chmod failed\n");

	return 0;
}








