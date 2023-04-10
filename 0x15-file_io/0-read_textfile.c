#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: A pointer to the name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The number of letters read and printed, or 0 if an error occurred.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *stream = malloc(letters * sizeof(char));
	int file = open(filename, O_RDONLY);

	if (filename == NULL)
		return (0);

	if (file == -1)
		return (0);

	ssize_t stream_read = read(file, stream, letters);
	if (stream_read == -1)
	{
		free(stream);
		close(file);
		return (0);
	}

	ssize_t stream_write = write(STDOUT_FILENO, stream, stream_read);
	if (stream_write == -1 || stream_write != stream_read)
	{
		free(stream);
		close(file);
		return (0);
	}

	free(stream);
	close(file);

	return (stream_write);
}
