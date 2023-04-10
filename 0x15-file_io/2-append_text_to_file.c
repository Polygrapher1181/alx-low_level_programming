#include "main.h"

/**
 * append_text_to_file - appends text to the end of a file
 * @filename: the name of the file
 * @text_content: the text to add to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, write_status = -1, i = 0;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[i])
			i++;

		write_status = write(file_descriptor, text_content, i);
		if (write_status == -1)
			write_status = -1;

		if (close(file_descriptor) == -1)
			write_status = -1;
	}

	return (write_status);
}
