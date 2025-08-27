/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:24:42 by chbadad           #+#    #+#             */
/*   Updated: 2021/05/30 16:44:21 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# define LINE_READ 1
# define EOF_REACHED 0
# define ERROR -1
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*save;
	char			*temp;
	struct s_list	*next;
}		t_list;

int		get_next_line(int fd, char **line);
int		create_next_line(char ***line, t_list **curr, int ret, t_list **head);
t_list	*ft_lstadd_back(t_list **alst, int fd);
t_list	*ft_list_return_if(t_list **head, int fd);
int		ft_newline_chr(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strdupcat(char *s1, char *s2, char **save);
char	*ft_strndup(const char *str, size_t len);
char	*ft_strtrim(char *s1);
int		free_curr(t_list **head, t_list **curr, int res);

#endif
