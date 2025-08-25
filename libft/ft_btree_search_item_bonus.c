/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_item_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:13:55 by etran             #+#    #+#             */
/*   Updated: 2021/11/26 18:41:16 by myhuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *,
			void *))
{
	int		ret;
	t_btree	*tmp;

	if (!root)
		return (0);
	tmp = btree_search_item(root->left, data_ref, cmpf);
	if (tmp)
		return (tmp);
	ret = cmpf(root->item, data_ref);
	if (!ret)
		return (root->item);
	tmp = btree_search_item(root->right, data_ref, cmpf);
	if (tmp)
		return (tmp);
	return (0);
}
