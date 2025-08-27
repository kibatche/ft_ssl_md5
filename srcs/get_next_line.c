/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:24:23 by chbadad           #+#    #+#             */
/*   Updated: 2021/05/30 16:44:07 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstadd_front(t_list **alst, t_list *new, int fd)
{
	new->fd = fd;
	new->save = ft_strndup("", 0);
	new->temp = NULL;
	new->next = *alst;
	*alst = new;
	return (new);
}

int	free_curr(t_list **head, t_list **curr, int res)
{
	t_list	*temp;

	if ((*head) == (*curr))
		(*head) = (*curr)->next;
	else
	{
		temp = (*head);
		while (temp->next != *curr)
			temp = temp->next;
		temp->next = (*curr)->next;
	}
	free((*curr)->save);
	free(*curr);
	*curr = NULL;
	return (res);
}

t_list	*ft_list_return_if(t_list **head, int fd)
{
	t_list	*begin_list;

	if (!(*head))
	{
		*head = malloc(sizeof(t_list));
		if (!*head)
			return (NULL);
		(*head)->fd = fd;
		(*head)->save = ft_strndup("", 0);
		(*head)->next = NULL;
	}
	begin_list = (*head);
	while (begin_list && begin_list->fd != fd)
		begin_list = begin_list->next;
	if (!begin_list)
	{
		begin_list = malloc(sizeof(t_list));
		if (!begin_list)
			return (NULL);
		ft_lstadd_front(&(*head), begin_list, fd);
	}
	return (begin_list);
}

int	create_next_line(char ***line, t_list **curr, int ret, t_list **head)
{
	int		nl;

	if (ret >= 0)
	{
		nl = ft_newline_chr((*curr)->save);
		if (ret > 0 || (nl != -1 && ret == 0))
			**line = ft_strndup((*curr)->save, nl);
		else
			**line = ft_strndup((*curr)->save, ft_strlen((*curr)->save));
		(*curr)->temp = ft_strtrim((*curr)->save);
		free((*curr)->save);
		(*curr)->save = ft_strndup((*curr)->temp, ft_strlen((*curr)->temp));
		free((*curr)->temp);
		if (ret == 0 && (*curr)->save[0] == 0 && nl == -1)
			return (free_curr(&(*head), &(*curr), EOF_REACHED));
		else
			return (LINE_READ);
	}
	else
		return (free_curr(&(*head), &(*curr), ERROR));
}

int	get_next_line(int fd, char **line)
{
	static t_list	*head;
	t_list			*curr;
	char			*buffer;
	int				ret;

	buffer = ft_strndup("", BUFFER_SIZE);
	if (fd < 0 || !line || read(fd, buffer, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		return (ERROR);
	}
	curr = ft_list_return_if(&head, fd);
	ret = BUFFER_SIZE;
	while (ret > 0 && curr->save[0] != '\n')
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		curr->temp = ft_strdupcat(curr->save, buffer, &curr->save);
		curr->save = ft_strndup(curr->temp, ft_strlen(curr->temp));
		free(curr->temp);
		if (ft_newline_chr(curr->save) != -1)
			break ;
	}
	free(buffer);
	return (create_next_line(&line, &curr, ret, &head));
}
