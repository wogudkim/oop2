#include <stdio.h>
#include <string.h>

//convert ls to oct
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
	printf("convert: %d%d%d%d\n", oc[0],oc[1],oc[2], oc[3]);
}

//convert oct to ls
int octls(char* oc)
{
	char ls[9] = "";
	if(oc[0] == '0')
	{
		for(int i = 1; i <=3; i++)
		{
			if(oc[i] == '0')
				strcat(ls,"---");
			else if(oc[i] == '1')
				strcat(ls,"--x");
			else if(oc[i] == '2')
				strcat(ls,"-w-");
			else if(oc[i] == '3')
				strcat(ls,"-wx");
			else if(oc[i] == '4')
				strcat(ls,"r--");
			else if(oc[i] == '5')
				strcat(ls,"r-x");
			else if(oc[i] == '6')
				strcat(ls,"rw-");
			else if(oc[i] == '7')
				strcat(ls,"rwx");
			else
			{
				printf("inapposite number\n");
				return - 1;
			}

		}
	}
	else
	{
		printf("inapposite number\n");
		return -1;
	}
	printf("convert: %s\n", ls);
	return 0;
}

int main(int argc, char* argv[])
{
	if(!strcmp(argv[1], "lsoct"))
		lsoct(argv[2]);
	else if(!strcmp(argv[1], "octls"))
		octls(argv[2]);
	else
	{
		printf("Nothing is found\n");
		return -1;
	}
	return 0;
}







