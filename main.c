#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main()
{
	size_t fd;
	char *s;

	fd = open("/home/mbozzi/Scrivania/prova.txt", O_RDWR);
	for (int i = 0; i < 50; i++)
	{
		s = get_next_line(fd);
		printf("'%s'\n\n", s);
		free(s);
	}
	close(fd);
}