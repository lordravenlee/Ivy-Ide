#include "type.h"

FILE *file;
FILE *listing;

char ch;

char buffer[1000]; 
char *buffer_ptr = buffer;

char token_string[1000];
char *token_ptr = token_string;

char ident_string[1000];


int buffer_offset;
int index = 0;
int level = 0;
int length = 0;

int line_num = 0;
int line_row  = 0;
int line_column = 0;

int max_token = 0;
int cur_scope = 0;


typedef enum
{
	false, true,
}pare;

char predirect[][12] = { "use", "system",  "label",  "translate" };

char header[][12] = { "haven","s_type","m_type", "n_type", "io" };

char file_type[][12] = { "enfi", "read", "write", "file", };

char data_type[][12] = { "mark",  "hollow",  "decii",  "decii", "quad", "num", "strand" };

char data_tool[][12] = { "loop",  "during",  "set",  "check", "else", "compare", "pare", "list", "construct", "log", "class", "public", "private",
"return", "merge", "message", "elem", "object" };

char data_modifiers[][12] = { "extern","static", "register","short", "long", "signed", "unsigned" };

typedef enum
{
	WORD, IDENT, NUMBER, SEPERATOR, OPERATOR, EQUALIZER, STRAND, SPACE, NELI, UNKNOWN, LETTER, MODIFIER,
	ELSE, THEN, SEMICOLON, CHECK, LOOP, SET, READ, WRITE, ASSIGN, EQUAL, LARROW, ADDITION, SUBTRACTION,
	MULTIPLICATION, DIVISION, LPAREN, RPAREN, ENFI, ERROR, DURING, COMMA, BEGIN, END, NUM_LITERAL, DIGIT,
	TAB,
} token_types;

token_types token_type;
