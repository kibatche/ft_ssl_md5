/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:40:17 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/23 18:34:18 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*curr;

	if (!lst)
		return (NULL);
	curr = ft_lstnew(f(lst->content));
	ptr = curr;
	while (lst && lst->next)
	{
		lst = lst->next;
		curr->next = ft_lstnew(f(lst->content));
		if (!curr->next)
		{
			ft_lstclear(&ptr, del);
			return (NULL);
		}
		curr = curr->next;
	}
	return (ptr);
}
