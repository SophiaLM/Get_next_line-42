#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_str_append(char *s1, char *s2)
{
	char	*s3;
	int	i;
	int	j;
	int	g;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	g = 0;
	while (s1[i])
		s3[g++] = s1[i++];
	while (s2[j])
		s3[g++] = s2[j++];
	s3[g] = '\0';
//	free(s2);
	return (s3);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	i;

	str = (void *)malloc(count * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i++ < count)
		*(unsigned char *)str++ = 0;
	return (str);
}
