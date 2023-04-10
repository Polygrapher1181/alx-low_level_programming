#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * print_error - function to print error messages to standard error
 * Return: void
 * @sms: error message string
 */
void print_error(char *sms)
{
	dprintf(STDERR_FILENO, "%s\n", sms);
}

/**
 * main - main function for copying the contents of one file to another
 * Return: 0 on success, other values on error
 * @argc: number of arguments passed to the program
 * @argv: array of argument strings
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t bytes_size;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		print_error("Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		print_error("Error: Can't read from file");
		exit(98);
	}

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (file_to == -1)
	{
		print_error("Error: Can't write to file");
		exit(99);
	}

	while ((bytes_size = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(file_to, buffer, bytes_size) != bytes_size)
		{
			print_error("Error: Can't write to file");
			exit(99);
		}
	}

	if (bytes_size == -1)
	{
		print_error("Error: Can't read from file");
		exit(98);
	}

	if (close(file_from) == -1)
	{
		print_error("Error: Can't close file descriptor");
		exit(100);
	}

	if (close(file_to) == -1)
	{
		print_error("Error: Can't close file descriptor");
		exit(100);
	}

	return (0);
}
