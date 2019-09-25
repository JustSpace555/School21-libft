#include <stdio.h>
#include <stdlib.h>

void	*my_malloc(size_t size, const char *file, int line, const char *func)
{
	void	*p = malloc(size);
	printf("Allocated = %s, %i, %s, %p[%li]\n", file, line, func, p, size);
	return(p);
}