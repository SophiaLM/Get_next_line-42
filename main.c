#include <stddef.h>
#include <stdlib.h>//dinamyc memory
#include <unistd.h>
#include <fcntl.h> //open

#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		*(unsigned char *)s++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = (void *)malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, nmemb * size);
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strappend(char *chain, char *block)
{
    char    *result;
    int        i;
    int        j;
    int        g;
//	int			len = (ft_strlen(chain)) + (ft_strlen(block) + 1);

    result = (char *)malloc(ft_strlen(chain)) + (ft_strlen(block) + 1);
    if (!result)
        return (NULL);
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

char    *ft_read(int fd)
{
    char    static *line;
    char    *buffer;
    int        bytes;
    int        i;
    int        j;

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

int    main()
{
    int    fd = open("texto.txt", O_RDONLY);

    char    *result = ft_read(fd);
    printf("%s\n", result);
}
