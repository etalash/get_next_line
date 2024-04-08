#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	return (0);
}
