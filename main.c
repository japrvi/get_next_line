#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char *p;
	char c;
	//int i = 20;

	c = 0;
	int fd = open("./fich.txt", O_RDONLY);
	p = get_next_line(fd);
	printf("%s", p);
	/*while(p)
	{
		p = get_next_line(fd);
		printf("%s", p);
	}
	close(fd);
	fd = open("./fich2.txt", O_RDONLY);
	p = get_next_line(fd);
	printf("%s", p);
	while(p)
	{
		p = get_next_line(fd);
		printf("%s", p);
	}*/
	read(fd, &c, 1);
	printf("%c", c);
	close(fd);
}
