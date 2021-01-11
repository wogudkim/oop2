#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

struct stat buf;

int my_double_ls (const char *name, int skip)
{
	struct dirent *d;
	DIR *dp;

	if((dp=opendir(name)) == NULL)
		return -1;

	while(d = readdir (dp))
	{
		if(d -> d_ino != 0)
		{
			if(skip == 0)
				printf("%s\n", d->d_name);
			else if(skip == 1)
			{
				if(d->d_name[0] != '.')
					printf("%s\n", d->d_name);
			}
		}
	}
	
	rewinddir(dp);

	while(d = readdir (dp))
	{
		if(d -> d_ino != 0)
		{
			if(skip == 0)
				printf("%s\n", d->d_name);
			else if(skip == 1)
			{
				if(d->d_name[0] != '.')
					printf("%s\n", d->d_name);
			}
		}
	}

	closedir (dp);
	return 0;
}

int main(int argc, char* argv[])
{
	my_double_ls(argv[1], atoi(argv[2]));

	return 0;
		
}











