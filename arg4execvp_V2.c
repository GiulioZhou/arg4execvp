
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//@The idea is to use dinamic sized array for the command line and arg

/* char **split (char **argv2, char *stringa){
	
	char *token;
	int nSpazi = 0;
 
	//strtok doesn't work -> bus error:10
 
	strtok(stringa, "\n");
	
	token = strtok(str, " ");
	
	while( token != NULL )
	{
 nSpazi++;
 
 //realloc doesn't work -> invalid old size
 // and probably other segmentation fault
 argv2 = realloc(argv2, sizeof(char*)* nSpazi);
 
 if( argv2 == NULL)
 exit(EXIT_FAILURE);
 argv2[nSpazi-1] = token;
 
 token = strtok(NULL, s);
	}
	
	argv2 = realloc(argv2, sizeof(char*) * (nSpazi + 1));
	argv2[nSpazi] = NULL;
	return argv2;
 }
 
 
 int main(int argc, char *argv[]){
	
	
	if (argc != 2) {
 fprintf(stderr, "Error: Expected 1 parameter.\n"
 "Usage: %s <pathname>\n", argv[0]);
 return(EXIT_FAILURE);
	}
 
	char *path = argv[1];
	char *cmdString = NULL;
	char **cmd;
	size_t n;
	ssize_t read;
	FILE *f;
	int pid;
	
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
	
	
	
	return 0;
 }
 
 */