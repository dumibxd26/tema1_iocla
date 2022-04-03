#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "structs.h"

#define SIZE_ADD (sizeof(head) + sizeof(ds_info))
#define BUFF_SIZE 256

int add_last(void **arr, int *len, data_structure *data)
{

	char *add_to = (char *)(*arr) + *len;
	char *add_from;

	add_from = (char *)data->header;

	for(int i = 0; i < sizeof(head); i++)
		add_to[i] = add_from[i];
	
	add_from = (char *)data->data;

	for(int i = 0; i < sizeof(ds_info); i++)
		add_to[i + sizeof(head)] = add_from[i];

	*len += sizeof(head) + sizeof(ds_info);

	return 1;

}

int add_at(void **arr, int *len, data_structure *data, int index)
{
	if(index < 0)
		return 0;
	
	//*len += sizeof(head) + sizeof(ds_info);

	char *arr_cast = (char *)(*arr);
	char *add_from;
	int i,j;

	for(i = *len / SIZE_ADD; i > index; i--)
		for(j = 0; j < sizeof(head) + sizeof(ds_info); j++)
			arr_cast[j + i * SIZE_ADD] = arr_cast[j + (i - 1) * SIZE_ADD];

	add_from = (char *)data->header;

	for(int d = 0; d < sizeof(head); d++)
		arr_cast[i * SIZE_ADD + d] = add_from[d];
	
	add_from = (char *)data->data;

	for(int d = 0; d < sizeof(ds_info); d++)
		arr_cast[i * SIZE_ADD + d + sizeof(head)] = add_from[d];

	*len += sizeof(head) + sizeof(ds_info);

	return 1;

}

void find(void *data_block, int len, int index) 
{

	if(index < 0 || index * (sizeof(ds_info) + sizeof(head)) >= len)
		return;
	
	char *arr_cast = (char *)data_block + index * (sizeof(ds_info) + sizeof(head));

	head *header = (head *)arr_cast;

	printf("%d\n", header->type);

	ds_info *data = (ds_info *)(arr_cast + sizeof(head)); 

	printf("%s\n", data->money_from);

	if(header->type == 1)
	{
		printf("%"PRId8"\n", data->type.one.first_bill);
		printf("%"PRId8"\n", data->type.one.second_bill);
	}

	if(header->type == 2)
	{
		printf("%"PRId16"\n", data->type.two.first_bill);
		printf("%"PRId32"\n", data->type.two.second_bill);
	}

	if(header->type == 3)
	{
		printf("%"PRId32"\n", data->type.three.first_bill);
		printf("%"PRId32"\n", data->type.three.second_bill);
	}
	
	printf("%s\n", data->money_to);
	

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

void print(void *arr, int len)
{
	int index = 0;

	while(index * (sizeof(head) + sizeof(ds_info)) < len)
	{
		find(arr, len, index);
		index++;
	}

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
			add_last(&arr, &len, data);
			free(data->header);
			free(data->data);
			free(data);

		} else if(strcmp(line, "find") == 0) {
			p = strtok(NULL, " ");
			int index = atoi(p);
			find(arr, len, index);
		} else if(strcmp(line, "insert_at") == 0) {
			p = strtok(NULL, " ");
			int index = atoi(p);
			data_structure *data = input_data(p);
			add_at(&arr, &len, data, index);
			free(data->header);
			free(data->data);
			free(data);
		} else if(strcmp(line, "print") == 0) {
			print((data_structure *)arr, len);
		} else {
			
			free(arr);
			break;
		}
			
	}

	free(arr);

	return 0;
}
