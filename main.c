#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "structs.h"

#define BUFF_SIZE 256

int add_last(void **arr, int *len, data_structure *data)
{

}

int add_at(void **arr, int *len, data_structure *data, int index)
{

}

void find(void *data_block, int len, int index) 
{

}

int delete_at(void **arr, int *len, int index)
{

}

int append_bytes(void *to, void *from, int size)
{
	char *convert_to = (char *)to;
	char *convert_from = (char *)from;

	for(int i = 0; i < size; i++)
		convert_to[i] = convert_from[i];

}

data_structure *input_data(char *p)
{
	data_structure *read_structure = malloc(sizeof(data_structure));
	read_structure->header = malloc(sizeof(head));
	read_structure->data = (info*)malloc(sizeof(info));

	p = strtok(NULL, " ");
	read_structure->header->type = (char)atoi(p);
	
	p = strtok(NULL, " ");
	read_structure->



}

int main() {
	// the vector of bytes u have to work with
	// good luck :)
	void *arr = malloc(9999999);
	int  len = 0;
	char *line = malloc((BUFF_SIZE + 2) * sizeof(char));
	char *p;

	if(line == NULL)
	{
		fprintf(stderr, "Malloc failure");
		exit(0);
	}

	// while(1)
	// {

	// 	fgets(line, BUFF_SIZE + 1, stdin);
	// 	line[strlen(line) - 1] = '\0';

	// 	p = strtok(line, " ");

	// 	if(strcmp(line, "insert") == 0) {

	// 		data_structure *data = input_data();
	// 		add_last(&arr, &len, data);
	// 		free(data);

	// 	} else if(strcmp(line, "print") == 0) {

	// 	} else {
			
	// 		free(arr);
	// 		break;
	// 	}
			
	// }

	return 0;
}
