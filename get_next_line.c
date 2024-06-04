#include "get_next_line.h"

char	*ft_read_line(int fd, char *str_buff)
{
	char	*buffer;
	int	bytes_read;

	if (!str_buff)
		str_buff = ft_calloc(1, sizeof(char));
	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && !ft_strchr(str_buff, '\n'))
	{
		buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			if (str_buff)
				return (str_buff);
			else
				return (NULL);
		}
		str_buff = ft_str_append(str_buff, buffer);
	}
	return (str_buff);
}

char	*ft_get_line(char *str_line)
{
	char	*line;
	int	i;
	int	j;

	i = 0;
	while (str_line[i] != '\0' && str_line[i] != '\n')
		i++;
	line = ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = str_line[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}
/*
char	*ft_save_next(char *str_line)
{
	char	*buffer;

	buffer = ft_strchr(str_
}
*/
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_line(fd, buffer);
	if (buffer)
	{
		free(buffer);
		buffer = ft_strchr(line, '\n');
	}
	else
		buffer = ft_strchr(line, '\n');
	line = ft_get_line(line);
	return (line);
}

int	main()
{
	int	fd = open("texto.txt", O_RDONLY);
	char	*result; //= get_next_line(fd);
	int	i;

//	printf("%s", result);
	i = 0;
	while (i < 3)
	{
		result = get_next_line(fd);
		printf("%s\n", result);
		i++;
	}	
	return (0);
}
