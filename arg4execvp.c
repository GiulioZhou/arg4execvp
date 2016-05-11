#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_ARGS 64
#define MAX_LINE 1024

//split the command line into { command, par1, par2, ..., parn, NULL}

void split(char *command[], char line[]){
	
	char *token;
	int spaces = 0;
 
	strtok(line, "\n");
	token = strtok(line, " ");
	
	while( token != NULL )
	{
		spaces++;
		command[spaces-1] = token;
		token = strtok(NULL, " ");
	}
	
	command[spaces] = NULL;
	
}

int main(int argc, char *argv[]){
	
	if (argc != 2) {
		fprintf(stderr, "Error: Expected 1 parameter.\n"
				"Usage: %s <pathname>\n", argv[0]);
		return(EXIT_FAILURE);
	}
	
	char *path = argv[1]; //indirizzo del file da leggere
	char *cmd[MAX_ARGS]; //vettore dei parametri
	char cmdString[MAX_LINE]; //riga di codice
	char *s =cmdString;
	FILE *f;
	int pid;
	
	//open the file
	
	f = fopen(path, "r");
	if (f == NULL){
		printf("cannot open the file\n");
		exit(EXIT_FAILURE);
	}
	
	//Gets all the line and execute
	
	while ( fgets (cmdString, MAX_LINE, f)!=NULL){
		
		if ( (pid = fork()) == -1) {
			return(EXIT_FAILURE);
		}
		
		if (pid == 0) {	//child
	
			split (cmd, cmdString);
			execvp(cmd[0], cmd);
			
			perror(cmd[0]);
			return(EXIT_FAILURE);
			
		} else {
			wait(NULL);	//wait for child to terminate
		}
	}
	fclose(f);
	return 0;
}



