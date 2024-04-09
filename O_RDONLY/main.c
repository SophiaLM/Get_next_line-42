#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	int	fd = open("texto.txt", O_RDONLY);
	char buffer[12];

	int	bytes = read(fd, buffer, sizeof(buffer));
	printf("%s\n", buffer);

	return (0);
}
