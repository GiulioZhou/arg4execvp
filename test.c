#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "mylib.h"


int main(int argc, char *argv[]){
	
	if (argc != 2) {
		fprintf(stderr, "Error: Expected 1 parameter.\n"
				"Usage: %s <pathname>\n", argv[0]);
		return(EXIT_FAILURE);
	}
	
	char *path = argv[1]; //indirizzo del file da leggere
	char *cmdString; //riga di codice
	size_t n;
	ssize_t read;


	FILE *f;
	int pid;
	
	//open the file
	
	f = fopen(path, "r");
	if (f == NULL){
		printf("cannot open the file\n");
		exit(EXIT_FAILURE);
	}
	
	//Gets all the line and execute
	
	while (( read = getline(&cmdString, &n, f))!=-1){
		
		if ( (pid = fork()) == -1) {
			return(EXIT_FAILURE);
		}
		
		if (pid == 0) {	//child
	
			myexec(cmdString);
			return(EXIT_FAILURE);
			
		} else {
			wait(NULL);	//wait for child to terminate
		}
	}
	fclose(f);
	return 0;
}