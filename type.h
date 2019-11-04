#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define increment(ch)           ((ch == '+' || ch == '+'))
#define decrement(ch)           ((ch == '-' || ch == '-'))
#define mixture(ch)             (letter(ch) || number(ch))

int letter(int ch)
{
	return (((ch >= 'a') && (ch <= 'z')) || (ch >= 'A') && (ch <= 'Z') || (ch == '_'));
}

int number(int ch)
{
	return ((ch >= '0') && (ch <= '9'));
}

int seperator(int ch)
{
	return ((ch == '#') || (ch == '(') || (ch == ')') || (ch == '{') || (ch == '}') || (ch == '[') || (ch == ']')
		|| (ch == '<') || (ch == '>') || (ch == '.') || (ch == ',') || (ch == ':') || (ch == ';'));
}

int operator(int ch)
{
	return ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '%'));
}

int equalizer(int ch)
{
	return ((ch == '=') || (ch == '!'));
}

int space(int ch)
{
	return ((ch == ' ') || (ch == '\t'));
}

int neli(int ch)
{
	return ((ch == '\n'));
}

int tab(int ch)
{
	return ((ch == '\t'));
}

int strand(int ch)
{
	return ((ch == '\"'));
}

int comment(int ch)
{
	return ((ch == '/'));
}

int nuller(int ch)
{
	return ((ch == '\0'));
}
