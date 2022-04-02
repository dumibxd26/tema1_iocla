#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "structs.h"

#define BUFF_SIZE 256

int add_last(void **arr, int *len, data_structure *data)
{

	char *add_to = (char *)(*arr) + *len;
	char *add_from = (char *)data;
	int  size = sizeof(data_structure);

	for(int i = 0; i < size; i++)
		add_to[i] = add_from[i];

	*len += size;

	data_structure *alka = *arr;
	printf("%d\n", alka->header->type);

	return 1;

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

data_structure *input_data(char *p)
{
	data_structure *read_structure = malloc(sizeof(data_structure));
	read_structure->header = malloc(sizeof(head));
	ds_info *info = malloc(sizeof(ds_info));

	p = strtok(NULL, " ");
	read_structure->header->type = (char)atoi(p);
	
	printf("%d\n", read_structure->header->type);

	p = strtok(NULL, " ");
	info->money_from = strdup(p);

	if(read_structure->header->type == 1)
	{
		p = strtok(NULL, " ");
		info->type.one.first_bill = atoi(p);

		p = strtok(NULL, " ");
		info->type.one.second_bill = atoi(p);
	}

	if(read_structure->header->type == 2)
	{
		p = strtok(NULL, " ");
		info->type.two.first_bill = atoi(p);

		p = strtok(NULL, " ");
		info->type.two.second_bill = atoi(p);
	}

	if(read_structure->header->type == 3)
	{
		p = strtok(NULL, " ");
		info->type.three.first_bill = atoi(p);

		p = strtok(NULL, " ");
		info->type.three.second_bill = atoi(p);
	}

	p = strtok(NULL, " ");
	info->money_to = strdup(p);

	read_structure->data = info;

	return read_structure;

}

void print(data_structure *arr)
{
	
	printf("%d\n", arr->header->type);

	ds_info *data = arr->data; 

	printf("%s\n", data->money_from);

	if(arr->header->type == 1)
	{
		printf("%"PRId8"\n", data->type.one.first_bill);
		printf("%"PRId8"\n", data->type.one.second_bill);
	}

	if(arr->header->type == 2)
	{
		printf("%"PRId16"\n", data->type.one.first_bill);
		printf("%"PRId32"\n", data->type.one.second_bill);
	}

	if(arr->header->type == 3)
	{
		printf("%"PRId32"\n", data->type.one.first_bill);
		printf("%"PRId32"\n", data->type.one.second_bill);
	}
	
	printf("%s\n", data->money_to);

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

	while(1)
	{

		fgets(line, BUFF_SIZE + 1, stdin);
		line[strlen(line) - 1] = '\0';

		p = strtok(line, " ");

		if(strcmp(line, "insert") == 0) {

			data_structure *data = input_data(p);
			printf("%d\n", data->header->type);
			add_last(&arr, &len, data);
			//free(data->header);
			//free(data);

		} else if(strcmp(line, "print") == 0) {
			data_structure *alka = arr;
			printf("%d\n", alka->header->type );
			print((data_structure *)arr);
		} else {
			
			free(arr);
			break;
		}
			
	}

	return 0;
}
