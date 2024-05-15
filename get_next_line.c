#include "get_next_line.h"

char	*ft_line(int fd, char *str_buff)
{
	char	*buffer;
	int	bytes_read;

	str_buff = malloc(sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char *));
	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && !ft_strchr(str_buff, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (NULL);
		str_buff = ft_str_append(str_buff, buffer);
	}
	return (str_buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || read(fd, NULL, 0))
		return (NULL);
	buffer = ft_line(fd, buffer);
	return (buffer);
}

int	main()
{
	int	fd = open("texto.txt", O_RDONLY);
	char	*result = get_next_line(fd);

	printf("%s", result);
	/*
	while (result)
	{
		printf("%s", result);
		free(result);
		result = get_next_line(fd);
	}
	return (0);
	*/
}
