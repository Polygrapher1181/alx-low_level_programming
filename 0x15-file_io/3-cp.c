#include "main.h"

#define BUFFER_SIZE 1204
#define ERROR_OUTPUT_FILENO STDERR_FILENO

/**
 * main - Create the copy
 * @argc: Argument
 * @argv: Arguments strings
 *
 * Return: 0 on success, otherwise 97, 98, 99, or 100
 */
int main(int argc, char *argv[])
{
	int input_fd, output_fd, istatus, ostatus;
	char buffer[BUFFER_SIZE];
	mode_t mode;

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	if (argc != 3)
		dprintf(ERROR_OUTPUT_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
		dprintf(ERROR_OUTPUT_FILENO,
				"Error: Can't read from file %s\n", argv[1]), exit(98);
	output_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (output_fd == -1)
		dprintf(ERROR_OUTPUT_FILENO,
				"Error: Can't write to %s\n", argv[2]), exit(99);
	do {
		istatus = read(input_fd, buffer, BUFFER_SIZE);
		if (istatus == -1)
		{
			dprintf(ERROR_OUTPUT_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		if (istatus > 0)
		{
			ostatus = write(output_fd, buffer, (ssize_t)istatus);
			if (ostatus == -1)
			{
				dprintf(ERROR_OUTPUT_FILENO, "Error: Can't write to %s\n", argv[2]);
				exit(99);
			}
		}
	} while (istatus > 0);
	istatus = close(input_fd);
	if (istatus == -1)
		dprintf(ERROR_OUTPUT_FILENO,
				"Error: Can't close fd %d\n", input_fd), exit(100);
	ostatus = close(output_fd);
	if (ostatus == -1)
		dprintf(ERROR_OUTPUT_FILENO,
				"Error: Can't close fd %d\n", output_fd), exit(100);
	return (0);
}
