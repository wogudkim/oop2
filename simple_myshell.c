#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#define MAX_CMD_ARG 10
#define BUFSIZ 256

const char *prompt = "myshell> ";
char* cmdvector[MAX_CMD_ARG];
char  cmdline[BUFSIZ];
int IS_BACKGROUND = 0;

pid_t pid;

typedef struct 
{
	char* name;
	char* desc;
	int (*func)(int argc, char** argv);
} COMMAND;

void fatal(char *str){
	perror(str);
	exit(1);
}

void fn(int _)
{
	printf("Signal received: \n");
}

int makelist(char *s, const char *delimiters, char** list, int MAX_LIST){	
  int i = 0;
  int numtokens = 0;
  char *snew = NULL;

  if( (s==NULL) || (delimiters==NULL) ) return -1;

  snew = s + strspn(s, delimiters);	/* Skip delimiters */
  if( (list[numtokens]=strtok(snew, delimiters)) == NULL )
    return numtokens;
	
  numtokens = 1;
  
  while(1){
     if( (list[numtokens]=strtok(NULL, delimiters)) == NULL)
	break;
     if(numtokens == (MAX_LIST-1)) return -1;
     numtokens++;
  }
  return numtokens;
}

//cd(change directory) command function
int cmd_cd(int argc, char** argv)
{
	if(argc == 1)
		chdir(getenv("HOME"));
	else if(argc == 2)
	{
		if(chdir(argv[1]))
			printf( "No such file or directory\n");
	}
	else
		printf("USAGE: cd [dir]\n");

	return 0;
}

//exit command function
int cmd_exit(int argc, char** argv)
{
	exit(0);
}

//list of command (struct)
static COMMAND builtin_cmds[] =
{
	{"cd", "Change directory", cmd_cd},
	{"exit", "Exit this shell", cmd_exit},
};

//background function

int parse_background(char* cmd)
{
	for(int i = 0; i < strlen(cmd); i++)
	{
		if(cmd[i] == '&')
		{
			cmd[i] = '\0';
			return 1;	
		}
	}
	return 0;
}

void killfunc(int sig)
{
	kill(pid, SIGKILL);
}

//parsing redirection command
void parse_redir(char* cmd){
	int fd;
	int i;
	char* arg;
	for(i = strlen(cmd) - 1; i >= 0; i--){
		switch(cmd[i])
		{
			
			case '<':
				arg =strtok(&cmd[i+1], " \t");
				if((fd=open(arg, O_RDONLY|O_CREAT, 0644)) == -1)
					fatal("file open error");
				dup2(fd, STDIN_FILENO);
				close(fd);
				cmd[i] = '\0';
				break;
			case '>':
				arg =strtok(&cmd[i+1], " \t");
				if((fd=open(arg, O_WRONLY|O_CREAT|O_TRUNC, 
				0644)) == -1)
					fatal("file open error");
				dup2(fd, STDOUT_FILENO);
				close(fd);
				cmd[i] = '\0';
				break;
			default:
				break;
		}	
	}
}

int main(int argc, char**argv){
  int numtokens;
  char* tmpvector[MAX_CMD_ARG];
  char tmpcmd[BUFSIZ];
  struct sigaction act;

  //signal
  sigemptyset(&act.sa_mask);
  act.sa_flags = SA_NOCLDSTOP;
  act.sa_handler = SIG_IGN;
  sigaction(SIGCHLD, &act, NULL);

  signal(SIGINT, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);

  while (1) {
  	fputs(prompt, stdout);
	fgets(cmdline, BUFSIZ, stdin);
	cmdline[strlen(cmdline) -1] = '\0';

	IS_BACKGROUND = parse_background(cmdline);
	strcpy(tmpcmd, cmdline);
	
	numtokens = makelist(tmpcmd, " \t", tmpvector, MAX_CMD_ARG);

	for(int i = 0; i < sizeof(builtin_cmds)/sizeof(COMMAND); i++)
	{
		if(strcmp(tmpcmd, builtin_cmds[i].name) == 0)
		{
			printf("%s\n", builtin_cmds[i].desc);
			builtin_cmds[i].func(numtokens, tmpvector);
		}
	}

	switch(pid=fork()){
	case 0:
		signal(SIGINT, killfunc);
		signal(SIGQUIT, killfunc);		
		
		int pfd[2];
		int i;
		char* cmd_list[MAX_CMD_ARG];

		numtokens = makelist(cmdline, "|", cmd_list, MAX_CMD_ARG);

		for(i = 0; i < numtokens - 1; i++)
		{
			if(pipe(pfd) == -1) fatal("pipe call");
			switch(fork())
			{
				case 0:
					close(pfd[0]);
					dup2(pfd[1], STDOUT_FILENO);
					parse_redir(cmd_list[i]);
					makelist(cmd_list[i], " \t", 
						cmdvector, MAX_CMD_ARG);
					execvp(cmdvector[0], cmdvector);
					fatal("main()");
				case -1:
					fatal("fork call");
				default:
					close(pfd[1]);
					dup2(pfd[0], STDIN_FILENO);
			}
		}
		parse_redir(cmd_list[i]);
		makelist(cmd_list[i], " \t", cmdvector, MAX_CMD_ARG);
		execvp(cmdvector[0], cmdvector);
		fatal("main()");
	case -1:
  		fatal("main()");
	default:
		if(IS_BACKGROUND) break;
		waitpid(pid,NULL, 0);
	}
  }
  return 0;
}
