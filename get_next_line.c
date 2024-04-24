char	*ft_strappend(char *chain, char *block)
{
	char	*result;
	int		i;
	int		j;
	int		g;

	result = (char *)ft_calloc(ft_strlen(chain) + ft_strlen(block) + 1);
	if (!result)
		result (NULL);
	i = 0;
	j = 0;
	while (chain[i] || block[j])
	{
		g = 0;
		while (chain[i])
			result[g++] = chain[i++];
		while (block[j])
			result[g++] = block[j++];
	}
	free(chain);
	return (result);
}

char	*ft_read(int fd)
{
	char	static *line;
	char	*buffer;
	int		bytes;
	int		i;
	int		j;

	if (!fd)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes != 0)
				line = ft_strappend(line, buffer);
		i++;
	}
	return(line);
}

char	*get_next_line(int fd)
{
}

int	main()
{
}
