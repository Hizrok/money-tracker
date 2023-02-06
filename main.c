/**
 * @file main.c
 * @author Jan Kapsa (jan.kapsa@seznam.cz)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define VERSION "0.0.1"
#define MAX_LEN 1024
#define ITEM_LEN 255

/**
 * @brief data is entered as a line of words seperated by spaces, get next separates data by spaces,
 *        returns next item and removes it from the initial string
 *        "add income 100" ... -> returns "add" and "income 100 ..."
 */
void get_next(char *string, char *item) {
	int i;
	for (i = 0; string[i] != 32 && string[i] != 10 && i < MAX_LEN; i++) {
		item[i] = string[i];
	}
	item[i++] = 0;
	
	for (int j = 0; j < MAX_LEN-i; j++) {
		string[j] = string[i++];
	}
	// printf("item: %s\nstring: %s\n", item, string);
}

bool handle_command(char *line) {

	char cmd[255];
	get_next(line, cmd);
	
	if (!strcmp(cmd, "exit")) {
		return true;
	} else if (!strcmp(cmd, "help")) {
		
	} else if (!strcmp(cmd, "add")) {
		
	} else if (!strcmp(cmd, "edit")) {
		
	} else if (!strcmp(cmd, "remove")) {
		
	} else {
		printf("invalid command, enter 'help' for the list of supported commands\n");
	}
	
	return false;
}

int main(void) {
	
	printf("welcome to money tracker version %s\n", VERSION);

	bool exit_command = false;

	do {
		char line[MAX_LEN];
		char *str = fgets(line, MAX_LEN, stdin);
		if (!str) exit(1);
	
		exit_command = handle_command(line);		

	} while (!exit_command);

	return 0;
}