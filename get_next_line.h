#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

char				*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
int found_newline(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

#endif