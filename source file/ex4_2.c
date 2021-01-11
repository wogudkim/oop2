#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

struct stat buf;

int my_double_ls (const char *name)
{
	struct dirent *d;
	DIR *dp;

	if((dp=opendir(name)) == NULL)
		return -1;

	while(d = readdir (dp))
	{
		if(d -> d_ino != 0)
		{
			if(d->d_name[0] != '.')
			{
				if(S_ISDIR(buf.st_mode))
					printf("%s*\n", d->d_name);
				else
					printf("%s\n", d->d_name);
			}
		}
	}

	closedir (dp);
	return 0;
}

int main(int argc, char* argv[])
{
	if(stat(argv[1], &buf) == -1)
	{
		perror("stat");
		return 1;
	}
	my_double_ls(argv[1]);

	return 0;
		
}











