#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char *p;
	//int i = 20;

	int fd = open("./get_next_line_utils.c", O_RDONLY);
	p = get_next_line(fd);
	printf("%s", p);
	while(p)
	{
		p = get_next_line(fd);
		printf("%s", p);
	}
	close(fd);
}
