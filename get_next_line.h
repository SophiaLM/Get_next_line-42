#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int	ft_strlen(char *str);
char	*ft_str_append(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
void	*ft_calloc(size_t count, size_t size);

char	*ft_read_line(int fd, char *buffer);
char    *get_next_line(int fd);

#endif
