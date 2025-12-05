#include "main.h"
/**
 * append_text_to_file - function that appends text at the end of a file
 * @filename: name of the file
 * @text_content: text to append
 * Return: 1 on success, -1 on fail

 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fic;
	ssize_t cslscl;

	if (filename == NULL)
		return (-1);

	fic = open(filename, O_WRONLY | O_APPEND);
	if (fic == -1)
		return (-1);

	if (text_content != NULL)
	{
		cslscl = write(fic, text_content, strlen(text_content));
		if (cslscl == -1)
		{
			close(fic);
			return (-1);
		}
	}

	close(fic);
	return (1);
}
