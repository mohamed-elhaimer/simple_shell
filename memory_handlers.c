#include "header.h"

/**
 * _realloc - block using malloc and free
 *@ptr: pointer
 *@oldsize:  Of The Pointer
 *@newsize: the pointer
 *Return:  memory
 */
void *_realloc(void *ptr, unsigned int oldsize, unsigned int newsize)
{
	void *result;

	if (newsize == oldsize)
		return (ptr);
	if (newsize == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(newsize);
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', newsize);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, oldsize);
		free(ptr);
	}
	return (result);
}

/**
 * free_all - free memory allocated
 * @cmd: array pointer
 * @line: char pointer
 * Return: Void
 */
void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * _memcpy - copy bytes of memory from source to destination
 *@dest: destination pointer
 *@src: source pointer
 *@n: size to be copied
 *Return: pointer to destination
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * fill_an_array - fill an array by constant byte
 *@a: void pointer
 *@el: int
 *@len: length for int
 *Return: void pointer
 */
void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * _calloc - allocates memory for an array using malloc
 *@size: size
 *Return: void pointer
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
