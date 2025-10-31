#include "main.h"

/**
 * cap_string - capitalizes all words of a string.
 * @sc: pointer to the string
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *sc)
{
	int i = 0;
	int up = 1;

	while (sc[i] != '\0')
	{
		if (up && sc[i] >= 97 && sc[i] <= 122)
		{
			sc[i] = sc[i] - 32;
			up = 0;
		}
		else if (sc[i] == 32 || sc[i] == 33 || sc[i] == 34 || sc[i] == 40 || sc[i] == 41 || sc[i] == 44 || sc[i] == 46 || sc[i] == 59 || sc[i] == 63 || sc[i] == 123 || sc[i] == 125 || sc[i] == 45)
		{
			up = 1;
		}
		else
		{
			up = 0;
		}
		i++;
	}
	return (sc);
}
