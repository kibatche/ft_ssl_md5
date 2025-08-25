/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:16:13 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/23 18:33:14 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*curr;

	if (!alst)
		return ;
	if (!*alst)
	{
		(*alst) = new;
		return ;
	}
	curr = &**alst;
	while (curr && curr->next)
		curr = curr->next;
	curr->next = new;
}
