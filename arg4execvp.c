#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>



char **split (char **argv2, char *stringa){
	
	char *token;
	int nSpazi = 0;
	
	strtok(stringa, "\n");
	printf("%s\n",stringa);
	/* get the first token */
	token = strtok(stringa, " ");
	printf("%s\n",token);

	/* walk through other tokens */
	/*while( token != NULL )
	{
		nSpazi++;
		
		argv2 = realloc(argv2, sizeof(char*)* nSpazi);
		
		if( argv2 == NULL)
			exit(EXIT_FAILURE);
		argv2[nSpazi-1] = token;
		
		token = strtok(NULL, s);
	}
	
	argv2 = realloc(argv2, sizeof(char*) * (nSpazi + 1));
	argv2[nSpazi] = NULL; */
	argv2 = realloc(argv2, sizeof(char*)* 1);
	argv2[0]="ls";
	nSpazi++;

	argv2 = realloc(argv2, sizeof(char*)* 2);
	argv2[1]="-l";
	nSpazi++;

	argv2 = realloc(argv2, sizeof(char*)* 3);
	argv2[2]=NULL;
	return argv2;
}

int main(int argc, char *argv[]){
	
	/*
	if (argc != 2) {
		fprintf(stderr, "Error: Expected 1 parameter.\n"
				"Usage: %s <pathname>\n", argv[0]);
		return(EXIT_FAILURE);
	}
 
	 */
	char *path = argv[1];
	char *cmdString = NULL;
	char **cmd;
	size_t n;
	ssize_t read;
	FILE *f;
	int pid;
	
	/*
	
	f = fopen("path", "r");
	if (f == NULL)
		exit(EXIT_FAILURE);
	
	while (( read = getline( &cmdString, &n, f)) != -1){
		
		
		if ( (pid = fork()) == -1) {
			perror("fork");
			return(EXIT_FAILURE);
		}
		
		if (pid == 0) {	//child
			
			cmd = split (cmd, cmdString);
			execvp(cmd[0], cmd);
			
			perror(cmd[0]);
			return(EXIT_FAILURE);
			
		} else {

			wait(NULL);	//wait for child to terminate
		}
		
		cmd = NULL;
	}
	
	
	fclose(f);
	
	 */
	
	cmd = split (cmd, "ls -l");
	execvp(cmd[0], cmd);
	
	perror(cmd[0]);
	return(EXIT_FAILURE);
	

	
	
	return 0;
}








