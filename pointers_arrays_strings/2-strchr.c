#include "main.h"
/**
 * _strchr - locate a character in a string
 * @s: string of character
 * @c: occurence of the character to locate
 * Return: character in the string
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
	s++;
	if (*s == '\0')
	{
		return (s);
	}
	}
	return (0);
}
