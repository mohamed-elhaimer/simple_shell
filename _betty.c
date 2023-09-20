#include "shell.h"
/**
 * main - programe that check betty of file
 * @argc: number of arguments passed
 * @argv: arguments passed
 * Return: 0
*/
int main(int argc, char *argv[])
{
	int res;

	const char *path = NULL;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <command>\n", argv[0]);
		exit(1);
	}

	if (strcmp(argv[1], "betty") == 0)
	{
		path = "/bin/betty";
	}
	res = execve(path, &argv[1], NULL);
	if (res == -1)
	{
		perror("ERROR");
		exit(1);
	}
	return (0);
}
