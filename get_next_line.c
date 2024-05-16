#include "get_next_line.h"

char	*ft_read_line(int fd, char *str_buff)
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

char	*ft_get_line(char *str_line)
{
	char	*line;
	int	len;
	int	i;
	int	j;

	len = ft_strlen(str_line);
	line = ft_calloc(len, sizeof(char *));
	i = 0;
	j = 0;
	while (i < len && str_line[j] != '\n')
	{
		line[i++]  = str_line[j++];
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_line(fd, buffer);//funcion que lee hasta el salto
	buffer = ft_get_line(line); //funcion que saca la linea hasta el salto
	return (line);
}

int	main()
{
	int	fd = open("texto.txt", O_RDONLY);
	char	*result = get_next_line(fd);

	printf("%s\n", result);
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
