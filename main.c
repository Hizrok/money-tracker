/**
 * @file main.c
 * @author Jan Kapsa (jan.kapsa@seznam.cz)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define VERSION "0.0.2"
#define MAX_LEN 1024

void add_item(char **data, int size) {
	printf("adding item: ");
	for(int i = 1; i < size; i++) {
		printf("%s ", data[i]);
	}
	printf("\n");
}

void edit_item(char **data, int size) {
	printf("editing item: ");
	for(int i = 1; i < size; i++) {
		printf("%s ", data[i]);
	}
	printf("\n");
}

void remove_item(char **data, int size) {
	printf("removing item: ");
	for(int i = 1; i < size; i++) {
		printf("%s ", data[i]);
	}
	printf("\n");
}

bool handle_command(char **data, int size) {
	if (!strcmp(data[0], "exit")) {
		return true;
	} else if (!strcmp(data[0], "add_item")) {
		add_item(data, size);
	} else if (!strcmp(data[0], "edit_item")) {
		edit_item(data, size);
	} else if (!strcmp(data[0], "remove_item")) {
		remove_item(data, size);
	}

	return false;
}

char **get_input(char *line, int *size) {
	bool in_quotes = false, found = false;	
	int data_count = 0, data_cap = 2, char_count = 0;
	char **data = (char**)malloc(data_cap * sizeof(char*));
	if (data == NULL) return NULL;

	for (int i = 0; i < MAX_LEN && line[i] != 0; i++) {

		if ((line[i] == ' ' || line[i] == 10) && char_count == 0) continue;

		if ((line[i] == ' ' || line[i] == 10) && !in_quotes) {
			found = true;
		} else if (line[i] == '"') {
			in_quotes = !in_quotes;
			if (in_quotes == false) {
				found = true;
			}
		} else {
			char_count++;
		}

		if (found) {
			data_count++;
			
			if (data_count == data_cap) {
				data_cap *= 2;
				data = (char**)realloc(data, data_cap * sizeof(char*));
				if (data == NULL) return NULL;
			}
			
			char *str = (char*)malloc((char_count+1) * sizeof(char));
			if (str == NULL) return NULL;
			int j;
			for (j = 0; j < char_count; j++) {
				str[j] = line[i - char_count + j];
			}
			str[j] = 0;
			data[data_count-1] = str;
			
			char_count = 0;
			found = false;
		}
	}

	*size = data_count;

	return data;
}

int main(void) {
	
	printf("welcome to money tracker version %s\n", VERSION);

	bool exit_command = false;

	do {
		char line[MAX_LEN];
		char *str = fgets(line, MAX_LEN, stdin);
		if (!str) exit(1);
	
		int size = 0;
		char **data = get_input(line, &size);

		exit_command = handle_command(data, size);

		if (data != NULL) {
			for (int i = 0; i < size; i++) {
				free(data[i]);
			}		
			free(data);
		}
	} while (!exit_command);

	return 0;
}