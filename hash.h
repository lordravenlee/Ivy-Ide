#include "globals.h"

typedef struct hash_table hash_table;

struct hash_table 
{
	int lin_num;
	char token[50];
	struct hash_table *next;
};
struct hash_table *hash[15];

char tokens[15][20];

void assign_tokens() 
{
	int i;

	for (i = 0; i < 12; i++)
	{
		if (i == 0) 
		{
			strcpy(tokens[i], "Predirect");
		}
		else if (i == 1)
		{
			strcpy(tokens[i], "Header");
		}
		else if (i == 2) 
		{
			strcpy(tokens[i], "Data_type");
		}
		else if (i == 3)
		{
			strcpy(tokens[i], "Data_tool");
		}
		else if (i == 4) 
		{
			strcpy(tokens[i], "Data_modifiers");
		}
		else if (i == 5) 
		{
			strcpy(tokens[i], "File_type");
		}
		else if (i == 6) 
		{
			strcpy(tokens[i], "Identifier");
		}
		else if (i == 7)
		{
			strcpy(tokens[i], "Seperator");
		}
		else if (i == 8)
		{
			strcpy(tokens[i], "Operator");
		}
		else if (i == 9) 
		{
			strcpy(tokens[i], "Equalizer");
		}
		else if (i == 10)
		{
			strcpy(tokens[i], "Number");
		}
		else if (i == 11)
		{
			strcpy(tokens[i], "Strand_Literal");
		}
		else 
		{
			strcpy(tokens[i], "Unknown");
		}
	}
}
void init_function()
{
	int i = 0;

	*hash=(struct hash_table*)malloc(50*sizeof(struct hash_table));

	for (i = 0; i < 15; i++) 
	{
		hash[i] = NULL;
	}
	assign_tokens();
}
struct hash_table* new_node()
{
	hash_table *temp = (hash_table*)malloc(sizeof(hash_table));
	temp->next = NULL;
	return temp;
}


print_hash(int a, char b[], int c)
{
	hash_table *temp1, *temp2;

	temp1 = new_node();

	strcpy(temp1->token, b);

	temp1->lin_num = a;

	if (hash[c] == NULL)
	{
		hash[c] = temp1;
	}
	else 
	{
		temp2 = hash[c];

		while (hash[c]->next != NULL) 
		{
			hash[c] = hash[c]->next;
		}
		hash[c]->next = temp1;
		hash[c] = temp2;
	}
}

create_output() 
{
	FILE *out_file = fopen("output.txt", "w");
	fprintf(out_file, "Token Type		Tokens with line_Number\n");
	fprintf(out_file, "--------------------------------------------------------------------------------\n");

	int i;

	for (i = 0; i < 12; i++) 
	{
		fprintf(out_file, "%s		                    \t", tokens[i]);
		//	printf("%s",tokens[i]);
		hash_table *temp;
		temp = hash[i];
		while (temp != NULL) 
		{
			fprintf(out_file, " [%03d, %s], ", temp->lin_num, temp->token);
			//		printf("[%d, %s] ",temp->lin_num,temp->token);
			temp = temp->next;
		}
		//	printf("\n");
		fprintf(out_file, "\n");

	}
	fclose(out_file);
}
