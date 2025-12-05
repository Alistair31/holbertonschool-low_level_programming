#include "main.h"
/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read and print
 * @letters: number of letters it should read and print
 * Return: number of letters readed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fic = 0;
	char buffer[2000];
	ssize_t count;

	if (filename == NULL)
	{
	return (0);
	}
	fic = open(filename, O_RDONLY);
	if (filename == NULL)
	{
		return (0);
	}
	count = read(fic, buffer, letters);
	if (count == -1)
	{
		return (0);
	}

	write(STDOUT_FILENO, buffer, count);

	close(fic);
	return (count);
}
