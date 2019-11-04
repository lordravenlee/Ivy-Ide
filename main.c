#include "globals.h"

check_word(char t[])
{
	int i;

	for (i = 0; i < 5; i++)
	{
		if (strcmp(t, predirect[i]) == 0)
		{
			printf(" %03d:   %s\t              Predirect\n", line_num, t);
			return;
		}
	}
	for (i = 0; i < 6; i++)
	{
		if (strcmp(t, header[i]) == 0)
		{
			printf(" %03d:   %s\t              Header\n", line_num, t);
			return;
		}
	}
	for (i = 0; i < 8; i++)
	{
		if (strcmp(t, data_type[i]) == 0)
		{
			printf(" %03d:   %s\t              Data_type\n", line_num, t);
			return;
		}
	}
	for (i = 0; i < 24; i++)
	{
		if (strcmp(t, data_tool[i]) == 0)
		{
			printf(" %03d:   %s\t              Data_tool\n", line_num, t);
			return;
		}
	}
	for (i = 0; i < 8; i++)
	{
		if (strcmp(t, data_modifiers[i]) == 0)
		{
			printf(" %03d:   %s\t              Data_modifiers\n", line_num, t);
			return;
		}
	}
	for (i = 0; i < 8; i++)
	{
		if (strcmp(t, file_type[i]) == 0)
		{
			printf(" %03d:   %s\t              File_type\n", line_num, t);
			return;
		}
	}
	check_ident(buffer);
}


check_ident(char t[])
{

	strcpy(ident_string, t);

	printf(" %03d:   %s\t              Identifier\n", line_num, ident_string);


	return IDENT;
}

get_token()
{
	while ((token_type = get_char(file, buffer, 1000 + 1)) != EOF)
	{
		line_num++;

		switch (token_type)
		{
		case SPACE:        printf("", buffer);                                                       break;
		case NELI:         printf("%s", buffer);                                                     break;

		case SEPERATOR:    printf(" %03d:   %s\t              Seperator\n", line_num, buffer);       break;
		case OPERATOR:     printf(" %03d:   %s\t              Operator\n", line_num, buffer);        break;
		case EQUALIZER:    printf(" %03d:   %s\t              Equalizer\n", line_num, buffer);       break;

		case NUMBER:       printf(" %03d:   %s\t              Number\n", line_num, buffer);          break;
		case WORD:         check_word(buffer);                                                       break;
		case IDENT:                                                                                  break;

		case STRAND:       printf(" %03d:   %s\t              String Literal\n", line_num, buffer);  break;
		case UNKNOWN:                                                                                break;

		default:
			printf(" %03d: \tASCII value %d       \tUnknown\n", line_num, buffer[0]);
			break;/* parser();  */
		}
	}
}


get_char(FILE *file, char *const buf, const int max_token)
{
	int length = 0;
	int ch;
	int i = 0;

	if ((ch = fgetc(file)) == EOF)
	{
		return EOF;
	}

	buffer[length++] = ch;
	buffer[length] = 0;


	if (space(ch))        return SPACE;
	if (neli(ch))         return NELI;
	if (seperator(ch))    return SEPERATOR;
	if (operator(ch))     return OPERATOR;
	if (equalizer(ch))    return EQUALIZER;
	if (number(ch))       return NUMBER;
	if (strand(ch))       return STRAND;


	if (!letter(ch))     return UNKNOWN;


	while ((ch = fgetc(file)) != EOF && length < max_token)
	{
		if (!letter(ch))
		{
			ungetc(ch, file);
			break;
		}
		buffer[length++] = ch;
	}
	buffer[length] = 0;

	return WORD;
}


int main() 
{


	file = fopen("source.txt", "r");
	
	get_token();


	fclose(file);
	return 0;
}
